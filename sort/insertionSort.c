#pragma once
#include <stdio.h>
#include <stdlib.h>

extern int change;
extern int compare;

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
	}
}

