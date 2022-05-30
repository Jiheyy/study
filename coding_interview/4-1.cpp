#include <iostream>
#include <map>
using namespace std;

bool arr[100][100];


bool checkWay(int x, int y, int node_cnt) {

	for(int k=0; k<node_cnt; k++) {
		for(int i=0; i<node_cnt; i++) {
			for(int j=i; j<node_cnt; j++) {
				if(arr[i][k] && arr[k][j]) {
					arr[i][j] = true;
				}
			}
		}
	}

	return arr[x][y];

}

int main() {


	int x, y, node_cnt;

	arr[0][1] = true;
	arr[1][2] = true;
	arr[2][0] = true;
	

	node_cnt = 3;
	x = 0;
	y = 2;
	cout << checkWay(x, y, node_cnt) <<endl;


}
