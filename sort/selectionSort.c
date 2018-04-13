#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

extern int change;
extern int compare;
extern FILE* selfp;



void selectionSort(int arr[], int size) {

	int i, j, min;
	for (i=0; i<size-1; i++) {
		
		min = i;
		change++; //min = i;
		for (j=min; j<size; j++) {
			
			if (arr[min] > arr[j]) {
				min = j;
				change++; // min = j;
			}
			compare++; //if
		}
		swap(&arr[i], &arr[min]);
		if (size < 1001)
			fprintArray(arr, size, selfp);
//		printArray("arr", arr, MAX_SIZE);
	}
//	printArray("arr", arr, MAX_SIZE);

}

/* void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	selectionSort(arr, MAX_SIZE);
	

}
*/