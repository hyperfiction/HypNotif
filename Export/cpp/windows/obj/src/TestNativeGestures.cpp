#include <hxcpp.h>

#ifndef INCLUDED_TestNativeGestures
#include <TestNativeGestures.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
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
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif

Void TestNativeGestures_obj::__construct()
{
{
	HX_SOURCE_POS("src/TestNativeGestures.hx",24)
	super::__construct();
	HX_SOURCE_POS("src/TestNativeGestures.hx",25)
	::neash::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::neash::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_SOURCE_POS("src/TestNativeGestures.hx",26)
	::neash::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetAlign(::neash::display::StageAlign_obj::TOP_LEFT_dyn());
	HX_SOURCE_POS("src/TestNativeGestures.hx",27)
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

Void TestNativeGestures_obj::_run( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::_run")
		HX_SOURCE_POS("src/TestNativeGestures.hx",40)
		::haxe::Log_obj::trace(HX_CSTRING("run"),hx::SourceInfo(HX_CSTRING("TestNativeGestures.hx"),41,HX_CSTRING("TestNativeGestures"),HX_CSTRING("_run")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestNativeGestures_obj,_run,(void))

Void TestNativeGestures_obj::main( ){
{
		HX_SOURCE_PUSH("TestNativeGestures_obj::main")
		HX_SOURCE_POS("src/TestNativeGestures.hx",49)
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
	HX_CSTRING("_run"),
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

