#include <hxcpp.h>

#ifndef INCLUDED_TestFacebook
#include <TestFacebook.h>
#endif
#ifndef INCLUDED_fr_hyperfiction_Facebook
#include <fr/hyperfiction/Facebook.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#include <org/shoebox/utils/system/Signal1.h>
#endif

Void TestFacebook_obj::__construct()
{
{
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",28)
	::haxe::Log_obj::trace(HX_CSTRING("constructor"),hx::SourceInfo(HX_CSTRING("TestFacebook.hx"),28,HX_CSTRING("TestFacebook"),HX_CSTRING("new")));
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",29)
	super::__construct();
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",30)
	this->_run();
}
;
	return null();
}

TestFacebook_obj::~TestFacebook_obj() { }

Dynamic TestFacebook_obj::__CreateEmpty() { return  new TestFacebook_obj; }
hx::ObjectPtr< TestFacebook_obj > TestFacebook_obj::__new()
{  hx::ObjectPtr< TestFacebook_obj > result = new TestFacebook_obj();
	result->__construct();
	return result;}

Dynamic TestFacebook_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestFacebook_obj > result = new TestFacebook_obj();
	result->__construct();
	return result;}

Void TestFacebook_obj::_run( ){
{
		HX_SOURCE_PUSH("TestFacebook_obj::_run")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",45)
		::fr::hyperfiction::Facebook fb = ::fr::hyperfiction::Facebook_obj::getInstance();
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",46)
		fb->init(HX_CSTRING("397904743584044"));
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",47)
		fb->onConnect->connect(this->_on_fb_connected_dyn(),null(),null());
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",48)
		fb->connect();
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",49)
		::haxe::Log_obj::trace(fb,hx::SourceInfo(HX_CSTRING("TestFacebook.hx"),49,HX_CSTRING("TestFacebook"),HX_CSTRING("_run")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestFacebook_obj,_run,(void))

Void TestFacebook_obj::_on_fb_connected( ::String sToken){
{
		HX_SOURCE_PUSH("TestFacebook_obj::_on_fb_connected")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",60)
		::haxe::Log_obj::trace((HX_CSTRING("_on_fb_connected ::: ") + sToken),hx::SourceInfo(HX_CSTRING("TestFacebook.hx"),60,HX_CSTRING("TestFacebook"),HX_CSTRING("_on_fb_connected")));
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",62)
		::fr::hyperfiction::Facebook_obj::getInstance()->feed(HX_CSTRING("Hello World title"),HX_CSTRING("hello world caption"),HX_CSTRING("description de test"),HX_CSTRING("http://www.hyperfiction.fr"),HX_CSTRING("http://hyperfiction.fr/LogoHyperfiction.png"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestFacebook_obj,_on_fb_connected,(void))

Dynamic TestFacebook_obj::hyp_fb_connect;

Dynamic TestFacebook_obj::hyp_fb_init;

Void TestFacebook_obj::main( ){
{
		HX_SOURCE_PUSH("TestFacebook_obj::main")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/src/TestFacebook.hx",67)
		::nme::Lib_obj::nmeGetCurrent()->addChild(::TestFacebook_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(TestFacebook_obj,main,(void))


TestFacebook_obj::TestFacebook_obj()
{
}

void TestFacebook_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TestFacebook);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TestFacebook_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"_run") ) { return _run_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hyp_fb_init") ) { return hyp_fb_init; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hyp_fb_connect") ) { return hyp_fb_connect; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_on_fb_connected") ) { return _on_fb_connected_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TestFacebook_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"hyp_fb_init") ) { hyp_fb_init=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hyp_fb_connect") ) { hyp_fb_connect=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TestFacebook_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("hyp_fb_connect"),
	HX_CSTRING("hyp_fb_init"),
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_run"),
	HX_CSTRING("_on_fb_connected"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TestFacebook_obj::hyp_fb_connect,"hyp_fb_connect");
	HX_MARK_MEMBER_NAME(TestFacebook_obj::hyp_fb_init,"hyp_fb_init");
};

Class TestFacebook_obj::__mClass;

void TestFacebook_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("TestFacebook"), hx::TCanCast< TestFacebook_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestFacebook_obj::__boot()
{
	hx::Static(hyp_fb_connect);
	hx::Static(hyp_fb_init);
}

