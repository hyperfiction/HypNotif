#include <hxcpp.h>

#ifndef INCLUDED_org_shoebox_collections_PriorityQueue
#include <org/shoebox/collections/PriorityQueue.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
namespace org{
namespace shoebox{
namespace utils{
namespace system{

Void ASignal_obj::__construct()
{
{
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",55)
	this->_oQueue = ::org::shoebox::collections::PriorityQueue_obj::__new();
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",56)
	this->_setEnabled(true);
}
;
	return null();
}

ASignal_obj::~ASignal_obj() { }

Dynamic ASignal_obj::__CreateEmpty() { return  new ASignal_obj; }
hx::ObjectPtr< ASignal_obj > ASignal_obj::__new()
{  hx::ObjectPtr< ASignal_obj > result = new ASignal_obj();
	result->__construct();
	return result;}

Dynamic ASignal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ASignal_obj > result = new ASignal_obj();
	result->__construct();
	return result;}

Void ASignal_obj::connect( Dynamic f,hx::Null< int >  __o_prio,hx::Null< int >  __o_count){
int prio = __o_prio.Default(0);
int count = __o_count.Default(-1);
	HX_SOURCE_PUSH("ASignal_obj::connect");
{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",69)
		if ((this->_exist(f,prio))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",70)
			return null();
		}
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &f,int &count){
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("listener") , f,false);
					__result->Add(HX_CSTRING("count") , count,false);
					return __result;
				}
				return null();
			}
		};
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",72)
		Dynamic s = _Function_1_1::Block(f,count);
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",73)
		this->_oQueue->add(s,prio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ASignal_obj,connect,(void))

Void ASignal_obj::disconnect( Dynamic f,hx::Null< int >  __o_prio){
int prio = __o_prio.Default(0);
	HX_SOURCE_PUSH("ASignal_obj::disconnect");
{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",85)
		Dynamic content = this->_oQueue->getContent();
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",86)
		{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",86)
			int _g = (int)0;
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",86)
			while(((_g < content->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",86)
				Dynamic o = content->__GetItem(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",86)
				++(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",88)
				if (((bool((o->__Field(HX_CSTRING("content"),true)->__Field(HX_CSTRING("listener"),true) == f)) && bool((o->__Field(HX_CSTRING("prio"),true) == prio))))){
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",89)
					content->__Field(HX_CSTRING("remove"),true)(o);
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",90)
					break;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ASignal_obj,disconnect,(void))

Void ASignal_obj::dispose( ){
{
		HX_SOURCE_PUSH("ASignal_obj::dispose")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",102)
		this->_oQueue = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ASignal_obj,dispose,(void))

bool ASignal_obj::_exist( Dynamic f,hx::Null< int >  __o_prio){
int prio = __o_prio.Default(0);
	HX_SOURCE_PUSH("ASignal_obj::_exist");
{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",116)
		bool b = false;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",117)
		Dynamic content = this->_oQueue->getContent();
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",118)
		{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",118)
			int _g = (int)0;
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",118)
			while(((_g < content->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",118)
				Dynamic o = content->__GetItem(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",118)
				++(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",119)
				if (((bool((o->__Field(HX_CSTRING("content"),true)->__Field(HX_CSTRING("listener"),true) == f)) && bool((o->__Field(HX_CSTRING("prio"),true) == prio))))){
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",120)
					b = true;
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",121)
					break;
				}
			}
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",124)
		return b;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(ASignal_obj,_exist,return )

Void ASignal_obj::_check( Dynamic l){
{
		HX_SOURCE_PUSH("ASignal_obj::_check")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",136)
		if (((l->__Field(HX_CSTRING("count"),true) != (int)-1))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",137)
			(l->__FieldRef(HX_CSTRING("count")))--;
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",139)
		if (((l->__Field(HX_CSTRING("count"),true) == (int)0))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",140)
			this->disconnect(l->__Field(HX_CSTRING("listener"),true),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ASignal_obj,_check,(void))

bool ASignal_obj::_setEnabled( bool b){
	HX_SOURCE_PUSH("ASignal_obj::_setEnabled")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",151)
	this->enabled = b;
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/utils/system/ASignal.hx",152)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(ASignal_obj,_setEnabled,return )


ASignal_obj::ASignal_obj()
{
}

void ASignal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ASignal);
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(_oQueue,"_oQueue");
	HX_MARK_END_CLASS();
}

Dynamic ASignal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_exist") ) { return _exist_dyn(); }
		if (HX_FIELD_EQ(inName,"_check") ) { return _check_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		if (HX_FIELD_EQ(inName,"_oQueue") ) { return _oQueue; }
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"disconnect") ) { return disconnect_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_setEnabled") ) { return _setEnabled_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ASignal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { if (inCallProp) return _setEnabled(inValue);enabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_oQueue") ) { _oQueue=inValue.Cast< ::org::shoebox::collections::PriorityQueue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ASignal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("_oQueue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("enabled"),
	HX_CSTRING("_oQueue"),
	HX_CSTRING("connect"),
	HX_CSTRING("disconnect"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_exist"),
	HX_CSTRING("_check"),
	HX_CSTRING("_setEnabled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ASignal_obj::__mClass;

void ASignal_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.shoebox.utils.system.ASignal"), hx::TCanCast< ASignal_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ASignal_obj::__boot()
{
}

} // end namespace org
} // end namespace shoebox
} // end namespace utils
} // end namespace system
