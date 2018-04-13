#pragma once
#include <stdio.h>

#define MAX_SIZE 10

extern int change;
extern int compare;

extern FILE* quifp;

int partition(int a[], int start, int end) {
	int pivot=start;
	int L=start;
	int R=end;
	change++; change++; change++; //�� ���� ���� change 3��

	while (L<R) {
		compare++; //while �����鼭 �� �ѹ�
		while ((a[L] <= a[pivot]) && (L < end)) {
			compare++; //while �����鼭 �� �ѹ�
			L++;
			change++; //L���� ����Ǿ����� change �߻�
		}
		compare++; //while�� �������� ������� �ʴ��� ���ǹ��� �ѹ� ��ġ�� �� ���̴� compare �߻�
		while (a[R] > a[pivot]) {
			compare++; //while �����鼭 �� �ѹ�
			R--;
			change++; //R���� ����Ǿ����� change �߻�
		}
		compare++; //while�� �������� ������� �ʴ��� ���ǹ��� �ѹ� ��ġ�� �� ���̴� compare �߻�
		if (L<R) swap(&a[L], &a[R]);
		compare++; //���� if���� �񱳿��� �߻�
	}
	compare++; //while�� �������� ������� �ʴ��� ���ǹ��� �ѹ� ��ġ�� �� ���̴� compare �߻�
	swap(&a[pivot],&a[R]);
	return R;
}

void quickSort(int a[], int start, int end, int size) {

	if (start<end) {
		int pivot = partition(a, start, end);
		if (size < 1001)
			fprintArray(a, size, quifp);
		change++; //pivot �Ҵ��� �Ǿ����� change
		quickSort(a, start, pivot-1, size);
		quickSort(a, pivot+1, end, size);
	}
	compare++; //if�� ������� �ʴ��� �񱳿����� ����ȴ�.
}

/* void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	quickSort(arr, 0, MAX_SIZE-1);	
	printArray("arr", arr, MAX_SIZE);

} */