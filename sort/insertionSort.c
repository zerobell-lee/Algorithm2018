#pragma once
#include <stdio.h>
#include <stdlib.h>

extern int change;
extern int compare;

void insertionSort(int arr[], int size) {

	int val, pos;
	for (int i=1; i<size; i++) {
		
		val = arr[i];	
		change++; //val = arr[i]
		
		for (pos=i; pos>0; pos--) {
			
			compare++; //if
			if (val < arr[pos - 1]) {
				arr[pos] = arr[pos - 1];
				change++; //arr[pos] = arr[pos-1]
			}
			else
				break;
		}
		
		arr[pos] = val;
		change++; //arr[pos] = val
	}
}

