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

#include <iostream>
#include <ctime>
using namespace std;

class BubbleSort {
private:
	int* arr;
	int size;
public:
	void swap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void display() {
		for(int i=0; i<this->size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << "\n";
	}

	BubbleSort(int a[], int size) {
		this->size = size;
		this->arr = new int[size];

		for(int i=0; i<size; i++) {
			this->arr[i] = a[i];
		}

		for(int i=0; i<this->size-1; i++) {
			for(int j=0; j<(this->size)-i-1; j++) {
				if (this->arr[j] > this->arr[j + 1]) {
					swap(&this->arr[j],&this->arr[j+1]);
				}
			}
		}
	}
};

int main() {
	int n;
	cout << "Enter array size: ";
	cin >> n;

	int arr[n];
	srand(time(0));
	for(int i=0; i<n; i++) {
		arr[i] = rand();
	}

	BubbleSort b1(arr, n);
	b1.display();
	return 0;
}
