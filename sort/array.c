#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SHUFFLE 1

extern int change;
extern int compare;

void printArray(char* name, int arr[], int size) {
	printf("%s[%d] : {", name, size);
	for (int i = 0; i<size; i++) {
		printf("%d", arr[i]);
		if (i + 1 != size)
			printf(", ");
	}
	printf("}\n");
}

void fprintArray(int arr[], int size, FILE* fp) {
	for (int i = 0; i<size; i++) {
		fprintf(fp, "%d", arr[i]);
		if (i + 1 != size)
			fprintf(fp, ", ");
	}
	fprintf(fp, "\n");
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	change += 2;
}


void arraySetup(int arr[], int size) {
	srand(time(NULL));
	if (SHUFFLE) {
		int i, j;
		for (i = 0; i < size; i++) {
			arr[i] = i;
		}
		for (i = 0; i < size; i++) {
			j = rand() % (size - i) + i;
			swap(&arr[i], &arr[j]);
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 10000;
		}
	}
}

void copyArray(int a[], int b[], int size) {
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
}

