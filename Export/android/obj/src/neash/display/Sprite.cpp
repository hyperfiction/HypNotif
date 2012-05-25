#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void Sprite_obj::__construct()
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",18)
	super::__construct(::neash::display::DisplayObjectContainer_obj::nme_create_display_object_container(),this->nmeGetType());
}
;
	return null();
}

Sprite_obj::~Sprite_obj() { }

Dynamic Sprite_obj::__CreateEmpty() { return  new Sprite_obj; }
hx::ObjectPtr< Sprite_obj > Sprite_obj::__new()
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

Dynamic Sprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

::String Sprite_obj::nmeGetType( ){
	HX_SOURCE_PUSH("Sprite_obj::nmeGetType")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",25)
	::String type = ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",26)
	int pos = type.lastIndexOf(HX_CSTRING("."),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",27)
	return (  (((pos >= (int)0))) ? ::String(type.substr((pos + (int)1),null())) : ::String(type) );
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,nmeGetType,return )

Void Sprite_obj::startDrag( hx::Null< bool >  __o_lockCenter,::neash::geom::Rectangle bounds){
bool lockCenter = __o_lockCenter.Default(false);
	HX_SOURCE_PUSH("Sprite_obj::startDrag");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",32)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",34)
			this->nmeGetStage()->nmeStartDrag(hx::ObjectPtr<OBJ_>(this),lockCenter,bounds);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Sprite_obj,startDrag,(void))

Void Sprite_obj::stopDrag( ){
{
		HX_SOURCE_PUSH("Sprite_obj::stopDrag")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",39)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Sprite.hx",41)
			this->nmeGetStage()->nmeStopDrag(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,stopDrag,(void))


Sprite_obj::Sprite_obj()
{
}

void Sprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sprite);
	HX_MARK_MEMBER_NAME(buttonMode,"buttonMode");
	HX_MARK_MEMBER_NAME(useHandCursor,"useHandCursor");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Sprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"stopDrag") ) { return stopDrag_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startDrag") ) { return startDrag_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"buttonMode") ) { return buttonMode; }
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"useHandCursor") ) { return useHandCursor; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"buttonMode") ) { buttonMode=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"useHandCursor") ) { useHandCursor=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buttonMode"));
	outFields->push(HX_CSTRING("useHandCursor"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("buttonMode"),
	HX_CSTRING("useHandCursor"),
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("startDrag"),
	HX_CSTRING("stopDrag"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Sprite_obj::__mClass;

void Sprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Sprite"), hx::TCanCast< Sprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
