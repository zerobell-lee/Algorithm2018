#pragma once
#include <stdio.h>
#include <stdlib.h>

extern int change;
extern int compare;

void insertionSort2(int arr[], int first, int last, int h) {

	int val, pos;
	for (int i=first; i<=last; i = i+h) {
		
		val = arr[i];	
		change++; //val
				
		for (pos=i; pos>first; pos= pos-h) {
			
			compare++; //if
			if (val < arr[pos - h]) {
				arr[pos] = arr[pos - h];
				change++; //arr
			}
			else
				break;
		}
		
		arr[pos] = val;
		change++; //arr
	}
}

void shellSort(int arr[], int size) {

	int h, i;
	for (h = (size / 2); h > 0; h = (h / 2)) {
		
		for (i = 0; i < h; i++) {
			
			insertionSort2(arr, i, size - 1, h);
		}
		
	}
	
}
