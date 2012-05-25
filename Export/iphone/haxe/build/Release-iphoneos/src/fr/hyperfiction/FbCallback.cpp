#include <hxcpp.h>

#ifndef INCLUDED_fr_hyperfiction_FbCallback
#include <fr/hyperfiction/FbCallback.h>
#endif
namespace fr{
namespace hyperfiction{

::fr::hyperfiction::FbCallback FbCallback_obj::ON_LOGIN;

HX_DEFINE_CREATE_ENUM(FbCallback_obj)

int FbCallback_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ON_LOGIN")) return 0;
	return super::__FindIndex(inName);
}

int FbCallback_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ON_LOGIN")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FbCallback_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ON_LOGIN")) return ON_LOGIN;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ON_LOGIN"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FbCallback_obj::ON_LOGIN,"ON_LOGIN");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FbCallback_obj::__mClass;

Dynamic __Create_FbCallback_obj() { return new FbCallback_obj; }

void FbCallback_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("fr.hyperfiction.FbCallback"), hx::TCanCast< FbCallback_obj >,sStaticFields,sMemberFields,
	&__Create_FbCallback_obj, &__Create,
	&super::__SGetClass(), &CreateFbCallback_obj, sMarkStatics);
}

void FbCallback_obj::__boot()
{
Static(ON_LOGIN) = hx::CreateEnum< FbCallback_obj >(HX_CSTRING("ON_LOGIN"),0);
}


} // end namespace fr
} // end namespace hyperfiction
