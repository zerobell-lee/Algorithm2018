#pragma once
#include <stdio.h>


extern int change;
extern int compare;

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

void quickSort(int a[], int start, int end) {

	if (start<end) {
		int pivot = partition(a, start, end);
		change++; //pivot �Ҵ��� �Ǿ����� change
		quickSort(a, start, pivot-1);
		quickSort(a, pivot+1, end);
	}
	compare++; //if�� ������� �ʴ��� �񱳿����� ����ȴ�.
}
