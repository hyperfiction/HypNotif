#include <hxcpp.h>

#ifndef INCLUDED_neash_errors_ArgumentError
#include <neash/errors/ArgumentError.h>
#endif
#ifndef INCLUDED_neash_errors_Error
#include <neash/errors/Error.h>
#endif
namespace neash{
namespace errors{

Void ArgumentError_obj::__construct(Dynamic inMessage,Dynamic id)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/errors/ArgumentError.hx",4)
	super::__construct(inMessage,id);
}
;
	return null();
}

ArgumentError_obj::~ArgumentError_obj() { }

Dynamic ArgumentError_obj::__CreateEmpty() { return  new ArgumentError_obj; }
hx::ObjectPtr< ArgumentError_obj > ArgumentError_obj::__new(Dynamic inMessage,Dynamic id)
{  hx::ObjectPtr< ArgumentError_obj > result = new ArgumentError_obj();
	result->__construct(inMessage,id);
	return result;}

Dynamic ArgumentError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArgumentError_obj > result = new ArgumentError_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


ArgumentError_obj::ArgumentError_obj()
{
}

void ArgumentError_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArgumentError);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ArgumentError_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic ArgumentError_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ArgumentError_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ArgumentError_obj::__mClass;

void ArgumentError_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.errors.ArgumentError"), hx::TCanCast< ArgumentError_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArgumentError_obj::__boot()
{
}

} // end namespace neash
} // end namespace errors
