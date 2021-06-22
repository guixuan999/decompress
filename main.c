/*
  1. This is test program for libapi.so and libchttpd.so
  2. libapi.so and libchttpd.so are linked in "guest C program"
  3. This test program is an example for "guest C program" on how to use libapi.so and libchttpd.so
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libdecompress.h"


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

