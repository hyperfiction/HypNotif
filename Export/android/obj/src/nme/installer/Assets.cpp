#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_media_Sound
#include <neash/media/Sound.h>
#endif
#ifndef INCLUDED_neash_media_SoundLoaderContext
#include <neash/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_neash_net_URLRequest
#include <neash/net/URLRequest.h>
#endif
#ifndef INCLUDED_neash_text_Font
#include <neash/text/Font.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace nme{
namespace installer{

Void Assets_obj::__construct()
{
	return null();
}

Assets_obj::~Assets_obj() { }

Dynamic Assets_obj::__CreateEmpty() { return  new Assets_obj; }
hx::ObjectPtr< Assets_obj > Assets_obj::__new()
{  hx::ObjectPtr< Assets_obj > result = new Assets_obj();
	result->__construct();
	return result;}

Dynamic Assets_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Assets_obj > result = new Assets_obj();
	result->__construct();
	return result;}

::Hash Assets_obj::cachedBitmapData;

bool Assets_obj::initialized;

::Hash Assets_obj::resourceNames;

::Hash Assets_obj::resourceTypes;

Void Assets_obj::initialize( ){
{
		HX_SOURCE_PUSH("Assets_obj::initialize")
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",26)
		if ((!(::nme::installer::Assets_obj::initialized))){
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",30)
			::nme::installer::Assets_obj::resourceNames->set(HX_CSTRING("assets/logo.png"),HX_CSTRING("assets_logo_png"));
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",31)
			::nme::installer::Assets_obj::resourceTypes->set(HX_CSTRING("assets/logo.png"),HX_CSTRING("image"));
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",32)
			::nme::installer::Assets_obj::resourceNames->set(HX_CSTRING("assets/nme.svg"),HX_CSTRING("assets_nme_svg"));
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",33)
			::nme::installer::Assets_obj::resourceTypes->set(HX_CSTRING("assets/nme.svg"),HX_CSTRING("asset"));
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",35)
			::nme::installer::Assets_obj::initialized = true;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Assets_obj,initialize,(void))

::String Assets_obj::getResourceName( ::String id){
	HX_SOURCE_PUSH("Assets_obj::getResourceName")
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",42)
	::nme::installer::Assets_obj::initialize();
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",43)
	return ::nme::installer::Assets_obj::resourceNames->get(id);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getResourceName,return )

::neash::display::BitmapData Assets_obj::getBitmapData( ::String id,hx::Null< bool >  __o_useCache){
bool useCache = __o_useCache.Default(true);
	HX_SOURCE_PUSH("Assets_obj::getBitmapData");
{
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",48)
		::nme::installer::Assets_obj::initialize();
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",50)
		if (((bool(::nme::installer::Assets_obj::resourceTypes->exists(id)) && bool((::nme::installer::Assets_obj::resourceTypes->get(id) == HX_CSTRING("image")))))){
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",50)
			if (((bool(useCache) && bool(::nme::installer::Assets_obj::cachedBitmapData->exists(id))))){
				HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",52)
				return ::nme::installer::Assets_obj::cachedBitmapData->get(id);
			}
			else{
				HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",58)
				::neash::display::BitmapData data = ::neash::display::BitmapData_obj::load(::nme::installer::Assets_obj::resourceNames->get(id),null());
				HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",60)
				if ((useCache)){
					HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",60)
					::nme::installer::Assets_obj::cachedBitmapData->set(id,data);
				}
				HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",66)
				return data;
			}
		}
		else{
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",72)
			::haxe::Log_obj::trace(((HX_CSTRING("[nme.Assets] There is no BitmapData asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),72,HX_CSTRING("nme.installer.Assets"),HX_CSTRING("getBitmapData")));
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",74)
			return null();
		}
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",50)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Assets_obj,getBitmapData,return )

::neash::utils::ByteArray Assets_obj::getBytes( ::String id){
	HX_SOURCE_PUSH("Assets_obj::getBytes")
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",83)
	::nme::installer::Assets_obj::initialize();
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",85)
	if ((::nme::installer::Assets_obj::resourceNames->exists(id))){
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",85)
		return ::neash::utils::ByteArray_obj::readFile(::nme::installer::Assets_obj::resourceNames->get(id));
	}
	else{
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",91)
		::haxe::Log_obj::trace(((HX_CSTRING("[nme.Assets] There is no String or ByteArray asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),91,HX_CSTRING("nme.installer.Assets"),HX_CSTRING("getBytes")));
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",93)
		return null();
	}
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",85)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getBytes,return )

::neash::text::Font Assets_obj::getFont( ::String id){
	HX_SOURCE_PUSH("Assets_obj::getFont")
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",102)
	::nme::installer::Assets_obj::initialize();
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",104)
	if (((bool(::nme::installer::Assets_obj::resourceTypes->exists(id)) && bool((::nme::installer::Assets_obj::resourceTypes->get(id) == HX_CSTRING("font")))))){
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",104)
		return ::neash::text::Font_obj::__new(::nme::installer::Assets_obj::resourceNames->get(id));
	}
	else{
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",110)
		::haxe::Log_obj::trace(((HX_CSTRING("[nme.Assets] There is no Font asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),110,HX_CSTRING("nme.installer.Assets"),HX_CSTRING("getFont")));
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",112)
		return null();
	}
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",104)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getFont,return )

::neash::media::Sound Assets_obj::getSound( ::String id){
	HX_SOURCE_PUSH("Assets_obj::getSound")
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",121)
	::nme::installer::Assets_obj::initialize();
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",123)
	if ((::nme::installer::Assets_obj::resourceTypes->exists(id))){
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",123)
		if (((::nme::installer::Assets_obj::resourceTypes->get(id) == HX_CSTRING("sound")))){
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",125)
			return ::neash::media::Sound_obj::__new(::neash::net::URLRequest_obj::__new(::nme::installer::Assets_obj::resourceNames->get(id)),null(),false);
		}
		else{
			HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",129)
			if (((::nme::installer::Assets_obj::resourceTypes->get(id) == HX_CSTRING("music")))){
				HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",129)
				return ::neash::media::Sound_obj::__new(::neash::net::URLRequest_obj::__new(::nme::installer::Assets_obj::resourceNames->get(id)),null(),true);
			}
		}
	}
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",137)
	::haxe::Log_obj::trace(((HX_CSTRING("[nme.Assets] There is no Sound asset with an ID of \"") + id) + HX_CSTRING("\"")),hx::SourceInfo(HX_CSTRING("Assets.hx"),137,HX_CSTRING("nme.installer.Assets"),HX_CSTRING("getSound")));
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",139)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getSound,return )

::String Assets_obj::getText( ::String id){
	HX_SOURCE_PUSH("Assets_obj::getText")
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",146)
	::neash::utils::ByteArray bytes = ::nme::installer::Assets_obj::getBytes(id);
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",148)
	if (((bytes == null()))){
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",148)
		return null();
	}
	else{
		HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",152)
		return bytes->readUTFBytes(bytes->length);
	}
	HX_SOURCE_POS("Export/android/haxe/nme/installer/Assets.hx",148)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Assets_obj,getText,return )


Assets_obj::Assets_obj()
{
}

void Assets_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Assets);
	HX_MARK_END_CLASS();
}

Dynamic Assets_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getFont") ) { return getFont_dyn(); }
		if (HX_FIELD_EQ(inName,"getText") ) { return getText_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { return initialized; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resourceNames") ) { return resourceNames; }
		if (HX_FIELD_EQ(inName,"resourceTypes") ) { return resourceTypes; }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getResourceName") ) { return getResourceName_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"cachedBitmapData") ) { return cachedBitmapData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Assets_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { initialized=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resourceNames") ) { resourceNames=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resourceTypes") ) { resourceTypes=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"cachedBitmapData") ) { cachedBitmapData=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Assets_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("cachedBitmapData"),
	HX_CSTRING("initialized"),
	HX_CSTRING("resourceNames"),
	HX_CSTRING("resourceTypes"),
	HX_CSTRING("initialize"),
	HX_CSTRING("getResourceName"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("getFont"),
	HX_CSTRING("getSound"),
	HX_CSTRING("getText"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Assets_obj::cachedBitmapData,"cachedBitmapData");
	HX_MARK_MEMBER_NAME(Assets_obj::initialized,"initialized");
	HX_MARK_MEMBER_NAME(Assets_obj::resourceNames,"resourceNames");
	HX_MARK_MEMBER_NAME(Assets_obj::resourceTypes,"resourceTypes");
};

Class Assets_obj::__mClass;

void Assets_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.installer.Assets"), hx::TCanCast< Assets_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Assets_obj::__boot()
{
	hx::Static(cachedBitmapData) = ::Hash_obj::__new();
	hx::Static(initialized) = false;
	hx::Static(resourceNames) = ::Hash_obj::__new();
	hx::Static(resourceTypes) = ::Hash_obj::__new();
}

} // end namespace nme
} // end namespace installer
