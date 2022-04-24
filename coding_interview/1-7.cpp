#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int main() {

	for(int x=0; x<n; x++){
		for(int y=0; y<n; y++) {
			map[x][y] = map[y][x];
		}
	}
}