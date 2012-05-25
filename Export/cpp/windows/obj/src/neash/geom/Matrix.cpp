#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace neash{
namespace geom{

Void Matrix_obj::__construct(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",27)
	this->a = (  (((in_a == null()))) ? Dynamic(1.0) : Dynamic(in_a) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",28)
	this->b = (  (((in_b == null()))) ? Dynamic(0.0) : Dynamic(in_b) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",29)
	this->c = (  (((in_c == null()))) ? Dynamic(0.0) : Dynamic(in_c) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",30)
	this->d = (  (((in_d == null()))) ? Dynamic(1.0) : Dynamic(in_d) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",31)
	this->tx = (  (((in_tx == null()))) ? Dynamic(0.0) : Dynamic(in_tx) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",32)
	this->ty = (  (((in_ty == null()))) ? Dynamic(0.0) : Dynamic(in_ty) );
}
;
	return null();
}

Matrix_obj::~Matrix_obj() { }

Dynamic Matrix_obj::__CreateEmpty() { return  new Matrix_obj; }
hx::ObjectPtr< Matrix_obj > Matrix_obj::__new(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(in_a,in_b,in_c,in_d,in_tx,in_ty);
	return result;}

Dynamic Matrix_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::neash::geom::Matrix Matrix_obj::clone( ){
	HX_SOURCE_PUSH("Matrix_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",37)
	return ::neash::geom::Matrix_obj::__new(this->a,this->b,this->c,this->d,this->tx,this->ty);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,clone,return )

Void Matrix_obj::concat( ::neash::geom::Matrix m){
{
		HX_SOURCE_PUSH("Matrix_obj::concat")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",58)
		double a1 = ((this->a * m->a) + (this->b * m->c));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",59)
		this->b = ((this->a * m->b) + (this->b * m->d));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",60)
		this->a = a1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",62)
		double c1 = ((this->c * m->a) + (this->d * m->c));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",63)
		this->d = ((this->c * m->b) + (this->d * m->d));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",65)
		this->c = c1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",67)
		double tx1 = (((this->tx * m->a) + (this->ty * m->c)) + m->tx);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",68)
		this->ty = (((this->tx * m->b) + (this->ty * m->d)) + m->ty);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",69)
		this->tx = tx1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,concat,(void))

Void Matrix_obj::createBox( double scaleX,double scaleY,Dynamic rotation,Dynamic tx,Dynamic ty){
{
		HX_SOURCE_PUSH("Matrix_obj::createBox")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",75)
		this->a = (  (((scaleX == null()))) ? double(1.0) : double(scaleX) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",76)
		this->d = (  (((scaleY == null()))) ? double(1.0) : double(scaleY) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",77)
		this->b = (  (((rotation == null()))) ? Dynamic(0.0) : Dynamic(rotation) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",78)
		this->tx = (  (((tx == null()))) ? Dynamic(0.0) : Dynamic(tx) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",79)
		this->ty = (  (((ty == null()))) ? Dynamic(0.0) : Dynamic(ty) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Matrix_obj,createBox,(void))

Void Matrix_obj::createGradientBox( double in_width,double in_height,Dynamic rotation,Dynamic in_tx,Dynamic in_ty){
{
		HX_SOURCE_PUSH("Matrix_obj::createGradientBox")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",85)
		this->a = (double(in_width) / double(1638.4));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",86)
		this->d = (double(in_height) / double(1638.4));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",89)
		if (((bool((rotation != null())) && bool((rotation != 0.0))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",91)
			double cos = ::Math_obj::cos(rotation);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",92)
			double sin = ::Math_obj::sin(rotation);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",93)
			this->b = (sin * this->d);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",94)
			this->c = (-(sin) * this->a);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",95)
			hx::MultEq(this->a,cos);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",96)
			hx::MultEq(this->d,cos);
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",99)
			this->b = this->c = (int)0;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",103)
		this->tx = (  (((in_tx != null()))) ? double((in_tx + (double(in_width) / double((int)2)))) : double((double(in_width) / double((int)2))) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",104)
		this->ty = (  (((in_ty != null()))) ? double((in_ty + (double(in_height) / double((int)2)))) : double((double(in_height) / double((int)2))) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Matrix_obj,createGradientBox,(void))

Void Matrix_obj::identity( ){
{
		HX_SOURCE_PUSH("Matrix_obj::identity")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",110)
		this->a = (int)1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",111)
		this->b = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",112)
		this->c = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",113)
		this->d = (int)1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",114)
		this->tx = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",115)
		this->ty = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,identity,(void))

::neash::geom::Matrix Matrix_obj::invert( ){
	HX_SOURCE_PUSH("Matrix_obj::invert")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",121)
	double norm = ((this->a * this->d) - (this->b * this->c));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",123)
	if (((norm == (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",125)
		this->a = this->b = this->c = this->d = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",126)
		this->tx = -(this->tx);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",127)
		this->ty = -(this->ty);
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",131)
		norm = (double(1.0) / double(norm));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",132)
		double a1 = (this->d * norm);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",133)
		this->d = (this->a * norm);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",134)
		this->a = a1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",135)
		hx::MultEq(this->b,-(norm));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",136)
		hx::MultEq(this->c,-(norm));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",138)
		double tx1 = ((-(this->a) * this->tx) - (this->c * this->ty));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",139)
		this->ty = ((-(this->b) * this->tx) - (this->d * this->ty));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",140)
		this->tx = tx1;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",143)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,invert,return )

::neash::geom::Matrix Matrix_obj::mult( ::neash::geom::Matrix m){
	HX_SOURCE_PUSH("Matrix_obj::mult")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",149)
	::neash::geom::Matrix result = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",151)
	result->a = ((this->a * m->a) + (this->b * m->c));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",152)
	result->b = ((this->a * m->b) + (this->b * m->d));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",153)
	result->c = ((this->c * m->a) + (this->d * m->c));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",154)
	result->d = ((this->c * m->b) + (this->d * m->d));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",156)
	result->tx = (((this->tx * m->a) + (this->ty * m->c)) + m->tx);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",157)
	result->ty = (((this->tx * m->b) + (this->ty * m->d)) + m->ty);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",159)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,mult,return )

Void Matrix_obj::rotate( double inTheta){
{
		HX_SOURCE_PUSH("Matrix_obj::rotate")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",177)
		double cos = ::Math_obj::cos(inTheta);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",178)
		double sin = ::Math_obj::sin(inTheta);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",180)
		double a1 = ((this->a * cos) - (this->b * sin));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",181)
		this->b = ((this->a * sin) + (this->b * cos));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",182)
		this->a = a1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",184)
		double c1 = ((this->c * cos) - (this->d * sin));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",185)
		this->d = ((this->c * sin) + (this->d * cos));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",186)
		this->c = c1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",188)
		double tx1 = ((this->tx * cos) - (this->ty * sin));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",189)
		this->ty = ((this->tx * sin) + (this->ty * cos));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",190)
		this->tx = tx1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,rotate,(void))

Void Matrix_obj::scale( double inSX,double inSY){
{
		HX_SOURCE_PUSH("Matrix_obj::scale")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",203)
		hx::MultEq(this->a,inSX);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",204)
		hx::MultEq(this->b,inSY);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",206)
		hx::MultEq(this->c,inSX);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",207)
		hx::MultEq(this->d,inSY);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",209)
		hx::MultEq(this->tx,inSX);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",210)
		hx::MultEq(this->ty,inSY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,scale,(void))

Void Matrix_obj::setRotation( double inTheta,Dynamic inScale){
{
		HX_SOURCE_PUSH("Matrix_obj::setRotation")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",216)
		double scale = (  (((inScale == null()))) ? Dynamic(1.0) : Dynamic(inScale) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",217)
		this->a = (::Math_obj::cos(inTheta) * scale);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",218)
		this->c = (::Math_obj::sin(inTheta) * scale);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",219)
		this->b = -(this->c);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",220)
		this->d = this->a;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,setRotation,(void))

::neash::geom::Point Matrix_obj::transformPoint( ::neash::geom::Point inPos){
	HX_SOURCE_PUSH("Matrix_obj::transformPoint")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",225)
	return ::neash::geom::Point_obj::__new((((inPos->x * this->a) + (inPos->y * this->c)) + this->tx),(((inPos->x * this->b) + (inPos->y * this->d)) + this->ty));
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,transformPoint,return )

Void Matrix_obj::translate( double inDX,double inDY){
{
		HX_SOURCE_PUSH("Matrix_obj::translate")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",232)
		hx::AddEq(this->tx,inDX);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/Matrix.hx",233)
		hx::AddEq(this->ty,inDY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,translate,(void))


Matrix_obj::Matrix_obj()
{
}

void Matrix_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Matrix);
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(d,"d");
	HX_MARK_MEMBER_NAME(tx,"tx");
	HX_MARK_MEMBER_NAME(ty,"ty");
	HX_MARK_END_CLASS();
}

Dynamic Matrix_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"d") ) { return d; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"tx") ) { return tx; }
		if (HX_FIELD_EQ(inName,"ty") ) { return ty; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mult") ) { return mult_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert_dyn(); }
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { return identity_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"createBox") ) { return createBox_dyn(); }
		if (HX_FIELD_EQ(inName,"translate") ) { return translate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setRotation") ) { return setRotation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"transformPoint") ) { return transformPoint_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"createGradientBox") ) { return createGradientBox_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

static int __id_a = __hxcpp_field_to_id("a");
static int __id_b = __hxcpp_field_to_id("b");
static int __id_c = __hxcpp_field_to_id("c");
static int __id_d = __hxcpp_field_to_id("d");
static int __id_tx = __hxcpp_field_to_id("tx");
static int __id_ty = __hxcpp_field_to_id("ty");
static int __id_clone = __hxcpp_field_to_id("clone");
static int __id_concat = __hxcpp_field_to_id("concat");
static int __id_createBox = __hxcpp_field_to_id("createBox");
static int __id_createGradientBox = __hxcpp_field_to_id("createGradientBox");
static int __id_identity = __hxcpp_field_to_id("identity");
static int __id_invert = __hxcpp_field_to_id("invert");
static int __id_mult = __hxcpp_field_to_id("mult");
static int __id_rotate = __hxcpp_field_to_id("rotate");
static int __id_scale = __hxcpp_field_to_id("scale");
static int __id_setRotation = __hxcpp_field_to_id("setRotation");
static int __id_transformPoint = __hxcpp_field_to_id("transformPoint");
static int __id_translate = __hxcpp_field_to_id("translate");


double Matrix_obj::__INumField(int inFieldID)
{
	if (inFieldID==__id_a) return hx::ToDouble( a ) ;
	if (inFieldID==__id_b) return hx::ToDouble( b ) ;
	if (inFieldID==__id_c) return hx::ToDouble( c ) ;
	if (inFieldID==__id_d) return hx::ToDouble( d ) ;
	if (inFieldID==__id_tx) return hx::ToDouble( tx ) ;
	if (inFieldID==__id_ty) return hx::ToDouble( ty ) ;
	if (inFieldID==__id_clone) return hx::ToDouble( clone_dyn() ) ;
	if (inFieldID==__id_concat) return hx::ToDouble( concat_dyn() ) ;
	if (inFieldID==__id_createBox) return hx::ToDouble( createBox_dyn() ) ;
	if (inFieldID==__id_createGradientBox) return hx::ToDouble( createGradientBox_dyn() ) ;
	if (inFieldID==__id_identity) return hx::ToDouble( identity_dyn() ) ;
	if (inFieldID==__id_invert) return hx::ToDouble( invert_dyn() ) ;
	if (inFieldID==__id_mult) return hx::ToDouble( mult_dyn() ) ;
	if (inFieldID==__id_rotate) return hx::ToDouble( rotate_dyn() ) ;
	if (inFieldID==__id_scale) return hx::ToDouble( scale_dyn() ) ;
	if (inFieldID==__id_setRotation) return hx::ToDouble( setRotation_dyn() ) ;
	if (inFieldID==__id_transformPoint) return hx::ToDouble( transformPoint_dyn() ) ;
	if (inFieldID==__id_translate) return hx::ToDouble( translate_dyn() ) ;
	return super::__INumField(inFieldID);
}

Dynamic Matrix_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d") ) { d=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"tx") ) { tx=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ty") ) { ty=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Matrix_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("tx"));
	outFields->push(HX_CSTRING("ty"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("a"),
	HX_CSTRING("b"),
	HX_CSTRING("c"),
	HX_CSTRING("d"),
	HX_CSTRING("tx"),
	HX_CSTRING("ty"),
	HX_CSTRING("clone"),
	HX_CSTRING("concat"),
	HX_CSTRING("createBox"),
	HX_CSTRING("createGradientBox"),
	HX_CSTRING("identity"),
	HX_CSTRING("invert"),
	HX_CSTRING("mult"),
	HX_CSTRING("rotate"),
	HX_CSTRING("scale"),
	HX_CSTRING("setRotation"),
	HX_CSTRING("transformPoint"),
	HX_CSTRING("translate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Matrix_obj::__mClass;

void Matrix_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Matrix"), hx::TCanCast< Matrix_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Matrix_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
