#pragma once
#include <stdio.h>
#include <stdlib.h>

extern int change;
extern int compare;


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

	}


}
