#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_errors_ArgumentError
#include <neash/errors/ArgumentError.h>
#endif
#ifndef INCLUDED_neash_errors_Error
#include <neash/errors/Error.h>
#endif
#ifndef INCLUDED_neash_errors_RangeError
#include <neash/errors/RangeError.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace neash{
namespace display{

Void DisplayObjectContainer_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",24)
	super::__construct(inHandle,inType);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",25)
	this->nmeChildren = Array_obj< ::neash::display::DisplayObject >::__new();
}
;
	return null();
}

DisplayObjectContainer_obj::~DisplayObjectContainer_obj() { }

Dynamic DisplayObjectContainer_obj::__CreateEmpty() { return  new DisplayObjectContainer_obj; }
hx::ObjectPtr< DisplayObjectContainer_obj > DisplayObjectContainer_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic DisplayObjectContainer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::neash::display::DisplayObject DisplayObjectContainer_obj::addChild( ::neash::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",31)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",32)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,addChild,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::addChildAt( ::neash::display::DisplayObject child,int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",38)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		if (((index > this->nmeChildren->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		::neash::display::DisplayObject s = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		int orig = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		if (((orig < (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				int realindex = (int)-1;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					int _g1 = (int)0;
					int _g = this->nmeChildren->length;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
						if (((this->nmeChildren->__get(i) == child))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
							realindex = i;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
							break;
						}
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				if (((realindex != (int)-1))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			hx::Throw (msg);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
		if (((index < orig))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			int i = orig;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			while(((i > index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				(i)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			this->nmeChildren[index] = child;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
			if (((orig < index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				while(((i < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
					(i)++;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",39)
				this->nmeChildren[index] = child;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",40)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,addChildAt,return )

bool DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint( ::neash::geom::Point point){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",45)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,areInaccessibleObjectsUnderPoint,return )

bool DisplayObjectContainer_obj::contains( ::neash::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::contains")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",52)
	if (((child == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",53)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",55)
	if (((hx::ObjectPtr<OBJ_>(this) == child))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",56)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",58)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",58)
		int _g = (int)0;
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",58)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",58)
			::neash::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",58)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",59)
			if (((c == child))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",60)
				return true;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",62)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,contains,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildAt( int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",68)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",69)
		return this->nmeChildren->__get(index);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",72)
	hx::Throw (::neash::errors::RangeError_obj::__new((((HX_CSTRING("getChildAt : index out of bounds ") + index) + HX_CSTRING("/")) + this->nmeChildren->length)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",74)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildAt,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::getChildByName( ::String name){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildByName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",80)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",80)
		int _g = (int)0;
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",80)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",80)
			::neash::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",80)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",81)
			if (((name == c->nmeGetName()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",82)
				return c;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",83)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildByName,return )

int DisplayObjectContainer_obj::getChildIndex( ::neash::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",88)
	return this->nmeGetChildIndex(child);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildIndex,return )

Array< ::neash::display::DisplayObject > DisplayObjectContainer_obj::getObjectsUnderPoint( ::neash::geom::Point point){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getObjectsUnderPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",95)
	Array< ::neash::display::DisplayObject > result = Array_obj< ::neash::display::DisplayObject >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",96)
	this->nmeGetObjectsUnderPoint(point,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",97)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getObjectsUnderPoint,return )

Void DisplayObjectContainer_obj::nmeAddChild( ::neash::display::DisplayObject child){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeAddChild")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",103)
		if (((child == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",104)
			hx::Throw (HX_CSTRING("Adding to self"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",108)
		if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",109)
			this->setChildIndex(child,(this->nmeChildren->length - (int)1));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",114)
			child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",115)
			this->nmeChildren->push(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",116)
			::neash::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeAddChild,(void))

Void DisplayObjectContainer_obj::nmeBroadcast( ::neash::events::Event inEvt){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeBroadcast")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",123)
		int i = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",125)
		if (((this->nmeChildren->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",126)
			while((true)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",128)
				::neash::display::DisplayObject child = this->nmeChildren->__get(i);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",129)
				child->nmeBroadcast(inEvt);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",131)
				if (((i >= this->nmeChildren->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",132)
					break;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",134)
				if (((this->nmeChildren->__get(i) == child))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",136)
					(i)++;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",137)
					if (((i >= this->nmeChildren->length))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",138)
						break;
					}
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",142)
		this->super::nmeBroadcast(inEvt);
	}
return null();
}


::neash::display::DisplayObject DisplayObjectContainer_obj::nmeFindByID( int inID){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeFindByID")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",148)
	if (((this->nmeID == inID))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",149)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",151)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",151)
		int _g = (int)0;
		Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",151)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",151)
			::neash::display::DisplayObject child = _g1->__get(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",151)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",153)
			::neash::display::DisplayObject found = child->nmeFindByID(inID);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",155)
			if (((found != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",156)
				return found;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",159)
	return this->super::nmeFindByID(inID);
}


int DisplayObjectContainer_obj::nmeGetChildIndex( ::neash::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetChildIndex")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",165)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",165)
		int _g1 = (int)0;
		int _g = this->nmeChildren->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",165)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",165)
			int i = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",166)
			if (((this->nmeChildren->__get(i) == child))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",167)
				return i;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",168)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeGetChildIndex,return )

Void DisplayObjectContainer_obj::nmeGetObjectsUnderPoint( ::neash::geom::Point point,Array< ::neash::display::DisplayObject > result){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetObjectsUnderPoint")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",174)
		this->super::nmeGetObjectsUnderPoint(point,result);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",176)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",176)
			int _g = (int)0;
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",176)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",176)
				::neash::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",176)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",177)
				child->nmeGetObjectsUnderPoint(point,result);
			}
		}
	}
return null();
}


Void DisplayObjectContainer_obj::nmeOnAdded( ::neash::display::DisplayObject inObj,bool inIsOnStage){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnAdded")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",183)
		this->super::nmeOnAdded(inObj,inIsOnStage);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",185)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",185)
			int _g = (int)0;
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",185)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",185)
				::neash::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",185)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",186)
				child->nmeOnAdded(inObj,inIsOnStage);
			}
		}
	}
return null();
}


Void DisplayObjectContainer_obj::nmeOnRemoved( ::neash::display::DisplayObject inObj,bool inWasOnStage){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnRemoved")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",192)
		this->super::nmeOnRemoved(inObj,inWasOnStage);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",194)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",194)
			int _g = (int)0;
			Array< ::neash::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",194)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",194)
				::neash::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",194)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",195)
				child->nmeOnRemoved(inObj,inWasOnStage);
			}
		}
	}
return null();
}


Void DisplayObjectContainer_obj::nmeRemoveChildFromArray( ::neash::display::DisplayObject child){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeRemoveChildFromArray")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",201)
		int i = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",203)
		if (((i >= (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",205)
			::neash::display::DisplayObjectContainer_obj::nme_doc_remove_child(this->nmeHandle,i);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",206)
			this->nmeChildren->splice(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeRemoveChildFromArray,(void))

Void DisplayObjectContainer_obj::nmeSetChildIndex( ::neash::display::DisplayObject child,int index){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetChildIndex")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",213)
		if (((index > this->nmeChildren->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",214)
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",216)
		::neash::display::DisplayObject s = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",217)
		int orig = this->nmeGetChildIndex(child);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",219)
		if (((orig < (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",221)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",223)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",225)
				int realindex = (int)-1;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",227)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",227)
					int _g1 = (int)0;
					int _g = this->nmeChildren->length;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",227)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",227)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",229)
						if (((this->nmeChildren->__get(i) == child))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",231)
							realindex = i;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",232)
							break;
						}
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",236)
				if (((realindex != (int)-1))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",237)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",239)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",242)
			hx::Throw (msg);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",245)
		::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",247)
		if (((index < orig))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",249)
			int i = orig;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",251)
			while(((i > index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",253)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",254)
				(i)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",257)
			this->nmeChildren[index] = child;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",260)
			if (((orig < index))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",262)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",263)
				while(((i < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",265)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",266)
					(i)++;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",269)
				this->nmeChildren[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSetChildIndex,(void))

Void DisplayObjectContainer_obj::nmeSwapChildrenAt( int index1,int index2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSwapChildrenAt")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",276)
		if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",277)
			hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",279)
		if (((index1 != index2))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",281)
			::neash::display::DisplayObject tmp = this->nmeChildren->__get(index1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",282)
			this->nmeChildren[index1] = this->nmeChildren->__get(index2);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",283)
			this->nmeChildren[index2] = tmp;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",284)
			::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeSwapChildrenAt,(void))

::neash::display::DisplayObject DisplayObjectContainer_obj::removeChild( ::neash::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChild")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",291)
	int c = this->nmeGetChildIndex(child);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",293)
	if (((c >= (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",295)
		child->nmeSetParent(null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",296)
		return child;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",299)
	hx::Throw (::neash::errors::ArgumentError_obj::__new(HX_CSTRING("The supplied DisplayObject must be a child of the caller."),null()));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",299)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChild,return )

::neash::display::DisplayObject DisplayObjectContainer_obj::removeChildAt( int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChildAt")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",305)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",307)
		::neash::display::DisplayObject result = this->nmeChildren->__get(index);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",308)
		result->nmeSetParent(null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",309)
		return result;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",312)
	hx::Throw (::neash::errors::ArgumentError_obj::__new(HX_CSTRING("The supplied DisplayObject must be a child of the caller."),null()));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",312)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChildAt,return )

Void DisplayObjectContainer_obj::setChildIndex( ::neash::display::DisplayObject child,int index){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::setChildIndex")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",317)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			if (((index > this->nmeChildren->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				hx::Throw ((HX_CSTRING("Invalid index position ") + index));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			::neash::display::DisplayObject s = null();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			int orig = this->nmeGetChildIndex(child);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			if (((orig < (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					int realindex = (int)-1;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						int _g1 = (int)0;
						int _g = this->nmeChildren->length;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						while(((_g1 < _g))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
							int i = (_g1)++;
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
							if (((this->nmeChildren->__get(i) == child))){
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
								realindex = i;
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
								break;
							}
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					if (((realindex != (int)-1))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				hx::Throw (msg);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			::neash::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
			if (((index < orig))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				int i = orig;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				while(((i > index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					(i)--;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				this->nmeChildren[index] = child;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
				if (((orig < index))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					int i = orig;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					while(((i < index))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
						(i)++;
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",318)
					this->nmeChildren[index] = child;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,setChildIndex,(void))

Void DisplayObjectContainer_obj::swapChildren( ::neash::display::DisplayObject child1,::neash::display::DisplayObject child2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildren")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",324)
		int idx1 = this->nmeGetChildIndex(child1);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",325)
		int idx2 = this->nmeGetChildIndex(child2);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",326)
		if (((bool((idx1 < (int)0)) || bool((idx2 < (int)0))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",327)
			hx::Throw (HX_CSTRING("swapChildren:Could not find children"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
			if (((bool((bool((bool((idx1 < (int)0)) || bool((idx2 < (int)0)))) || bool((idx1 > this->nmeChildren->length)))) || bool((idx2 > this->nmeChildren->length))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
				hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
			if (((idx1 != idx2))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
				::neash::display::DisplayObject tmp = this->nmeChildren->__get(idx1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
				this->nmeChildren[idx1] = this->nmeChildren->__get(idx2);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
				this->nmeChildren[idx2] = tmp;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",328)
				::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,idx1,idx2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildren,(void))

Void DisplayObjectContainer_obj::swapChildrenAt( int index1,int index2){
{
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildrenAt")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",333)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
			if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
				hx::Throw (::neash::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
			if (((index1 != index2))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
				::neash::display::DisplayObject tmp = this->nmeChildren->__get(index1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
				this->nmeChildren[index1] = this->nmeChildren->__get(index2);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
				this->nmeChildren[index2] = tmp;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",334)
				::neash::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildrenAt,(void))

bool DisplayObjectContainer_obj::nmeGetMouseChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetMouseChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",343)
	return ::neash::display::DisplayObjectContainer_obj::nme_doc_get_mouse_children(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetMouseChildren,return )

bool DisplayObjectContainer_obj::nmeSetMouseChildren( bool inVal){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetMouseChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",346)
	::neash::display::DisplayObjectContainer_obj::nme_doc_set_mouse_children(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",347)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetMouseChildren,return )

int DisplayObjectContainer_obj::nmeGetNumChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetNumChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",351)
	return this->nmeChildren->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetNumChildren,return )

bool DisplayObjectContainer_obj::nmeGetTabChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetTabChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",352)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetTabChildren,return )

bool DisplayObjectContainer_obj::nmeSetTabChildren( bool inValue){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetTabChildren")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObjectContainer.hx",353)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetTabChildren,return )

Dynamic DisplayObjectContainer_obj::nme_create_display_object_container;

Dynamic DisplayObjectContainer_obj::nme_doc_add_child;

Dynamic DisplayObjectContainer_obj::nme_doc_remove_child;

Dynamic DisplayObjectContainer_obj::nme_doc_set_child_index;

Dynamic DisplayObjectContainer_obj::nme_doc_get_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_set_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_swap_children;


DisplayObjectContainer_obj::DisplayObjectContainer_obj()
{
}

void DisplayObjectContainer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObjectContainer);
	HX_MARK_MEMBER_NAME(mouseChildren,"mouseChildren");
	HX_MARK_MEMBER_NAME(numChildren,"numChildren");
	HX_MARK_MEMBER_NAME(tabChildren,"tabChildren");
	HX_MARK_MEMBER_NAME(nmeChildren,"nmeChildren");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic DisplayObjectContainer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addChildAt") ) { return addChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildAt") ) { return getChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { return inCallProp ? nmeGetNumChildren() : numChildren; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return inCallProp ? nmeGetTabChildren() : tabChildren; }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { return nmeChildren; }
		if (HX_FIELD_EQ(inName,"nmeAddChild") ) { return nmeAddChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildren") ) { return swapChildren_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return inCallProp ? nmeGetMouseChildren() : mouseChildren; }
		if (HX_FIELD_EQ(inName,"getChildIndex") ) { return getChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChildAt") ) { return removeChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"setChildIndex") ) { return setChildIndex_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getChildByName") ) { return getChildByName_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildrenAt") ) { return swapChildrenAt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeGetChildIndex") ) { return nmeGetChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetChildIndex") ) { return nmeSetChildIndex_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { return nme_doc_add_child; }
		if (HX_FIELD_EQ(inName,"nmeSwapChildrenAt") ) { return nmeSwapChildrenAt_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumChildren") ) { return nmeGetNumChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTabChildren") ) { return nmeGetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTabChildren") ) { return nmeSetTabChildren_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetMouseChildren") ) { return nmeGetMouseChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMouseChildren") ) { return nmeSetMouseChildren_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { return nme_doc_remove_child; }
		if (HX_FIELD_EQ(inName,"getObjectsUnderPoint") ) { return getObjectsUnderPoint_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { return nme_doc_swap_children; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { return nme_doc_set_child_index; }
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeRemoveChildFromArray") ) { return nmeRemoveChildFromArray_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { return nme_doc_get_mouse_children; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { return nme_doc_set_mouse_children; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"areInaccessibleObjectsUnderPoint") ) { return areInaccessibleObjectsUnderPoint_dyn(); }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { return nme_create_display_object_container; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObjectContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { numChildren=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { if (inCallProp) return nmeSetTabChildren(inValue);tabChildren=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { nmeChildren=inValue.Cast< Array< ::neash::display::DisplayObject > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { if (inCallProp) return nmeSetMouseChildren(inValue);mouseChildren=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { nme_doc_add_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { nme_doc_remove_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { nme_doc_swap_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { nme_doc_set_child_index=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { nme_doc_get_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { nme_doc_set_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { nme_create_display_object_container=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObjectContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouseChildren"));
	outFields->push(HX_CSTRING("numChildren"));
	outFields->push(HX_CSTRING("tabChildren"));
	outFields->push(HX_CSTRING("nmeChildren"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_create_display_object_container"),
	HX_CSTRING("nme_doc_add_child"),
	HX_CSTRING("nme_doc_remove_child"),
	HX_CSTRING("nme_doc_set_child_index"),
	HX_CSTRING("nme_doc_get_mouse_children"),
	HX_CSTRING("nme_doc_set_mouse_children"),
	HX_CSTRING("nme_doc_swap_children"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseChildren"),
	HX_CSTRING("numChildren"),
	HX_CSTRING("tabChildren"),
	HX_CSTRING("nmeChildren"),
	HX_CSTRING("addChild"),
	HX_CSTRING("addChildAt"),
	HX_CSTRING("areInaccessibleObjectsUnderPoint"),
	HX_CSTRING("contains"),
	HX_CSTRING("getChildAt"),
	HX_CSTRING("getChildByName"),
	HX_CSTRING("getChildIndex"),
	HX_CSTRING("getObjectsUnderPoint"),
	HX_CSTRING("nmeAddChild"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeGetChildIndex"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("nmeRemoveChildFromArray"),
	HX_CSTRING("nmeSetChildIndex"),
	HX_CSTRING("nmeSwapChildrenAt"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("removeChildAt"),
	HX_CSTRING("setChildIndex"),
	HX_CSTRING("swapChildren"),
	HX_CSTRING("swapChildrenAt"),
	HX_CSTRING("nmeGetMouseChildren"),
	HX_CSTRING("nmeSetMouseChildren"),
	HX_CSTRING("nmeGetNumChildren"),
	HX_CSTRING("nmeGetTabChildren"),
	HX_CSTRING("nmeSetTabChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_create_display_object_container,"nme_create_display_object_container");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_add_child,"nme_doc_add_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_remove_child,"nme_doc_remove_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_child_index,"nme_doc_set_child_index");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_get_mouse_children,"nme_doc_get_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_mouse_children,"nme_doc_set_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_swap_children,"nme_doc_swap_children");
};

Class DisplayObjectContainer_obj::__mClass;

void DisplayObjectContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.DisplayObjectContainer"), hx::TCanCast< DisplayObjectContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObjectContainer_obj::__boot()
{
	hx::Static(nme_create_display_object_container) = ::neash::Loader_obj::load(HX_CSTRING("nme_create_display_object_container"),(int)0);
	hx::Static(nme_doc_add_child) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_add_child"),(int)2);
	hx::Static(nme_doc_remove_child) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_remove_child"),(int)2);
	hx::Static(nme_doc_set_child_index) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_set_child_index"),(int)3);
	hx::Static(nme_doc_get_mouse_children) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_get_mouse_children"),(int)1);
	hx::Static(nme_doc_set_mouse_children) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_set_mouse_children"),(int)2);
	hx::Static(nme_doc_swap_children) = ::neash::Loader_obj::load(HX_CSTRING("nme_doc_swap_children"),(int)3);
}

} // end namespace neash
} // end namespace display
