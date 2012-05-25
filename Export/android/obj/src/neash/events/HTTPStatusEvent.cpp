#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_HTTPStatusEvent
#include <neash/events/HTTPStatusEvent.h>
#endif
namespace neash{
namespace events{

Void HTTPStatusEvent_obj::__construct(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int status = __o_status.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/HTTPStatusEvent.hx",13)
	super::__construct(inType,bubbles,cancelable);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/HTTPStatusEvent.hx",14)
	this->status = status;
}
;
	return null();
}

HTTPStatusEvent_obj::~HTTPStatusEvent_obj() { }

Dynamic HTTPStatusEvent_obj::__CreateEmpty() { return  new HTTPStatusEvent_obj; }
hx::ObjectPtr< HTTPStatusEvent_obj > HTTPStatusEvent_obj::__new(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status)
{  hx::ObjectPtr< HTTPStatusEvent_obj > result = new HTTPStatusEvent_obj();
	result->__construct(inType,__o_bubbles,__o_cancelable,__o_status);
	return result;}

Dynamic HTTPStatusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPStatusEvent_obj > result = new HTTPStatusEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::neash::events::Event HTTPStatusEvent_obj::clone( ){
	HX_SOURCE_PUSH("HTTPStatusEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/HTTPStatusEvent.hx",19)
	return ::neash::events::HTTPStatusEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->status);
}


::String HTTPStatusEvent_obj::toString( ){
	HX_SOURCE_PUSH("HTTPStatusEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/HTTPStatusEvent.hx",25)
	return ((((((((HX_CSTRING("[HTTPStatusEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" status=")) + this->status) + HX_CSTRING("]"));
}


::String HTTPStatusEvent_obj::HTTP_STATUS;


HTTPStatusEvent_obj::HTTPStatusEvent_obj()
{
}

void HTTPStatusEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPStatusEvent);
	HX_MARK_MEMBER_NAME(status,"status");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTTPStatusEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HTTP_STATUS") ) { return HTTP_STATUS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPStatusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HTTP_STATUS") ) { HTTP_STATUS=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPStatusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("status"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTTP_STATUS"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("status"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPStatusEvent_obj::HTTP_STATUS,"HTTP_STATUS");
};

Class HTTPStatusEvent_obj::__mClass;

void HTTPStatusEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.events.HTTPStatusEvent"), hx::TCanCast< HTTPStatusEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTTPStatusEvent_obj::__boot()
{
	hx::Static(HTTP_STATUS) = HX_CSTRING("httpStatus");
}

} // end namespace neash
} // end namespace events
