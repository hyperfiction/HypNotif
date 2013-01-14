rm -rf "obj"
echo "compiling for armv6"
haxelib run hxcpp Build.xml -Diphoneos
echo "compiling for armv7"
haxelib run hxcpp Build.xml -Diphoneos -DHXCPP_ARMV7
echo "compiling for simulator"
haxelib run hxcpp Build.xml -Diphonesim
echo "Copying sim"
cp ../ndll/iPhone/libHypVideo.iphonesim.a ../../../bin/ios/Tests/lib/i386/libHypVideo.a
echo "Copying sim debug"
cp ../ndll/iPhone/libHypVideo.iphonesim.a ../../../bin/ios/Tests/lib/i386-debug/libHypVideo.a
echo "Copying v6"
cp ../ndll/iPhone/libHypVideo.iphoneos.a ../../../bin/ios/Tests/lib/armv6/libHypVideo.a
echo "Copying v7"
cp ../ndll/iPhone/libHypVideo.iphoneos-v7.a ../../../bin/ios/Tests/lib/armv7/libHypVideo.a
echo "Copying v7 debug"
cp ../ndll/iPhone/libHypVideo.iphoneos-v7.a ../../../bin/ios/Tests/lib/armv7-debug/libHypVideo.a
echo "Done !"