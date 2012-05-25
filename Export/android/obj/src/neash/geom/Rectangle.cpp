#include <hxcpp.h>

#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace neash{
namespace geom{

Void Rectangle_obj::__construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",45)
	this->x = (  (((inX == null()))) ? Dynamic((int)0) : Dynamic(inX) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",46)
	this->y = (  (((inY == null()))) ? Dynamic((int)0) : Dynamic(inY) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",47)
	this->width = (  (((inWidth == null()))) ? Dynamic((int)0) : Dynamic(inWidth) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",48)
	this->height = (  (((inHeight == null()))) ? Dynamic((int)0) : Dynamic(inHeight) );
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inX,inY,inWidth,inHeight);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::neash::geom::Rectangle Rectangle_obj::clone( ){
	HX_SOURCE_PUSH("Rectangle_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",53)
	return ::neash::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )

bool Rectangle_obj::contains( double inX,double inY){
	HX_SOURCE_PUSH("Rectangle_obj::contains")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",59)
	return (bool((bool((bool((inX >= this->x)) && bool((inY >= this->y)))) && bool((inX < this->nmeGetRight())))) && bool((inY < this->nmeGetBottom())));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

bool Rectangle_obj::containsPoint( ::neash::geom::Point point){
	HX_SOURCE_PUSH("Rectangle_obj::containsPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",65)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::containsRect( ::neash::geom::Rectangle rect){
	HX_SOURCE_PUSH("Rectangle_obj::containsRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",71)
	return (bool(this->contains(rect->x,rect->y)) && bool(this->containsPoint(rect->nmeGetBottomRight())));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::equals( ::neash::geom::Rectangle toCompare){
	HX_SOURCE_PUSH("Rectangle_obj::equals")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",77)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

Void Rectangle_obj::extendBounds( ::neash::geom::Rectangle r){
{
		HX_SOURCE_PUSH("Rectangle_obj::extendBounds")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",84)
		double dx = (this->x - r->x);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",85)
		if (((dx > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",87)
			hx::SubEq(this->x,dx);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",88)
			hx::AddEq(this->width,dx);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",90)
		double dy = (this->y - r->y);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",91)
		if (((dy > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",93)
			hx::SubEq(this->y,dy);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",94)
			hx::AddEq(this->height,dy);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",96)
		if (((r->nmeGetRight() > this->nmeGetRight()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",97)
			this->nmeSetRight(r->nmeGetRight());
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",98)
		if (((r->nmeGetBottom() > this->nmeGetBottom()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",99)
			this->nmeSetBottom(r->nmeGetBottom());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))

Void Rectangle_obj::inflate( double dx,double dy){
{
		HX_SOURCE_PUSH("Rectangle_obj::inflate")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",105)
		hx::SubEq(this->x,dx);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",105)
		hx::AddEq(this->width,(dx * (int)2));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",106)
		hx::SubEq(this->y,dy);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",106)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::inflatePoint( ::neash::geom::Point point){
{
		HX_SOURCE_PUSH("Rectangle_obj::inflatePoint")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",111)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

::neash::geom::Rectangle Rectangle_obj::intersection( ::neash::geom::Rectangle toIntersect){
	HX_SOURCE_PUSH("Rectangle_obj::intersection")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",118)
	double x0 = (  (((this->x < toIntersect->x))) ? double(toIntersect->x) : double(this->x) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",119)
	double x1 = (  (((this->nmeGetRight() > toIntersect->nmeGetRight()))) ? double(toIntersect->nmeGetRight()) : double(this->nmeGetRight()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",120)
	if (((x1 <= x0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",121)
		return ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",123)
	double y0 = (  (((this->y < toIntersect->y))) ? double(toIntersect->y) : double(this->y) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",124)
	double y1 = (  (((this->nmeGetBottom() > toIntersect->nmeGetBottom()))) ? double(toIntersect->nmeGetBottom()) : double(this->nmeGetBottom()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",125)
	if (((y1 <= y0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",126)
		return ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",128)
	return ::neash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

bool Rectangle_obj::intersects( ::neash::geom::Rectangle toIntersect){
	HX_SOURCE_PUSH("Rectangle_obj::intersects")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",134)
	double x0 = (  (((this->x < toIntersect->x))) ? double(toIntersect->x) : double(this->x) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",135)
	double x1 = (  (((this->nmeGetRight() > toIntersect->nmeGetRight()))) ? double(toIntersect->nmeGetRight()) : double(this->nmeGetRight()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",136)
	if (((x1 <= x0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",137)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",139)
	double y0 = (  (((this->y < toIntersect->y))) ? double(toIntersect->y) : double(this->y) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",140)
	double y1 = (  (((this->nmeGetBottom() > toIntersect->nmeGetBottom()))) ? double(toIntersect->nmeGetBottom()) : double(this->nmeGetBottom()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",141)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

bool Rectangle_obj::isEmpty( ){
	HX_SOURCE_PUSH("Rectangle_obj::isEmpty")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",146)
	return (bool((this->width == (int)0)) && bool((this->height == (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

Void Rectangle_obj::offset( double dx,double dy){
{
		HX_SOURCE_PUSH("Rectangle_obj::offset")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",153)
		hx::AddEq(this->x,dx);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",154)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

Void Rectangle_obj::offsetPoint( ::neash::geom::Point point){
{
		HX_SOURCE_PUSH("Rectangle_obj::offsetPoint")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",160)
		hx::AddEq(this->x,point->x);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",161)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::setEmpty( ){
{
		HX_SOURCE_PUSH("Rectangle_obj::setEmpty")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",166)
		this->x = this->y = this->width = this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

::neash::geom::Rectangle Rectangle_obj::transform( ::neash::geom::Matrix m){
	HX_SOURCE_PUSH("Rectangle_obj::transform")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",173)
	double tx0 = ((m->a * this->x) + (m->c * this->y));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",174)
	double tx1 = tx0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",175)
	double ty0 = ((m->b * this->x) + (m->d * this->y));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",176)
	double ty1 = tx0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",178)
	double tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",179)
	double ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",180)
	if (((tx < tx0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",180)
		tx0 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",181)
	if (((ty < ty0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",181)
		ty0 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",182)
	if (((tx > tx1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",182)
		tx1 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",183)
	if (((ty > ty1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",183)
		ty1 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",185)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",186)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",187)
	if (((tx < tx0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",187)
		tx0 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",188)
	if (((ty < ty0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",188)
		ty0 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",189)
	if (((tx > tx1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",189)
		tx1 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",190)
	if (((ty > ty1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",190)
		ty1 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",192)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",193)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",194)
	if (((tx < tx0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",194)
		tx0 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",195)
	if (((ty < ty0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",195)
		ty0 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",196)
	if (((tx > tx1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",196)
		tx1 = tx;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",197)
	if (((ty > ty1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",197)
		ty1 = ty;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",199)
	return ::neash::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

::neash::geom::Rectangle Rectangle_obj::_union( ::neash::geom::Rectangle toUnion){
	HX_SOURCE_PUSH("Rectangle_obj::union")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",205)
	double x0 = (  (((this->x > toUnion->x))) ? double(toUnion->x) : double(this->x) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",206)
	double x1 = (  (((this->nmeGetRight() < toUnion->nmeGetRight()))) ? double(toUnion->nmeGetRight()) : double(this->nmeGetRight()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",207)
	double y0 = (  (((this->y > toUnion->y))) ? double(toUnion->x) : double(this->y) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",208)
	double y1 = (  (((this->nmeGetBottom() < toUnion->nmeGetBottom()))) ? double(toUnion->nmeGetBottom()) : double(this->nmeGetBottom()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",209)
	return ::neash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

double Rectangle_obj::nmeGetBottom( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetBottom")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",218)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetBottom,return )

double Rectangle_obj::nmeSetBottom( double b){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetBottom")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",219)
	this->height = (b - this->y);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",219)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetBottom,return )

::neash::geom::Point Rectangle_obj::nmeGetBottomRight( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetBottomRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",220)
	return ::neash::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetBottomRight,return )

::neash::geom::Point Rectangle_obj::nmeSetBottomRight( ::neash::geom::Point p){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetBottomRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",221)
	this->width = (p->x - this->x);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",221)
	this->height = (p->y - this->y);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",221)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetBottomRight,return )

double Rectangle_obj::nmeGetLeft( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",222)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetLeft,return )

double Rectangle_obj::nmeSetLeft( double l){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",223)
	hx::SubEq(this->width,(l - this->x));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",223)
	this->x = l;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",223)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetLeft,return )

double Rectangle_obj::nmeGetRight( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",224)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetRight,return )

double Rectangle_obj::nmeSetRight( double r){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetRight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",225)
	this->width = (r - this->x);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",225)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetRight,return )

::neash::geom::Point Rectangle_obj::nmeGetSize( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetSize")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",226)
	return ::neash::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetSize,return )

::neash::geom::Point Rectangle_obj::nmeSetSize( ::neash::geom::Point p){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetSize")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",227)
	this->width = p->x;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",227)
	this->height = p->y;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",227)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetSize,return )

double Rectangle_obj::nmeGetTop( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetTop")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",228)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetTop,return )

double Rectangle_obj::nmeSetTop( double t){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetTop")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",229)
	hx::SubEq(this->height,(t - this->y));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",229)
	this->y = t;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",229)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetTop,return )

::neash::geom::Point Rectangle_obj::nmeGetTopLeft( ){
	HX_SOURCE_PUSH("Rectangle_obj::nmeGetTopLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",230)
	return ::neash::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetTopLeft,return )

::neash::geom::Point Rectangle_obj::nmeSetTopLeft( ::neash::geom::Point p){
	HX_SOURCE_PUSH("Rectangle_obj::nmeSetTopLeft")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",231)
	this->x = p->x;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",231)
	this->y = p->y;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Rectangle.hx",231)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetTopLeft,return )


Rectangle_obj::Rectangle_obj()
{
}

void Rectangle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rectangle);
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(bottomRight,"bottomRight");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(topLeft,"topLeft");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

Dynamic Rectangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return inCallProp ? nmeGetTop() : top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return inCallProp ? nmeGetLeft() : left; }
		if (HX_FIELD_EQ(inName,"size") ) { return inCallProp ? nmeGetTopLeft() : size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? nmeGetRight() : right; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { return inCallProp ? nmeGetBottom() : bottom; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { return inCallProp ? nmeGetTopLeft() : topLeft; }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTop") ) { return nmeGetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTop") ) { return nmeSetTop_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetLeft") ) { return nmeGetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetLeft") ) { return nmeSetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetSize") ) { return nmeGetSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetSize") ) { return nmeSetSize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return inCallProp ? nmeGetBottomRight() : bottomRight; }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetRight") ) { return nmeGetRight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetRight") ) { return nmeSetRight_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBottom") ) { return nmeGetBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBottom") ) { return nmeSetBottom_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTopLeft") ) { return nmeGetTopLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTopLeft") ) { return nmeSetTopLeft_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetBottomRight") ) { return nmeGetBottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetBottomRight") ) { return nmeSetBottomRight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { if (inCallProp) return nmeSetTop(inValue);top=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { if (inCallProp) return nmeSetLeft(inValue);left=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp) return nmeSetTopLeft(inValue);size=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { if (inCallProp) return nmeSetRight(inValue);right=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { if (inCallProp) return nmeSetBottom(inValue);bottom=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { if (inCallProp) return nmeSetTopLeft(inValue);topLeft=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { if (inCallProp) return nmeSetBottomRight(inValue);bottomRight=inValue.Cast< ::neash::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("bottomRight"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("topLeft"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bottom"),
	HX_CSTRING("bottomRight"),
	HX_CSTRING("height"),
	HX_CSTRING("left"),
	HX_CSTRING("right"),
	HX_CSTRING("size"),
	HX_CSTRING("top"),
	HX_CSTRING("topLeft"),
	HX_CSTRING("width"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("clone"),
	HX_CSTRING("contains"),
	HX_CSTRING("containsPoint"),
	HX_CSTRING("containsRect"),
	HX_CSTRING("equals"),
	HX_CSTRING("extendBounds"),
	HX_CSTRING("inflate"),
	HX_CSTRING("inflatePoint"),
	HX_CSTRING("intersection"),
	HX_CSTRING("intersects"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("offset"),
	HX_CSTRING("offsetPoint"),
	HX_CSTRING("setEmpty"),
	HX_CSTRING("transform"),
	HX_CSTRING("union"),
	HX_CSTRING("nmeGetBottom"),
	HX_CSTRING("nmeSetBottom"),
	HX_CSTRING("nmeGetBottomRight"),
	HX_CSTRING("nmeSetBottomRight"),
	HX_CSTRING("nmeGetLeft"),
	HX_CSTRING("nmeSetLeft"),
	HX_CSTRING("nmeGetRight"),
	HX_CSTRING("nmeSetRight"),
	HX_CSTRING("nmeGetSize"),
	HX_CSTRING("nmeSetSize"),
	HX_CSTRING("nmeGetTop"),
	HX_CSTRING("nmeSetTop"),
	HX_CSTRING("nmeGetTopLeft"),
	HX_CSTRING("nmeSetTopLeft"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
