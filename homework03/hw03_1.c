#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 새로운 주소로 변환하는 함수
char* addrParser(char *src) {
	char *dst;
	char *src1 = "/";
	char *dst1 = "mysite/index.html";
	char *src2 = "/tmp.html";
	char *dst2 = "mysite/tmp.html";
	char *src3 = "/foo/bar.html";
	char *dst3 = "mysite/foo/bar.html";
	char *errDst = "mysite/err.html";

	if (!src) return NULL;

	if (strcmp(src, src1)==0) {
		return dst1;
	} else if (strcmp(src, src2)==0) {
		return dst2;
	} else if (strcmp(src, src3)==0) {
		return dst3;
	} else {
		return errDst;
	}
}

// 메세지중 주소만 따오는 함수
char* getAddr(char *src) {
	char *addr;
	char space = ' ';
	int i = 0;
	if(!src) return NULL;

	addr = (char*)malloc(sizeof(char)*200);
	src = strchr(src, '/');

	while(*src != space) {
		*(addr+i) = *src;
		src++;
		i++;
	}
	
	*(addr+i) = (char)NULL;

	return addr;
}

