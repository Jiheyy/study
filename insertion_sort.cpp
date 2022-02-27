#include <iostream>
#include <vector>
using namespace std;

int arr[10] = {8, 6, 5, 3, 1, 2, 7, 4, 9, 0};

void insertion_sort() {
	for(int i=0; i<10; i++) {
		for(int j=0; j<i; j++) {
			// swap
			if(arr[j] > arr[i]) {
				swap(arr[i], arr[j]);
				continue;
			}
		}
	}
}

int main() {

	insertion_sort();

	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}

}