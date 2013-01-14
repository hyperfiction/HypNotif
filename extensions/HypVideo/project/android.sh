rm -rf "obj"
rm ../ndll/Android/libHypVideo.so
echo "Compiling for armv6"
haxelib run hxcpp Build.xml -Dandroid
echo "Copying..."
cp ../ndll/Android/libHypVideo.so ../../../bin/android/bin/libs/armeabi/libHypVideo.so