#ifndef INCLUDED_neash_display_MovieClip
#define INCLUDED_neash_display_MovieClip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,MovieClip)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace neash{
namespace display{


class MovieClip_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
		typedef MovieClip_obj OBJ_;
		MovieClip_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MovieClip_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovieClip_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MovieClip"); }

		int currentFrame; /* REM */ 
		bool enabled; /* REM */ 
		int framesLoaded; /* REM */ 
		int totalFrames; /* REM */ 
		int mCurrentFrame; /* REM */ 
		int mTotalFrames; /* REM */ 
		virtual Void gotoAndPlay( Dynamic frame,::String scene);
		Dynamic gotoAndPlay_dyn();

		virtual Void gotoAndStop( Dynamic frame,::String scene);
		Dynamic gotoAndStop_dyn();

		virtual ::String nmeGetType( );

		virtual Void play( );
		Dynamic play_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual int nmeGetCurrentFrame( );
		Dynamic nmeGetCurrentFrame_dyn();

		virtual int nmeGetTotalFrames( );
		Dynamic nmeGetTotalFrames_dyn();

};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_MovieClip */ 
