#include <iostream>
#include <vector>
using namespace std;

int arr[10] = {8, 6, 5, 3, 1, 2, 7, 4, 9, 0};


void selection_sort() {

	for(int i=0; i<10; i++) {
		int min = arr[i];
		int target = i;
		for(int j=i+1; j<10; j++) {
			if(min > arr[j]) {
				target = j;
				min = arr[j];
			}
		}
		swap(arr[i], arr[target]);
	}
}

int main() {

	selection_sort();

	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}

}