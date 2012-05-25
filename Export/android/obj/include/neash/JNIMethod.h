#ifndef INCLUDED_neash_JNIMethod
#define INCLUDED_neash_JNIMethod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(neash,JNIMethod)
namespace neash{


class JNIMethod_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JNIMethod_obj OBJ_;
		JNIMethod_obj();
		Void __construct(Dynamic method);

	public:
		static hx::ObjectPtr< JNIMethod_obj > __new(Dynamic method);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JNIMethod_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JNIMethod"); }

		Dynamic method; /* REM */ 
		virtual Dynamic callMember( Dynamic args);
		Dynamic callMember_dyn();

		virtual Dynamic callStatic( Dynamic args);
		Dynamic callStatic_dyn();

		virtual Dynamic getMemberMethod( bool useArray);
		Dynamic getMemberMethod_dyn();

		virtual Dynamic getStaticMethod( bool useArray);
		Dynamic getStaticMethod_dyn();

		static Dynamic nme_jni_call_member; /* REM */ 
		static Dynamic &nme_jni_call_member_dyn() { return nme_jni_call_member;}
		static Dynamic nme_jni_call_static; /* REM */ 
		static Dynamic &nme_jni_call_static_dyn() { return nme_jni_call_static;}
};

} // end namespace neash

#endif /* INCLUDED_neash_JNIMethod */ 
