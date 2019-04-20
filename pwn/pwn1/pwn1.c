#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __(char* buffer) {
	int len = strlen(buffer);
	int i;
	for(i =0 ; i<len; i++) {
		if(i%2==0) {
			buffer[i]=buffer[i]+10;
		} else {
			buffer[i]=buffer[i]-10;		
		}
	}
	printf(buffer);
}	

int main(int argc, char** argv) {
	char buffer[64];
	printf("if you want pwn you get pwn!, now give me a shellcode to execute: ");
	setvbuf(stdout, NULL, _IONBF, 0);
	gets(buffer);
	__(buffer);
	exit(0);
}
