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

void selectionSort(int arr[], int size) {

	int i, j, min;
	for (i=0; i<size-1; i++) {
		min = i;
		for (j=min; j<size; j++) {
			if (arr[min]>arr[j])
				min = j;	
		}
		swap(&arr[i], &arr[min]);
		printArray("arr", arr, MAX_SIZE);
	}
	printArray("arr", arr, MAX_SIZE);

}

void main(int argc, char* argv[]) {
	int arr[MAX_SIZE];
	
	arraySetup(arr, MAX_SIZE);
	printArray("arr", arr, MAX_SIZE);

	selectionSort(arr, MAX_SIZE);
	

}
