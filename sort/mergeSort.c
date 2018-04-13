#pragma once
#include <stdio.h>

#define MAX_SIZE 10

extern int change;
extern int compare;

extern FILE* merfp;

void merge(int a[], int start, int middle, int end) {
	int* b = (int *)malloc((end - start + 1)*sizeof(int)); //Visual Studio������ �迭�� ũ�Ⱑ ������ �������� �ʴ´�.
	int i = start;
	int j = middle+1;
	change++; change++; //���� i�� j�� �Ҵ�Ǿ����Ƿ� change 2�� �߻�
	for (int k=0; k<=(end-start); k++) {
		
		if ((i<=middle)&&(j>end||a[i]<=a[j])) {
			b[k] = a[i];
			i++;
			change++;
			change++; //������ �Ҵ��� �ι� �Ͼ���� �̰͵� �ι�
		}
		else {
			b[k] = a[j];
			j++;
			change++;
			change++; //��������
		}
		compare++; //if�� ���Ŀ����Ƿ� change �߻�
	}
	
	for (int k=0; (k<=end-start); k++) {
		a[k+start] = b[k];
		change++; //���ٿ��� �߻��� change
	}
}

void mergeSort(int a[], int start, int end, int size) {

	compare++; //�Ʒ� if���� �ᱹ �񱳿����� �����ϹǷ� compare �߻�
	if ((end - start) < 1)
		return;
	int middle = (start+end)/2;
	change++; //middle �Ҵ翡�� change �߻�.
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