#ifndef INCLUDED_neash_events_KeyboardEvent
#define INCLUDED_neash_events_KeyboardEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
namespace neash{
namespace events{


class KeyboardEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef KeyboardEvent_obj OBJ_;
		KeyboardEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_charCodeValue,hx::Null< int >  __o_keyCodeValue,hx::Null< int >  __o_keyLocationValue,hx::Null< bool >  __o_ctrlKeyValue,hx::Null< bool >  __o_altKeyValue,hx::Null< bool >  __o_shiftKeyValue,hx::Null< bool >  __o_controlKeyValue,hx::Null< bool >  __o_commandKeyValue);

	public:
		static hx::ObjectPtr< KeyboardEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_charCodeValue,hx::Null< int >  __o_keyCodeValue,hx::Null< int >  __o_keyLocationValue,hx::Null< bool >  __o_ctrlKeyValue,hx::Null< bool >  __o_altKeyValue,hx::Null< bool >  __o_shiftKeyValue,hx::Null< bool >  __o_controlKeyValue,hx::Null< bool >  __o_commandKeyValue);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("KeyboardEvent"); }

		bool altKey; /* REM */ 
		int charCode; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool controlKey; /* REM */ 
		bool commandKey; /* REM */ 
		int keyCode; /* REM */ 
		int keyLocation; /* REM */ 
		bool shiftKey; /* REM */ 
		virtual ::neash::events::Event clone( );

		virtual ::String toString( );

		static ::String KEY_DOWN; /* REM */ 
		static ::String KEY_UP; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_KeyboardEvent */ 
