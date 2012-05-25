#include <hxcpp.h>

#ifndef INCLUDED_ApplicationMain
#include <ApplicationMain.h>
#endif
#ifndef INCLUDED_TestFacebook
#include <TestFacebook.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
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
		HX_SOURCE_POS("ApplicationMain.hx",6)
		::nme::Lib_obj::setPackage(HX_CSTRING("Hyperfiction"),HX_CSTRING("hypertest"),HX_CSTRING("fr.hyperfiction.Tests"),HX_CSTRING("1.0.0"));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		bool run(int orientation){
{
				HX_SOURCE_POS("ApplicationMain.hx",12)
				if (((bool((orientation == ::nme::display::Stage_obj::OrientationLandscapeLeft)) || bool((orientation == ::nme::display::Stage_obj::OrientationLandscapeRight))))){
					HX_SOURCE_POS("ApplicationMain.hx",13)
					return true;
				}
				HX_SOURCE_POS("ApplicationMain.hx",16)
				return false;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_SOURCE_POS("ApplicationMain.hx",9)
		::nme::display::Stage_obj::shouldRotateInterface =  Dynamic(new _Function_1_1());

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
		Void run(){
{
				HX_SOURCE_POS("ApplicationMain.hx",22)
				{
				}
				HX_SOURCE_POS("ApplicationMain.hx",28)
				::TestFacebook_obj::main();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("ApplicationMain.hx",20)
		::nme::Lib_obj::create( Dynamic(new _Function_1_2()),(int)1024,(int)768,(int)60,(int)16777215,(int((int((int(::nme::Lib_obj::HARDWARE) | int(::nme::Lib_obj::RESIZABLE))) | int((int)0))) | int((int)0)),HX_CSTRING("HyperTest(s)"),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ApplicationMain_obj,main,(void))

Dynamic ApplicationMain_obj::getAsset( ::String inName){
	HX_SOURCE_PUSH("ApplicationMain_obj::getAsset")
	HX_SOURCE_POS("ApplicationMain.hx",46)
	if (((inName == HX_CSTRING("assets/logo.png")))){
		HX_SOURCE_POS("ApplicationMain.hx",47)
		return ::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/logo.png"),null());
	}
	HX_SOURCE_POS("ApplicationMain.hx",53)
	if (((inName == HX_CSTRING("assets/nme.svg")))){
		HX_SOURCE_POS("ApplicationMain.hx",54)
		return ::nme::installer::Assets_obj::getBytes(HX_CSTRING("assets/nme.svg"));
	}
	HX_SOURCE_POS("ApplicationMain.hx",60)
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

