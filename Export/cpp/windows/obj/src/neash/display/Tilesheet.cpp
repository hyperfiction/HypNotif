#include <hxcpp.h>

#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_Tilesheet
#include <neash/display/Tilesheet.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void Tilesheet_obj::__construct(::neash::display::BitmapData inImage)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Tilesheet.hx",27)
	this->nmeBitmap = inImage;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Tilesheet.hx",28)
	this->nmeHandle = ::neash::display::Tilesheet_obj::nme_tilesheet_create(inImage->nmeHandle);
}
;
	return null();
}

Tilesheet_obj::~Tilesheet_obj() { }

Dynamic Tilesheet_obj::__CreateEmpty() { return  new Tilesheet_obj; }
hx::ObjectPtr< Tilesheet_obj > Tilesheet_obj::__new(::neash::display::BitmapData inImage)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(inImage);
	return result;}

Dynamic Tilesheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Tilesheet_obj::addTileRect( ::neash::geom::Rectangle rectangle,::neash::geom::Point centerPoint){
{
		HX_SOURCE_PUSH("Tilesheet_obj::addTileRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Tilesheet.hx",33)
		::neash::display::Tilesheet_obj::nme_tilesheet_add_rect(this->nmeHandle,rectangle,centerPoint);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Tilesheet_obj,addTileRect,(void))

Void Tilesheet_obj::drawTiles( ::neash::display::Graphics graphics,Array< double > tileData,hx::Null< bool >  __o_smooth,hx::Null< int >  __o_flags){
bool smooth = __o_smooth.Default(false);
int flags = __o_flags.Default(0);
	HX_SOURCE_PUSH("Tilesheet_obj::drawTiles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Tilesheet.hx",58)
		graphics->drawTiles(hx::ObjectPtr<OBJ_>(this),tileData,smooth,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Tilesheet_obj,drawTiles,(void))

int Tilesheet_obj::TILE_SCALE;

int Tilesheet_obj::TILE_ROTATION;

int Tilesheet_obj::TILE_RGB;

int Tilesheet_obj::TILE_ALPHA;

int Tilesheet_obj::TILE_BLEND_NORMAL;

int Tilesheet_obj::TILE_BLEND_ADD;

Dynamic Tilesheet_obj::nme_tilesheet_create;

Dynamic Tilesheet_obj::nme_tilesheet_add_rect;


Tilesheet_obj::Tilesheet_obj()
{
}

void Tilesheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tilesheet);
	HX_MARK_MEMBER_NAME(nmeBitmap,"nmeBitmap");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic Tilesheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { return TILE_RGB; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeBitmap") ) { return nmeBitmap; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { return TILE_SCALE; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { return TILE_ALPHA; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addTileRect") ) { return addTileRect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { return TILE_ROTATION; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { return TILE_BLEND_ADD; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { return TILE_BLEND_NORMAL; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_create") ) { return nme_tilesheet_create; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_add_rect") ) { return nme_tilesheet_add_rect; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Tilesheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { TILE_RGB=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeBitmap") ) { nmeBitmap=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { TILE_SCALE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { TILE_ALPHA=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { TILE_ROTATION=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { TILE_BLEND_ADD=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { TILE_BLEND_NORMAL=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_create") ) { nme_tilesheet_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_add_rect") ) { nme_tilesheet_add_rect=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Tilesheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeBitmap"));
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("TILE_BLEND_NORMAL"),
	HX_CSTRING("TILE_BLEND_ADD"),
	HX_CSTRING("nme_tilesheet_create"),
	HX_CSTRING("nme_tilesheet_add_rect"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeBitmap"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("addTileRect"),
	HX_CSTRING("drawTiles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::nme_tilesheet_create,"nme_tilesheet_create");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::nme_tilesheet_add_rect,"nme_tilesheet_add_rect");
};

Class Tilesheet_obj::__mClass;

void Tilesheet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Tilesheet"), hx::TCanCast< Tilesheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Tilesheet_obj::__boot()
{
	hx::Static(TILE_SCALE) = (int)1;
	hx::Static(TILE_ROTATION) = (int)2;
	hx::Static(TILE_RGB) = (int)4;
	hx::Static(TILE_ALPHA) = (int)8;
	hx::Static(TILE_BLEND_NORMAL) = (int)0;
	hx::Static(TILE_BLEND_ADD) = (int)65536;
	hx::Static(nme_tilesheet_create) = ::neash::Loader_obj::load(HX_CSTRING("nme_tilesheet_create"),(int)1);
	hx::Static(nme_tilesheet_add_rect) = ::neash::Loader_obj::load(HX_CSTRING("nme_tilesheet_add_rect"),(int)3);
}

} // end namespace neash
} // end namespace display
