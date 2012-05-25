#ifndef INCLUDED_neash_geom_ColorTransform
#define INCLUDED_neash_geom_ColorTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,ColorTransform)
namespace neash{
namespace geom{


class ColorTransform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorTransform_obj OBJ_;
		ColorTransform_obj();
		Void __construct(hx::Null< double >  __o_inRedMultiplier,hx::Null< double >  __o_inGreenMultiplier,hx::Null< double >  __o_inBlueMultiplier,hx::Null< double >  __o_inAlphaMultiplier,hx::Null< double >  __o_inRedOffset,hx::Null< double >  __o_inGreenOffset,hx::Null< double >  __o_inBlueOffset,hx::Null< double >  __o_inAlphaOffset);

	public:
		static hx::ObjectPtr< ColorTransform_obj > __new(hx::Null< double >  __o_inRedMultiplier,hx::Null< double >  __o_inGreenMultiplier,hx::Null< double >  __o_inBlueMultiplier,hx::Null< double >  __o_inAlphaMultiplier,hx::Null< double >  __o_inRedOffset,hx::Null< double >  __o_inGreenOffset,hx::Null< double >  __o_inBlueOffset,hx::Null< double >  __o_inAlphaOffset);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorTransform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColorTransform"); }

		double alphaMultiplier; /* REM */ 
		double alphaOffset; /* REM */ 
		double blueMultiplier; /* REM */ 
		double blueOffset; /* REM */ 
		double greenMultiplier; /* REM */ 
		double greenOffset; /* REM */ 
		double redMultiplier; /* REM */ 
		double redOffset; /* REM */ 
		virtual Void concat( ::neash::geom::ColorTransform second);
		Dynamic concat_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_ColorTransform */ 
