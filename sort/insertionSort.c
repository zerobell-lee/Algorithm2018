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
		change++; //val�� �Ҵ������Ƿ� change�� �߻�
		
		for (pos=i; pos>0; pos--) {
			
			compare++; //�Ʒ� if������ �񱳿����� �ϹǷ� compare �߻�
			if (val < arr[pos - 1]) {
				arr[pos] = arr[pos - 1];
				change++; //�迭 �Ҵ��� �����Ƿ� change �߻�
			}
			else
				break;
		}
		
		arr[pos] = val;
		change++; //arr[pos]�� �Ҵ������Ƿ� change �߻�
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