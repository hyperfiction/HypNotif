#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys__FileSystem_FileKind
#include <sys/_FileSystem/FileKind.h>
#endif
namespace sys{

Void FileSystem_obj::__construct()
{
	return null();
}

FileSystem_obj::~FileSystem_obj() { }

Dynamic FileSystem_obj::__CreateEmpty() { return  new FileSystem_obj; }
hx::ObjectPtr< FileSystem_obj > FileSystem_obj::__new()
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Dynamic FileSystem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

bool FileSystem_obj::exists( ::String path){
	HX_SOURCE_PUSH("FileSystem_obj::exists")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",36)
	return ::sys::FileSystem_obj::sys_exists(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,exists,return )

Void FileSystem_obj::rename( ::String path,::String newpath){
{
		HX_SOURCE_PUSH("FileSystem_obj::rename")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",40)
		if (((::sys::FileSystem_obj::sys_rename(path,newpath) == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",42)
			hx::Throw ((((HX_CSTRING("Could not rename:") + path) + HX_CSTRING(" to ")) + newpath));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FileSystem_obj,rename,(void))

Dynamic FileSystem_obj::stat( ::String path){
	HX_SOURCE_PUSH("FileSystem_obj::stat")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",46)
	Dynamic s = ::sys::FileSystem_obj::sys_stat(path);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",47)
	if (((s == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("gid") , (int)0,false);
					__result->Add(HX_CSTRING("uid") , (int)0,false);
					__result->Add(HX_CSTRING("atime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("mtime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("ctime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("dev") , (int)0,false);
					__result->Add(HX_CSTRING("ino") , (int)0,false);
					__result->Add(HX_CSTRING("nlink") , (int)0,false);
					__result->Add(HX_CSTRING("rdev") , (int)0,false);
					__result->Add(HX_CSTRING("size") , (int)0,false);
					__result->Add(HX_CSTRING("mode") , (int)0,false);
					return __result;
				}
				return null();
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",48)
		return _Function_2_1::Block();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",49)
	s->__FieldRef(HX_CSTRING("atime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("atime"),true)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",50)
	s->__FieldRef(HX_CSTRING("mtime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("mtime"),true)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",51)
	s->__FieldRef(HX_CSTRING("ctime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("ctime"),true)));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",52)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,stat,return )

::String FileSystem_obj::fullPath( ::String relpath){
	HX_SOURCE_PUSH("FileSystem_obj::fullPath")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",55)
	return ::String(::sys::FileSystem_obj::file_full_path(relpath));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,fullPath,return )

::sys::_FileSystem::FileKind FileSystem_obj::kind( ::String path){
	HX_SOURCE_PUSH("FileSystem_obj::kind")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",60)
	::String k = ::sys::FileSystem_obj::sys_file_type(path);
	struct _Function_1_1{
		inline static ::sys::_FileSystem::FileKind Block( ::String &k){
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",61)
				::String _switch_1 = (k);
				if (  ( _switch_1==HX_CSTRING("file"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",62)
					return ::sys::_FileSystem::FileKind_obj::kfile_dyn();
				}
				else if (  ( _switch_1==HX_CSTRING("dir"))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",63)
					return ::sys::_FileSystem::FileKind_obj::kdir_dyn();
				}
				else  {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",64)
					return ::sys::_FileSystem::FileKind_obj::kother(k);
				}
;
;
			}
			return null();
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",61)
	return _Function_1_1::Block(k);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,kind,return )

bool FileSystem_obj::isDirectory( ::String path){
	HX_SOURCE_PUSH("FileSystem_obj::isDirectory")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",68)
	return (::sys::FileSystem_obj::kind(path) == ::sys::_FileSystem::FileKind_obj::kdir_dyn());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,isDirectory,return )

Void FileSystem_obj::createDirectory( ::String path){
{
		HX_SOURCE_PUSH("FileSystem_obj::createDirectory")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",72)
		if (((::sys::FileSystem_obj::sys_create_dir(path,(int)493) == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",74)
			hx::Throw ((HX_CSTRING("Could not create directory:") + path));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,createDirectory,(void))

Void FileSystem_obj::deleteFile( ::String path){
{
		HX_SOURCE_PUSH("FileSystem_obj::deleteFile")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",77)
		if (((::sys::FileSystem_obj::file_delete(path) == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",79)
			hx::Throw ((HX_CSTRING("Could not delete file:") + path));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,deleteFile,(void))

Void FileSystem_obj::deleteDirectory( ::String path){
{
		HX_SOURCE_PUSH("FileSystem_obj::deleteDirectory")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",82)
		if (((::sys::FileSystem_obj::sys_remove_dir(path) == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",84)
			hx::Throw ((HX_CSTRING("Could not delete directory:") + path));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,deleteDirectory,(void))

Array< ::String > FileSystem_obj::readDirectory( ::String path){
	HX_SOURCE_PUSH("FileSystem_obj::readDirectory")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/_std/sys/FileSystem.hx",87)
	return ::sys::FileSystem_obj::sys_read_dir(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,readDirectory,return )

Dynamic FileSystem_obj::sys_exists;

Dynamic FileSystem_obj::file_delete;

Dynamic FileSystem_obj::sys_rename;

Dynamic FileSystem_obj::sys_stat;

Dynamic FileSystem_obj::sys_file_type;

Dynamic FileSystem_obj::sys_create_dir;

Dynamic FileSystem_obj::sys_remove_dir;

Dynamic FileSystem_obj::sys_read_dir;

Dynamic FileSystem_obj::file_full_path;


FileSystem_obj::FileSystem_obj()
{
}

void FileSystem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileSystem);
	HX_MARK_END_CLASS();
}

Dynamic FileSystem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stat") ) { return stat_dyn(); }
		if (HX_FIELD_EQ(inName,"kind") ) { return kind_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"rename") ) { return rename_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fullPath") ) { return fullPath_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_stat") ) { return sys_stat; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deleteFile") ) { return deleteFile_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_exists") ) { return sys_exists; }
		if (HX_FIELD_EQ(inName,"sys_rename") ) { return sys_rename; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isDirectory") ) { return isDirectory_dyn(); }
		if (HX_FIELD_EQ(inName,"file_delete") ) { return file_delete; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_read_dir") ) { return sys_read_dir; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readDirectory") ) { return readDirectory_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { return sys_file_type; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sys_create_dir") ) { return sys_create_dir; }
		if (HX_FIELD_EQ(inName,"sys_remove_dir") ) { return sys_remove_dir; }
		if (HX_FIELD_EQ(inName,"file_full_path") ) { return file_full_path; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"createDirectory") ) { return createDirectory_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteDirectory") ) { return deleteDirectory_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileSystem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"sys_stat") ) { sys_stat=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_exists") ) { sys_exists=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sys_rename") ) { sys_rename=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"file_delete") ) { file_delete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_read_dir") ) { sys_read_dir=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { sys_file_type=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sys_create_dir") ) { sys_create_dir=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sys_remove_dir") ) { sys_remove_dir=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_full_path") ) { file_full_path=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileSystem_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("exists"),
	HX_CSTRING("rename"),
	HX_CSTRING("stat"),
	HX_CSTRING("fullPath"),
	HX_CSTRING("kind"),
	HX_CSTRING("isDirectory"),
	HX_CSTRING("createDirectory"),
	HX_CSTRING("deleteFile"),
	HX_CSTRING("deleteDirectory"),
	HX_CSTRING("readDirectory"),
	HX_CSTRING("sys_exists"),
	HX_CSTRING("file_delete"),
	HX_CSTRING("sys_rename"),
	HX_CSTRING("sys_stat"),
	HX_CSTRING("sys_file_type"),
	HX_CSTRING("sys_create_dir"),
	HX_CSTRING("sys_remove_dir"),
	HX_CSTRING("sys_read_dir"),
	HX_CSTRING("file_full_path"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_exists,"sys_exists");
	HX_MARK_MEMBER_NAME(FileSystem_obj::file_delete,"file_delete");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_rename,"sys_rename");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_stat,"sys_stat");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_file_type,"sys_file_type");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_create_dir,"sys_create_dir");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_remove_dir,"sys_remove_dir");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_read_dir,"sys_read_dir");
	HX_MARK_MEMBER_NAME(FileSystem_obj::file_full_path,"file_full_path");
};

Class FileSystem_obj::__mClass;

void FileSystem_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.FileSystem"), hx::TCanCast< FileSystem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FileSystem_obj::__boot()
{
	hx::Static(sys_exists) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exists"),(int)1);
	hx::Static(file_delete) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_delete"),(int)1);
	hx::Static(sys_rename) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_rename"),(int)2);
	hx::Static(sys_stat) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_stat"),(int)1);
	hx::Static(sys_file_type) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_file_type"),(int)1);
	hx::Static(sys_create_dir) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_create_dir"),(int)2);
	hx::Static(sys_remove_dir) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_remove_dir"),(int)1);
	hx::Static(sys_read_dir) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_read_dir"),(int)1);
	hx::Static(file_full_path) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_full_path"),(int)1);
}

} // end namespace sys
