#include <hxcpp.h>

#ifndef INCLUDED_neash_JNI
#include <neash/JNI.h>
#endif
#ifndef INCLUDED_nme_Test
#include <nme/Test.h>
#endif
namespace nme{

Void Test_obj::__construct(Dynamic handle)
{
{
	HX_SOURCE_POS("src/nme/Test.hx",16)
	this->__jobject = handle;
}
;
	return null();
}

Test_obj::~Test_obj() { }

Dynamic Test_obj::__CreateEmpty() { return  new Test_obj; }
hx::ObjectPtr< Test_obj > Test_obj::__new(Dynamic handle)
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct(handle);
	return result;}

Dynamic Test_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Test_obj::callMe( double arg0){
{
		HX_SOURCE_PUSH("Test_obj::callMe")
		HX_SOURCE_POS("src/nme/Test.hx",37)
		if (((::nme::Test_obj::_callMe_func == null()))){
			HX_SOURCE_POS("src/nme/Test.hx",38)
			::nme::Test_obj::_callMe_func = ::neash::JNI_obj::createMemberMethod(HX_CSTRING("nme.Test"),HX_CSTRING("callMe"),HX_CSTRING("(D)V"),true);
		}
		HX_SOURCE_POS("src/nme/Test.hx",39)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("src/nme/Test.hx",40)
		a->__Field(HX_CSTRING("push"),true)(this->__jobject);
		HX_SOURCE_POS("src/nme/Test.hx",41)
		a->__Field(HX_CSTRING("push"),true)(arg0);
		HX_SOURCE_POS("src/nme/Test.hx",42)
		::nme::Test_obj::_callMe_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Test_obj,callMe,(void))

Dynamic Test_obj::_create_func;

::nme::Test Test_obj::create( Dynamic arg0){
	HX_SOURCE_PUSH("Test_obj::create")
	HX_SOURCE_POS("src/nme/Test.hx",25)
	if (((::nme::Test_obj::_create_func == null()))){
		HX_SOURCE_POS("src/nme/Test.hx",26)
		::nme::Test_obj::_create_func = ::neash::JNI_obj::createStaticMethod(HX_CSTRING("nme.Test"),HX_CSTRING("create"),HX_CSTRING("(Lorg/haxe/nme/HaxeObject;)Lnme/Test;"),true);
	}
	HX_SOURCE_POS("src/nme/Test.hx",27)
	Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("src/nme/Test.hx",28)
	a->__Field(HX_CSTRING("push"),true)(arg0);
	HX_SOURCE_POS("src/nme/Test.hx",29)
	return ::nme::Test_obj::__new(::nme::Test_obj::_create_func(a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Test_obj,create,return )

Dynamic Test_obj::_callMe_func;


Test_obj::Test_obj()
{
}

void Test_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Test);
	HX_MARK_MEMBER_NAME(__jobject,"__jobject");
	HX_MARK_END_CLASS();
}

Dynamic Test_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Test_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Test_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Test_obj::_create_func,"_create_func");
	HX_MARK_MEMBER_NAME(Test_obj::_callMe_func,"_callMe_func");
};

Class Test_obj::__mClass;

void Test_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Test"), hx::TCanCast< Test_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Test_obj::__boot()
{
	hx::Static(_create_func);
	hx::Static(_callMe_func);
}

} // end namespace nme
