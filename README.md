A decpresss dynamic link library implemented by golang

For linux,
1. build libdecompress.so
go build -buildmode=c-shared -o libdecompress.so gx.io/cgo/decompress

example guest program:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libdecompress.h"

int main(int argc, char* argv[]) {
	if(argc < 3) {
		printf("Usage: %s src_file dst_path\n", argv[0]);
		exit(1);
	}
	GoString file = {argv[1], strlen(argv[1])};
	GoString path = {argv[2], strlen(argv[2])};
	int i = extract(file, path);
	printf("i=%d\n", i);
}

2. build decompress(demo program to use libdecompress.so)
gcc -o decompress  main.c -Wl,-rpath-link . -L. -ldecompress

3. run test program
LD_LIBRARY_PATH=. ./decompress compressed_file dest_path
