/*
Name: Sumir Vats
Faculty No.: 21COB133
Enrolment No.: GK7140
Sr. No.: 7

Group Partner: Aisha Tanveer
Faculty No.: 21COB164
Enrolment No.: GM6535
Sr. No. 17
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Sorting the array rows
//void sort(int arr[100][100], int rows, int cols) {
//	for (int i=0; i<rows; i++) {
//		for (int j=0; j<cols-1; j++) {
//			for (int k=0; k<cols-j-1; k++) {
//				if(arr[i][k] > arr[i][k+1]) {
//					int temp = arr[i][k];
//					arr[i][k] = arr[i][k+1];
//					arr[i][k+1] = temp;
//				}
//			}
//		}
//	}
//}


void sort(int arr[100][100], int rows, int cols)
{
	int ind = 0;
	// int size = rows*cols;
	int arr1[150];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr1[ind] = arr[i][j];
			ind++;
		}
	}
	for (int j = 0; j < ind - 1; j++)
	{
		for (int k = 0; k < ind - j - 1; k++)
		{
			if (arr1[k] > arr1[k + 1])
			{
				int temp = arr1[k];
				arr1[k] = arr1[k + 1];
				arr1[k + 1] = temp;
			}
		}
	}
	ind = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = arr1[ind];
			ind++;
		}
	}
}

// Implementing Binary Search for each row
int binarySearch(int arr[100][100], int rows, int cols, int s) {
	int comparisions = 0;
	for (int i=0; i<rows; i++) {
		int start = 0;
		int end = cols-1;
		while(start < end) {
			int mid = (start + end)/2;
			comparisions++;
			if (arr[i][mid] == s) {
				printf("Row: %d ", i);
				printf("No. of comparisions made = %d\n", comparisions);
				return mid;
			}
			else if (arr[i][mid] > s) {
				end = mid-1;
			}
			else {
				start = mid+1;
			}
		}
	}
	return -1;
}

int main() {
	
	// input array size
	int rows, cols;
	printf("Input array size\n");
	printf("Rows: ");
	scanf("%d", &rows);
	printf("Columns: ");
	scanf("%d", &cols);

	int arr[100][100];
	
	// generating random array elements
	srand(time(0));
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			arr[i][j] = rand();
		}
	}

	// Printing the array
	printf("Generated array: \n");
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// Sorting the array rows and printing it
	sort(arr, rows, cols);
	printf("Sorted array: \n");
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// Input number to search
	printf("Enter element to search: ");
	int s;
	scanf("%d", &s);

	// Part B
	int ind = binarySearch(arr, rows, cols, s);
	if (ind>=0) printf("Element found at index %d\n", ind);
	else printf("Element not found\n");

	return 0;
}
