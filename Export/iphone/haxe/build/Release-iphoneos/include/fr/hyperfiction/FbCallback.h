#ifndef INCLUDED_fr_hyperfiction_FbCallback
#define INCLUDED_fr_hyperfiction_FbCallback

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(fr,hyperfiction,FbCallback)
namespace fr{
namespace hyperfiction{


class FbCallback_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FbCallback_obj OBJ_;

	public:
		FbCallback_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("fr.hyperfiction.FbCallback"); }
		::String __ToString() const { return HX_CSTRING("FbCallback.") + tag; }

		static ::fr::hyperfiction::FbCallback ON_LOGIN;
		static inline ::fr::hyperfiction::FbCallback ON_LOGIN_dyn() { return ON_LOGIN; }
};

} // end namespace fr
} // end namespace hyperfiction

#endif /* INCLUDED_fr_hyperfiction_FbCallback */ 
