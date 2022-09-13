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

void sort(int arr[], int n) {
	for (int j=0; j<n-1; j++) {
		for (int k=0; k<n-j-1; k++) {
			if(arr[k] > arr[k+1]) {
				int temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
			}
		}
	}
}

int linearSearch(int arr[], int n, int s) {
	int comparisions = 0;
	for(int i=0; i<n; i++) {
		comparisions++;
		if(arr[i] == s) {
			return i;
		}
	}
	printf("No. of comparisions made = %d\n", comparisions);
	return -1;
}

int binarySearch(int arr[], int n, int s) {
	sort(arr, n);
	int comparisions = 0;
	int start = 0;
	int end = n-1;
	while(start < end) {
		comparisions++;
		int mid = (start + end)/2;
		if (arr[mid] == s) {
			return mid;
		}
		else if (arr[mid] > s) {
			end = mid-1;
		}
		else {
			start = mid+1;
		}
	}
	printf("No. of comparisions made = %d\n", comparisions);
	return -1;
}

int main() {
	
	// input array size
	int n;
	printf("Input array size: ");
	scanf("%d", &n);

	int arr[100];
	
	// generating random array elements
	srand(time(0));
	for (int i=0; i<n; i++) {
		arr[i] = rand();
		// printf("%d ", arr[i]);
	}

	// Input number to search
	printf("Enter element to search: ");
	int s;
	scanf("%d", &s);

	printf("Implement Linear Search(1) or Binary Search(2): ");
	int choice;
	scanf("%d", &choice);

	// Part A
	int ind;
	
	if (choice == 1) ind = linearSearch(arr, n, s);
	else ind = binarySearch(arr, n, s);

	if (ind>=0) printf("Element found at index %d\n", ind);
	else printf("Element not found\n");

	return 0;
}
