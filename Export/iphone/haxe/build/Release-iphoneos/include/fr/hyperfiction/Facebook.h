#ifndef INCLUDED_fr_hyperfiction_Facebook
#define INCLUDED_fr_hyperfiction_Facebook

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(fr,hyperfiction,Facebook)
HX_DECLARE_CLASS4(org,shoebox,utils,system,ASignal)
HX_DECLARE_CLASS4(org,shoebox,utils,system,Signal1)
namespace fr{
namespace hyperfiction{


class Facebook_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Facebook_obj OBJ_;
		Facebook_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Facebook_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Facebook_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Facebook"); }

		::String session_token; /* REM */ 
		::String app_id; /* REM */ 
		::org::shoebox::utils::system::Signal1 onConnect; /* REM */ 
		::String _sAppID; /* REM */ 
		bool _bConnected; /* REM */ 
		::String _sFb_session_token; /* REM */ 
		virtual Void init( ::String app_id);
		Dynamic init_dyn();

		virtual Void connect( );
		Dynamic connect_dyn();

		virtual Void appRequest( ::String sTitle,Dynamic sMessage,::String toUser);
		Dynamic appRequest_dyn();

		virtual Void feed( ::String sTitle,::String sCaption,::String sDescription,::String sLink,::String sPictureUrl);
		Dynamic feed_dyn();

		virtual Void _init( ::String sAppId);
		Dynamic _init_dyn();

		virtual Void _connect( );
		Dynamic _connect_dyn();

		virtual Void _onCallback( ::String sType,::String arg);
		Dynamic _onCallback_dyn();

		static Dynamic hyp_fb_init; /* REM */ 
		static Dynamic &hyp_fb_init_dyn() { return hyp_fb_init;}
		static Dynamic hypfb_connect; /* REM */ 
		static Dynamic &hypfb_connect_dyn() { return hypfb_connect;}
		static Dynamic hypfb_set_callback; /* REM */ 
		static Dynamic &hypfb_set_callback_dyn() { return hypfb_set_callback;}
		static Dynamic hyp_fb_apprequest; /* REM */ 
		static Dynamic &hyp_fb_apprequest_dyn() { return hyp_fb_apprequest;}
		static Dynamic hyp_fb_apprequest_to_user; /* REM */ 
		static Dynamic &hyp_fb_apprequest_to_user_dyn() { return hyp_fb_apprequest_to_user;}
		static Dynamic hyp_fb_feed; /* REM */ 
		static Dynamic &hyp_fb_feed_dyn() { return hyp_fb_feed;}
		static ::fr::hyperfiction::Facebook getInstance( );
		static Dynamic getInstance_dyn();

		static ::fr::hyperfiction::Facebook __instance; /* REM */ 
};

} // end namespace fr
} // end namespace hyperfiction

#endif /* INCLUDED_fr_hyperfiction_Facebook */ 
