#include<stdio.h>

int main(int argc, char** argv) {
	char review[64];
	char name[64];
	int i;
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Name: ");
	gets(name);
	printf("Review: ");
	gets(review);
	printf("thanks! for your review, encrypting and storing your review now!");
	return 0;
}