#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int change = 0;
int compare = 0;

void main() {
	
	printf("???? ????? ?? 201202564 ????? \n");

	FILE* log;
	int* arr[10];
	int* orig[10];
	char buff[1024];

	
	log = fopen("log.csv", "a+");

	for (int i = 0; i < 10; i++)
	{
		int size = (i + 1) * 1000;
		orig[i] = malloc(size * sizeof(int));
		arr[i] = malloc(size * sizeof(int));
		arraySetup(orig[i], size);
	}

	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Selection Sort");
			printf("%s \n", buff);
			break;
		case 1:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Bubble Sort");
			printf("%s \n", buff);
			break;
		case 2:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Insertion Sort");
			printf("%s \n", buff);
			break;
		case 3:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Shell Sort");
			printf("%s \n", buff);
			break;
		case 4:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Merge Sort");
			printf("%s \n", buff);
			break;
		case 5:
			memset(buff, 0x0, sizeof(buff));
			strcpy(buff, "Quick Sort");
			printf("%s \n", buff);
			break;
		}
		
		for (int j = 0; j < 10; j++) {
			int size = (j + 1) * 1000;
			copyArray(orig[j], arr[j], size);
			switch (i) {
				case 0:
					selectionSort(arr[j], size);
					break;
				case 1:
					bubbleSort(arr[j], size);
					break;
				case 2:
					insertionSort(arr[j], size);
					break;
				case 3:
					shellSort(arr[j], size);
					break;
				case 4:
					mergeSort(arr[j], 0, size - 1);
					break;
				case 5:
					quickSort(arr[j], 0, size - 1);
					break;
			}
			printf("size=%d ", size);
			fprintf(log, "%s, %d, %d, %d\n", buff, size, compare, change);
			printf("compare = %d move = %d\n", compare, change);
			compare = 0; change = 0;
		}
		printf("\n");
	}
	
	for(int i = 0; i < 10; i++) {
		free(arr[i]);
		free(orig[i]);
	}
	fclose(log);
	return 0;
}
