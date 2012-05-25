#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_JNI
#include <neash/JNI.h>
#endif
#ifndef INCLUDED_neash_JNIMethod
#include <neash/JNIMethod.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
namespace neash{

Void JNI_obj::__construct()
{
	return null();
}

JNI_obj::~JNI_obj() { }

Dynamic JNI_obj::__CreateEmpty() { return  new JNI_obj; }
hx::ObjectPtr< JNI_obj > JNI_obj::__new()
{  hx::ObjectPtr< JNI_obj > result = new JNI_obj();
	result->__construct();
	return result;}

Dynamic JNI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JNI_obj > result = new JNI_obj();
	result->__construct();
	return result;}

bool JNI_obj::isInit;

Void JNI_obj::init( ){
{
		HX_SOURCE_PUSH("JNI_obj::init")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",16)
		if ((!(::neash::JNI_obj::isInit))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",19)
			::neash::JNI_obj::isInit = true;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",20)
			Dynamic func = ::neash::Loader_obj::load(HX_CSTRING("nme_jni_init_callback"),(int)1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",21)
			func(::neash::JNI_obj::onCallback_dyn());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(JNI_obj,init,(void))

Dynamic JNI_obj::onCallback( Dynamic inObj,Dynamic inFunc,Dynamic inArgs){
	HX_SOURCE_PUSH("JNI_obj::onCallback")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",27)
	Dynamic field = ::Reflect_obj::field(inObj,inFunc);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",28)
	if (((field != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",29)
		return ::Reflect_obj::callMethod(inObj,field,inArgs);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",30)
	::haxe::Log_obj::trace((HX_CSTRING("onCallback - unknown field ") + inFunc),hx::SourceInfo(HX_CSTRING("JNI.hx"),30,HX_CSTRING("neash.JNI"),HX_CSTRING("onCallback")));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",31)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JNI_obj,onCallback,return )

Dynamic JNI_obj::createMemberMethod( ::String className,::String memberName,::String signature,hx::Null< bool >  __o_useArray){
bool useArray = __o_useArray.Default(false);
	HX_SOURCE_PUSH("JNI_obj::createMemberMethod");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",44)
		::neash::JNI_obj::init();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",45)
		::neash::JNIMethod method = ::neash::JNIMethod_obj::__new(::neash::JNI_obj::nme_jni_create_method(className,memberName,signature,false));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",46)
		return method->getMemberMethod(useArray);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(JNI_obj,createMemberMethod,return )

Dynamic JNI_obj::createStaticMethod( ::String className,::String memberName,::String signature,hx::Null< bool >  __o_useArray){
bool useArray = __o_useArray.Default(false);
	HX_SOURCE_PUSH("JNI_obj::createStaticMethod");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",60)
		::neash::JNI_obj::init();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",61)
		::neash::JNIMethod method = ::neash::JNIMethod_obj::__new(::neash::JNI_obj::nme_jni_create_method(className,memberName,signature,true));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/JNI.hx",62)
		return method->getStaticMethod(useArray);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(JNI_obj,createStaticMethod,return )

Dynamic JNI_obj::nme_jni_create_method;


JNI_obj::JNI_obj()
{
}

void JNI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JNI);
	HX_MARK_END_CLASS();
}

Dynamic JNI_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isInit") ) { return isInit; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onCallback") ) { return onCallback_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createMemberMethod") ) { return createMemberMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"createStaticMethod") ) { return createStaticMethod_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_jni_create_method") ) { return nme_jni_create_method; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JNI_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"isInit") ) { isInit=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_jni_create_method") ) { nme_jni_create_method=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JNI_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isInit"),
	HX_CSTRING("init"),
	HX_CSTRING("onCallback"),
	HX_CSTRING("createMemberMethod"),
	HX_CSTRING("createStaticMethod"),
	HX_CSTRING("nme_jni_create_method"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JNI_obj::isInit,"isInit");
	HX_MARK_MEMBER_NAME(JNI_obj::nme_jni_create_method,"nme_jni_create_method");
};

Class JNI_obj::__mClass;

void JNI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.JNI"), hx::TCanCast< JNI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void JNI_obj::__boot()
{
	hx::Static(isInit) = false;
	hx::Static(nme_jni_create_method) = ::neash::Loader_obj::load(HX_CSTRING("nme_jni_create_method"),(int)4);
}

} // end namespace neash
