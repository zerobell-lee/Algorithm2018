#pragma once
#include <stdio.h>

#define MAX_SIZE 10

extern int change;
extern int compare;

extern FILE* merfp;

void merge(int a[], int start, int middle, int end) {
	int* b = (int *)malloc((end - start + 1)*sizeof(int)); //Visual Studio에서는 배열의 크기가 변수로 지정되지 않는다.
	int i = start;
	int j = middle+1;
	change++; change++; //위의 i와 j가 할당되었으므로 change 2번 발생
	for (int k=0; k<=(end-start); k++) {
		
		if ((i<=middle)&&(j>end||a[i]<=a[j])) {
			b[k] = a[i];
			i++;
			change++;
			change++; //위에서 할당이 두번 일어났으니 이것도 두번
		}
		else {
			b[k] = a[j];
			j++;
			change++;
			change++; //마찬가지
		}
		compare++; //if을 거쳐왔으므로 change 발생
	}
	
	for (int k=0; (k<=end-start); k++) {
		a[k+start] = b[k];
		change++; //윗줄에서 발생한 change
	}
}

void mergeSort(int a[], int start, int end, int size) {

	compare++; //아래 if에서 결국 비교연산을 수행하므로 compare 발생
	if ((end - start) < 1)
		return;
	int middle = (start+end)/2;
	change++; //middle 할당에서 change 발생.
	mergeSort(a, start, middle, size);
	mergeSort(a, middle+1, end, size);
	merge(a, start, middle, end);
	if (size < 1001)
		fprintArray(a, size, merfp);

}

/* void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	mergeSort(arr, 0, MAX_SIZE-1);	
	printArray("arr", arr, MAX_SIZE);

}
*/