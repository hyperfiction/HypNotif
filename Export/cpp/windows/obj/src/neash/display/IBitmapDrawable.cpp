#include <hxcpp.h>

#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

HX_DEFINE_DYNAMIC_FUNC6(IBitmapDrawable_obj,nmeDrawToSurface,)


Class IBitmapDrawable_obj::__mClass;

void IBitmapDrawable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.IBitmapDrawable"), hx::TCanCast< IBitmapDrawable_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace neash
} // end namespace display
