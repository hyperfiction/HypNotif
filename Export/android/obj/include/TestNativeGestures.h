#ifndef INCLUDED_TestNativeGestures
#define INCLUDED_TestNativeGestures

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS0(TestNativeGestures)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)


class TestNativeGestures_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
		typedef TestNativeGestures_obj OBJ_;
		TestNativeGestures_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestNativeGestures_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestNativeGestures_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TestNativeGestures"); }

		virtual Void onCallback( );
		Dynamic onCallback_dyn();

		virtual Void _run( );
		Dynamic _run_dyn();

		virtual Void _test( );
		Dynamic _test_dyn();

		virtual Void _onConnect( ::String sToken);
		Dynamic _onConnect_dyn();

		virtual Void _onClick( Dynamic _);
		Dynamic _onClick_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_TestNativeGestures */ 
