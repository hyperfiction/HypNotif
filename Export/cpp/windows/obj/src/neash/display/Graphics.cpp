#include <hxcpp.h>

#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_CapsStyle
#include <neash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_neash_display_GradientType
#include <neash/display/GradientType.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_IGraphicsData
#include <neash/display/IGraphicsData.h>
#endif
#ifndef INCLUDED_neash_display_InterpolationMethod
#include <neash/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_neash_display_JointStyle
#include <neash/display/JointStyle.h>
#endif
#ifndef INCLUDED_neash_display_LineScaleMode
#include <neash/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_neash_display_SpreadMethod
#include <neash/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_neash_display_Tilesheet
#include <neash/display/Tilesheet.h>
#endif
#ifndef INCLUDED_neash_display_TriangleCulling
#include <neash/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
namespace neash{
namespace display{

Void Graphics_obj::__construct(Dynamic inHandle)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",26)
	this->nmeHandle = inHandle;
}
;
	return null();
}

Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new(Dynamic inHandle)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inHandle);
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Graphics_obj::arcTo( double inCX,double inCY,double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::arcTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",32)
		::neash::display::Graphics_obj::nme_gfx_arc_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,arcTo,(void))

Void Graphics_obj::beginBitmapFill( ::neash::display::BitmapData bitmap,::neash::geom::Matrix matrix,hx::Null< bool >  __o_repeat,hx::Null< bool >  __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::beginBitmapFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",38)
		::neash::display::Graphics_obj::nme_gfx_begin_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,beginBitmapFill,(void))

Void Graphics_obj::beginFill( int color,hx::Null< double >  __o_alpha){
double alpha = __o_alpha.Default(1.0);
	HX_SOURCE_PUSH("Graphics_obj::beginFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",44)
		::neash::display::Graphics_obj::nme_gfx_begin_fill(this->nmeHandle,color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,beginFill,(void))

Void Graphics_obj::beginGradientFill( ::neash::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::neash::geom::Matrix matrix,::neash::display::SpreadMethod spreadMethod,::neash::display::InterpolationMethod interpolationMethod,hx::Null< double >  __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::beginGradientFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",51)
		if (((matrix == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",53)
			matrix = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",54)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",57)
		::neash::display::Graphics_obj::nme_gfx_begin_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,beginGradientFill,(void))

Void Graphics_obj::clear( ){
{
		HX_SOURCE_PUSH("Graphics_obj::clear")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",62)
		::neash::display::Graphics_obj::nme_gfx_clear(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,clear,(void))

Void Graphics_obj::curveTo( double inCX,double inCY,double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::curveTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",68)
		::neash::display::Graphics_obj::nme_gfx_curve_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,curveTo,(void))

Void Graphics_obj::drawCircle( double inX,double inY,double inRadius){
{
		HX_SOURCE_PUSH("Graphics_obj::drawCircle")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",74)
		::neash::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,(inRadius * (int)2),(inRadius * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawCircle,(void))

Void Graphics_obj::drawEllipse( double inX,double inY,double inWidth,double inHeight){
{
		HX_SOURCE_PUSH("Graphics_obj::drawEllipse")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",80)
		::neash::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawEllipse,(void))

Void Graphics_obj::drawGraphicsData( Array< ::neash::display::IGraphicsData > graphicsData){
{
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsData")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",87)
		Dynamic handles = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",89)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",89)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",89)
			while(((_g < graphicsData->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",89)
				::neash::display::IGraphicsData datum = graphicsData->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",89)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",90)
				handles->__Field(HX_CSTRING("push"),true)(datum->nmeHandle);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",92)
		::neash::display::Graphics_obj::nme_gfx_draw_data(this->nmeHandle,handles);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsData,(void))

Void Graphics_obj::drawGraphicsDatum( ::neash::display::IGraphicsData graphicsDatum){
{
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsDatum")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",97)
		::neash::display::Graphics_obj::nme_gfx_draw_datum(this->nmeHandle,graphicsDatum->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsDatum,(void))

Void Graphics_obj::drawPoints( Array< double > inXY,Array< int > inPointRGBA,hx::Null< int >  __o_inDefaultRGBA,hx::Null< double >  __o_inSize){
int inDefaultRGBA = __o_inDefaultRGBA.Default(-1);
double inSize = __o_inSize.Default(-1.0);
	HX_SOURCE_PUSH("Graphics_obj::drawPoints");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",103)
		::neash::display::Graphics_obj::nme_gfx_draw_points(this->nmeHandle,inXY,inPointRGBA,inDefaultRGBA,false,inSize);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawPoints,(void))

Void Graphics_obj::drawRect( double inX,double inY,double inWidth,double inHeight){
{
		HX_SOURCE_PUSH("Graphics_obj::drawRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",109)
		::neash::display::Graphics_obj::nme_gfx_draw_rect(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawRect,(void))

Void Graphics_obj::drawRoundRect( double inX,double inY,double inWidth,double inHeight,double inRadX,Dynamic inRadY){
{
		HX_SOURCE_PUSH("Graphics_obj::drawRoundRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",115)
		::neash::display::Graphics_obj::nme_gfx_draw_round_rect(this->nmeHandle,inX,inY,inWidth,inHeight,inRadX,(  (((inRadY == null()))) ? Dynamic(inRadX) : Dynamic(inRadY) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawRoundRect,(void))

Void Graphics_obj::drawTiles( ::neash::display::Tilesheet sheet,Array< double > inXYID,hx::Null< bool >  __o_inSmooth,hx::Null< int >  __o_inFlags){
bool inSmooth = __o_inSmooth.Default(false);
int inFlags = __o_inFlags.Default(0);
	HX_SOURCE_PUSH("Graphics_obj::drawTiles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",125)
		this->beginBitmapFill(sheet->nmeBitmap,null(),false,inSmooth);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",127)
		if ((inSmooth)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",128)
			hx::OrEq(inFlags,(int)4096);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",130)
		::neash::display::Graphics_obj::nme_gfx_draw_tiles(this->nmeHandle,sheet->nmeHandle,inXYID,inFlags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawTiles,(void))

Void Graphics_obj::drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::neash::display::TriangleCulling culling,Array< int > colours,hx::Null< int >  __o_blendMode,Array< double > viewport){
int blendMode = __o_blendMode.Default(0);
	HX_SOURCE_PUSH("Graphics_obj::drawTriangles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",136)
		int cull = (  (((culling == null()))) ? int((int)0) : int((culling->__Index() - (int)1)) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",137)
		::neash::display::Graphics_obj::nme_gfx_draw_triangles(this->nmeHandle,vertices,indices,uvtData,cull,colours,blendMode,viewport);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Graphics_obj,drawTriangles,(void))

Void Graphics_obj::endFill( ){
{
		HX_SOURCE_PUSH("Graphics_obj::endFill")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",142)
		::neash::display::Graphics_obj::nme_gfx_end_fill(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,endFill,(void))

Void Graphics_obj::lineBitmapStyle( ::neash::display::BitmapData bitmap,::neash::geom::Matrix matrix,hx::Null< bool >  __o_repeat,hx::Null< bool >  __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::lineBitmapStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",148)
		::neash::display::Graphics_obj::nme_gfx_line_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,lineBitmapStyle,(void))

Void Graphics_obj::lineGradientStyle( ::neash::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::neash::geom::Matrix matrix,::neash::display::SpreadMethod spreadMethod,::neash::display::InterpolationMethod interpolationMethod,hx::Null< double >  __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::lineGradientStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",155)
		if (((matrix == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",157)
			matrix = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",158)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",161)
		::neash::display::Graphics_obj::nme_gfx_line_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineGradientStyle,(void))

Void Graphics_obj::lineStyle( Dynamic thickness,hx::Null< int >  __o_color,hx::Null< double >  __o_alpha,hx::Null< bool >  __o_pixelHinting,::neash::display::LineScaleMode scaleMode,::neash::display::CapsStyle caps,::neash::display::JointStyle joints,hx::Null< double >  __o_miterLimit){
int color = __o_color.Default(0);
double alpha = __o_alpha.Default(1.0);
bool pixelHinting = __o_pixelHinting.Default(false);
double miterLimit = __o_miterLimit.Default(3);
	HX_SOURCE_PUSH("Graphics_obj::lineStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",166)
		::neash::display::Graphics_obj::nme_gfx_line_style(this->nmeHandle,thickness,color,alpha,pixelHinting,(  (((scaleMode == null()))) ? int((int)0) : int(scaleMode->__Index()) ),(  (((caps == null()))) ? int((int)0) : int(caps->__Index()) ),(  (((joints == null()))) ? int((int)0) : int(joints->__Index()) ),miterLimit);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineStyle,(void))

Void Graphics_obj::lineTo( double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::lineTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",172)
		::neash::display::Graphics_obj::nme_gfx_line_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,lineTo,(void))

Void Graphics_obj::moveTo( double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::moveTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",178)
		::neash::display::Graphics_obj::nme_gfx_move_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,moveTo,(void))

int Graphics_obj::TILE_SCALE;

int Graphics_obj::TILE_ROTATION;

int Graphics_obj::TILE_RGB;

int Graphics_obj::TILE_ALPHA;

int Graphics_obj::TILE_SMOOTH;

int Graphics_obj::TILE_BLEND_NORMAL;

int Graphics_obj::TILE_BLEND_ADD;

int Graphics_obj::RGBA( int inRGB,hx::Null< int >  __o_inA){
int inA = __o_inA.Default(255);
	HX_SOURCE_PUSH("Graphics_obj::RGBA");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/display/Graphics.hx",184)
		return (int(inRGB) | int((int(inA) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,RGBA,return )

Dynamic Graphics_obj::nme_gfx_clear;

Dynamic Graphics_obj::nme_gfx_begin_fill;

Dynamic Graphics_obj::nme_gfx_begin_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_line_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_begin_gradient_fill;

Dynamic Graphics_obj::nme_gfx_line_gradient_fill;

Dynamic Graphics_obj::nme_gfx_end_fill;

Dynamic Graphics_obj::nme_gfx_line_style;

Dynamic Graphics_obj::nme_gfx_move_to;

Dynamic Graphics_obj::nme_gfx_line_to;

Dynamic Graphics_obj::nme_gfx_curve_to;

Dynamic Graphics_obj::nme_gfx_arc_to;

Dynamic Graphics_obj::nme_gfx_draw_ellipse;

Dynamic Graphics_obj::nme_gfx_draw_data;

Dynamic Graphics_obj::nme_gfx_draw_datum;

Dynamic Graphics_obj::nme_gfx_draw_rect;

Dynamic Graphics_obj::nme_gfx_draw_tiles;

Dynamic Graphics_obj::nme_gfx_draw_points;

Dynamic Graphics_obj::nme_gfx_draw_round_rect;

Dynamic Graphics_obj::nme_gfx_draw_triangles;


Graphics_obj::Graphics_obj()
{
}

void Graphics_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Graphics);
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic Graphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"RGBA") ) { return RGBA_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"arcTo") ) { return arcTo_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { return TILE_RGB; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { return TILE_SCALE; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { return TILE_ALPHA; }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPoints") ) { return drawPoints_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_SMOOTH") ) { return TILE_SMOOTH; }
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { return TILE_ROTATION; }
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { return nme_gfx_clear; }
		if (HX_FIELD_EQ(inName,"drawRoundRect") ) { return drawRoundRect_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTriangles") ) { return drawTriangles_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { return TILE_BLEND_ADD; }
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { return nme_gfx_arc_to; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { return nme_gfx_move_to; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { return nme_gfx_line_to; }
		if (HX_FIELD_EQ(inName,"beginBitmapFill") ) { return beginBitmapFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineBitmapStyle") ) { return lineBitmapStyle_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { return nme_gfx_end_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { return nme_gfx_curve_to; }
		if (HX_FIELD_EQ(inName,"drawGraphicsData") ) { return drawGraphicsData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { return TILE_BLEND_NORMAL; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { return nme_gfx_draw_data; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { return nme_gfx_draw_rect; }
		if (HX_FIELD_EQ(inName,"beginGradientFill") ) { return beginGradientFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawGraphicsDatum") ) { return drawGraphicsDatum_dyn(); }
		if (HX_FIELD_EQ(inName,"lineGradientStyle") ) { return lineGradientStyle_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { return nme_gfx_begin_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { return nme_gfx_line_style; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { return nme_gfx_draw_datum; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { return nme_gfx_draw_tiles; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { return nme_gfx_draw_points; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { return nme_gfx_draw_ellipse; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { return nme_gfx_draw_triangles; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { return nme_gfx_draw_round_rect; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { return nme_gfx_line_bitmap_fill; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { return nme_gfx_begin_bitmap_fill; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { return nme_gfx_line_gradient_fill; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { return nme_gfx_begin_gradient_fill; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { TILE_RGB=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { TILE_SCALE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { TILE_ALPHA=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_SMOOTH") ) { TILE_SMOOTH=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { TILE_ROTATION=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { nme_gfx_clear=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { TILE_BLEND_ADD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { nme_gfx_arc_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { nme_gfx_move_to=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { nme_gfx_line_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { nme_gfx_end_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { nme_gfx_curve_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { TILE_BLEND_NORMAL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { nme_gfx_draw_data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { nme_gfx_draw_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { nme_gfx_begin_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { nme_gfx_line_style=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { nme_gfx_draw_datum=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { nme_gfx_draw_tiles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { nme_gfx_draw_points=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { nme_gfx_draw_ellipse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { nme_gfx_draw_triangles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { nme_gfx_draw_round_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { nme_gfx_line_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { nme_gfx_begin_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { nme_gfx_line_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { nme_gfx_begin_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("TILE_SMOOTH"),
	HX_CSTRING("TILE_BLEND_NORMAL"),
	HX_CSTRING("TILE_BLEND_ADD"),
	HX_CSTRING("RGBA"),
	HX_CSTRING("nme_gfx_clear"),
	HX_CSTRING("nme_gfx_begin_fill"),
	HX_CSTRING("nme_gfx_begin_bitmap_fill"),
	HX_CSTRING("nme_gfx_line_bitmap_fill"),
	HX_CSTRING("nme_gfx_begin_gradient_fill"),
	HX_CSTRING("nme_gfx_line_gradient_fill"),
	HX_CSTRING("nme_gfx_end_fill"),
	HX_CSTRING("nme_gfx_line_style"),
	HX_CSTRING("nme_gfx_move_to"),
	HX_CSTRING("nme_gfx_line_to"),
	HX_CSTRING("nme_gfx_curve_to"),
	HX_CSTRING("nme_gfx_arc_to"),
	HX_CSTRING("nme_gfx_draw_ellipse"),
	HX_CSTRING("nme_gfx_draw_data"),
	HX_CSTRING("nme_gfx_draw_datum"),
	HX_CSTRING("nme_gfx_draw_rect"),
	HX_CSTRING("nme_gfx_draw_tiles"),
	HX_CSTRING("nme_gfx_draw_points"),
	HX_CSTRING("nme_gfx_draw_round_rect"),
	HX_CSTRING("nme_gfx_draw_triangles"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("arcTo"),
	HX_CSTRING("beginBitmapFill"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("beginGradientFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawGraphicsData"),
	HX_CSTRING("drawGraphicsDatum"),
	HX_CSTRING("drawPoints"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawRoundRect"),
	HX_CSTRING("drawTiles"),
	HX_CSTRING("drawTriangles"),
	HX_CSTRING("endFill"),
	HX_CSTRING("lineBitmapStyle"),
	HX_CSTRING("lineGradientStyle"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SMOOTH,"TILE_SMOOTH");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_clear,"nme_gfx_clear");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_fill,"nme_gfx_begin_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_bitmap_fill,"nme_gfx_begin_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_bitmap_fill,"nme_gfx_line_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_gradient_fill,"nme_gfx_begin_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_gradient_fill,"nme_gfx_line_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_end_fill,"nme_gfx_end_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_style,"nme_gfx_line_style");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_move_to,"nme_gfx_move_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_to,"nme_gfx_line_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_curve_to,"nme_gfx_curve_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_arc_to,"nme_gfx_arc_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_ellipse,"nme_gfx_draw_ellipse");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_data,"nme_gfx_draw_data");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_datum,"nme_gfx_draw_datum");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_rect,"nme_gfx_draw_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_tiles,"nme_gfx_draw_tiles");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_points,"nme_gfx_draw_points");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_round_rect,"nme_gfx_draw_round_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_triangles,"nme_gfx_draw_triangles");
};

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Graphics_obj::__boot()
{
	hx::Static(TILE_SCALE) = (int)1;
	hx::Static(TILE_ROTATION) = (int)2;
	hx::Static(TILE_RGB) = (int)4;
	hx::Static(TILE_ALPHA) = (int)8;
	hx::Static(TILE_SMOOTH) = (int)4096;
	hx::Static(TILE_BLEND_NORMAL) = (int)0;
	hx::Static(TILE_BLEND_ADD) = (int)65536;
	hx::Static(nme_gfx_clear) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_clear"),(int)1);
	hx::Static(nme_gfx_begin_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_begin_fill"),(int)3);
	hx::Static(nme_gfx_begin_bitmap_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_begin_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_line_bitmap_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_line_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_begin_gradient_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_begin_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_line_gradient_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_line_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_end_fill) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_end_fill"),(int)1);
	hx::Static(nme_gfx_line_style) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_line_style"),(int)-1);
	hx::Static(nme_gfx_move_to) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_move_to"),(int)3);
	hx::Static(nme_gfx_line_to) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_line_to"),(int)3);
	hx::Static(nme_gfx_curve_to) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_curve_to"),(int)5);
	hx::Static(nme_gfx_arc_to) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_arc_to"),(int)5);
	hx::Static(nme_gfx_draw_ellipse) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_ellipse"),(int)5);
	hx::Static(nme_gfx_draw_data) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_data"),(int)2);
	hx::Static(nme_gfx_draw_datum) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_datum"),(int)2);
	hx::Static(nme_gfx_draw_rect) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_rect"),(int)5);
	hx::Static(nme_gfx_draw_tiles) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_tiles"),(int)4);
	hx::Static(nme_gfx_draw_points) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_points"),(int)-1);
	hx::Static(nme_gfx_draw_round_rect) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_round_rect"),(int)-1);
	hx::Static(nme_gfx_draw_triangles) = ::neash::Loader_obj::load(HX_CSTRING("nme_gfx_draw_triangles"),(int)-1);
}

} // end namespace neash
} // end namespace display
