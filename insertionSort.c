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

void insertionSort(int arr[], int size) {

	int val, pos;
	for (int i=1; i<size; i++) {
		val = arr[i];	
				
		for (pos=i; pos>0; pos--) {

			if (val<arr[pos-1])
				arr[pos]=arr[pos-1];
			else
				break;
		}
		arr[pos] = val;
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
	insertionSort(arr, ARRAY_SIZE);

	
	printArray("arr", arr, ARRAY_SIZE);
}
