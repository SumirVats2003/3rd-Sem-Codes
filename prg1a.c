#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int s) {
	int comparisions = 0;
	for(int i=0; i<n; i++) {
		comparisions++;
		if(arr[i] == s) {
			return i;
		}
	}
	printf("No. of comparisions made = %d", comparisions);
	return -1;
}

int binarySearch(int arr[], int n, int s) {
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
	printf("No. of comparisions made = %d", comparisions);
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

	if (ind>=0) printf("Element found at index %d", ind);
	else printf("Element not found");

	return 0;
}
