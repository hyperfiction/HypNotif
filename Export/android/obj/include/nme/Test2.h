#ifndef INCLUDED_nme_Test2
#define INCLUDED_nme_Test2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nme,Test2)
namespace nme{


class Test2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Test2_obj OBJ_;
		Test2_obj();
		Void __construct(Dynamic handle);

	public:
		static hx::ObjectPtr< Test2_obj > __new(Dynamic handle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Test2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Test2"); }

		Dynamic __jobject; /* REM */ 
		virtual Void callMe( double arg0);
		Dynamic callMe_dyn();

		static Dynamic _create_func; /* REM */ 
		static ::nme::Test2 create( Dynamic arg0);
		static Dynamic create_dyn();

		static Dynamic _callMe_func; /* REM */ 
};

} // end namespace nme

#endif /* INCLUDED_nme_Test2 */ 
