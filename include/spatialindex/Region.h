// Spatial Index Library
//
// Copyright (C) 2004  Navel Ltd.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Email:
//    mhadji@gmail.com

#pragma once

namespace SpatialIndex
{
	class SIDX_DLL Region : public Tools::IObject, public virtual IShape
	{
	public:
		Region();
		Region(const double* pLow, const double* pHigh, uint32_t dimension);
		Region(const Point& low, const Point& high);
		Region(const Region& in);
		virtual ~Region();

		virtual Region& operator=(const Region& r);
		virtual bool operator==(const Region&) const;

		//
		// IObject interface
		//
		virtual Region* clone();

		//
		// ISerializable interface
		//
		virtual uint32_t getByteArraySize() const;
		virtual void loadFromByteArray(const byte* data);
		virtual void storeToByteArray(byte** data, uint32_t& length) const;

		//
		// IShape interface
		//
		virtual bool intersectsShape(const IShape& in) const;
		virtual bool containsShape(const IShape& in) const;
		virtual bool touchesShape(const IShape& in) const;
		virtual void getCenter(Point& out) const;
		virtual uint32_t getDimension() const;
		virtual void getMBR(Region& out) const;
		virtual double getArea() const;
		virtual double getMinimumDistance(const IShape& in) const;

		virtual bool intersectsRegion(const Region& in) const;
		virtual bool containsRegion(const Region& in) const;
		virtual bool touchesRegion(const Region& in) const;
		virtual double getMinimumDistance(const Region& in) const;

		virtual bool containsPoint(const Point& in) const;
		virtual bool touchesPoint(const Point& in) const;
		virtual double getMinimumDistance(const Point& in) const;

		virtual Region getIntersectingRegion(const Region& r) const;
		virtual double getIntersectingArea(const Region& in) const;
		virtual double getMargin() const;

		virtual void combineRegion(const Region& in);
		virtual void combinePoint(const Point& in);
		virtual void getCombinedRegion(Region& out, const Region& in) const;

		virtual double getLow(uint32_t index) const;
		virtual double getHigh(uint32_t index) const;

		virtual void makeInfinite(uint32_t dimension);
		virtual void makeDimension(uint32_t dimension);

	private:
		void initialize(const double* pLow, const double* pHigh, uint32_t dimension);

	public:
		uint32_t m_dimension;
		double* m_pLow;
		double* m_pHigh;

		friend SIDX_DLL std::ostream& operator<<(std::ostream& os, const Region& r);
	}; // Region
	
	typedef Tools::PoolPointer<Region> RegionPtr;
	SIDX_DLL std::ostream& operator<<(std::ostream& os, const Region& r);
}
