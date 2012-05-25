#ifndef INCLUDED_neash_geom_Matrix
#define INCLUDED_neash_geom_Matrix

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace neash{
namespace geom{


class Matrix_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix_obj OBJ_;
		Matrix_obj();
		Void __construct(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty);

	public:
		static hx::ObjectPtr< Matrix_obj > __new(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Matrix_obj();

		HX_DO_RTTI;
		double __INumField(int inFieldID);
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Matrix"); }

		double a; /* REM */ 
		double b; /* REM */ 
		double c; /* REM */ 
		double d; /* REM */ 
		double tx; /* REM */ 
		double ty; /* REM */ 
		virtual ::neash::geom::Matrix clone( );
		Dynamic clone_dyn();

		virtual Void concat( ::neash::geom::Matrix m);
		Dynamic concat_dyn();

		virtual Void createBox( double scaleX,double scaleY,Dynamic rotation,Dynamic tx,Dynamic ty);
		Dynamic createBox_dyn();

		virtual Void createGradientBox( double in_width,double in_height,Dynamic rotation,Dynamic in_tx,Dynamic in_ty);
		Dynamic createGradientBox_dyn();

		virtual Void identity( );
		Dynamic identity_dyn();

		virtual ::neash::geom::Matrix invert( );
		Dynamic invert_dyn();

		virtual ::neash::geom::Matrix mult( ::neash::geom::Matrix m);
		Dynamic mult_dyn();

		virtual Void rotate( double inTheta);
		Dynamic rotate_dyn();

		virtual Void scale( double inSX,double inSY);
		Dynamic scale_dyn();

		virtual Void setRotation( double inTheta,Dynamic inScale);
		Dynamic setRotation_dyn();

		virtual ::neash::geom::Point transformPoint( ::neash::geom::Point inPos);
		Dynamic transformPoint_dyn();

		virtual Void translate( double inDX,double inDY);
		Dynamic translate_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Matrix */ 
