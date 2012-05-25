#ifndef INCLUDED_neash_geom_Rectangle
#define INCLUDED_neash_geom_Rectangle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace geom{


class Rectangle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Rectangle_obj OBJ_;
		Rectangle_obj();
		Void __construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight);

	public:
		static hx::ObjectPtr< Rectangle_obj > __new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Rectangle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Rectangle"); }

		double bottom; /* REM */ 
		::neash::geom::Point bottomRight; /* REM */ 
		double height; /* REM */ 
		double left; /* REM */ 
		double right; /* REM */ 
		::neash::geom::Point size; /* REM */ 
		double top; /* REM */ 
		::neash::geom::Point topLeft; /* REM */ 
		double width; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		virtual ::neash::geom::Rectangle clone( );
		Dynamic clone_dyn();

		virtual bool contains( double inX,double inY);
		Dynamic contains_dyn();

		virtual bool containsPoint( ::neash::geom::Point point);
		Dynamic containsPoint_dyn();

		virtual bool containsRect( ::neash::geom::Rectangle rect);
		Dynamic containsRect_dyn();

		virtual bool equals( ::neash::geom::Rectangle toCompare);
		Dynamic equals_dyn();

		virtual Void extendBounds( ::neash::geom::Rectangle r);
		Dynamic extendBounds_dyn();

		virtual Void inflate( double dx,double dy);
		Dynamic inflate_dyn();

		virtual Void inflatePoint( ::neash::geom::Point point);
		Dynamic inflatePoint_dyn();

		virtual ::neash::geom::Rectangle intersection( ::neash::geom::Rectangle toIntersect);
		Dynamic intersection_dyn();

		virtual bool intersects( ::neash::geom::Rectangle toIntersect);
		Dynamic intersects_dyn();

		virtual bool isEmpty( );
		Dynamic isEmpty_dyn();

		virtual Void offset( double dx,double dy);
		Dynamic offset_dyn();

		virtual Void offsetPoint( ::neash::geom::Point point);
		Dynamic offsetPoint_dyn();

		virtual Void setEmpty( );
		Dynamic setEmpty_dyn();

		virtual ::neash::geom::Rectangle transform( ::neash::geom::Matrix m);
		Dynamic transform_dyn();

		virtual ::neash::geom::Rectangle _union( ::neash::geom::Rectangle toUnion);
		Dynamic _union_dyn();

		virtual double nmeGetBottom( );
		Dynamic nmeGetBottom_dyn();

		virtual double nmeSetBottom( double b);
		Dynamic nmeSetBottom_dyn();

		virtual ::neash::geom::Point nmeGetBottomRight( );
		Dynamic nmeGetBottomRight_dyn();

		virtual ::neash::geom::Point nmeSetBottomRight( ::neash::geom::Point p);
		Dynamic nmeSetBottomRight_dyn();

		virtual double nmeGetLeft( );
		Dynamic nmeGetLeft_dyn();

		virtual double nmeSetLeft( double l);
		Dynamic nmeSetLeft_dyn();

		virtual double nmeGetRight( );
		Dynamic nmeGetRight_dyn();

		virtual double nmeSetRight( double r);
		Dynamic nmeSetRight_dyn();

		virtual ::neash::geom::Point nmeGetSize( );
		Dynamic nmeGetSize_dyn();

		virtual ::neash::geom::Point nmeSetSize( ::neash::geom::Point p);
		Dynamic nmeSetSize_dyn();

		virtual double nmeGetTop( );
		Dynamic nmeGetTop_dyn();

		virtual double nmeSetTop( double t);
		Dynamic nmeSetTop_dyn();

		virtual ::neash::geom::Point nmeGetTopLeft( );
		Dynamic nmeGetTopLeft_dyn();

		virtual ::neash::geom::Point nmeSetTopLeft( ::neash::geom::Point p);
		Dynamic nmeSetTopLeft_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Rectangle */ 
