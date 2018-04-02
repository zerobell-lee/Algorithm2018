#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10

void printArray(char* name, int arr[], int size) {
	printf("%s = {", name);
	for (int i=0; i<size; i++) {
		printf("%d", arr[i]);
		if (i!=size-1)
			printf(", ");	
	}
	printf("}\n");
}

void insertionSort2(int arr[], int first, int last, int h) {

	int val, pos;
	for (int i=first; i<=last; i = i+h) {
		val = arr[i];	
				
		for (pos=i; pos>first; pos= pos-h) {

			if (val<arr[pos-h])
				arr[pos]=arr[pos-h];
			else
				break;
		}
		arr[pos] = val;
	}
}

void shellSort(int arr[], int size) {

	int h, i;
	for (h=(size/2); h>0; h=(h/2))
		for (i=0; i<h; i++) {
			insertionSort2(arr, i, size-1, h);
			printArray("arr", arr, size);

		}
}


void main() {

	int arr[ARRAY_SIZE];

	srand(time(NULL));

	for (int i=0; i<ARRAY_SIZE; i++) {

		arr[i] = rand()%1000;

	}
	printArray("arr", arr, ARRAY_SIZE);
	shellSort(arr, ARRAY_SIZE);

	
	printArray("arr", arr, ARRAY_SIZE);
}
