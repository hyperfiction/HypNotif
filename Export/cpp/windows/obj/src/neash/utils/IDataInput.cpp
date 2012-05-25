#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_neash_utils_ByteArray
#include <neash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_neash_utils_IDataInput
#include <neash/utils/IDataInput.h>
#endif
namespace neash{
namespace utils{

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readBoolean,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readByte,return )

HX_DEFINE_DYNAMIC_FUNC3(IDataInput_obj,readBytes,)

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readDouble,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readFloat,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readInt,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readShort,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedByte,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedInt,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUnsignedShort,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,readUTF,return )

HX_DEFINE_DYNAMIC_FUNC1(IDataInput_obj,readUTFBytes,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,nmeGetBytesAvailable,return )

HX_DEFINE_DYNAMIC_FUNC0(IDataInput_obj,nmeGetEndian,return )

HX_DEFINE_DYNAMIC_FUNC1(IDataInput_obj,nmeSetEndian,return )


Class IDataInput_obj::__mClass;

void IDataInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.utils.IDataInput"), hx::TCanCast< IDataInput_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace neash
} // end namespace utils
