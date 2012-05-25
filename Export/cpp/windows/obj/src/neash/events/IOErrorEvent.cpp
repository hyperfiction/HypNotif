#include <hxcpp.h>

#ifndef INCLUDED_neash_events_ErrorEvent
#include <neash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_IOErrorEvent
#include <neash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_TextEvent
#include <neash/events/TextEvent.h>
#endif
namespace neash{
namespace events{

Void IOErrorEvent_obj::__construct(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< ::String >  __o_text,hx::Null< int >  __o_id)
{
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
::String text = __o_text.Default(HX_CSTRING(""));
int id = __o_id.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/IOErrorEvent.hx",11)
	super::__construct(inType,bubbles,cancelable,text,id);
}
;
	return null();
}

IOErrorEvent_obj::~IOErrorEvent_obj() { }

Dynamic IOErrorEvent_obj::__CreateEmpty() { return  new IOErrorEvent_obj; }
hx::ObjectPtr< IOErrorEvent_obj > IOErrorEvent_obj::__new(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< ::String >  __o_text,hx::Null< int >  __o_id)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(inType,__o_bubbles,__o_cancelable,__o_text,__o_id);
	return result;}

Dynamic IOErrorEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

::neash::events::Event IOErrorEvent_obj::clone( ){
	HX_SOURCE_PUSH("IOErrorEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/IOErrorEvent.hx",17)
	return ::neash::events::IOErrorEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->text,this->errorID);
}


::String IOErrorEvent_obj::toString( ){
	HX_SOURCE_PUSH("IOErrorEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/events/IOErrorEvent.hx",23)
	return ((((((((((HX_CSTRING("[IOErrorEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" text=")) + this->text) + HX_CSTRING(" errorID=")) + this->errorID) + HX_CSTRING("]"));
}


::String IOErrorEvent_obj::IO_ERROR;


IOErrorEvent_obj::IOErrorEvent_obj()
{
}

void IOErrorEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IOErrorEvent);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic IOErrorEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"IO_ERROR") ) { return IO_ERROR; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IOErrorEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"IO_ERROR") ) { IO_ERROR=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IOErrorEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("IO_ERROR"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IOErrorEvent_obj::IO_ERROR,"IO_ERROR");
};

Class IOErrorEvent_obj::__mClass;

void IOErrorEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.events.IOErrorEvent"), hx::TCanCast< IOErrorEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IOErrorEvent_obj::__boot()
{
	hx::Static(IO_ERROR) = HX_CSTRING("ioError");
}

} // end namespace neash
} // end namespace events
