#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_BlendMode
#include <neash/display/BlendMode.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_neash_geom_Transform
#include <neash/geom/Transform.h>
#endif
namespace neash{
namespace display{

Void DisplayObject_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",172)
	super::__construct(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",174)
	this->nmeParent = null();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",175)
	this->nmeHandle = inHandle;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",176)
	this->nmeID = ::neash::display::DisplayObject_obj::nme_display_object_get_id(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",177)
	this->nmeSetName(((inType + HX_CSTRING(" ")) + this->nmeID));
}
;
	return null();
}

DisplayObject_obj::~DisplayObject_obj() { }

Dynamic DisplayObject_obj::__CreateEmpty() { return  new DisplayObject_obj; }
hx::ObjectPtr< DisplayObject_obj > DisplayObject_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic DisplayObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *DisplayObject_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::neash::display::IBitmapDrawable_obj)) return operator ::neash::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

bool DisplayObject_obj::dispatchEvent( ::neash::events::Event event){
	HX_SOURCE_PUSH("DisplayObject_obj::dispatchEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",183)
	bool result = this->nmeDispatchEvent(event);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",185)
	if ((event->nmeGetIsCancelled())){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",186)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",188)
	if (((bool(event->nmeGetBubbles()) && bool((this->nmeGetParent() != null()))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",189)
		this->nmeGetParent()->dispatchEvent(event);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",193)
	return result;
}


::neash::geom::Point DisplayObject_obj::globalToLocal( ::neash::geom::Point inGlobal){
	HX_SOURCE_PUSH("DisplayObject_obj::globalToLocal")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",204)
	::neash::geom::Point result = inGlobal->clone();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",205)
	::neash::display::DisplayObject_obj::nme_display_object_global_to_local(this->nmeHandle,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",206)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,globalToLocal,return )

bool DisplayObject_obj::hitTestPoint( double x,double y,hx::Null< bool >  __o_shapeFlag){
bool shapeFlag = __o_shapeFlag.Default(false);
	HX_SOURCE_PUSH("DisplayObject_obj::hitTestPoint");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",222)
		return ::neash::display::DisplayObject_obj::nme_display_object_hit_test_point(this->nmeHandle,x,y,shapeFlag,true);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,hitTestPoint,return )

::neash::geom::Point DisplayObject_obj::localToGlobal( ::neash::geom::Point inLocal){
	HX_SOURCE_PUSH("DisplayObject_obj::localToGlobal")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",234)
	::neash::geom::Point result = inLocal->clone();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",235)
	::neash::display::DisplayObject_obj::nme_display_object_local_to_global(this->nmeHandle,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",236)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,localToGlobal,return )

::neash::display::InteractiveObject DisplayObject_obj::nmeAsInteractiveObject( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeAsInteractiveObject")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",241)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeAsInteractiveObject,return )

Void DisplayObject_obj::nmeBroadcast( ::neash::events::Event inEvt){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeBroadcast")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",247)
		this->nmeDispatchEvent(inEvt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeBroadcast,(void))

bool DisplayObject_obj::nmeDispatchEvent( ::neash::events::Event inEvt){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeDispatchEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",254)
	if (((inEvt->nmeGetTarget() == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",255)
		inEvt->nmeSetTarget(hx::ObjectPtr<OBJ_>(this));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",258)
	inEvt->nmeSetCurrentTarget(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",259)
	return this->super::dispatchEvent(inEvt);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeDispatchEvent,return )

Void DisplayObject_obj::nmeDrawToSurface( Dynamic inSurface,::neash::geom::Matrix matrix,::neash::geom::ColorTransform colorTransform,::String blendMode,::neash::geom::Rectangle clipRect,bool smoothing){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeDrawToSurface")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",264)
		::neash::display::DisplayObject_obj::nme_display_object_draw_to_surface(this->nmeHandle,inSurface,matrix,colorTransform,blendMode,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(DisplayObject_obj,nmeDrawToSurface,(void))

::neash::display::DisplayObject DisplayObject_obj::nmeFindByID( int inID){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeFindByID")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",272)
	if (((this->nmeID == inID))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",273)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",274)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeFindByID,return )

Void DisplayObject_obj::nmeFireEvent( ::neash::events::Event inEvt){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeFireEvent")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",280)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",282)
		if (((this->nmeParent != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",283)
			this->nmeParent->nmeGetInteractiveObjectStack(stack);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",285)
		int l = stack->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",287)
		if (((l > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",290)
			inEvt->nmeSetPhase(::neash::events::EventPhase_obj::CAPTURING_PHASE);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",291)
			stack->reverse();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",293)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",293)
				int _g = (int)0;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",293)
				while(((_g < stack->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",293)
					::neash::display::InteractiveObject obj = stack->__get(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",293)
					++(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",295)
					inEvt->nmeSetCurrentTarget(obj);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",296)
					obj->nmeDispatchEvent(inEvt);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",298)
					if ((inEvt->nmeGetIsCancelled())){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",299)
						return null();
					}
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",305)
		inEvt->nmeSetPhase(::neash::events::EventPhase_obj::AT_TARGET);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",306)
		inEvt->nmeSetCurrentTarget(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",307)
		this->nmeDispatchEvent(inEvt);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",309)
		if ((inEvt->nmeGetIsCancelled())){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",310)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",313)
		if ((inEvt->nmeGetBubbles())){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",315)
			inEvt->nmeSetPhase(::neash::events::EventPhase_obj::BUBBLING_PHASE);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",316)
			stack->reverse();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",318)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",318)
				int _g = (int)0;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",318)
				while(((_g < stack->length))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",318)
					::neash::display::InteractiveObject obj = stack->__get(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",318)
					++(_g);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",320)
					inEvt->nmeSetCurrentTarget(obj);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",321)
					obj->nmeDispatchEvent(inEvt);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",323)
					if ((inEvt->nmeGetIsCancelled())){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",324)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeFireEvent,(void))

::neash::geom::ColorTransform DisplayObject_obj::nmeGetColorTransform( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetColorTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",332)
	::neash::geom::ColorTransform trans = ::neash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",333)
	::neash::display::DisplayObject_obj::nme_display_object_get_color_transform(this->nmeHandle,trans,false);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",334)
	return trans;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetColorTransform,return )

::neash::geom::ColorTransform DisplayObject_obj::nmeGetConcatenatedColorTransform( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetConcatenatedColorTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",340)
	::neash::geom::ColorTransform trans = ::neash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",341)
	::neash::display::DisplayObject_obj::nme_display_object_get_color_transform(this->nmeHandle,trans,true);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",342)
	return trans;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetConcatenatedColorTransform,return )

::neash::geom::Matrix DisplayObject_obj::nmeGetConcatenatedMatrix( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetConcatenatedMatrix")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",348)
	::neash::geom::Matrix mtx = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",349)
	::neash::display::DisplayObject_obj::nme_display_object_get_matrix(this->nmeHandle,mtx,true);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",350)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetConcatenatedMatrix,return )

Void DisplayObject_obj::nmeGetInteractiveObjectStack( Array< ::neash::display::InteractiveObject > outStack){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeGetInteractiveObjectStack")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",356)
		::neash::display::InteractiveObject io = this->nmeAsInteractiveObject();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",358)
		if (((io != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",359)
			outStack->push(io);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",361)
		if (((this->nmeParent != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",362)
			this->nmeParent->nmeGetInteractiveObjectStack(outStack);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeGetInteractiveObjectStack,(void))

::neash::geom::Matrix DisplayObject_obj::nmeGetMatrix( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetMatrix")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",368)
	::neash::geom::Matrix mtx = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",369)
	::neash::display::DisplayObject_obj::nme_display_object_get_matrix(this->nmeHandle,mtx,false);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",370)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMatrix,return )

Void DisplayObject_obj::nmeGetObjectsUnderPoint( ::neash::geom::Point point,Array< ::neash::display::DisplayObject > result){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeGetObjectsUnderPoint")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",375)
		if ((::neash::display::DisplayObject_obj::nme_display_object_hit_test_point(this->nmeHandle,point->x,point->y,true,false))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",377)
			result->push(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeGetObjectsUnderPoint,(void))

::neash::geom::Rectangle DisplayObject_obj::nmeGetPixelBounds( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetPixelBounds")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",383)
	::neash::geom::Rectangle rect = ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",384)
	::neash::display::DisplayObject_obj::nme_display_object_get_pixel_bounds(this->nmeHandle,rect);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",385)
	return rect;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetPixelBounds,return )

Void DisplayObject_obj::nmeOnAdded( ::neash::display::DisplayObject inObj,bool inIsOnStage){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeOnAdded")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",391)
		if (((inObj == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",393)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED,true,false);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",394)
			evt->nmeSetTarget(inObj);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",395)
			this->dispatchEvent(evt);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",398)
		if ((inIsOnStage)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",400)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::ADDED_TO_STAGE,false,false);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",401)
			evt->nmeSetTarget(inObj);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",402)
			this->dispatchEvent(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeOnAdded,(void))

Void DisplayObject_obj::nmeOnRemoved( ::neash::display::DisplayObject inObj,bool inWasOnStage){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeOnRemoved")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",409)
		if (((inObj == hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",411)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED,true,false);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",412)
			evt->nmeSetTarget(inObj);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",413)
			this->dispatchEvent(evt);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",416)
		if ((inWasOnStage)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",418)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::REMOVED_FROM_STAGE,false,false);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",419)
			evt->nmeSetTarget(inObj);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",420)
			this->dispatchEvent(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,nmeOnRemoved,(void))

Void DisplayObject_obj::nmeSetColorTransform( ::neash::geom::ColorTransform inTrans){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeSetColorTransform")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",426)
		::neash::display::DisplayObject_obj::nme_display_object_set_color_transform(this->nmeHandle,inTrans);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetColorTransform,(void))

Void DisplayObject_obj::nmeSetMatrix( ::neash::geom::Matrix inMatrix){
{
		HX_SOURCE_PUSH("DisplayObject_obj::nmeSetMatrix")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",432)
		::neash::display::DisplayObject_obj::nme_display_object_set_matrix(this->nmeHandle,inMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetMatrix,(void))

::String DisplayObject_obj::toString( ){
	HX_SOURCE_PUSH("DisplayObject_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",441)
	return this->nmeGetName();
}


double DisplayObject_obj::nmeGetAlpha( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetAlpha")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",451)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_alpha(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetAlpha,return )

double DisplayObject_obj::nmeSetAlpha( double inAlpha){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetAlpha")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",454)
	::neash::display::DisplayObject_obj::nme_display_object_set_alpha(this->nmeHandle,inAlpha);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",455)
	return inAlpha;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetAlpha,return )

Dynamic DisplayObject_obj::nmeGetBG( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetBG")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",461)
	int i = ::neash::display::DisplayObject_obj::nme_display_object_get_bg(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",462)
	if (((((int(i) & int((int)16777216))) == (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",463)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",465)
	return (int(i) & int((int)16777215));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetBG,return )

Dynamic DisplayObject_obj::nmeSetBG( Dynamic inBG){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetBG")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",471)
	if (((inBG == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",472)
		::neash::display::DisplayObject_obj::nme_display_object_set_bg(this->nmeHandle,(int)0);
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",474)
		::neash::display::DisplayObject_obj::nme_display_object_set_bg(this->nmeHandle,inBG);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",476)
	return inBG;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetBG,return )

::neash::display::BlendMode DisplayObject_obj::nmeGetBlendMode( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetBlendMode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",482)
	int i = ::neash::display::DisplayObject_obj::nme_display_object_get_blend_mode(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",483)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::BlendMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetBlendMode,return )

::neash::display::BlendMode DisplayObject_obj::nmeSetBlendMode( ::neash::display::BlendMode inMode){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetBlendMode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",489)
	::neash::display::DisplayObject_obj::nme_display_object_set_blend_mode(this->nmeHandle,inMode->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",490)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetBlendMode,return )

bool DisplayObject_obj::nmeGetCacheAsBitmap( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetCacheAsBitmap")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",494)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_cache_as_bitmap(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetCacheAsBitmap,return )

bool DisplayObject_obj::nmeSetCacheAsBitmap( bool inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetCacheAsBitmap")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",497)
	::neash::display::DisplayObject_obj::nme_display_object_set_cache_as_bitmap(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",498)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetCacheAsBitmap,return )

Dynamic DisplayObject_obj::nmeGetFilters( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetFilters")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",504)
	if (((this->nmeFilters == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",504)
		return Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",506)
	Dynamic result = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",508)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",508)
		int _g = (int)0;
		Dynamic _g1 = this->nmeFilters;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",508)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",508)
			Dynamic filter = _g1->__GetItem(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",508)
			++(_g);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",509)
			result->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",511)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetFilters,return )

Dynamic DisplayObject_obj::nmeSetFilters( Dynamic inFilters){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetFilters")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",517)
	if (((inFilters == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",518)
		this->nmeFilters = null();
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",523)
		this->nmeFilters = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",525)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",525)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",525)
			while(((_g < inFilters->__Field(HX_CSTRING("length"),true)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",525)
				Dynamic filter = inFilters->__GetItem(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",525)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",526)
				this->nmeFilters->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",529)
	::neash::display::DisplayObject_obj::nme_display_object_set_filters(this->nmeHandle,this->nmeFilters);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",531)
	return inFilters;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetFilters,return )

::neash::display::Graphics DisplayObject_obj::nmeGetGraphics( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetGraphics")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",537)
	if (((this->nmeGraphicsCache == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",538)
		this->nmeGraphicsCache = ::neash::display::Graphics_obj::__new(::neash::display::DisplayObject_obj::nme_display_object_get_graphics(this->nmeHandle));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",539)
	return this->nmeGraphicsCache;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetGraphics,return )

double DisplayObject_obj::nmeGetHeight( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetHeight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",543)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetHeight,return )

double DisplayObject_obj::nmeSetHeight( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetHeight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",546)
	::neash::display::DisplayObject_obj::nme_display_object_set_height(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",547)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetHeight,return )

::neash::display::DisplayObject DisplayObject_obj::nmeSetMask( ::neash::display::DisplayObject inObject){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetMask")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",553)
	this->mask = inObject;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",554)
	::neash::display::DisplayObject_obj::nme_display_object_set_mask(this->nmeHandle,(  (((inObject == null()))) ? Dynamic(null()) : Dynamic(inObject->nmeHandle) ));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",555)
	return inObject;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetMask,return )

double DisplayObject_obj::nmeGetMouseX( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetMouseX")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",559)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_mouse_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMouseX,return )

double DisplayObject_obj::nmeGetMouseY( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetMouseY")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",560)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_mouse_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetMouseY,return )

::String DisplayObject_obj::nmeGetName( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",563)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_name(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetName,return )

::String DisplayObject_obj::nmeSetName( ::String inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",566)
	::neash::display::DisplayObject_obj::nme_display_object_set_name(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",567)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetName,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::nmeGetParent( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetParent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",571)
	return this->nmeParent;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetParent,return )

::neash::display::DisplayObjectContainer DisplayObject_obj::nmeSetParent( ::neash::display::DisplayObjectContainer inParent){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetParent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",576)
	if (((inParent == this->nmeParent))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",577)
		return inParent;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",579)
	if (((this->nmeParent != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",580)
		this->nmeParent->nmeRemoveChildFromArray(hx::ObjectPtr<OBJ_>(this));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",582)
	if (((bool((this->nmeParent == null())) && bool((inParent != null()))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",584)
		this->nmeParent = inParent;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",585)
		this->nmeOnAdded(hx::ObjectPtr<OBJ_>(this),(this->nmeGetStage() != null()));
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",587)
		if (((bool((this->nmeParent != null())) && bool((inParent == null()))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",589)
			bool was_on_stage = (this->nmeGetStage() != null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",590)
			this->nmeParent = inParent;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",591)
			this->nmeOnRemoved(hx::ObjectPtr<OBJ_>(this),was_on_stage);
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",594)
			this->nmeParent = inParent;
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",598)
	return inParent;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetParent,return )

double DisplayObject_obj::nmeGetRotation( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetRotation")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",602)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_rotation(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetRotation,return )

double DisplayObject_obj::nmeSetRotation( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetRotation")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",605)
	::neash::display::DisplayObject_obj::nme_display_object_set_rotation(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",606)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetRotation,return )

::neash::geom::Rectangle DisplayObject_obj::nmeGetScale9Grid( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetScale9Grid")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",610)
	return (  (((this->nmeScale9Grid == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(this->nmeScale9Grid->clone()) );
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScale9Grid,return )

::neash::geom::Rectangle DisplayObject_obj::nmeSetScale9Grid( ::neash::geom::Rectangle inRect){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetScale9Grid")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",613)
	this->nmeScale9Grid = (  (((inRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(inRect->clone()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",614)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale9_grid(this->nmeHandle,this->nmeScale9Grid);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",615)
	return inRect;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScale9Grid,return )

double DisplayObject_obj::nmeGetScaleX( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetScaleX")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",619)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_scale_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScaleX,return )

double DisplayObject_obj::nmeSetScaleX( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetScaleX")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",622)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale_x(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",623)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScaleX,return )

double DisplayObject_obj::nmeGetScaleY( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetScaleY")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",627)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_scale_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScaleY,return )

double DisplayObject_obj::nmeSetScaleY( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetScaleY")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",630)
	::neash::display::DisplayObject_obj::nme_display_object_set_scale_y(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",631)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScaleY,return )

::neash::geom::Rectangle DisplayObject_obj::nmeGetScrollRect( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetScrollRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",635)
	return (  (((this->nmeScrollRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(this->nmeScrollRect->clone()) );
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetScrollRect,return )

::neash::geom::Rectangle DisplayObject_obj::nmeSetScrollRect( ::neash::geom::Rectangle inRect){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetScrollRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",638)
	this->nmeScrollRect = (  (((inRect == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(inRect->clone()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",639)
	::neash::display::DisplayObject_obj::nme_display_object_set_scroll_rect(this->nmeHandle,this->nmeScrollRect);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",640)
	return inRect;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetScrollRect,return )

::neash::display::Stage DisplayObject_obj::nmeGetStage( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetStage")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",646)
	if (((this->nmeParent != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",647)
		return this->nmeParent->nmeGetStage();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",649)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetStage,return )

::neash::geom::Transform DisplayObject_obj::nmeGetTransform( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",653)
	return ::neash::geom::Transform_obj::__new(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetTransform,return )

::neash::geom::Transform DisplayObject_obj::nmeSetTransform( ::neash::geom::Transform inTransform){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetTransform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",656)
	this->nmeSetMatrix(inTransform->nmeGetMatrix());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",657)
	this->nmeSetColorTransform(inTransform->nmeGetColorTransform());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",658)
	return inTransform;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetTransform,return )

bool DisplayObject_obj::nmeGetVisible( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetVisible")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",662)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_visible(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetVisible,return )

bool DisplayObject_obj::nmeSetVisible( bool inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetVisible")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",665)
	::neash::display::DisplayObject_obj::nme_display_object_set_visible(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",666)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetVisible,return )

double DisplayObject_obj::nmeGetWidth( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetWidth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",670)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetWidth,return )

double DisplayObject_obj::nmeSetWidth( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetWidth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",673)
	::neash::display::DisplayObject_obj::nme_display_object_set_width(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",674)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetWidth,return )

double DisplayObject_obj::nmeGetX( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetX")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",678)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_x(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetX,return )

double DisplayObject_obj::nmeSetX( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetX")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",681)
	::neash::display::DisplayObject_obj::nme_display_object_set_x(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",682)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetX,return )

double DisplayObject_obj::nmeGetY( ){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeGetY")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",686)
	return ::neash::display::DisplayObject_obj::nme_display_object_get_y(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,nmeGetY,return )

double DisplayObject_obj::nmeSetY( double inVal){
	HX_SOURCE_PUSH("DisplayObject_obj::nmeSetY")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",689)
	::neash::display::DisplayObject_obj::nme_display_object_set_y(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/DisplayObject.hx",690)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,nmeSetY,return )

Dynamic DisplayObject_obj::nme_create_display_object;

Dynamic DisplayObject_obj::nme_display_object_get_graphics;

Dynamic DisplayObject_obj::nme_display_object_draw_to_surface;

Dynamic DisplayObject_obj::nme_display_object_get_id;

Dynamic DisplayObject_obj::nme_display_object_get_x;

Dynamic DisplayObject_obj::nme_display_object_set_x;

Dynamic DisplayObject_obj::nme_display_object_get_y;

Dynamic DisplayObject_obj::nme_display_object_set_y;

Dynamic DisplayObject_obj::nme_display_object_get_scale_x;

Dynamic DisplayObject_obj::nme_display_object_set_scale_x;

Dynamic DisplayObject_obj::nme_display_object_get_scale_y;

Dynamic DisplayObject_obj::nme_display_object_set_scale_y;

Dynamic DisplayObject_obj::nme_display_object_get_mouse_x;

Dynamic DisplayObject_obj::nme_display_object_get_mouse_y;

Dynamic DisplayObject_obj::nme_display_object_get_rotation;

Dynamic DisplayObject_obj::nme_display_object_set_rotation;

Dynamic DisplayObject_obj::nme_display_object_get_bg;

Dynamic DisplayObject_obj::nme_display_object_set_bg;

Dynamic DisplayObject_obj::nme_display_object_get_name;

Dynamic DisplayObject_obj::nme_display_object_set_name;

Dynamic DisplayObject_obj::nme_display_object_get_width;

Dynamic DisplayObject_obj::nme_display_object_set_width;

Dynamic DisplayObject_obj::nme_display_object_get_height;

Dynamic DisplayObject_obj::nme_display_object_set_height;

Dynamic DisplayObject_obj::nme_display_object_get_alpha;

Dynamic DisplayObject_obj::nme_display_object_set_alpha;

Dynamic DisplayObject_obj::nme_display_object_get_blend_mode;

Dynamic DisplayObject_obj::nme_display_object_set_blend_mode;

Dynamic DisplayObject_obj::nme_display_object_get_cache_as_bitmap;

Dynamic DisplayObject_obj::nme_display_object_set_cache_as_bitmap;

Dynamic DisplayObject_obj::nme_display_object_get_visible;

Dynamic DisplayObject_obj::nme_display_object_set_visible;

Dynamic DisplayObject_obj::nme_display_object_set_filters;

Dynamic DisplayObject_obj::nme_display_object_global_to_local;

Dynamic DisplayObject_obj::nme_display_object_local_to_global;

Dynamic DisplayObject_obj::nme_display_object_set_scale9_grid;

Dynamic DisplayObject_obj::nme_display_object_set_scroll_rect;

Dynamic DisplayObject_obj::nme_display_object_set_mask;

Dynamic DisplayObject_obj::nme_display_object_set_matrix;

Dynamic DisplayObject_obj::nme_display_object_get_matrix;

Dynamic DisplayObject_obj::nme_display_object_get_color_transform;

Dynamic DisplayObject_obj::nme_display_object_set_color_transform;

Dynamic DisplayObject_obj::nme_display_object_get_pixel_bounds;

Dynamic DisplayObject_obj::nme_display_object_hit_test_point;


DisplayObject_obj::DisplayObject_obj()
{
}

void DisplayObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObject);
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(blendMode,"blendMode");
	HX_MARK_MEMBER_NAME(cacheAsBitmap,"cacheAsBitmap");
	HX_MARK_MEMBER_NAME(filters,"filters");
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(mask,"mask");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(opaqueBackground,"opaqueBackground");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scale9Grid,"scale9Grid");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(scrollRect,"scrollRect");
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(nmeFilters,"nmeFilters");
	HX_MARK_MEMBER_NAME(nmeGraphicsCache,"nmeGraphicsCache");
	HX_MARK_MEMBER_NAME(nmeID,"nmeID");
	HX_MARK_MEMBER_NAME(nmeParent,"nmeParent");
	HX_MARK_MEMBER_NAME(nmeScale9Grid,"nmeScale9Grid");
	HX_MARK_MEMBER_NAME(nmeScrollRect,"nmeScrollRect");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic DisplayObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return inCallProp ? nmeGetX() : x; }
		if (HX_FIELD_EQ(inName,"y") ) { return inCallProp ? nmeGetY() : y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { return mask; }
		if (HX_FIELD_EQ(inName,"name") ) { return inCallProp ? nmeGetName() : name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return inCallProp ? nmeGetAlpha() : alpha; }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? nmeGetStage() : stage; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? nmeGetWidth() : width; }
		if (HX_FIELD_EQ(inName,"nmeID") ) { return nmeID; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? nmeGetHeight() : height; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return inCallProp ? nmeGetMouseX() : mouseX; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return inCallProp ? nmeGetMouseY() : mouseY; }
		if (HX_FIELD_EQ(inName,"parent") ) { return inCallProp ? nmeGetParent() : parent; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return inCallProp ? nmeGetScaleX() : scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return inCallProp ? nmeGetScaleY() : scaleY; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return inCallProp ? nmeGetFilters() : filters; }
		if (HX_FIELD_EQ(inName,"visible") ) { return inCallProp ? nmeGetVisible() : visible; }
		if (HX_FIELD_EQ(inName,"nmeGetX") ) { return nmeGetX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetX") ) { return nmeSetX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetY") ) { return nmeGetY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetY") ) { return nmeSetY_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { return inCallProp ? nmeGetGraphics() : graphics; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? nmeGetRotation() : rotation; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBG") ) { return nmeGetBG_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBG") ) { return nmeSetBG_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { return inCallProp ? nmeGetBlendMode() : blendMode; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? nmeGetTransform() : transform; }
		if (HX_FIELD_EQ(inName,"nmeParent") ) { return nmeParent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return inCallProp ? nmeGetScale9Grid() : scale9Grid; }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return inCallProp ? nmeGetScrollRect() : scrollRect; }
		if (HX_FIELD_EQ(inName,"nmeFilters") ) { return nmeFilters; }
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMask") ) { return nmeSetMask_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetName") ) { return nmeGetName_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetName") ) { return nmeSetName_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetAlpha") ) { return nmeGetAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAlpha") ) { return nmeSetAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetWidth") ) { return nmeGetWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetWidth") ) { return nmeSetWidth_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hitTestPoint") ) { return hitTestPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFireEvent") ) { return nmeFireEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMatrix") ) { return nmeGetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMatrix") ) { return nmeSetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetHeight") ) { return nmeGetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetHeight") ) { return nmeSetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseX") ) { return nmeGetMouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseY") ) { return nmeGetMouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetParent") ) { return nmeGetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetParent") ) { return nmeSetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleX") ) { return nmeGetScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScaleX") ) { return nmeSetScaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleY") ) { return nmeGetScaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScaleY") ) { return nmeSetScaleY_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return inCallProp ? nmeGetCacheAsBitmap() : cacheAsBitmap; }
		if (HX_FIELD_EQ(inName,"nmeScale9Grid") ) { return nmeScale9Grid; }
		if (HX_FIELD_EQ(inName,"nmeScrollRect") ) { return nmeScrollRect; }
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"globalToLocal") ) { return globalToLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"localToGlobal") ) { return localToGlobal_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetFilters") ) { return nmeGetFilters_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFilters") ) { return nmeSetFilters_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetVisible") ) { return nmeGetVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetVisible") ) { return nmeSetVisible_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeGetGraphics") ) { return nmeGetGraphics_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetRotation") ) { return nmeGetRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetRotation") ) { return nmeSetRotation_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeGetBlendMode") ) { return nmeGetBlendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBlendMode") ) { return nmeSetBlendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTransform") ) { return nmeGetTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTransform") ) { return nmeSetTransform_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return inCallProp ? nmeGetBG() : opaqueBackground; }
		if (HX_FIELD_EQ(inName,"nmeGraphicsCache") ) { return nmeGraphicsCache; }
		if (HX_FIELD_EQ(inName,"nmeDispatchEvent") ) { return nmeDispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeDrawToSurface") ) { return nmeDrawToSurface_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScale9Grid") ) { return nmeGetScale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScale9Grid") ) { return nmeSetScale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScrollRect") ) { return nmeGetScrollRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScrollRect") ) { return nmeSetScrollRect_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetPixelBounds") ) { return nmeGetPixelBounds_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetCacheAsBitmap") ) { return nmeGetCacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetCacheAsBitmap") ) { return nmeSetCacheAsBitmap_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeGetColorTransform") ) { return nmeGetColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetColorTransform") ) { return nmeSetColorTransform_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeAsInteractiveObject") ) { return nmeAsInteractiveObject_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_x") ) { return nme_display_object_get_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_x") ) { return nme_display_object_set_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_y") ) { return nme_display_object_get_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_y") ) { return nme_display_object_set_y; }
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedMatrix") ) { return nmeGetConcatenatedMatrix_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_create_display_object") ) { return nme_create_display_object; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_id") ) { return nme_display_object_get_id; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bg") ) { return nme_display_object_get_bg; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_bg") ) { return nme_display_object_set_bg; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_name") ) { return nme_display_object_get_name; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_name") ) { return nme_display_object_set_name; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mask") ) { return nme_display_object_set_mask; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_width") ) { return nme_display_object_get_width; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_width") ) { return nme_display_object_set_width; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_alpha") ) { return nme_display_object_get_alpha; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_alpha") ) { return nme_display_object_set_alpha; }
		if (HX_FIELD_EQ(inName,"nmeGetInteractiveObjectStack") ) { return nmeGetInteractiveObjectStack_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_height") ) { return nme_display_object_get_height; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_height") ) { return nme_display_object_set_height; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_matrix") ) { return nme_display_object_set_matrix; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_matrix") ) { return nme_display_object_get_matrix; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_x") ) { return nme_display_object_get_scale_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_x") ) { return nme_display_object_set_scale_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_y") ) { return nme_display_object_get_scale_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_y") ) { return nme_display_object_set_scale_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_x") ) { return nme_display_object_get_mouse_x; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_y") ) { return nme_display_object_get_mouse_y; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_visible") ) { return nme_display_object_get_visible; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_visible") ) { return nme_display_object_set_visible; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_filters") ) { return nme_display_object_set_filters; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_graphics") ) { return nme_display_object_get_graphics; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_rotation") ) { return nme_display_object_get_rotation; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_rotation") ) { return nme_display_object_set_rotation; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedColorTransform") ) { return nmeGetConcatenatedColorTransform_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_blend_mode") ) { return nme_display_object_get_blend_mode; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_blend_mode") ) { return nme_display_object_set_blend_mode; }
		if (HX_FIELD_EQ(inName,"nme_display_object_hit_test_point") ) { return nme_display_object_hit_test_point; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_display_object_draw_to_surface") ) { return nme_display_object_draw_to_surface; }
		if (HX_FIELD_EQ(inName,"nme_display_object_global_to_local") ) { return nme_display_object_global_to_local; }
		if (HX_FIELD_EQ(inName,"nme_display_object_local_to_global") ) { return nme_display_object_local_to_global; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale9_grid") ) { return nme_display_object_set_scale9_grid; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scroll_rect") ) { return nme_display_object_set_scroll_rect; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_bounds") ) { return nme_display_object_get_pixel_bounds; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_cache_as_bitmap") ) { return nme_display_object_get_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_cache_as_bitmap") ) { return nme_display_object_set_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_color_transform") ) { return nme_display_object_get_color_transform; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_color_transform") ) { return nme_display_object_set_color_transform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { if (inCallProp) return nmeSetX(inValue);x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { if (inCallProp) return nmeSetY(inValue);y=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { if (inCallProp) return nmeSetMask(inValue);mask=inValue.Cast< ::neash::display::DisplayObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp) return nmeSetName(inValue);name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return nmeSetAlpha(inValue);alpha=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::neash::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return nmeSetWidth(inValue);width=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeID") ) { nmeID=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return nmeSetHeight(inValue);height=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { if (inCallProp) return nmeSetScaleX(inValue);scaleX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { if (inCallProp) return nmeSetScaleY(inValue);scaleY=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { if (inCallProp) return nmeSetFilters(inValue);filters=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visible") ) { if (inCallProp) return nmeSetVisible(inValue);visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { if (inCallProp) return nmeSetRotation(inValue);rotation=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { if (inCallProp) return nmeSetBlendMode(inValue);blendMode=inValue.Cast< ::neash::display::BlendMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { if (inCallProp) return nmeSetTransform(inValue);transform=inValue.Cast< ::neash::geom::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeParent") ) { nmeParent=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { if (inCallProp) return nmeSetScale9Grid(inValue);scale9Grid=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { if (inCallProp) return nmeSetScrollRect(inValue);scrollRect=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFilters") ) { nmeFilters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { if (inCallProp) return nmeSetCacheAsBitmap(inValue);cacheAsBitmap=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeScale9Grid") ) { nmeScale9Grid=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeScrollRect") ) { nmeScrollRect=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { if (inCallProp) return nmeSetBG(inValue);opaqueBackground=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeGraphicsCache") ) { nmeGraphicsCache=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_x") ) { nme_display_object_get_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_x") ) { nme_display_object_set_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_y") ) { nme_display_object_get_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_y") ) { nme_display_object_set_y=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_create_display_object") ) { nme_create_display_object=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_id") ) { nme_display_object_get_id=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_bg") ) { nme_display_object_get_bg=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_bg") ) { nme_display_object_set_bg=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_name") ) { nme_display_object_get_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_name") ) { nme_display_object_set_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mask") ) { nme_display_object_set_mask=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_width") ) { nme_display_object_get_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_width") ) { nme_display_object_set_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_alpha") ) { nme_display_object_get_alpha=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_alpha") ) { nme_display_object_set_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_height") ) { nme_display_object_get_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_height") ) { nme_display_object_set_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_matrix") ) { nme_display_object_set_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_matrix") ) { nme_display_object_get_matrix=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_x") ) { nme_display_object_get_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_x") ) { nme_display_object_set_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_scale_y") ) { nme_display_object_get_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale_y") ) { nme_display_object_set_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_x") ) { nme_display_object_get_mouse_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_mouse_y") ) { nme_display_object_get_mouse_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_visible") ) { nme_display_object_get_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_visible") ) { nme_display_object_set_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_filters") ) { nme_display_object_set_filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_graphics") ) { nme_display_object_get_graphics=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_rotation") ) { nme_display_object_get_rotation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_rotation") ) { nme_display_object_set_rotation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_blend_mode") ) { nme_display_object_get_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_blend_mode") ) { nme_display_object_set_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_hit_test_point") ) { nme_display_object_hit_test_point=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_display_object_draw_to_surface") ) { nme_display_object_draw_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_global_to_local") ) { nme_display_object_global_to_local=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_local_to_global") ) { nme_display_object_local_to_global=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scale9_grid") ) { nme_display_object_set_scale9_grid=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_scroll_rect") ) { nme_display_object_set_scroll_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_pixel_bounds") ) { nme_display_object_get_pixel_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"nme_display_object_get_cache_as_bitmap") ) { nme_display_object_get_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_cache_as_bitmap") ) { nme_display_object_set_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_color_transform") ) { nme_display_object_get_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_set_color_transform") ) { nme_display_object_set_color_transform=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("blendMode"));
	outFields->push(HX_CSTRING("cacheAsBitmap"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("graphics"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("opaqueBackground"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale9Grid"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scrollRect"));
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("nmeFilters"));
	outFields->push(HX_CSTRING("nmeGraphicsCache"));
	outFields->push(HX_CSTRING("nmeID"));
	outFields->push(HX_CSTRING("nmeParent"));
	outFields->push(HX_CSTRING("nmeScale9Grid"));
	outFields->push(HX_CSTRING("nmeScrollRect"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_create_display_object"),
	HX_CSTRING("nme_display_object_get_graphics"),
	HX_CSTRING("nme_display_object_draw_to_surface"),
	HX_CSTRING("nme_display_object_get_id"),
	HX_CSTRING("nme_display_object_get_x"),
	HX_CSTRING("nme_display_object_set_x"),
	HX_CSTRING("nme_display_object_get_y"),
	HX_CSTRING("nme_display_object_set_y"),
	HX_CSTRING("nme_display_object_get_scale_x"),
	HX_CSTRING("nme_display_object_set_scale_x"),
	HX_CSTRING("nme_display_object_get_scale_y"),
	HX_CSTRING("nme_display_object_set_scale_y"),
	HX_CSTRING("nme_display_object_get_mouse_x"),
	HX_CSTRING("nme_display_object_get_mouse_y"),
	HX_CSTRING("nme_display_object_get_rotation"),
	HX_CSTRING("nme_display_object_set_rotation"),
	HX_CSTRING("nme_display_object_get_bg"),
	HX_CSTRING("nme_display_object_set_bg"),
	HX_CSTRING("nme_display_object_get_name"),
	HX_CSTRING("nme_display_object_set_name"),
	HX_CSTRING("nme_display_object_get_width"),
	HX_CSTRING("nme_display_object_set_width"),
	HX_CSTRING("nme_display_object_get_height"),
	HX_CSTRING("nme_display_object_set_height"),
	HX_CSTRING("nme_display_object_get_alpha"),
	HX_CSTRING("nme_display_object_set_alpha"),
	HX_CSTRING("nme_display_object_get_blend_mode"),
	HX_CSTRING("nme_display_object_set_blend_mode"),
	HX_CSTRING("nme_display_object_get_cache_as_bitmap"),
	HX_CSTRING("nme_display_object_set_cache_as_bitmap"),
	HX_CSTRING("nme_display_object_get_visible"),
	HX_CSTRING("nme_display_object_set_visible"),
	HX_CSTRING("nme_display_object_set_filters"),
	HX_CSTRING("nme_display_object_global_to_local"),
	HX_CSTRING("nme_display_object_local_to_global"),
	HX_CSTRING("nme_display_object_set_scale9_grid"),
	HX_CSTRING("nme_display_object_set_scroll_rect"),
	HX_CSTRING("nme_display_object_set_mask"),
	HX_CSTRING("nme_display_object_set_matrix"),
	HX_CSTRING("nme_display_object_get_matrix"),
	HX_CSTRING("nme_display_object_get_color_transform"),
	HX_CSTRING("nme_display_object_set_color_transform"),
	HX_CSTRING("nme_display_object_get_pixel_bounds"),
	HX_CSTRING("nme_display_object_hit_test_point"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("alpha"),
	HX_CSTRING("blendMode"),
	HX_CSTRING("cacheAsBitmap"),
	HX_CSTRING("filters"),
	HX_CSTRING("graphics"),
	HX_CSTRING("height"),
	HX_CSTRING("mask"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("name"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("opaqueBackground"),
	HX_CSTRING("parent"),
	HX_CSTRING("rotation"),
	HX_CSTRING("scale9Grid"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("scrollRect"),
	HX_CSTRING("stage"),
	HX_CSTRING("transform"),
	HX_CSTRING("visible"),
	HX_CSTRING("width"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("nmeFilters"),
	HX_CSTRING("nmeGraphicsCache"),
	HX_CSTRING("nmeID"),
	HX_CSTRING("nmeParent"),
	HX_CSTRING("nmeScale9Grid"),
	HX_CSTRING("nmeScrollRect"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("globalToLocal"),
	HX_CSTRING("hitTestPoint"),
	HX_CSTRING("localToGlobal"),
	HX_CSTRING("nmeAsInteractiveObject"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeDispatchEvent"),
	HX_CSTRING("nmeDrawToSurface"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeFireEvent"),
	HX_CSTRING("nmeGetColorTransform"),
	HX_CSTRING("nmeGetConcatenatedColorTransform"),
	HX_CSTRING("nmeGetConcatenatedMatrix"),
	HX_CSTRING("nmeGetInteractiveObjectStack"),
	HX_CSTRING("nmeGetMatrix"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("nmeGetPixelBounds"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("nmeSetColorTransform"),
	HX_CSTRING("nmeSetMatrix"),
	HX_CSTRING("toString"),
	HX_CSTRING("nmeGetAlpha"),
	HX_CSTRING("nmeSetAlpha"),
	HX_CSTRING("nmeGetBG"),
	HX_CSTRING("nmeSetBG"),
	HX_CSTRING("nmeGetBlendMode"),
	HX_CSTRING("nmeSetBlendMode"),
	HX_CSTRING("nmeGetCacheAsBitmap"),
	HX_CSTRING("nmeSetCacheAsBitmap"),
	HX_CSTRING("nmeGetFilters"),
	HX_CSTRING("nmeSetFilters"),
	HX_CSTRING("nmeGetGraphics"),
	HX_CSTRING("nmeGetHeight"),
	HX_CSTRING("nmeSetHeight"),
	HX_CSTRING("nmeSetMask"),
	HX_CSTRING("nmeGetMouseX"),
	HX_CSTRING("nmeGetMouseY"),
	HX_CSTRING("nmeGetName"),
	HX_CSTRING("nmeSetName"),
	HX_CSTRING("nmeGetParent"),
	HX_CSTRING("nmeSetParent"),
	HX_CSTRING("nmeGetRotation"),
	HX_CSTRING("nmeSetRotation"),
	HX_CSTRING("nmeGetScale9Grid"),
	HX_CSTRING("nmeSetScale9Grid"),
	HX_CSTRING("nmeGetScaleX"),
	HX_CSTRING("nmeSetScaleX"),
	HX_CSTRING("nmeGetScaleY"),
	HX_CSTRING("nmeSetScaleY"),
	HX_CSTRING("nmeGetScrollRect"),
	HX_CSTRING("nmeSetScrollRect"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("nmeGetTransform"),
	HX_CSTRING("nmeSetTransform"),
	HX_CSTRING("nmeGetVisible"),
	HX_CSTRING("nmeSetVisible"),
	HX_CSTRING("nmeGetWidth"),
	HX_CSTRING("nmeSetWidth"),
	HX_CSTRING("nmeGetX"),
	HX_CSTRING("nmeSetX"),
	HX_CSTRING("nmeGetY"),
	HX_CSTRING("nmeSetY"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_create_display_object,"nme_create_display_object");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_graphics,"nme_display_object_get_graphics");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_draw_to_surface,"nme_display_object_draw_to_surface");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_id,"nme_display_object_get_id");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_x,"nme_display_object_get_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_x,"nme_display_object_set_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_y,"nme_display_object_get_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_y,"nme_display_object_set_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_x,"nme_display_object_get_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_x,"nme_display_object_set_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_scale_y,"nme_display_object_get_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale_y,"nme_display_object_set_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_x,"nme_display_object_get_mouse_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_mouse_y,"nme_display_object_get_mouse_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_rotation,"nme_display_object_get_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_rotation,"nme_display_object_set_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_bg,"nme_display_object_get_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_bg,"nme_display_object_set_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_name,"nme_display_object_get_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_name,"nme_display_object_set_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_width,"nme_display_object_get_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_width,"nme_display_object_set_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_height,"nme_display_object_get_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_height,"nme_display_object_set_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_alpha,"nme_display_object_get_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_alpha,"nme_display_object_set_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_blend_mode,"nme_display_object_get_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_blend_mode,"nme_display_object_set_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_cache_as_bitmap,"nme_display_object_get_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_cache_as_bitmap,"nme_display_object_set_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_visible,"nme_display_object_get_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_visible,"nme_display_object_set_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_filters,"nme_display_object_set_filters");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_global_to_local,"nme_display_object_global_to_local");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_local_to_global,"nme_display_object_local_to_global");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scale9_grid,"nme_display_object_set_scale9_grid");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_scroll_rect,"nme_display_object_set_scroll_rect");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_mask,"nme_display_object_set_mask");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_matrix,"nme_display_object_set_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_matrix,"nme_display_object_get_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_color_transform,"nme_display_object_get_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_set_color_transform,"nme_display_object_set_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_get_pixel_bounds,"nme_display_object_get_pixel_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::nme_display_object_hit_test_point,"nme_display_object_hit_test_point");
};

Class DisplayObject_obj::__mClass;

void DisplayObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.DisplayObject"), hx::TCanCast< DisplayObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObject_obj::__boot()
{
	hx::Static(nme_create_display_object) = ::neash::Loader_obj::load(HX_CSTRING("nme_create_display_object"),(int)0);
	hx::Static(nme_display_object_get_graphics) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_graphics"),(int)1);
	hx::Static(nme_display_object_draw_to_surface) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_draw_to_surface"),(int)-1);
	hx::Static(nme_display_object_get_id) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_id"),(int)1);
	hx::Static(nme_display_object_get_x) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_x"),(int)1);
	hx::Static(nme_display_object_set_x) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_x"),(int)2);
	hx::Static(nme_display_object_get_y) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_y"),(int)1);
	hx::Static(nme_display_object_set_y) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_y"),(int)2);
	hx::Static(nme_display_object_get_scale_x) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_scale_x"),(int)1);
	hx::Static(nme_display_object_set_scale_x) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale_x"),(int)2);
	hx::Static(nme_display_object_get_scale_y) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_scale_y"),(int)1);
	hx::Static(nme_display_object_set_scale_y) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale_y"),(int)2);
	hx::Static(nme_display_object_get_mouse_x) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_mouse_x"),(int)1);
	hx::Static(nme_display_object_get_mouse_y) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_mouse_y"),(int)1);
	hx::Static(nme_display_object_get_rotation) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_rotation"),(int)1);
	hx::Static(nme_display_object_set_rotation) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_rotation"),(int)2);
	hx::Static(nme_display_object_get_bg) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_bg"),(int)1);
	hx::Static(nme_display_object_set_bg) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_bg"),(int)2);
	hx::Static(nme_display_object_get_name) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_name"),(int)1);
	hx::Static(nme_display_object_set_name) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_name"),(int)2);
	hx::Static(nme_display_object_get_width) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_width"),(int)1);
	hx::Static(nme_display_object_set_width) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_width"),(int)2);
	hx::Static(nme_display_object_get_height) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_height"),(int)1);
	hx::Static(nme_display_object_set_height) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_height"),(int)2);
	hx::Static(nme_display_object_get_alpha) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_alpha"),(int)1);
	hx::Static(nme_display_object_set_alpha) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_alpha"),(int)2);
	hx::Static(nme_display_object_get_blend_mode) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_blend_mode"),(int)1);
	hx::Static(nme_display_object_set_blend_mode) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_blend_mode"),(int)2);
	hx::Static(nme_display_object_get_cache_as_bitmap) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_cache_as_bitmap"),(int)1);
	hx::Static(nme_display_object_set_cache_as_bitmap) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_cache_as_bitmap"),(int)2);
	hx::Static(nme_display_object_get_visible) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_visible"),(int)1);
	hx::Static(nme_display_object_set_visible) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_visible"),(int)2);
	hx::Static(nme_display_object_set_filters) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_filters"),(int)2);
	hx::Static(nme_display_object_global_to_local) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_global_to_local"),(int)2);
	hx::Static(nme_display_object_local_to_global) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_local_to_global"),(int)2);
	hx::Static(nme_display_object_set_scale9_grid) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scale9_grid"),(int)2);
	hx::Static(nme_display_object_set_scroll_rect) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_scroll_rect"),(int)2);
	hx::Static(nme_display_object_set_mask) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_mask"),(int)2);
	hx::Static(nme_display_object_set_matrix) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_matrix"),(int)2);
	hx::Static(nme_display_object_get_matrix) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_matrix"),(int)3);
	hx::Static(nme_display_object_get_color_transform) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_color_transform"),(int)3);
	hx::Static(nme_display_object_set_color_transform) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_color_transform"),(int)2);
	hx::Static(nme_display_object_get_pixel_bounds) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_pixel_bounds"),(int)2);
	hx::Static(nme_display_object_hit_test_point) = ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_hit_test_point"),(int)5);
}

} // end namespace neash
} // end namespace display
