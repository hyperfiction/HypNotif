#ifndef INCLUDED_nme_events_ErrorEvent
#define INCLUDED_nme_events_ErrorEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/TextEvent.h>
HX_DECLARE_CLASS2(nme,events,ErrorEvent)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,TextEvent)
namespace nme{
namespace events{


class ErrorEvent_obj : public ::nme::events::TextEvent_obj{
	public:
		typedef ::nme::events::TextEvent_obj super;
		typedef ErrorEvent_obj OBJ_;
		ErrorEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< ::String >  __o_text,hx::Null< int >  __o_id);

	public:
		static hx::ObjectPtr< ErrorEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< ::String >  __o_text,hx::Null< int >  __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ErrorEvent"); }

		int errorID; /* REM */ 
		virtual ::nme::events::Event clone( );

		virtual ::String toString( );

};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_ErrorEvent */ 
