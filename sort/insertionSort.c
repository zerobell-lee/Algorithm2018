#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

extern int change;
extern int compare;

extern FILE* insfp;

void insertionSort(int arr[], int size) {

	int val, pos;
	for (int i=1; i<size; i++) {
		
		val = arr[i];	
		change++; //val을 할당했으므로 change가 발생
		
		for (pos=i; pos>0; pos--) {
			
			compare++; //아래 if문에서 비교연산을 하므로 compare 발생
			if (val < arr[pos - 1]) {
				arr[pos] = arr[pos - 1];
				change++; //배열 할당을 했으므로 change 발생
			}
			else
				break;
		}
		
		arr[pos] = val;
		change++; //arr[pos]를 할당했으므로 change 발생
		if (size < 1001)
			fprintArray(arr, size, insfp);
		// printArray("arr", arr, size);
	}
}


/* void main() {

	int arr[ARRAY_SIZE];

	srand(time(NULL));

	for (int i=0; i<ARRAY_SIZE; i++) {

		arr[i] = rand()%1000;

	}
	printArray("arr", arr, ARRAY_SIZE);
	insertionSort(arr, ARRAY_SIZE);

	
	printArray("arr", arr, ARRAY_SIZE);
}
*/