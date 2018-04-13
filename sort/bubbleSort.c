#pragma once
#include <stdio.h>
#define MAX_SIZE 10

extern int change;
extern int compare;

extern FILE* bubfp;

void bubbleSort(int arr[], int size) {

	int i, j, flag;
	for (i=size-1; i>0; i--) {
		flag = 0;
		change++; //위에 flag를 할당했으므로 change가 들어간다.
		for (j=0; j<i; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 1;
				change++; //위에 flag를 할당했으므로 change가 들어간다.
			}
			change++;
			compare++;
		}
		if (size < 1001)
			fprintArray(arr, size, bubfp);
//		printArray("arr", arr, MAX_SIZE);
		compare++; //아래 flag 판별을 하므로 compare가 들어간다.
		if (!flag)
			break;
	}
}

/* void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	bubbleSort(arr, MAX_SIZE);
	

}
*/