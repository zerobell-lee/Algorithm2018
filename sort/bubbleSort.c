#pragma once
#include <stdio.h>

extern int change;
extern int compare;

void bubbleSort(int arr[], int size) {

	int i, j, flag;
	for (i=size-1; i>0; i--) {
		flag = 0;
		change++; //flag 할당에서 사용
		for (j=0; j<i; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 1;
				change++; //flag
			}
			change++;
			compare++;
		}
		compare++; //아래 !flag 판별에 사용
		if (!flag)
			break;
	}
}
