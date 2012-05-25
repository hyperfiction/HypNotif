#include <hxcpp.h>

#ifndef INCLUDED_JavaTest
#include <JavaTest.h>
#endif
#ifndef INCLUDED_neash_JNI
#include <neash/JNI.h>
#endif

Void JavaTest_obj::__construct(Dynamic handle)
{
{
	HX_SOURCE_POS("src/JavaTest.hx",16)
	this->__jobject = handle;
}
;
	return null();
}

JavaTest_obj::~JavaTest_obj() { }

Dynamic JavaTest_obj::__CreateEmpty() { return  new JavaTest_obj; }
hx::ObjectPtr< JavaTest_obj > JavaTest_obj::__new(Dynamic handle)
{  hx::ObjectPtr< JavaTest_obj > result = new JavaTest_obj();
	result->__construct(handle);
	return result;}

Dynamic JavaTest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JavaTest_obj > result = new JavaTest_obj();
	result->__construct(inArgs[0]);
	return result;}

Void JavaTest_obj::callMe( double arg0){
{
		HX_SOURCE_PUSH("JavaTest_obj::callMe")
		HX_SOURCE_POS("src/JavaTest.hx",37)
		if (((::JavaTest_obj::_callMe_func == null()))){
			HX_SOURCE_POS("src/JavaTest.hx",38)
			::JavaTest_obj::_callMe_func = ::neash::JNI_obj::createMemberMethod(HX_CSTRING("JavaTest"),HX_CSTRING("callMe"),HX_CSTRING("(D)V"),true);
		}
		HX_SOURCE_POS("src/JavaTest.hx",39)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("src/JavaTest.hx",40)
		a->__Field(HX_CSTRING("push"),true)(this->__jobject);
		HX_SOURCE_POS("src/JavaTest.hx",41)
		a->__Field(HX_CSTRING("push"),true)(arg0);
		HX_SOURCE_POS("src/JavaTest.hx",42)
		::JavaTest_obj::_callMe_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(JavaTest_obj,callMe,(void))

Dynamic JavaTest_obj::_create_func;

::JavaTest JavaTest_obj::create( Dynamic arg0){
	HX_SOURCE_PUSH("JavaTest_obj::create")
	HX_SOURCE_POS("src/JavaTest.hx",25)
	if (((::JavaTest_obj::_create_func == null()))){
		HX_SOURCE_POS("src/JavaTest.hx",26)
		::JavaTest_obj::_create_func = ::neash::JNI_obj::createStaticMethod(HX_CSTRING("JavaTest"),HX_CSTRING("create"),HX_CSTRING("(Lorg/haxe/nme/HaxeObject;)LJavaTest;"),true);
	}
	HX_SOURCE_POS("src/JavaTest.hx",27)
	Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("src/JavaTest.hx",28)
	a->__Field(HX_CSTRING("push"),true)(arg0);
	HX_SOURCE_POS("src/JavaTest.hx",29)
	return ::JavaTest_obj::__new(::JavaTest_obj::_create_func(a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(JavaTest_obj,create,return )

Dynamic JavaTest_obj::_callMe_func;


JavaTest_obj::JavaTest_obj()
{
}

void JavaTest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JavaTest);
	HX_MARK_MEMBER_NAME(__jobject,"__jobject");
	HX_MARK_END_CLASS();
}

Dynamic JavaTest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"callMe") ) { return callMe_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__jobject") ) { return __jobject; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_create_func") ) { return _create_func; }
		if (HX_FIELD_EQ(inName,"_callMe_func") ) { return _callMe_func; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JavaTest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"__jobject") ) { __jobject=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_create_func") ) { _create_func=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_callMe_func") ) { _callMe_func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JavaTest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__jobject"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_create_func"),
	HX_CSTRING("create"),
	HX_CSTRING("_callMe_func"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__jobject"),
	HX_CSTRING("callMe"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JavaTest_obj::_create_func,"_create_func");
	HX_MARK_MEMBER_NAME(JavaTest_obj::_callMe_func,"_callMe_func");
};

Class JavaTest_obj::__mClass;

void JavaTest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("JavaTest"), hx::TCanCast< JavaTest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void JavaTest_obj::__boot()
{
	hx::Static(_create_func);
	hx::Static(_callMe_func);
}

