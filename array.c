/*
201202564 일본어학전공
이영종
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100


void printArray(char *name, int a[], int len) {
	printf("%s[%d] = { ", name, len);
	for (int i=0; i<len; i++) { //size가 0인 array는 내용을 출력하지 않는다.
		printf("%d", a[i]);
		if (i!=len-1)
			printf(","); //마지막 요소가 아닐 경우에만 쉼표를 출력한다.
		if (i==MAX_LENGTH)
			break; //배열의 최대 사이즈를 넘게 출력하지 않는다.
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

	srand(time(NULL));

	for (int i=0; i<size; i++)
		list[i] = i + rand()%20; 

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


