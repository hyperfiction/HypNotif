#ifndef INCLUDED_nme_events_JoystickEvent
#define INCLUDED_nme_events_JoystickEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,JoystickEvent)
namespace nme{
namespace events{


class JoystickEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef JoystickEvent_obj OBJ_;
		JoystickEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_device,hx::Null< int >  __o_id,hx::Null< double >  __o_x,hx::Null< double >  __o_y,hx::Null< double >  __o_z);

	public:
		static hx::ObjectPtr< JoystickEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_device,hx::Null< int >  __o_id,hx::Null< double >  __o_x,hx::Null< double >  __o_y,hx::Null< double >  __o_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JoystickEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JoystickEvent"); }

		int device; /* REM */ 
		int id; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		virtual ::nme::events::Event clone( );

		virtual ::String toString( );

		static ::String AXIS_MOVE; /* REM */ 
		static ::String BALL_MOVE; /* REM */ 
		static ::String BUTTON_DOWN; /* REM */ 
		static ::String BUTTON_UP; /* REM */ 
		static ::String HAT_MOVE; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_JoystickEvent */ 
