#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



int main() {

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			if(arr[i][j] == 0) {
				
				for(int a=0; a<m; a++)
					arr[i][a] = 0;

				for(int a=0; a<n; a++)
					arr[a][j] = 0;
					
			}
		}
}