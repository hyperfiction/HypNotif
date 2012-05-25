#ifndef INCLUDED_neash_JNI
#define INCLUDED_neash_JNI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(neash,JNI)
namespace neash{


class JNI_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JNI_obj OBJ_;
		JNI_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< JNI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JNI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JNI"); }

		static bool isInit; /* REM */ 
		static Void init( );
		static Dynamic init_dyn();

		static Dynamic onCallback( Dynamic inObj,Dynamic inFunc,Dynamic inArgs);
		static Dynamic onCallback_dyn();

		static Dynamic createMemberMethod( ::String className,::String memberName,::String signature,hx::Null< bool >  useArray);
		static Dynamic createMemberMethod_dyn();

		static Dynamic createStaticMethod( ::String className,::String memberName,::String signature,hx::Null< bool >  useArray);
		static Dynamic createStaticMethod_dyn();

		static Dynamic nme_jni_create_method; /* REM */ 
		static Dynamic &nme_jni_create_method_dyn() { return nme_jni_create_method;}
};

} // end namespace neash

#endif /* INCLUDED_neash_JNI */ 
