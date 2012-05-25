#include <hxcpp.h>

#ifndef INCLUDED_ApplicationMain
#include <ApplicationMain.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_TestNativeGestures
#include <TestNativeGestures.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
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
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif

Void ApplicationMain_obj::__construct()
{
	return null();
}

ApplicationMain_obj::~ApplicationMain_obj() { }

Dynamic ApplicationMain_obj::__CreateEmpty() { return  new ApplicationMain_obj; }
hx::ObjectPtr< ApplicationMain_obj > ApplicationMain_obj::__new()
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

Dynamic ApplicationMain_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

Void ApplicationMain_obj::main( ){
{
		HX_SOURCE_PUSH("ApplicationMain_obj::main")
		HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",15)
		::neash::Lib_obj::setPackage(HX_CSTRING("Hyperfiction"),HX_CSTRING("hypertest"),HX_CSTRING("fr.hyperfiction.Tests"),HX_CSTRING("1.0.0"));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(){
{
				HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",41)
				{
				}
				HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",47)
				bool hasMain = false;
				HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",49)
				{
					HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",49)
					int _g = (int)0;
					Array< ::String > _g1 = ::Type_obj::getClassFields(hx::ClassOf< ::TestNativeGestures >());
					HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",49)
					while(((_g < _g1->length))){
						HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",49)
						::String methodName = _g1->__get(_g);
						HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",49)
						++(_g);
						HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",51)
						if (((methodName == HX_CSTRING("main")))){
							HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",53)
							hasMain = true;
							HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",54)
							break;
						}
					}
				}
				HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",58)
				if ((hasMain)){
					HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",59)
					::Reflect_obj::callMethod(hx::ClassOf< ::TestNativeGestures >(),::Reflect_obj::field(hx::ClassOf< ::TestNativeGestures >(),HX_CSTRING("main")),Dynamic( Array_obj<Dynamic>::__new()));
				}
				else{
					HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",63)
					::neash::Lib_obj::nmeGetCurrent()->addChild(hx::TCast< neash::display::DisplayObject >::cast(::Type_obj::createInstance(hx::ClassOf< ::TestNativeGestures >(),Dynamic( Array_obj<Dynamic>::__new()))));
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",39)
		::neash::Lib_obj::create( Dynamic(new _Function_1_1()),(int)1024,(int)768,(int)60,(int)16777215,(int((int((int((int((int((int(::neash::Lib_obj::HARDWARE) | int(::neash::Lib_obj::RESIZABLE))) | int((int)0))) | int((int)0))) | int((int)0))) | int((int)0))) | int((int)0)),HX_CSTRING("HyperTest(s)"),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ApplicationMain_obj,main,(void))

Dynamic ApplicationMain_obj::getAsset( ::String inName){
	HX_SOURCE_PUSH("ApplicationMain_obj::getAsset")
	HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",89)
	if (((inName == HX_CSTRING("assets/logo.png")))){
		HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",90)
		return ::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/logo.png"),null());
	}
	HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",96)
	if (((inName == HX_CSTRING("assets/nme.svg")))){
		HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",97)
		return ::nme::installer::Assets_obj::getBytes(HX_CSTRING("assets/nme.svg"));
	}
	HX_SOURCE_POS("Export/android/haxe/ApplicationMain.hx",103)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ApplicationMain_obj,getAsset,return )


ApplicationMain_obj::ApplicationMain_obj()
{
}

void ApplicationMain_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ApplicationMain);
	HX_MARK_END_CLASS();
}

Dynamic ApplicationMain_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAsset") ) { return getAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ApplicationMain_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ApplicationMain_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	HX_CSTRING("getAsset"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ApplicationMain_obj::__mClass;

void ApplicationMain_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("ApplicationMain"), hx::TCanCast< ApplicationMain_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ApplicationMain_obj::__boot()
{
}

