rm -rf "obj"
echo "compiling for armv6"
haxelib run hxcpp Build.xml -Diphoneos
echo "compiling for armv7"
haxelib run hxcpp Build.xml -Diphoneos -DHXCPP_ARMV7
echo "compiling for simulator"
haxelib run hxcpp Build.xml -Diphonesim
echo "Copying sim"
cp ../ndll/iPhone/libHypFacebook.iphonesim.a ../../../bin/ios/Tests/lib/i386/libHypFacebook.a
echo "Copying sim debug"
cp ../ndll/iPhone/libHypFacebook.iphonesim.a ../../../bin/ios/Tests/lib/i386-debug/libHypFacebook.a
echo "Copying v6"
cp ../ndll/iPhone/libHypFacebook.iphoneos.a ../../../bin/ios/Tests/lib/armv6/libHypFacebook.a
echo "Copying v7"
cp ../ndll/iPhone/libHypFacebook.iphoneos-v7.a ../../../bin/ios/Tests/lib/armv7/libHypFacebook.a
echo "Copying v7 debug"
cp ../ndll/iPhone/libHypFacebook.iphoneos-v7.a ../../../bin/ios/Tests/lib/armv7-debug/libHypFacebook.a
echo "Done !"