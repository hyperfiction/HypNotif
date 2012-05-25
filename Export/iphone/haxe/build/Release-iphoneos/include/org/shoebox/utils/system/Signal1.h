#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#define INCLUDED_org_shoebox_utils_system_Signal1

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <org/shoebox/utils/system/ASignal.h>
HX_DECLARE_CLASS4(org,shoebox,utils,system,ASignal)
HX_DECLARE_CLASS4(org,shoebox,utils,system,Signal1)
namespace org{
namespace shoebox{
namespace utils{
namespace system{


class Signal1_obj : public ::org::shoebox::utils::system::ASignal_obj{
	public:
		typedef ::org::shoebox::utils::system::ASignal_obj super;
		typedef Signal1_obj OBJ_;
		Signal1_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Signal1_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Signal1_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Signal1"); }

		virtual Void emit( Dynamic arg);
		Dynamic emit_dyn();

};

} // end namespace org
} // end namespace shoebox
} // end namespace utils
} // end namespace system

#endif /* INCLUDED_org_shoebox_utils_system_Signal1 */ 
