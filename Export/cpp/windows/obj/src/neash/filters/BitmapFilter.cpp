#include <hxcpp.h>

#ifndef INCLUDED_neash_filters_BitmapFilter
#include <neash/filters/BitmapFilter.h>
#endif
namespace neash{
namespace filters{

Void BitmapFilter_obj::__construct(::String inType)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/filters/BitmapFilter.hx",11)
	this->type = inType;
}
;
	return null();
}

BitmapFilter_obj::~BitmapFilter_obj() { }

Dynamic BitmapFilter_obj::__CreateEmpty() { return  new BitmapFilter_obj; }
hx::ObjectPtr< BitmapFilter_obj > BitmapFilter_obj::__new(::String inType)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(inType);
	return result;}

Dynamic BitmapFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(inArgs[0]);
	return result;}

::neash::filters::BitmapFilter BitmapFilter_obj::clone( ){
	HX_SOURCE_PUSH("BitmapFilter_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/filters/BitmapFilter.hx",18)
	hx::Throw (HX_CSTRING("clone not implemented"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/filters/BitmapFilter.hx",19)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFilter_obj,clone,return )


BitmapFilter_obj::BitmapFilter_obj()
{
}

void BitmapFilter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapFilter);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_END_CLASS();
}

Dynamic BitmapFilter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapFilter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapFilter_obj::__mClass;

void BitmapFilter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.filters.BitmapFilter"), hx::TCanCast< BitmapFilter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapFilter_obj::__boot()
{
}

} // end namespace neash
} // end namespace filters
