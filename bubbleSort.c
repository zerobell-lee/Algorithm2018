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
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int arr[], int size) {

	int i, j, flag;
	for (i=size; i>0; i--) {
		flag = 0;
		for (j=0; j<i; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		printArray("arr", arr, MAX_SIZE);
		if (!flag)
			break;
	}
}

void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	bubbleSort(arr, MAX_SIZE);
	

}
