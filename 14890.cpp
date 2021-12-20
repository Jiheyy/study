#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
int arr[200][110];



int main(int argc, char ** argv) {

	int answer = 0;

	scanf("%d %d", &N, &L);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);


	// 90 도 돌려 밑에다가 가져다 붙이기
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			arr[N+i][j] = arr[j][i];


	// horiziontal
	for(int i=0; i< 2*N ; i++) {
		bool success = true;
		int count = 1 ;
		for(int j=0; j<N-1; j++)
			if(arr[i][j] == arr[i][j+1]) {
				count++;
			}

			// 오르막 && 경사로를 놓을 수 있으면
			else if(arr[i][j]+1 == arr[i][j+1] && count >= L) {
				count = 1;
			}
			// 내리막 && 
			else if(arr[i][j]-1 == arr[i][j+1] && count >= 0)
				count = 1-L;

			else {
				success = false;
				break;
			}

		if(success == true && count >= 0)
			answer++;
			
	}


	printf("%d\n", answer);

	return 0;

}