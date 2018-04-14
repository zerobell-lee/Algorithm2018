#pragma once
#include <stdio.h>
#include <stdlib.h>


extern int change;
extern int compare;

void merge(int a[], int start, int middle, int end) {
	int* b = (int *)malloc((end - start + 1)*sizeof(int)); //Visual Studio에서는 배열 사이즈를 변수로 할당하는 것이 불가능하다.
	int i = start;
	int j = middle+1;
	change++; change++; //int i, int j
	for (int k=0; k<=(end-start); k++) {
		
		if ((i<=middle)&&(j>end||a[i]<=a[j])) {
			b[k] = a[i];
			i++;
			change++;
			change++; //b[k], i++
		}
		else {
			b[k] = a[j];
			j++;
			change++;
			change++; //b[k], j++
		}
		compare++; //if
	}
	
	for (int k=0; (k<=end-start); k++) {
		a[k+start] = b[k];
		change++; //a[k]
	}
}

void mergeSort(int a[], int start, int end) {

	compare++; //if
	if ((end - start) < 1)
		return;
	int middle = (start+end)/2;
	change++; //middle = 
	mergeSort(a, start, middle);
	mergeSort(a, middle+1, end);
	merge(a, start, middle, end);

}