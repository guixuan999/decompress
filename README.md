A decpresss dynamic link library implemented by golang

For linux,
1. build libdecompress.so
go build -buildmode=c-shared -o libdecompress.so gx.io/cgo/decompress

2. build decompress(demo program to use libdecompress.so)
gcc -o decompress  main.c -Wl,-rpath-link . -L. -ldecompress

3. run test program
LD_LIBRARY_PATH=. ./decompress compressed_file dest_path
