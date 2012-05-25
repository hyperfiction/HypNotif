#ifndef INCLUDED_neash_errors_Error
#define INCLUDED_neash_errors_Error

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,errors,Error)
namespace neash{
namespace errors{


class Error_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Error_obj OBJ_;
		Error_obj();
		Void __construct(Dynamic inMessage,Dynamic __o_id);

	public:
		static hx::ObjectPtr< Error_obj > __new(Dynamic inMessage,Dynamic __o_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Error_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Error"); }

		int errorID; /* REM */ 
		Dynamic message; /* REM */ 
		Dynamic name; /* REM */ 
		virtual ::String getStackTrace( );
		Dynamic getStackTrace_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace neash
} // end namespace errors

#endif /* INCLUDED_neash_errors_Error */ 
