#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_SampleDataEvent
#include <nme/events/SampleDataEvent.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace nme{
namespace events{

Void SampleDataEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,3,1/nme/events/SampleDataEvent.hx",18)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,3,1/nme/events/SampleDataEvent.hx",19)
	this->data = ::nme::utils::ByteArray_obj::__new(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,3,1/nme/events/SampleDataEvent.hx",20)
	this->position = 0.0;
}
;
	return null();
}

SampleDataEvent_obj::~SampleDataEvent_obj() { }

Dynamic SampleDataEvent_obj::__CreateEmpty() { return  new SampleDataEvent_obj; }
hx::ObjectPtr< SampleDataEvent_obj > SampleDataEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< SampleDataEvent_obj > result = new SampleDataEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic SampleDataEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SampleDataEvent_obj > result = new SampleDataEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::nme::events::Event SampleDataEvent_obj::clone( ){
	HX_SOURCE_PUSH("SampleDataEvent_obj::clone")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,3,1/nme/events/SampleDataEvent.hx",25)
	return ::nme::events::SampleDataEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable());
}


::String SampleDataEvent_obj::toString( ){
	HX_SOURCE_PUSH("SampleDataEvent_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,3,1/nme/events/SampleDataEvent.hx",31)
	return ((((((HX_CSTRING("[SampleDataEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING("]"));
}


::String SampleDataEvent_obj::SAMPLE_DATA;


SampleDataEvent_obj::SampleDataEvent_obj()
{
}

void SampleDataEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SampleDataEvent);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(position,"position");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic SampleDataEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SAMPLE_DATA") ) { return SAMPLE_DATA; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SampleDataEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::nme::utils::ByteArray >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SAMPLE_DATA") ) { SAMPLE_DATA=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SampleDataEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("position"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SAMPLE_DATA"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("position"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SampleDataEvent_obj::SAMPLE_DATA,"SAMPLE_DATA");
};

Class SampleDataEvent_obj::__mClass;

void SampleDataEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.SampleDataEvent"), hx::TCanCast< SampleDataEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SampleDataEvent_obj::__boot()
{
	hx::Static(SAMPLE_DATA) = HX_CSTRING("sampleData");
}

} // end namespace nme
} // end namespace events
