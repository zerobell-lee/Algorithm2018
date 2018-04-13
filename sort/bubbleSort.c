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
		change++; //���� flag�� �Ҵ������Ƿ� change�� ����.
		for (j=0; j<i; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 1;
				change++; //���� flag�� �Ҵ������Ƿ� change�� ����.
			}
			change++;
			compare++;
		}
		if (size < 1001)
			fprintArray(arr, size, bubfp);
//		printArray("arr", arr, MAX_SIZE);
		compare++; //�Ʒ� flag �Ǻ��� �ϹǷ� compare�� ����.
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