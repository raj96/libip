#!/usr/local/bin

sh ./build.sh
strip libip.so

mkdir -p /usr/include/ip

cp ip.h /usr/include/ip/
cp libip.so /usr/lib/

rm libip.so

export LD_LIBRARY_PATH=/usr/lib/:$LD_LIBRARY_PATH
ldconfig

echo "libip-1.0 installed"
