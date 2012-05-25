#ifndef INCLUDED_TestCB
#define INCLUDED_TestCB

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(TestCB)
HX_DECLARE_CLASS4(org,shoebox,utils,system,ASignal)
HX_DECLARE_CLASS4(org,shoebox,utils,system,Signal1)


class TestCB_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestCB_obj OBJ_;
		TestCB_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestCB_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestCB_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TestCB"); }

		::org::shoebox::utils::system::Signal1 onCallBack; /* REM */ 
		virtual Void onToken( ::String sToken);
		Dynamic onToken_dyn();

};


#endif /* INCLUDED_TestCB */ 
