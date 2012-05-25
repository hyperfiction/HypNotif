#include <hxcpp.h>

#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
namespace neash{
namespace geom{

Void ColorTransform_obj::__construct(hx::Null< double >  __o_inRedMultiplier,hx::Null< double >  __o_inGreenMultiplier,hx::Null< double >  __o_inBlueMultiplier,hx::Null< double >  __o_inAlphaMultiplier,hx::Null< double >  __o_inRedOffset,hx::Null< double >  __o_inGreenOffset,hx::Null< double >  __o_inBlueOffset,hx::Null< double >  __o_inAlphaOffset)
{
double inRedMultiplier = __o_inRedMultiplier.Default(1.0);
double inGreenMultiplier = __o_inGreenMultiplier.Default(1.0);
double inBlueMultiplier = __o_inBlueMultiplier.Default(1.0);
double inAlphaMultiplier = __o_inAlphaMultiplier.Default(1.0);
double inRedOffset = __o_inRedOffset.Default(0.0);
double inGreenOffset = __o_inGreenOffset.Default(0.0);
double inBlueOffset = __o_inBlueOffset.Default(0.0);
double inAlphaOffset = __o_inAlphaOffset.Default(0.0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",24)
	this->redMultiplier = inRedMultiplier;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",25)
	this->greenMultiplier = inGreenMultiplier;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",26)
	this->blueMultiplier = inBlueMultiplier;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",27)
	this->alphaMultiplier = inAlphaMultiplier;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",28)
	this->redOffset = inRedOffset;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",29)
	this->greenOffset = inGreenOffset;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",30)
	this->blueOffset = inBlueOffset;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",31)
	this->alphaOffset = inAlphaOffset;
}
;
	return null();
}

ColorTransform_obj::~ColorTransform_obj() { }

Dynamic ColorTransform_obj::__CreateEmpty() { return  new ColorTransform_obj; }
hx::ObjectPtr< ColorTransform_obj > ColorTransform_obj::__new(hx::Null< double >  __o_inRedMultiplier,hx::Null< double >  __o_inGreenMultiplier,hx::Null< double >  __o_inBlueMultiplier,hx::Null< double >  __o_inAlphaMultiplier,hx::Null< double >  __o_inRedOffset,hx::Null< double >  __o_inGreenOffset,hx::Null< double >  __o_inBlueOffset,hx::Null< double >  __o_inAlphaOffset)
{  hx::ObjectPtr< ColorTransform_obj > result = new ColorTransform_obj();
	result->__construct(__o_inRedMultiplier,__o_inGreenMultiplier,__o_inBlueMultiplier,__o_inAlphaMultiplier,__o_inRedOffset,__o_inGreenOffset,__o_inBlueOffset,__o_inAlphaOffset);
	return result;}

Dynamic ColorTransform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorTransform_obj > result = new ColorTransform_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

Void ColorTransform_obj::concat( ::neash::geom::ColorTransform second){
{
		HX_SOURCE_PUSH("ColorTransform_obj::concat")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",37)
		hx::AddEq(this->redMultiplier,second->redMultiplier);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",38)
		hx::AddEq(this->greenMultiplier,second->greenMultiplier);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",39)
		hx::AddEq(this->blueMultiplier,second->blueMultiplier);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/geom/ColorTransform.hx",40)
		hx::AddEq(this->alphaMultiplier,second->alphaMultiplier);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColorTransform_obj,concat,(void))


ColorTransform_obj::ColorTransform_obj()
{
}

void ColorTransform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColorTransform);
	HX_MARK_MEMBER_NAME(alphaMultiplier,"alphaMultiplier");
	HX_MARK_MEMBER_NAME(alphaOffset,"alphaOffset");
	HX_MARK_MEMBER_NAME(blueMultiplier,"blueMultiplier");
	HX_MARK_MEMBER_NAME(blueOffset,"blueOffset");
	HX_MARK_MEMBER_NAME(greenMultiplier,"greenMultiplier");
	HX_MARK_MEMBER_NAME(greenOffset,"greenOffset");
	HX_MARK_MEMBER_NAME(redMultiplier,"redMultiplier");
	HX_MARK_MEMBER_NAME(redOffset,"redOffset");
	HX_MARK_END_CLASS();
}

Dynamic ColorTransform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"redOffset") ) { return redOffset; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blueOffset") ) { return blueOffset; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"alphaOffset") ) { return alphaOffset; }
		if (HX_FIELD_EQ(inName,"greenOffset") ) { return greenOffset; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"redMultiplier") ) { return redMultiplier; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"blueMultiplier") ) { return blueMultiplier; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"alphaMultiplier") ) { return alphaMultiplier; }
		if (HX_FIELD_EQ(inName,"greenMultiplier") ) { return greenMultiplier; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColorTransform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"redOffset") ) { redOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blueOffset") ) { blueOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"alphaOffset") ) { alphaOffset=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"greenOffset") ) { greenOffset=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"redMultiplier") ) { redMultiplier=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"blueMultiplier") ) { blueMultiplier=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"alphaMultiplier") ) { alphaMultiplier=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"greenMultiplier") ) { greenMultiplier=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColorTransform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alphaMultiplier"));
	outFields->push(HX_CSTRING("alphaOffset"));
	outFields->push(HX_CSTRING("blueMultiplier"));
	outFields->push(HX_CSTRING("blueOffset"));
	outFields->push(HX_CSTRING("greenMultiplier"));
	outFields->push(HX_CSTRING("greenOffset"));
	outFields->push(HX_CSTRING("redMultiplier"));
	outFields->push(HX_CSTRING("redOffset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("alphaMultiplier"),
	HX_CSTRING("alphaOffset"),
	HX_CSTRING("blueMultiplier"),
	HX_CSTRING("blueOffset"),
	HX_CSTRING("greenMultiplier"),
	HX_CSTRING("greenOffset"),
	HX_CSTRING("redMultiplier"),
	HX_CSTRING("redOffset"),
	HX_CSTRING("concat"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ColorTransform_obj::__mClass;

void ColorTransform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.ColorTransform"), hx::TCanCast< ColorTransform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ColorTransform_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
