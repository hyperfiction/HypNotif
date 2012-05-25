#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_sys_io_Process
#include <sys/io/Process.h>
#endif
namespace neash{

Void Loader_obj::__construct()
{
	return null();
}

Loader_obj::~Loader_obj() { }

Dynamic Loader_obj::__CreateEmpty() { return  new Loader_obj; }
hx::ObjectPtr< Loader_obj > Loader_obj::__new()
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

Dynamic Loader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

bool Loader_obj::moduleInit;

::String Loader_obj::moduleName;

::String Loader_obj::findHaxeLib( ::String inLib){
	HX_SOURCE_PUSH("Loader_obj::findHaxeLib")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",35)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",37)
		::sys::io::Process proc = ::sys::io::Process_obj::__new(HX_CSTRING("haxelib"),Array_obj< ::String >::__new().Add(HX_CSTRING("path")).Add(inLib));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",38)
		if (((proc != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",40)
			::haxe::io::Input stream = proc->_stdout;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",41)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",42)
				while((true)){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",45)
					::String s = stream->readLine();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",46)
					if (((s.substr((int)0,(int)1) != HX_CSTRING("-")))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",48)
						stream->close();
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",49)
						proc->close();
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",50)
						::neash::Loader_obj::loaderTrace((HX_CSTRING("Found haxelib ") + s));
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",51)
						return s;
					}
				}
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",56)
			stream->close();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",57)
			proc->close();
		}
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",62)
	return HX_CSTRING("");
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,findHaxeLib,return )

Dynamic Loader_obj::load( ::String func,int args){
	HX_SOURCE_PUSH("Loader_obj::load")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",68)
	if ((::neash::Loader_obj::moduleInit)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",69)
		return ::cpp::Lib_obj::load(::neash::Loader_obj::moduleName,func,args);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",77)
	::neash::Loader_obj::moduleInit = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",78)
	::neash::Loader_obj::moduleName = HX_CSTRING("nme");
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",81)
	Dynamic result = ::neash::Loader_obj::tryLoad(HX_CSTRING("./nme"),func,args);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",82)
	if (((result == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",83)
		result = ::neash::Loader_obj::tryLoad(HX_CSTRING(".\\nme"),func,args);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",86)
	if (((result == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",87)
		result = ::neash::Loader_obj::tryLoad(HX_CSTRING("nme"),func,args);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",89)
	if (((result == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",91)
		::String slash = (  (((::neash::Loader_obj::sysName()->__Field(HX_CSTRING("substr"),true)((int)7)->__Field(HX_CSTRING("toLowerCase"),true)() == HX_CSTRING("windows")))) ? ::String(HX_CSTRING("\\")) : ::String(HX_CSTRING("/")) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",92)
		::String haxelib = ::neash::Loader_obj::findHaxeLib(HX_CSTRING("nme"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",93)
		if (((haxelib != HX_CSTRING("")))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",95)
			result = ::neash::Loader_obj::tryLoad(((((((haxelib + slash) + HX_CSTRING("ndll")) + slash) + ::neash::Loader_obj::sysName()) + slash) + HX_CSTRING("nme")),func,args);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",98)
			if (((result == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",99)
				result = ::neash::Loader_obj::tryLoad((((((((haxelib + slash) + HX_CSTRING("ndll")) + slash) + ::neash::Loader_obj::sysName()) + HX_CSTRING("64")) + slash) + HX_CSTRING("nme")),func,args);
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",103)
	::neash::Loader_obj::loaderTrace((HX_CSTRING("Result : ") + result));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",109)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Loader_obj,load,return )

Void Loader_obj::loaderTrace( ::String inStr){
{
		HX_SOURCE_PUSH("Loader_obj::loaderTrace")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",132)
		Dynamic get_env = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_env"),(int)1);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",133)
		bool debug = (get_env(HX_CSTRING("NME_LOAD_DEBUG")) != null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",138)
		if ((debug)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",139)
			::cpp::Lib_obj::println(inStr);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Loader_obj,loaderTrace,(void))

Dynamic Loader_obj::sysName( ){
	HX_SOURCE_PUSH("Loader_obj::sysName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",147)
	Dynamic sys_string = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_string"),(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",148)
	return sys_string();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Loader_obj,sysName,return )

Dynamic Loader_obj::tryLoad( ::String inName,::String func,int args){
	HX_SOURCE_PUSH("Loader_obj::tryLoad")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",157)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",159)
		Dynamic result = ::cpp::Lib_obj::load(inName,func,args);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",160)
		if (((result != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",162)
			::neash::Loader_obj::loaderTrace((HX_CSTRING("Got result ") + inName));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",163)
			::neash::Loader_obj::moduleName = inName;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",164)
			return result;
		}
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",168)
				::neash::Loader_obj::loaderTrace((HX_CSTRING("Failed to load : ") + inName));
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,2/neash/Loader.hx",171)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Loader_obj,tryLoad,return )


Loader_obj::Loader_obj()
{
}

void Loader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Loader);
	HX_MARK_END_CLASS();
}

Dynamic Loader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"sysName") ) { return sysName_dyn(); }
		if (HX_FIELD_EQ(inName,"tryLoad") ) { return tryLoad_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { return moduleInit; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { return moduleName; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"findHaxeLib") ) { return findHaxeLib_dyn(); }
		if (HX_FIELD_EQ(inName,"loaderTrace") ) { return loaderTrace_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Loader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { moduleInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { moduleName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Loader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("moduleInit"),
	HX_CSTRING("moduleName"),
	HX_CSTRING("findHaxeLib"),
	HX_CSTRING("load"),
	HX_CSTRING("loaderTrace"),
	HX_CSTRING("sysName"),
	HX_CSTRING("tryLoad"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Loader_obj::moduleInit,"moduleInit");
	HX_MARK_MEMBER_NAME(Loader_obj::moduleName,"moduleName");
};

Class Loader_obj::__mClass;

void Loader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.Loader"), hx::TCanCast< Loader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Loader_obj::__boot()
{
	hx::Static(moduleInit) = false;
	hx::Static(moduleName) = HX_CSTRING("");
}

} // end namespace neash
