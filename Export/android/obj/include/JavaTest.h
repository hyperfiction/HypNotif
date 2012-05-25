#ifndef INCLUDED_JavaTest
#define INCLUDED_JavaTest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(JavaTest)


class JavaTest_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JavaTest_obj OBJ_;
		JavaTest_obj();
		Void __construct(Dynamic handle);

	public:
		static hx::ObjectPtr< JavaTest_obj > __new(Dynamic handle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JavaTest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JavaTest"); }

		Dynamic __jobject; /* REM */ 
		virtual Void callMe( double arg0);
		Dynamic callMe_dyn();

		static Dynamic _create_func; /* REM */ 
		static ::JavaTest create( Dynamic arg0);
		static Dynamic create_dyn();

		static Dynamic _callMe_func; /* REM */ 
};


#endif /* INCLUDED_JavaTest */ 
