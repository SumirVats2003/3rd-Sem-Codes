#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int s) {
	for(int i=0; i<n; i++) {
		if(arr[i] == s) {
			return i;
		}
	}
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

	// Part A
	int ind = linearSearch(arr, n, s);
	if (ind>=0) printf("Element found at index %d", ind);
	else printf("Element not found");

	return 0;
}
