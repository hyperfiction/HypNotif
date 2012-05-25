#include <hxcpp.h>

#ifndef INCLUDED_org_shoebox_collections_PrioQueueIterator
#include <org/shoebox/collections/PrioQueueIterator.h>
#endif
namespace org{
namespace shoebox{
namespace collections{

Void PrioQueueIterator_obj::__construct(Dynamic content)
{
{
	HX_SOURCE_POS("../inthebox/src/org/shoebox/collections/PriorityQueue.hx",268)
	this->_aContent = content->__Field(HX_CSTRING("copy"),true)();
}
;
	return null();
}

PrioQueueIterator_obj::~PrioQueueIterator_obj() { }

Dynamic PrioQueueIterator_obj::__CreateEmpty() { return  new PrioQueueIterator_obj; }
hx::ObjectPtr< PrioQueueIterator_obj > PrioQueueIterator_obj::__new(Dynamic content)
{  hx::ObjectPtr< PrioQueueIterator_obj > result = new PrioQueueIterator_obj();
	result->__construct(content);
	return result;}

Dynamic PrioQueueIterator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrioQueueIterator_obj > result = new PrioQueueIterator_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PrioQueueIterator_obj::reset( ){
{
		HX_SOURCE_PUSH("PrioQueueIterator_obj::reset")
		HX_SOURCE_POS("../inthebox/src/org/shoebox/collections/PriorityQueue.hx",280)
		this->inc = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PrioQueueIterator_obj,reset,(void))

bool PrioQueueIterator_obj::hasNext( ){
	HX_SOURCE_PUSH("PrioQueueIterator_obj::hasNext")
	HX_SOURCE_POS("../inthebox/src/org/shoebox/collections/PriorityQueue.hx",290)
	return (this->inc < this->_aContent->__Field(HX_CSTRING("length"),true));
}


HX_DEFINE_DYNAMIC_FUNC0(PrioQueueIterator_obj,hasNext,return )

Dynamic PrioQueueIterator_obj::next( ){
	HX_SOURCE_PUSH("PrioQueueIterator_obj::next")
	HX_SOURCE_POS("../inthebox/src/org/shoebox/collections/PriorityQueue.hx",300)
	return this->_aContent->__GetItem((this->inc)++)->__Field(HX_CSTRING("content"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(PrioQueueIterator_obj,next,return )


PrioQueueIterator_obj::PrioQueueIterator_obj()
{
}

void PrioQueueIterator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PrioQueueIterator);
	HX_MARK_MEMBER_NAME(inc,"inc");
	HX_MARK_MEMBER_NAME(_aContent,"_aContent");
	HX_MARK_END_CLASS();
}

Dynamic PrioQueueIterator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"inc") ) { return inc; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_aContent") ) { return _aContent; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PrioQueueIterator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"inc") ) { inc=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_aContent") ) { _aContent=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PrioQueueIterator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("inc"));
	outFields->push(HX_CSTRING("_aContent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("inc"),
	HX_CSTRING("_aContent"),
	HX_CSTRING("reset"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PrioQueueIterator_obj::__mClass;

void PrioQueueIterator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.shoebox.collections.PrioQueueIterator"), hx::TCanCast< PrioQueueIterator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PrioQueueIterator_obj::__boot()
{
}

} // end namespace org
} // end namespace shoebox
} // end namespace collections
