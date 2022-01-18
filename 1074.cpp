#include <iostream>
#include <cmath>
using namespace std;

// 분할정복


int main() {
	int n, r, c;
	//long long arr[40000][40000];

	int no = -1;

	scanf("%d %d %d", &n, &r, &c);
	int block = 0;
	for(int i=0; i<pow(2, n); i+=2) {
		for(int j=0; j<pow(2, n); j+=2) {

			if(i == r && j == c) {
				printf("%d\n", block*4 + 1);
				break;
			}
			else if(i==r && j+1 == c) {
				printf("%d\n", block*4 + 2);
				break;
			}
			else if(i+1==r && j == c){
				printf("%d\n", block*4 +3);
				break;
			}
			else if(i+1 == r && j+1 == c) {
				printf("%d\n", block* 4 + 3);
				break;
			}

			else
				no += 4;
			/*
			arr[i][j] = ++no;
			arr[i][j+1] = ++no;
			arr[i+1][j] = ++no;
			arr[i+1][j+1] = ++no;
			*/
		}
	}
	/*
	for(int i=0; i<pow(2, n); i++) {
		for(int j=0; j<pow(2, n); j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	*/
	//printf("%d\n", arr[r][c]);
}