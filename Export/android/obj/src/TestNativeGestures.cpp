#include <hxcpp.h>

#ifndef INCLUDED_TestCB
#include <TestCB.h>
#endif
#ifndef INCLUDED_TestNativeGestures
#include <TestNativeGestures.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_JNI
#include <neash/JNI.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
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
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#include <org/shoebox/utils/system/Signal1.h>
#endif

Void TestNativeGestures_obj::__construct()
{
{
	HX_SOURCE_POS("src/TestNativeGestures.hx",26)
	super::__construct();
	HX_SOURCE_POS("src/TestNativeGestures.hx",27)
	::neash::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::neash::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_SOURCE_POS("src/TestNativeGestures.hx",28)
	::neash::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetAlign(::neash::display::StageAlign_obj::TOP_LEFT_dyn());
	HX_SOURCE_POS("src/TestNativeGestures.hx",29)
	this->_run();
}
;
	return null();
}

TestNativeGestures_obj::~TestNativeGestures_obj() { }

Dynamic TestNativeGestures_obj::__CreateEmpty() { return  new TestNativeGestures_obj; }
hx::ObjectPtr< TestNativeGestures_obj > TestNativeGestures_obj::__new()
{  hx::ObjectPtr< TestNativeGestures_obj > result = new TestNativeGestures_obj();
	result->__construct();
	return result;}

Dynamic TestNativeGestures_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestNativeGestures_obj > result = new TestNativeGestures_obj();
	result->__construct();
	return result;}

Void TestNativeGestures_obj::onCallback( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::onCallback")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestNativeGestures_obj,onCallback,(void))

Void TestNativeGestures_obj::_run( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::_run")
		HX_SOURCE_POS("src/TestNativeGestures.hx",54)
		::haxe::Log_obj::trace(HX_CSTRING("run"),hx::SourceInfo(HX_CSTRING("TestNativeGestures.hx"),54,HX_CSTRING("TestNativeGestures"),HX_CSTRING("_run")));
		HX_SOURCE_POS("src/TestNativeGestures.hx",55)
		::neash::display::BitmapData bmp = ::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/logo.png"),null());
		HX_SOURCE_POS("src/TestNativeGestures.hx",56)
		this->addChild(::neash::display::Bitmap_obj::__new(bmp,null(),null()));
		HX_SOURCE_POS("src/TestNativeGestures.hx",63)
		Array< ::TestCB > cb = Array_obj< ::TestCB >::__new().Add(::TestCB_obj::__new());
		HX_SOURCE_POS("src/TestNativeGestures.hx",64)
		cb->__get((int)0)->onCallBack->connect(this->_onConnect_dyn(),null(),null());
		HX_SOURCE_POS("src/TestNativeGestures.hx",66)
		Dynamic launch2 = Dynamic( Array_obj<Dynamic>::__new().Add(::neash::JNI_obj::createStaticMethod(HX_CSTRING("fb.FacebookConnector"),HX_CSTRING("nmeCreate"),HX_CSTRING("(Lorg/haxe/nme/HaxeObject;)I"),null())));

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,launch2,Array< ::TestCB >,cb)
		Void run(){
{
				HX_SOURCE_POS("src/TestNativeGestures.hx",67)
				launch2->__GetItem((int)0)(cb->__get((int)0));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("src/TestNativeGestures.hx",67)
		::neash::Lib_obj::postUICallback( Dynamic(new _Function_1_1(launch2,cb)));
		HX_SOURCE_POS("src/TestNativeGestures.hx",78)
		::neash::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::MouseEvent_obj::CLICK,this->_onClick_dyn(),false,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestNativeGestures_obj,_run,(void))

Void TestNativeGestures_obj::_test( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::_test")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestNativeGestures_obj,_test,(void))

Void TestNativeGestures_obj::_onConnect( ::String sToken){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::_onConnect")
		HX_SOURCE_POS("src/TestNativeGestures.hx",96)
		::haxe::Log_obj::trace((HX_CSTRING("onConnect ::: ") + sToken),hx::SourceInfo(HX_CSTRING("TestNativeGestures.hx"),97,HX_CSTRING("TestNativeGestures"),HX_CSTRING("_onConnect")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestNativeGestures_obj,_onConnect,(void))

Void TestNativeGestures_obj::_onClick( Dynamic _){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::_onClick")
		HX_SOURCE_POS("src/TestNativeGestures.hx",106)
		::haxe::Log_obj::trace(HX_CSTRING("onClick"),hx::SourceInfo(HX_CSTRING("TestNativeGestures.hx"),107,HX_CSTRING("TestNativeGestures"),HX_CSTRING("_onClick")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestNativeGestures_obj,_onClick,(void))

Void TestNativeGestures_obj::main( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::main")
		HX_SOURCE_POS("src/TestNativeGestures.hx",112)
		::neash::Lib_obj::nmeGetCurrent()->addChild(::TestNativeGestures_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(TestNativeGestures_obj,main,(void))


TestNativeGestures_obj::TestNativeGestures_obj()
{
}

void TestNativeGestures_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TestNativeGestures);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TestNativeGestures_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"_run") ) { return _run_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_test") ) { return _test_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onClick") ) { return _onClick_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onCallback") ) { return onCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"_onConnect") ) { return _onConnect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TestNativeGestures_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TestNativeGestures_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onCallback"),
	HX_CSTRING("_run"),
	HX_CSTRING("_test"),
	HX_CSTRING("_onConnect"),
	HX_CSTRING("_onClick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TestNativeGestures_obj::__mClass;

void TestNativeGestures_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("TestNativeGestures"), hx::TCanCast< TestNativeGestures_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestNativeGestures_obj::__boot()
{
}

