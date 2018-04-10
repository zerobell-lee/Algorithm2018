#include <stdio.h>
#include <time.h>
#define MAX_SIZE 10

void printArray(char* name, int arr[], int size) {
	printf("%s[%d] : {", name, size);
	for (int i=0; i<size; i++) {
		printf("%d", arr[i]);
		if (i+1!=size)
			printf(", ");
	}
	printf("}\n");
}

void arraySetup(int arr[], int size) {
	srand(time(NULL));
	for (int i=0; i<size; i++) {
		arr[i] = rand()%100;
	}
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[], int start, int end) {
	int pivot=start;
	int L=start;
	int R=end;

	while (L<R) {
		while ((a[L]<=a[pivot])&&(L<end))
			L++;
		while (a[R]>a[pivot])
			R--;
		if (L<R) swap(&a[L], &a[R]);
	}
	swap(&a[pivot],&a[R]);
	return R;
}

void quickSort(int a[], int start, int end) {

	if (start<end) {
		int pivot = partition(a, start, end);
		quickSort(a, start, pivot);
		quickSort(a, pivot+1, end);
	}
}

void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	quickSort(arr, 0, MAX_SIZE-1);	
	printArray("arr", arr, MAX_SIZE);

}
