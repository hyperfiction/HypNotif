#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_ProgressEvent
#include <neash/events/ProgressEvent.h>
#endif
namespace neash{
namespace events{

Void ProgressEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_bytesLoaded,hx::Null< int >  __o_bytesTotal)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int bytesLoaded = __o_bytesLoaded.Default(0);
int bytesTotal = __o_bytesTotal.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/ProgressEvent.hx",16)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/ProgressEvent.hx",17)
	this->bytesLoaded = bytesLoaded;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/ProgressEvent.hx",18)
	this->bytesTotal = bytesTotal;
}
;
	return null();
}

ProgressEvent_obj::~ProgressEvent_obj() { }

Dynamic ProgressEvent_obj::__CreateEmpty() { return  new ProgressEvent_obj; }
hx::ObjectPtr< ProgressEvent_obj > ProgressEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_bytesLoaded,hx::Null< int >  __o_bytesTotal)
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_bytesLoaded,__o_bytesTotal);
	return result;}

Dynamic ProgressEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

::neash::events::Event ProgressEvent_obj::clone( ){
	HX_SOURCE_PUSH("ProgressEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/ProgressEvent.hx",23)
	return ::neash::events::ProgressEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->bytesLoaded,this->bytesTotal);
}


::String ProgressEvent_obj::toString( ){
	HX_SOURCE_PUSH("ProgressEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/ProgressEvent.hx",29)
	return ((((((((((HX_CSTRING("[ProgressEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" bytesLoaded=")) + this->bytesLoaded) + HX_CSTRING(" bytesTotal=")) + this->bytesTotal) + HX_CSTRING("]"));
}


::String ProgressEvent_obj::PROGRESS;

::String ProgressEvent_obj::SOCKET_DATA;


ProgressEvent_obj::ProgressEvent_obj()
{
}

void ProgressEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ProgressEvent);
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ProgressEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"PROGRESS") ) { return PROGRESS; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SOCKET_DATA") ) { return SOCKET_DATA; }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ProgressEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"PROGRESS") ) { PROGRESS=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SOCKET_DATA") ) { SOCKET_DATA=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ProgressEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROGRESS"),
	HX_CSTRING("SOCKET_DATA"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ProgressEvent_obj::PROGRESS,"PROGRESS");
	HX_MARK_MEMBER_NAME(ProgressEvent_obj::SOCKET_DATA,"SOCKET_DATA");
};

Class ProgressEvent_obj::__mClass;

void ProgressEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.events.ProgressEvent"), hx::TCanCast< ProgressEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ProgressEvent_obj::__boot()
{
	hx::Static(PROGRESS) = HX_CSTRING("progress");
	hx::Static(SOCKET_DATA) = HX_CSTRING("socketData");
}

} // end namespace neash
} // end namespace events
