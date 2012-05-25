#ifndef INCLUDED_nme_events_HTTPStatusEvent
#define INCLUDED_nme_events_HTTPStatusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,HTTPStatusEvent)
namespace nme{
namespace events{


class HTTPStatusEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef HTTPStatusEvent_obj OBJ_;
		HTTPStatusEvent_obj();
		Void __construct(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status);

	public:
		static hx::ObjectPtr< HTTPStatusEvent_obj > __new(::String inType,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_status);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTTPStatusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTTPStatusEvent"); }

		int status; /* REM */ 
		virtual ::nme::events::Event clone( );

		virtual ::String toString( );

		static ::String HTTP_STATUS; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_HTTPStatusEvent */ 
