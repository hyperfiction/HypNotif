#include <hxcpp.h>

#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
namespace neash{
namespace display{

Void Bitmap_obj::__construct(::neash::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",34)
	super::__construct(::neash::display::DisplayObject_obj::nme_create_display_object(),HX_CSTRING("Bitmap"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",36)
	this->pixelSnapping = inPixelSnapping;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",37)
	this->nmeSetSmoothing(inSmoothing);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",39)
	this->nmeSetBitmapData(inBitmapData);
}
;
	return null();
}

Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::neash::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inBitmapData,inPixelSnapping,inSmoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Bitmap_obj::nmeRebuid( ){
{
		HX_SOURCE_PUSH("Bitmap_obj::nmeRebuid")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",45)
		::neash::display::Graphics gfx = this->nmeGetGraphics();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",46)
		gfx->clear();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",48)
		if (((this->bitmapData != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",50)
			gfx->beginBitmapFill(this->bitmapData,null(),false,this->smoothing);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",51)
			gfx->drawRect((int)0,(int)0,this->bitmapData->nmeGetWidth(),this->bitmapData->nmeGetHeight());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",52)
			gfx->endFill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,nmeRebuid,(void))

::neash::display::BitmapData Bitmap_obj::nmeSetBitmapData( ::neash::display::BitmapData inBitmapData){
	HX_SOURCE_PUSH("Bitmap_obj::nmeSetBitmapData")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",64)
	this->bitmapData = inBitmapData;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",65)
	this->nmeRebuid();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",67)
	return inBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,nmeSetBitmapData,return )

bool Bitmap_obj::nmeSetSmoothing( bool inSmooth){
	HX_SOURCE_PUSH("Bitmap_obj::nmeSetSmoothing")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",73)
	this->smoothing = inSmooth;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",74)
	this->nmeRebuid();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Bitmap.hx",76)
	return inSmooth;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,nmeSetSmoothing,return )


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(pixelSnapping,"pixelSnapping");
	HX_MARK_MEMBER_NAME(smoothing,"smoothing");
	HX_MARK_MEMBER_NAME(mGraphics,"mGraphics");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Bitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { return smoothing; }
		if (HX_FIELD_EQ(inName,"mGraphics") ) { return mGraphics; }
		if (HX_FIELD_EQ(inName,"nmeRebuid") ) { return nmeRebuid_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return pixelSnapping; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeSetSmoothing") ) { return nmeSetSmoothing_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeSetBitmapData") ) { return nmeSetBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { if (inCallProp) return nmeSetSmoothing(inValue);smoothing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mGraphics") ) { mGraphics=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { if (inCallProp) return nmeSetBitmapData(inValue);bitmapData=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { pixelSnapping=inValue.Cast< ::neash::display::PixelSnapping >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("pixelSnapping"));
	outFields->push(HX_CSTRING("smoothing"));
	outFields->push(HX_CSTRING("mGraphics"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bitmapData"),
	HX_CSTRING("pixelSnapping"),
	HX_CSTRING("smoothing"),
	HX_CSTRING("mGraphics"),
	HX_CSTRING("nmeRebuid"),
	HX_CSTRING("nmeSetBitmapData"),
	HX_CSTRING("nmeSetSmoothing"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bitmap_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
