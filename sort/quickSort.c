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
	change++; change++; change++; //위 세줄 덕에 change 3번

	while (L<R) {
		compare++; //while 들어오면서 비교 한번
		while ((a[L] <= a[pivot]) && (L < end)) {
			compare++; //while 들어오면서 비교 한번
			L++;
			change++; //L값이 변경되었으니 change 발생
		}
		compare++; //while이 마지막에 실행되지 않더라도 조건문을 한번 거치고 온 것이니 compare 발생
		while (a[R] > a[pivot]) {
			compare++; //while 들어오면서 비교 한번
			R--;
			change++; //R값이 변경되었으니 change 발생
		}
		compare++; //while이 마지막에 실행되지 않더라도 조건문을 한번 거치고 온 것이니 compare 발생
		if (L<R) swap(&a[L], &a[R]);
		compare++; //위의 if에서 비교연산 발생
	}
	compare++; //while이 마지막에 실행되지 않더라도 조건문을 한번 거치고 온 것이니 compare 발생
	swap(&a[pivot],&a[R]);
	return R;
}

void quickSort(int a[], int start, int end, int size) {

	if (start<end) {
		int pivot = partition(a, start, end);
		if (size < 1001)
			fprintArray(a, size, quifp);
		change++; //pivot 할당이 되었으니 change
		quickSort(a, start, pivot-1, size);
		quickSort(a, pivot+1, end, size);
	}
	compare++; //if가 실행되지 않더라도 비교연산은 시행된다.
}

/* void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	quickSort(arr, 0, MAX_SIZE-1);	
	printArray("arr", arr, MAX_SIZE);

} */