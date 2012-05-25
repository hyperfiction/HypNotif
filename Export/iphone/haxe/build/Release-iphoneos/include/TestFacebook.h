#ifndef INCLUDED_TestFacebook
#define INCLUDED_TestFacebook

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS0(TestFacebook)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)


class TestFacebook_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef TestFacebook_obj OBJ_;
		TestFacebook_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestFacebook_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestFacebook_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TestFacebook"); }

		virtual Void _run( );
		Dynamic _run_dyn();

		virtual Void _on_fb_connected( ::String sToken);
		Dynamic _on_fb_connected_dyn();

		static Dynamic hyp_fb_connect; /* REM */ 
		static Dynamic hyp_fb_init; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_TestFacebook */ 
