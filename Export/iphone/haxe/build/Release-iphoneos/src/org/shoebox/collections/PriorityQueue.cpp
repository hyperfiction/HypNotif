#include <hxcpp.h>

#ifndef INCLUDED_org_shoebox_collections_PrioQueueIterator
#include <org/shoebox/collections/PrioQueueIterator.h>
#endif
#ifndef INCLUDED_org_shoebox_collections_PriorityQueue
#include <org/shoebox/collections/PriorityQueue.h>
#endif
namespace org{
namespace shoebox{
namespace collections{

Void PriorityQueue_obj::__construct()
{
{
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",25)
	this->_aContent = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",26)
	this->_bInvalidate = true;
}
;
	return null();
}

PriorityQueue_obj::~PriorityQueue_obj() { }

Dynamic PriorityQueue_obj::__CreateEmpty() { return  new PriorityQueue_obj; }
hx::ObjectPtr< PriorityQueue_obj > PriorityQueue_obj::__new()
{  hx::ObjectPtr< PriorityQueue_obj > result = new PriorityQueue_obj();
	result->__construct();
	return result;}

Dynamic PriorityQueue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PriorityQueue_obj > result = new PriorityQueue_obj();
	result->__construct();
	return result;}

Void PriorityQueue_obj::add( Dynamic value,hx::Null< int >  __o_prio){
int prio = __o_prio.Default(0);
	HX_SOURCE_PUSH("PriorityQueue_obj::add");
{
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &value,int &prio){
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("content") , value,false);
					__result->Add(HX_CSTRING("prio") , prio,false);
					return __result;
				}
				return null();
			}
		};
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",39)
		Dynamic desc = _Function_1_1::Block(value,prio);
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",41)
		this->_add(desc,prio);
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",42)
		this->_bInvalidate = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PriorityQueue_obj,add,(void))

bool PriorityQueue_obj::remove( Dynamic value,hx::Null< int >  __o_prio){
int prio = __o_prio.Default(-1);
	HX_SOURCE_PUSH("PriorityQueue_obj::remove");
{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",53)
		Dynamic desc;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",54)
		bool b = false;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",55)
		{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",55)
			int _g = (int)0;
			Dynamic _g1 = this->_aContent;
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",55)
			while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",55)
				Dynamic desc1 = _g1->__GetItem(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",55)
				++(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",56)
				if (((bool((desc1->__Field(HX_CSTRING("content"),true) == value)) && bool(((bool((prio == (int)-1)) || bool((desc1->__Field(HX_CSTRING("prio"),true) == prio)))))))){
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",57)
					this->_aContent->__Field(HX_CSTRING("remove"),true)(desc1);
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",58)
					b = true;
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",59)
					break;
				}
			}
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",62)
		this->_bInvalidate = true;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",63)
		return b;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(PriorityQueue_obj,remove,return )

bool PriorityQueue_obj::contains( Dynamic value,int prio){
	HX_SOURCE_PUSH("PriorityQueue_obj::contains")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",74)
	bool b = false;
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",75)
	{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",75)
		int _g = (int)0;
		Dynamic _g1 = this->_aContent;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",75)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",75)
			Dynamic desc = _g1->__GetItem(_g);
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",75)
			++(_g);
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",76)
			if (((bool((desc->__Field(HX_CSTRING("content"),true) == value)) && bool((desc->__Field(HX_CSTRING("prio"),true) == prio))))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",77)
				b = true;
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",78)
				break;
			}
		}
	}
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",82)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC2(PriorityQueue_obj,contains,return )

Void PriorityQueue_obj::sort( ){
{
		HX_SOURCE_PUSH("PriorityQueue_obj::sort")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",91)
		this->_sort();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PriorityQueue_obj,sort,(void))

::org::shoebox::collections::PrioQueueIterator PriorityQueue_obj::iterator( ){
	HX_SOURCE_PUSH("PriorityQueue_obj::iterator")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",103)
	if ((!(this->_bInvalidate))){
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",104)
		return this->_oIterator;
	}
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",106)
	this->_oIterator = ::org::shoebox::collections::PrioQueueIterator_obj::__new(this->_aContent);
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",107)
	return this->_oIterator;
}


HX_DEFINE_DYNAMIC_FUNC0(PriorityQueue_obj,iterator,return )

Void PriorityQueue_obj::setPrioOf( Dynamic value,int prio){
{
		HX_SOURCE_PUSH("PriorityQueue_obj::setPrioOf")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",118)
		{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",118)
			int _g = (int)0;
			Dynamic _g1 = this->_aContent;
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",118)
			while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",118)
				Dynamic o = _g1->__GetItem(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",118)
				++(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",119)
				if (((o->__Field(HX_CSTRING("content"),true) == value))){
					HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",120)
					o->__FieldRef(HX_CSTRING("prio")) = prio;
				}
			}
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",122)
		this->_sort();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PriorityQueue_obj,setPrioOf,(void))

int PriorityQueue_obj::getPrioOf( Dynamic value){
	HX_SOURCE_PUSH("PriorityQueue_obj::getPrioOf")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",133)
	bool b = false;
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",134)
	int p = (int)-1;
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",135)
	{
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",135)
		int _g = (int)0;
		Dynamic _g1 = this->_aContent;
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",135)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",135)
			Dynamic desc = _g1->__GetItem(_g);
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",135)
			++(_g);
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",136)
			if (((desc->__Field(HX_CSTRING("content"),true) == value))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",137)
				p = desc->__Field(HX_CSTRING("prio"),true);
			}
		}
	}
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",140)
	return p;
}


HX_DEFINE_DYNAMIC_FUNC1(PriorityQueue_obj,getPrioOf,return )

Dynamic PriorityQueue_obj::getContent( ){
	HX_SOURCE_PUSH("PriorityQueue_obj::getContent")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",149)
	return this->_aContent;
}


HX_DEFINE_DYNAMIC_FUNC0(PriorityQueue_obj,getContent,return )

Void PriorityQueue_obj::_sort( ){
{
		HX_SOURCE_PUSH("PriorityQueue_obj::_sort")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",162)
		Dynamic a = this->_aContent->__Field(HX_CSTRING("copy"),true)();
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",163)
		this->_aContent = Dynamic( Array_obj<Dynamic>::__new());
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",164)
		{
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",164)
			int _g = (int)0;
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",164)
			while(((_g < a->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",164)
				Dynamic desc = a->__GetItem(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",164)
				++(_g);
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",165)
				this->_add(desc,desc->__Field(HX_CSTRING("prio"),true));
			}
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",166)
		this->_bInvalidate = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PriorityQueue_obj,_sort,(void))

Void PriorityQueue_obj::_add( Dynamic desc,int prio){
{
		HX_SOURCE_PUSH("PriorityQueue_obj::_add")
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",176)
		int inc = this->_aContent->__Field(HX_CSTRING("length"),true);
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",177)
		while((((inc)-- > (int)0))){
			HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",177)
			if (((this->_aContent->__GetItem(inc)->__Field(HX_CSTRING("prio"),true) >= prio))){
				HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",179)
				break;
			}
		}
		HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",182)
		this->_aContent->__Field(HX_CSTRING("insert"),true)((inc + (int)1),desc);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PriorityQueue_obj,_add,(void))

int PriorityQueue_obj::_getLength( ){
	HX_SOURCE_PUSH("PriorityQueue_obj::_getLength")
	HX_SOURCE_POS("/Volumes/workspaceHaxe/inthebox/src/org/shoebox/collections/PriorityQueue.hx",191)
	return this->_aContent->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(PriorityQueue_obj,_getLength,return )


PriorityQueue_obj::PriorityQueue_obj()
{
}

void PriorityQueue_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PriorityQueue);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(_aContent,"_aContent");
	HX_MARK_MEMBER_NAME(_bInvalidate,"_bInvalidate");
	HX_MARK_MEMBER_NAME(_oIterator,"_oIterator");
	HX_MARK_END_CLASS();
}

Dynamic PriorityQueue_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"sort") ) { return sort_dyn(); }
		if (HX_FIELD_EQ(inName,"_add") ) { return _add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_sort") ) { return _sort_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? _getLength() : length; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_aContent") ) { return _aContent; }
		if (HX_FIELD_EQ(inName,"setPrioOf") ) { return setPrioOf_dyn(); }
		if (HX_FIELD_EQ(inName,"getPrioOf") ) { return getPrioOf_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_oIterator") ) { return _oIterator; }
		if (HX_FIELD_EQ(inName,"getContent") ) { return getContent_dyn(); }
		if (HX_FIELD_EQ(inName,"_getLength") ) { return _getLength_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_bInvalidate") ) { return _bInvalidate; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PriorityQueue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_aContent") ) { _aContent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_oIterator") ) { _oIterator=inValue.Cast< ::org::shoebox::collections::PrioQueueIterator >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_bInvalidate") ) { _bInvalidate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PriorityQueue_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("_aContent"));
	outFields->push(HX_CSTRING("_bInvalidate"));
	outFields->push(HX_CSTRING("_oIterator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("_aContent"),
	HX_CSTRING("_bInvalidate"),
	HX_CSTRING("_oIterator"),
	HX_CSTRING("add"),
	HX_CSTRING("remove"),
	HX_CSTRING("contains"),
	HX_CSTRING("sort"),
	HX_CSTRING("iterator"),
	HX_CSTRING("setPrioOf"),
	HX_CSTRING("getPrioOf"),
	HX_CSTRING("getContent"),
	HX_CSTRING("_sort"),
	HX_CSTRING("_add"),
	HX_CSTRING("_getLength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PriorityQueue_obj::__mClass;

void PriorityQueue_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.shoebox.collections.PriorityQueue"), hx::TCanCast< PriorityQueue_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PriorityQueue_obj::__boot()
{
}

} // end namespace org
} // end namespace shoebox
} // end namespace collections
