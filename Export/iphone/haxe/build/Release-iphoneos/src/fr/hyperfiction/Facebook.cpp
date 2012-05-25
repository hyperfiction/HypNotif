#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_fr_hyperfiction_Facebook
#include <fr/hyperfiction/Facebook.h>
#endif
#ifndef INCLUDED_fr_hyperfiction_FbCallback
#include <fr/hyperfiction/FbCallback.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#include <org/shoebox/utils/system/Signal1.h>
#endif
namespace fr{
namespace hyperfiction{

Void Facebook_obj::__construct()
{
{
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",40)
	::haxe::Log_obj::trace(HX_CSTRING("constructor"),hx::SourceInfo(HX_CSTRING("Facebook.hx"),40,HX_CSTRING("fr.hyperfiction.Facebook"),HX_CSTRING("new")));
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",41)
	this->onConnect = ::org::shoebox::utils::system::Signal1_obj::__new();
}
;
	return null();
}

Facebook_obj::~Facebook_obj() { }

Dynamic Facebook_obj::__CreateEmpty() { return  new Facebook_obj; }
hx::ObjectPtr< Facebook_obj > Facebook_obj::__new()
{  hx::ObjectPtr< Facebook_obj > result = new Facebook_obj();
	result->__construct();
	return result;}

Dynamic Facebook_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Facebook_obj > result = new Facebook_obj();
	result->__construct();
	return result;}

Void Facebook_obj::init( ::String app_id){
{
		HX_SOURCE_PUSH("Facebook_obj::init")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",52)
		this->_init(app_id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facebook_obj,init,(void))

Void Facebook_obj::connect( ){
{
		HX_SOURCE_PUSH("Facebook_obj::connect")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",64)
		if (((this->_sAppID == null()))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",65)
			hx::Throw (::nme::errors::Error_obj::__new(HX_CSTRING("Facebook App ID is not defined"),null()));
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",68)
		this->_connect();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facebook_obj,connect,(void))

Void Facebook_obj::appRequest( ::String sTitle,Dynamic sMessage,::String toUser){
{
		HX_SOURCE_PUSH("Facebook_obj::appRequest")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",78)
		if (((toUser != null()))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",81)
			::fr::hyperfiction::Facebook_obj::hyp_fb_apprequest(sTitle,sMessage);
		}
		else{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",83)
			::fr::hyperfiction::Facebook_obj::hyp_fb_apprequest_to_user(sTitle,sMessage,toUser);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Facebook_obj,appRequest,(void))

Void Facebook_obj::feed( ::String sTitle,::String sCaption,::String sDescription,::String sLink,::String sPictureUrl){
{
		HX_SOURCE_PUSH("Facebook_obj::feed")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",100)
		::fr::hyperfiction::Facebook_obj::hyp_fb_feed(sTitle,sCaption,sDescription,sLink,sPictureUrl);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Facebook_obj,feed,(void))

Void Facebook_obj::_init( ::String sAppId){
{
		HX_SOURCE_PUSH("Facebook_obj::_init")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",118)
		this->_sAppID = sAppId;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",122)
		::fr::hyperfiction::Facebook_obj::hyp_fb_init(this->_sAppID);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facebook_obj,_init,(void))

Void Facebook_obj::_connect( ){
{
		HX_SOURCE_PUSH("Facebook_obj::_connect")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",136)
		::fr::hyperfiction::Facebook_obj::hypfb_set_callback(this->_onCallback_dyn());
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",137)
		::fr::hyperfiction::Facebook_obj::hypfb_connect();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facebook_obj,_connect,(void))

Void Facebook_obj::_onCallback( ::String sType,::String arg){
{
		HX_SOURCE_PUSH("Facebook_obj::_onCallback")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",148)
		::fr::hyperfiction::FbCallback type = ::Type_obj::createEnum(hx::ClassOf< ::fr::hyperfiction::FbCallback >(),sType,null());
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",149)
		{
::fr::hyperfiction::FbCallback _switch_1 = (::Type_obj::createEnum(hx::ClassOf< ::fr::hyperfiction::FbCallback >(),sType,null()));
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",152)
					this->session_token = arg;
					HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",153)
					this->_bConnected = true;
					HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",154)
					this->onConnect->emit(this->session_token);
					HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",155)
					::haxe::Log_obj::trace((HX_CSTRING("onLogin ::: token : ") + this->session_token),hx::SourceInfo(HX_CSTRING("Facebook.hx"),155,HX_CSTRING("fr.hyperfiction.Facebook"),HX_CSTRING("_onCallback")));
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Facebook_obj,_onCallback,(void))

Dynamic Facebook_obj::hyp_fb_init;

Dynamic Facebook_obj::hypfb_connect;

Dynamic Facebook_obj::hypfb_set_callback;

Dynamic Facebook_obj::hyp_fb_apprequest;

Dynamic Facebook_obj::hyp_fb_apprequest_to_user;

Dynamic Facebook_obj::hyp_fb_feed;

::fr::hyperfiction::Facebook Facebook_obj::getInstance( ){
	HX_SOURCE_PUSH("Facebook_obj::getInstance")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",170)
	if (((::fr::hyperfiction::Facebook_obj::__instance == null()))){
		HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",171)
		::fr::hyperfiction::Facebook_obj::__instance = ::fr::hyperfiction::Facebook_obj::__new();
	}
	HX_SOURCE_POS("/Volumes/workspaceHaxe/HyperExtensions/extensions/fb/fr/hyperfiction/Facebook.hx",173)
	return ::fr::hyperfiction::Facebook_obj::__instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Facebook_obj,getInstance,return )

::fr::hyperfiction::Facebook Facebook_obj::__instance;


Facebook_obj::Facebook_obj()
{
}

void Facebook_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Facebook);
	HX_MARK_MEMBER_NAME(session_token,"session_token");
	HX_MARK_MEMBER_NAME(app_id,"app_id");
	HX_MARK_MEMBER_NAME(onConnect,"onConnect");
	HX_MARK_MEMBER_NAME(_sAppID,"_sAppID");
	HX_MARK_MEMBER_NAME(_bConnected,"_bConnected");
	HX_MARK_MEMBER_NAME(_sFb_session_token,"_sFb_session_token");
	HX_MARK_END_CLASS();
}

Dynamic Facebook_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"feed") ) { return feed_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_init") ) { return _init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"app_id") ) { return app_id; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sAppID") ) { return _sAppID; }
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_connect") ) { return _connect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onConnect") ) { return onConnect; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__instance") ) { return __instance; }
		if (HX_FIELD_EQ(inName,"appRequest") ) { return appRequest_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hyp_fb_init") ) { return hyp_fb_init; }
		if (HX_FIELD_EQ(inName,"hyp_fb_feed") ) { return hyp_fb_feed; }
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"_bConnected") ) { return _bConnected; }
		if (HX_FIELD_EQ(inName,"_onCallback") ) { return _onCallback_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hypfb_connect") ) { return hypfb_connect; }
		if (HX_FIELD_EQ(inName,"session_token") ) { return session_token; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"hyp_fb_apprequest") ) { return hyp_fb_apprequest; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"hypfb_set_callback") ) { return hypfb_set_callback; }
		if (HX_FIELD_EQ(inName,"_sFb_session_token") ) { return _sFb_session_token; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"hyp_fb_apprequest_to_user") ) { return hyp_fb_apprequest_to_user; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Facebook_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"app_id") ) { app_id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sAppID") ) { _sAppID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onConnect") ) { onConnect=inValue.Cast< ::org::shoebox::utils::system::Signal1 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__instance") ) { __instance=inValue.Cast< ::fr::hyperfiction::Facebook >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hyp_fb_init") ) { hyp_fb_init=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hyp_fb_feed") ) { hyp_fb_feed=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bConnected") ) { _bConnected=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hypfb_connect") ) { hypfb_connect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"session_token") ) { session_token=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"hyp_fb_apprequest") ) { hyp_fb_apprequest=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"hypfb_set_callback") ) { hypfb_set_callback=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sFb_session_token") ) { _sFb_session_token=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"hyp_fb_apprequest_to_user") ) { hyp_fb_apprequest_to_user=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Facebook_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("session_token"));
	outFields->push(HX_CSTRING("app_id"));
	outFields->push(HX_CSTRING("onConnect"));
	outFields->push(HX_CSTRING("_sAppID"));
	outFields->push(HX_CSTRING("_bConnected"));
	outFields->push(HX_CSTRING("_sFb_session_token"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("hyp_fb_init"),
	HX_CSTRING("hypfb_connect"),
	HX_CSTRING("hypfb_set_callback"),
	HX_CSTRING("hyp_fb_apprequest"),
	HX_CSTRING("hyp_fb_apprequest_to_user"),
	HX_CSTRING("hyp_fb_feed"),
	HX_CSTRING("getInstance"),
	HX_CSTRING("__instance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("session_token"),
	HX_CSTRING("app_id"),
	HX_CSTRING("onConnect"),
	HX_CSTRING("_sAppID"),
	HX_CSTRING("_bConnected"),
	HX_CSTRING("_sFb_session_token"),
	HX_CSTRING("init"),
	HX_CSTRING("connect"),
	HX_CSTRING("appRequest"),
	HX_CSTRING("feed"),
	HX_CSTRING("_init"),
	HX_CSTRING("_connect"),
	HX_CSTRING("_onCallback"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Facebook_obj::hyp_fb_init,"hyp_fb_init");
	HX_MARK_MEMBER_NAME(Facebook_obj::hypfb_connect,"hypfb_connect");
	HX_MARK_MEMBER_NAME(Facebook_obj::hypfb_set_callback,"hypfb_set_callback");
	HX_MARK_MEMBER_NAME(Facebook_obj::hyp_fb_apprequest,"hyp_fb_apprequest");
	HX_MARK_MEMBER_NAME(Facebook_obj::hyp_fb_apprequest_to_user,"hyp_fb_apprequest_to_user");
	HX_MARK_MEMBER_NAME(Facebook_obj::hyp_fb_feed,"hyp_fb_feed");
	HX_MARK_MEMBER_NAME(Facebook_obj::__instance,"__instance");
};

Class Facebook_obj::__mClass;

void Facebook_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("fr.hyperfiction.Facebook"), hx::TCanCast< Facebook_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Facebook_obj::__boot()
{
	hx::Static(hyp_fb_init) = ::nme::Loader_obj::load(HX_CSTRING("hyp_fb_init"),(int)1);
	hx::Static(hypfb_connect) = ::nme::Loader_obj::load(HX_CSTRING("hyp_fb_connect"),(int)0);
	hx::Static(hypfb_set_callback) = ::nme::Loader_obj::load(HX_CSTRING("hypfb_set_callback"),(int)1);
	hx::Static(hyp_fb_apprequest) = ::nme::Loader_obj::load(HX_CSTRING("hyp_fb_apprequest"),(int)2);
	hx::Static(hyp_fb_apprequest_to_user) = ::nme::Loader_obj::load(HX_CSTRING("hyp_fb_apprequest_to_user"),(int)3);
	hx::Static(hyp_fb_feed) = ::nme::Loader_obj::load(HX_CSTRING("hypfb_feed"),(int)5);
	hx::Static(__instance) = null();
}

} // end namespace fr
} // end namespace hyperfiction
