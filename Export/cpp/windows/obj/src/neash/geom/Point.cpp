#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace neash{
namespace geom{

Void Point_obj::__construct(hx::Null< double >  __o_inX,hx::Null< double >  __o_inY)
{
double inX = __o_inX.Default(0);
double inY = __o_inY.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",40)
	this->x = inX;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",41)
	this->y = inY;
}
;
	return null();
}

Point_obj::~Point_obj() { }

Dynamic Point_obj::__CreateEmpty() { return  new Point_obj; }
hx::ObjectPtr< Point_obj > Point_obj::__new(hx::Null< double >  __o_inX,hx::Null< double >  __o_inY)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(__o_inX,__o_inY);
	return result;}

Dynamic Point_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::neash::geom::Point Point_obj::add( ::neash::geom::Point v){
	HX_SOURCE_PUSH("Point_obj::add")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",46)
	return ::neash::geom::Point_obj::__new((v->x + this->x),(v->y + this->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,add,return )

::neash::geom::Point Point_obj::clone( ){
	HX_SOURCE_PUSH("Point_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",52)
	return ::neash::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Point_obj,clone,return )

bool Point_obj::equals( ::neash::geom::Point toCompare){
	HX_SOURCE_PUSH("Point_obj::equals")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",66)
	return (bool((toCompare->x == this->x)) && bool((toCompare->y == this->y)));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,equals,return )

Void Point_obj::normalize( double thickness){
{
		HX_SOURCE_PUSH("Point_obj::normalize")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",78)
		if (((bool((this->x == (int)0)) && bool((this->y == (int)0))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",80)
			this->x = thickness;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",83)
			double norm = (double(thickness) / double(::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)))));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",84)
			hx::MultEq(this->x,norm);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",85)
			hx::MultEq(this->y,norm);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,normalize,(void))

Void Point_obj::offset( double dx,double dy){
{
		HX_SOURCE_PUSH("Point_obj::offset")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",92)
		hx::AddEq(this->x,dx);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",93)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Point_obj,offset,(void))

::neash::geom::Point Point_obj::subtract( ::neash::geom::Point v){
	HX_SOURCE_PUSH("Point_obj::subtract")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",104)
	return ::neash::geom::Point_obj::__new((this->x - v->x),(this->y - v->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,subtract,return )

double Point_obj::nmeGetLength( ){
	HX_SOURCE_PUSH("Point_obj::nmeGetLength")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",115)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(Point_obj,nmeGetLength,return )

double Point_obj::distance( ::neash::geom::Point pt1,::neash::geom::Point pt2){
	HX_SOURCE_PUSH("Point_obj::distance")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",59)
	double dx = (pt1->x - pt2->x);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",60)
	double dy = (pt1->y - pt2->y);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",61)
	return ::Math_obj::sqrt(((dx * dx) + (dy * dy)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point_obj,distance,return )

::neash::geom::Point Point_obj::interpolate( ::neash::geom::Point pt1,::neash::geom::Point pt2,double f){
	HX_SOURCE_PUSH("Point_obj::interpolate")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",72)
	return ::neash::geom::Point_obj::__new((pt2->x + (f * ((pt1->x - pt2->x)))),(pt2->y + (f * ((pt1->y - pt2->y)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Point_obj,interpolate,return )

::neash::geom::Point Point_obj::polar( double len,double angle){
	HX_SOURCE_PUSH("Point_obj::polar")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Point.hx",98)
	return ::neash::geom::Point_obj::__new((len * ::Math_obj::cos(angle)),(len * ::Math_obj::sin(angle)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point_obj,polar,return )


Point_obj::Point_obj()
{
}

void Point_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Point);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

Dynamic Point_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"polar") ) { return polar_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? nmeGetLength() : length; }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance_dyn(); }
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interpolate") ) { return interpolate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeGetLength") ) { return nmeGetLength_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Point_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Point_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("distance"),
	HX_CSTRING("interpolate"),
	HX_CSTRING("polar"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("add"),
	HX_CSTRING("clone"),
	HX_CSTRING("equals"),
	HX_CSTRING("normalize"),
	HX_CSTRING("offset"),
	HX_CSTRING("subtract"),
	HX_CSTRING("nmeGetLength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Point_obj::__mClass;

void Point_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Point"), hx::TCanCast< Point_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
