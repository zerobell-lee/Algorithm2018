#pragma once
#include <stdio.h>


extern int change;
extern int compare;

int partition(int a[], int start, int end) {
	int pivot=start;
	int L=start;
	int R=end;
	change++; change++; change++; //pivot, L, R 할당에 세번 발생

	while (L<R) {
		compare++; //while 조건문에서 비교 발생
		while ((a[L] <= a[pivot]) && (L < end)) {
			compare++; //while 조건문에서 비교 발생
			L++;
			change++; //L값 증가
		}
		compare++; //while이 실행되지 않을 때도 비교 연산은 수행된 후이므로 비교횟수 상승
		while (a[R] > a[pivot]) {
			compare++; //while 
			R--;
			change++; //R값 감소
		}
		compare++; //while. 이유는 상술한 바와 같음.
		if (L<R) swap(&a[L], &a[R]);
		compare++; //위의 if
	}
	compare++; //while. 설명 생략
	swap(&a[pivot],&a[R]);
	return R;
}

void quickSort(int a[], int start, int end) {

	if (start<end) {
		int pivot = partition(a, start, end);
		change++; //pivot
		quickSort(a, start, pivot-1);
		quickSort(a, pivot+1, end);
	}
	compare++; //if수행 되었으니
}
