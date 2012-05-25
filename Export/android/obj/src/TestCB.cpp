#include <hxcpp.h>

#ifndef INCLUDED_TestCB
#include <TestCB.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#include <org/shoebox/utils/system/Signal1.h>
#endif

Void TestCB_obj::__construct()
{
{
	HX_SOURCE_POS("src/TestNativeGestures.hx",134)
	this->onCallBack = ::org::shoebox::utils::system::Signal1_obj::__new();
}
;
	return null();
}

TestCB_obj::~TestCB_obj() { }

Dynamic TestCB_obj::__CreateEmpty() { return  new TestCB_obj; }
hx::ObjectPtr< TestCB_obj > TestCB_obj::__new()
{  hx::ObjectPtr< TestCB_obj > result = new TestCB_obj();
	result->__construct();
	return result;}

Dynamic TestCB_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestCB_obj > result = new TestCB_obj();
	result->__construct();
	return result;}

Void TestCB_obj::onToken( ::String sToken){
{
		HX_SOURCE_PUSH("TestCB_obj::onToken")
		HX_SOURCE_POS("src/TestNativeGestures.hx",147)
		::haxe::Log_obj::trace((HX_CSTRING("onCallBack ::: ") + sToken),hx::SourceInfo(HX_CSTRING("TestNativeGestures.hx"),147,HX_CSTRING("TestCB"),HX_CSTRING("onToken")));
		HX_SOURCE_POS("src/TestNativeGestures.hx",148)
		this->onCallBack->emit(sToken);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestCB_obj,onToken,(void))


TestCB_obj::TestCB_obj()
{
}

void TestCB_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TestCB);
	HX_MARK_MEMBER_NAME(onCallBack,"onCallBack");
	HX_MARK_END_CLASS();
}

Dynamic TestCB_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onToken") ) { return onToken_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onCallBack") ) { return onCallBack; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TestCB_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"onCallBack") ) { onCallBack=inValue.Cast< ::org::shoebox::utils::system::Signal1 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TestCB_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("onCallBack"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onCallBack"),
	HX_CSTRING("onToken"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TestCB_obj::__mClass;

void TestCB_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("TestCB"), hx::TCanCast< TestCB_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestCB_obj::__boot()
{
}

