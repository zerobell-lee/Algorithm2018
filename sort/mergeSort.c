#pragma once
#include <stdio.h>
#include <stdlib.h>


extern int change;
extern int compare;

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

void mergeSort(int a[], int start, int end) {

	compare++; //�Ʒ� if���� �ᱹ �񱳿����� �����ϹǷ� compare �߻�
	if ((end - start) < 1)
		return;
	int middle = (start+end)/2;
	change++; //middle �Ҵ翡�� change �߻�.
	mergeSort(a, start, middle);
	mergeSort(a, middle+1, end);
	merge(a, start, middle, end);

}