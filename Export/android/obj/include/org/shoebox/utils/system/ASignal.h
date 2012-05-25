#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#define INCLUDED_org_shoebox_utils_system_ASignal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(org,shoebox,collections,PriorityQueue)
HX_DECLARE_CLASS4(org,shoebox,utils,system,ASignal)
namespace org{
namespace shoebox{
namespace utils{
namespace system{


class ASignal_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ASignal_obj OBJ_;
		ASignal_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ASignal_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ASignal_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ASignal"); }

		bool enabled; /* REM */ 
		::org::shoebox::collections::PriorityQueue _oQueue; /* REM */ 
		virtual Void connect( Dynamic f,hx::Null< int >  prio,hx::Null< int >  count);
		Dynamic connect_dyn();

		virtual Void disconnect( Dynamic f,hx::Null< int >  prio);
		Dynamic disconnect_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual bool _exist( Dynamic f,hx::Null< int >  prio);
		Dynamic _exist_dyn();

		virtual Void _check( Dynamic l);
		Dynamic _check_dyn();

		virtual bool _setEnabled( bool b);
		Dynamic _setEnabled_dyn();

};

} // end namespace org
} // end namespace shoebox
} // end namespace utils
} // end namespace system

#endif /* INCLUDED_org_shoebox_utils_system_ASignal */ 
