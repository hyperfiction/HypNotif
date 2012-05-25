#ifndef INCLUDED_nme_events_SampleDataEvent
#define INCLUDED_nme_events_SampleDataEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,SampleDataEvent)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
namespace events{


class SampleDataEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef SampleDataEvent_obj OBJ_;
		SampleDataEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< SampleDataEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SampleDataEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SampleDataEvent"); }

		::nme::utils::ByteArray data; /* REM */ 
		double position; /* REM */ 
		virtual ::nme::events::Event clone( );

		virtual ::String toString( );

		static ::String SAMPLE_DATA; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_SampleDataEvent */ 
