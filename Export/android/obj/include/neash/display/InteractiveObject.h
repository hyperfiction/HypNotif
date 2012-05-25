#ifndef INCLUDED_neash_display_InteractiveObject
#define INCLUDED_neash_display_InteractiveObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/DisplayObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace neash{
namespace display{


class InteractiveObject_obj : public ::neash::display::DisplayObject_obj{
	public:
		typedef ::neash::display::DisplayObject_obj super;
		typedef InteractiveObject_obj OBJ_;
		InteractiveObject_obj();
		Void __construct(Dynamic inHandle,::String inType);

	public:
		static hx::ObjectPtr< InteractiveObject_obj > __new(Dynamic inHandle,::String inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InteractiveObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InteractiveObject"); }

		bool doubleClickEnabled; /* REM */ 
		bool mouseEnabled; /* REM */ 
		bool moveForSoftKeyboard; /* REM */ 
		bool needsSoftKeyboard; /* REM */ 
		bool nmeMouseEnabled; /* REM */ 
		virtual ::neash::display::InteractiveObject nmeAsInteractiveObject( );

		virtual bool requestSoftKeyboard( );
		Dynamic requestSoftKeyboard_dyn();

		virtual bool nmeGetMouseEnabled( );
		Dynamic nmeGetMouseEnabled_dyn();

		virtual bool nmeSetMouseEnabled( bool inVal);
		Dynamic nmeSetMouseEnabled_dyn();

		virtual bool nmeSetMoveForSoftKeyboard( bool inVal);
		Dynamic nmeSetMoveForSoftKeyboard_dyn();

		virtual bool nmeGetMoveForSoftKeyboard( );
		Dynamic nmeGetMoveForSoftKeyboard_dyn();

		virtual bool nmeSetNeedsSoftKeyboard( bool inVal);
		Dynamic nmeSetNeedsSoftKeyboard_dyn();

		virtual bool nmeGetNeedsSoftKeyboard( );
		Dynamic nmeGetNeedsSoftKeyboard_dyn();

		static Dynamic nme_display_object_set_mouse_enabled; /* REM */ 
		static Dynamic &nme_display_object_set_mouse_enabled_dyn() { return nme_display_object_set_mouse_enabled;}
		static Dynamic nme_display_object_set_needs_soft_keyboard; /* REM */ 
		static Dynamic &nme_display_object_set_needs_soft_keyboard_dyn() { return nme_display_object_set_needs_soft_keyboard;}
		static Dynamic nme_display_object_get_needs_soft_keyboard; /* REM */ 
		static Dynamic &nme_display_object_get_needs_soft_keyboard_dyn() { return nme_display_object_get_needs_soft_keyboard;}
		static Dynamic nme_display_object_set_moves_for_soft_keyboard; /* REM */ 
		static Dynamic &nme_display_object_set_moves_for_soft_keyboard_dyn() { return nme_display_object_set_moves_for_soft_keyboard;}
		static Dynamic nme_display_object_get_moves_for_soft_keyboard; /* REM */ 
		static Dynamic &nme_display_object_get_moves_for_soft_keyboard_dyn() { return nme_display_object_get_moves_for_soft_keyboard;}
		static Dynamic nme_display_object_request_soft_keyboard; /* REM */ 
		static Dynamic &nme_display_object_request_soft_keyboard_dyn() { return nme_display_object_request_soft_keyboard;}
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_InteractiveObject */ 
