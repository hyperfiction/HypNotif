﻿haxelib set hxcpp 2.10
rm -rf "obj"
echo "compiling for armv6"
haxelib run hxcpp Build.xml -Diphoneos
echo "compiling for armv7"
haxelib run hxcpp Build.xml -Diphoneos -DHXCPP_ARMV7
echo "compiling for simulator"
haxelib run hxcpp Build.xml -Diphonesim
echo "Copying sim"
cp ../ndll/iPhone/libhypwebview.iphonesim.a ../../../Export/ios/hypertest/lib/i386/libhypwebview.a
echo "Copying v6"
cp ../ndll/iPhone/libhypwebview.iphoneos.a ../../../Export/ios/hypertest/lib/armv6/libHypWebView.a
echo "Copying v7"
cp ../ndll/iPhone/libhypwebview.iphoneos-v7.a ../../../Export/ios/hypertest/lib/armv7/libHypWebView.a
echo "Setting back hxcpp to 2.10.2"
haxelib set hxcpp 2.10.2