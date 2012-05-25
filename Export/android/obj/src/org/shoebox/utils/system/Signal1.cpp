#include <hxcpp.h>

#ifndef INCLUDED_org_shoebox_collections_PrioQueueIterator
#include <org/shoebox/collections/PrioQueueIterator.h>
#endif
#ifndef INCLUDED_org_shoebox_collections_PriorityQueue
#include <org/shoebox/collections/PriorityQueue.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_ASignal
#include <org/shoebox/utils/system/ASignal.h>
#endif
#ifndef INCLUDED_org_shoebox_utils_system_Signal1
#include <org/shoebox/utils/system/Signal1.h>
#endif
namespace org{
namespace shoebox{
namespace utils{
namespace system{

Void Signal1_obj::__construct()
{
{
	HX_SOURCE_POS("../inthebox/src/org/shoebox/utils/system/Signal1.hx",47)
	super::__construct();
}
;
	return null();
}

Signal1_obj::~Signal1_obj() { }

Dynamic Signal1_obj::__CreateEmpty() { return  new Signal1_obj; }
hx::ObjectPtr< Signal1_obj > Signal1_obj::__new()
{  hx::ObjectPtr< Signal1_obj > result = new Signal1_obj();
	result->__construct();
	return result;}

Dynamic Signal1_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal1_obj > result = new Signal1_obj();
	result->__construct();
	return result;}

Void Signal1_obj::emit( Dynamic arg){
{
		HX_SOURCE_PUSH("Signal1_obj::emit")
		HX_SOURCE_POS("../inthebox/src/org/shoebox/utils/system/Signal1.hx",59)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(this->_oQueue->iterator());  __it->hasNext(); ){
			Dynamic l = __it->next();
			{
				HX_SOURCE_POS("../inthebox/src/org/shoebox/utils/system/Signal1.hx",61)
				l->__Field(HX_CSTRING("listener"),true)(arg);
				HX_SOURCE_POS("../inthebox/src/org/shoebox/utils/system/Signal1.hx",62)
				this->_check(l);
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Signal1_obj,emit,(void))


Signal1_obj::Signal1_obj()
{
}

void Signal1_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Signal1);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Signal1_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"emit") ) { return emit_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Signal1_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal1_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("emit"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Signal1_obj::__mClass;

void Signal1_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.shoebox.utils.system.Signal1"), hx::TCanCast< Signal1_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Signal1_obj::__boot()
{
}

} // end namespace org
} // end namespace shoebox
} // end namespace utils
} // end namespace system
