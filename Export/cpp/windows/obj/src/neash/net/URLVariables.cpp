#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_neash_net_URLVariables
#include <neash/net/URLVariables.h>
#endif
namespace neash{
namespace net{

Void URLVariables_obj::__construct(::String inEncoded)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",7)
	if (((inEncoded != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",9)
		this->decode(inEncoded);
	}
}
;
	return null();
}

URLVariables_obj::~URLVariables_obj() { }

Dynamic URLVariables_obj::__CreateEmpty() { return  new URLVariables_obj; }
hx::ObjectPtr< URLVariables_obj > URLVariables_obj::__new(::String inEncoded)
{  hx::ObjectPtr< URLVariables_obj > result = new URLVariables_obj();
	result->__construct(inEncoded);
	return result;}

Dynamic URLVariables_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLVariables_obj > result = new URLVariables_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLVariables_obj::decode( ::String inVars){
{
		HX_SOURCE_PUSH("URLVariables_obj::decode")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",14)
		Array< ::String > fields = ::Reflect_obj::fields(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",15)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",15)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",15)
			while(((_g < fields->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",15)
				::String f = fields->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",15)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",16)
				::Reflect_obj::deleteField(hx::ObjectPtr<OBJ_>(this),f);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",17)
		Array< ::String > fields1 = inVars.split(HX_CSTRING(";"))->join(HX_CSTRING("&")).split(HX_CSTRING("&"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",18)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",18)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",18)
			while(((_g < fields1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",18)
				::String f = fields1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",18)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",20)
				int eq = f.indexOf(HX_CSTRING("="),null());
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",21)
				if (((eq > (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",22)
					this->__SetField(::StringTools_obj::urlDecode(f.substr((int)0,eq)),::StringTools_obj::urlDecode(f.substr((eq + (int)1),null())),false);
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",24)
					if (((eq != (int)0))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",25)
						this->__SetField(::StringTools_obj::urlDecode(f),HX_CSTRING(""),false);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLVariables_obj,decode,(void))

::String URLVariables_obj::toString( ){
	HX_SOURCE_PUSH("URLVariables_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",31)
	Array< ::String > result = Array_obj< ::String >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",32)
	Array< ::String > fields = ::Reflect_obj::fields(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",33)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",33)
		int _g = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",33)
		while(((_g < fields->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",33)
			::String f = fields->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",33)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",34)
			result->push(((::StringTools_obj::urlEncode(f) + HX_CSTRING("=")) + ::StringTools_obj::urlEncode(::Reflect_obj::field(hx::ObjectPtr<OBJ_>(this),f))));
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/net/URLVariables.hx",36)
	return result->join(HX_CSTRING("&"));
}


HX_DEFINE_DYNAMIC_FUNC0(URLVariables_obj,toString,return )


URLVariables_obj::URLVariables_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void URLVariables_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLVariables);
	HX_MARK_DYNAMIC;
	HX_MARK_END_CLASS();
}

Dynamic URLVariables_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"decode") ) { return decode_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	HX_CHECK_DYNAMIC_GET_FIELD(inName);
	return super::__Field(inName,inCallProp);
}

Dynamic URLVariables_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	try { return super::__SetField(inName,inValue,inCallProp); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void URLVariables_obj::__GetFields(Array< ::String> &outFields)
{
	HX_APPEND_DYNAMIC_FIELDS(outFields);
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("decode"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class URLVariables_obj::__mClass;

void URLVariables_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.net.URLVariables"), hx::TCanCast< URLVariables_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLVariables_obj::__boot()
{
}

} // end namespace neash
} // end namespace net
