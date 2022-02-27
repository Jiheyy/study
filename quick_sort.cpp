#include <iostream>
#include <vector>
using namespace std;

vector <int> arr(10);

void quick_sort(int start, int end) {
	printf("start %d end  %d\n", start, end);
	if(start >= end) return;

	int pivot = start;
	int i = start + 1;
	int j = end;
	printf("\n------before-----------\n");
	for(int i=start; i<end; i++)
		printf("%d ", arr[i]);


	while(i <= j) {
		while(i <= end && arr[i] < arr[pivot])
			i++;
		while(j >= start && arr[j] > arr[pivot])
			j--;

		if(i > j) {
			printf("swap 1 : %d %d\n", arr[j], arr[pivot]);
			swap(arr[j], arr[pivot]);
		}
		else {
			printf("swap 2 : %d %d\n", arr[i], arr[j]);
			swap(arr[i], arr[j]);
		}
	}
	for(int i=start; i<end; i++)
		printf("%d ", arr[i]);
	printf("\n-----------------\n");
	quick_sort(start, j-1);
	quick_sort(j+1, end);
}



int main() {
	arr = {0, 6, 5, 3, 1, 2, 7, 4};
	quick_sort(0, 7);

	for(int i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}

}