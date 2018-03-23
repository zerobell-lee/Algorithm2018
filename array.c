#include <stdio.h>
#define MAX_LENGTH 100

void printArray(char *name, int a[], int len) {
	printf("%s[%d] = { ", name, len);
	for (int i=0; i<len; i++) {
		printf("%d", a[i]);
		if (i!=len-1)
			printf(",");
	}
	printf(" }\n");
}

int insertElem(int a[], int size, int index, int value) {
	for (int i=size-1; i>=index; i--)
		a[i+1] = a[i];
	a[index] = value;
	return size+1;
}

int deleteElem(int a[], int size, int index) {
	for (int i=index; i<size; i++)
		a[i] = a[i+1];

	return size-1;
}

void main() {
	int list[MAX_LENGTH];
	int size = 5;

	for (int i=0; i<size; i++)
		list[i] = 10 + i*10;

	printf("HW 1. Insert & Delete Element\n");
	printArray("list", list, size);
	size = insertElem(list, size, 3, 200);
	printArray("list", list, size);
	size = insertElem(list, size, 0, 300);
	printArray("list", list, size);
	size = deleteElem(list, size, 3);
	printArray("list", list, size);
	size = deleteElem(list, size, 0);
	printArray("list", list, size);
}


