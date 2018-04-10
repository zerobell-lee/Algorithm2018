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

void merge(int a[], int start, int middle, int end) {
	int b[end-start+1];
	int i = start;
	int j = middle+1;
	for (int k=0; k<=(end-start); k++) {
		if ((i<=middle)&&(j>end||a[i]<=a[j])) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
	}
	for (int k=0; (k<=end-start); k++) {
		a[k+start] = b[k];
	}
}

void mergeSort(int a[], int start, int end) {

	if ((end - start) < 1)
		return;
	int middle = (start+end)/2;
	mergeSort(a, start, middle);
	mergeSort(a, middle+1, end);
	merge(a, start, middle, end);

}

void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	mergeSort(arr, 0, MAX_SIZE-1);	
	printArray("arr", arr, MAX_SIZE);

}
