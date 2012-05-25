#include <hxcpp.h>

#ifndef INCLUDED_neash_JNI
#include <neash/JNI.h>
#endif
#ifndef INCLUDED_nme_Test2
#include <nme/Test2.h>
#endif
namespace nme{

Void Test2_obj::__construct(Dynamic handle)
{
{
	HX_SOURCE_POS("src/nme/Test2.hx",16)
	this->__jobject = handle;
}
;
	return null();
}

Test2_obj::~Test2_obj() { }

Dynamic Test2_obj::__CreateEmpty() { return  new Test2_obj; }
hx::ObjectPtr< Test2_obj > Test2_obj::__new(Dynamic handle)
{  hx::ObjectPtr< Test2_obj > result = new Test2_obj();
	result->__construct(handle);
	return result;}

Dynamic Test2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Test2_obj > result = new Test2_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Test2_obj::callMe( double arg0){
{
		HX_SOURCE_PUSH("Test2_obj::callMe")
		HX_SOURCE_POS("src/nme/Test2.hx",37)
		if (((::nme::Test2_obj::_callMe_func == null()))){
			HX_SOURCE_POS("src/nme/Test2.hx",38)
			::nme::Test2_obj::_callMe_func = ::neash::JNI_obj::createMemberMethod(HX_CSTRING("nme.Test2"),HX_CSTRING("callMe"),HX_CSTRING("(D)V"),true);
		}
		HX_SOURCE_POS("src/nme/Test2.hx",39)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("src/nme/Test2.hx",40)
		a->__Field(HX_CSTRING("push"),true)(this->__jobject);
		HX_SOURCE_POS("src/nme/Test2.hx",41)
		a->__Field(HX_CSTRING("push"),true)(arg0);
		HX_SOURCE_POS("src/nme/Test2.hx",42)
		::nme::Test2_obj::_callMe_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Test2_obj,callMe,(void))

Dynamic Test2_obj::_create_func;

::nme::Test2 Test2_obj::create( Dynamic arg0){
	HX_SOURCE_PUSH("Test2_obj::create")
	HX_SOURCE_POS("src/nme/Test2.hx",25)
	if (((::nme::Test2_obj::_create_func == null()))){
		HX_SOURCE_POS("src/nme/Test2.hx",26)
		::nme::Test2_obj::_create_func = ::neash::JNI_obj::createStaticMethod(HX_CSTRING("nme.Test2"),HX_CSTRING("create"),HX_CSTRING("(Lorg/haxe/nme/HaxeObject;)Lnme/Test2;"),true);
	}
	HX_SOURCE_POS("src/nme/Test2.hx",27)
	Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("src/nme/Test2.hx",28)
	a->__Field(HX_CSTRING("push"),true)(arg0);
	HX_SOURCE_POS("src/nme/Test2.hx",29)
	return ::nme::Test2_obj::__new(::nme::Test2_obj::_create_func(a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Test2_obj,create,return )

Dynamic Test2_obj::_callMe_func;


Test2_obj::Test2_obj()
{
}

void Test2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Test2);
	HX_MARK_MEMBER_NAME(__jobject,"__jobject");
	HX_MARK_END_CLASS();
}

Dynamic Test2_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Test2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Test2_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Test2_obj::_create_func,"_create_func");
	HX_MARK_MEMBER_NAME(Test2_obj::_callMe_func,"_callMe_func");
};

Class Test2_obj::__mClass;

void Test2_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Test2"), hx::TCanCast< Test2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Test2_obj::__boot()
{
	hx::Static(_create_func);
	hx::Static(_callMe_func);
}

} // end namespace nme
