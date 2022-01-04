#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Tire {
	char mag[10];
	int dir;

};

Tire tire[4];
int k;

void initTire() {

	for(int i=0; i<4; i++) {
		tire[i].dir = 0;
	}
}

void turnTire(int no, int dir) {
	char copy_mag[8];

	for(int i=0; i<8; i++)
		copy_mag[i] = tire[no].mag[i];

	// clockwise
	if (dir == 1) {
		tire[no].mag[0] = copy_mag[7];
		for(int i=1; i<8; i++)
			tire[no].mag[i] = copy_mag[i-1];

	}
	else if(dir == -1){
		tire[no].mag[7] = copy_mag[0];
		for(int i=0; i<7; i++)
			tire[no].mag[i] = copy_mag[i+1];
	}

}

void solve(int tire_no, int dir) {

	tire[tire_no].dir = dir;

	// -> check
	for(int no = tire_no; no < 3; no++) {

		// do not turn
		if (tire[no].mag[2] == tire[no+1].mag[6]) {
			break;
		}
		else {
			tire[no+1].dir = tire[no].dir * -1;
		}
	}

	// <- check
	for(int no = tire_no; no >= 1; no--) {
		
		// do not turn
		if(tire[no].mag[6] == tire[no-1].mag[2]) {
			break;
		}
		else {
			tire[no-1].dir = tire[no].dir * -1;
		}
	}
	
	// change into new pos
	for(int i=0; i<4; i++) {
		if(tire[i].dir != 0)
			turnTire(i, tire[i].dir);
	}
	
}


int count() {
	int ret = 0;

	for(int i=0; i<4; i++)
		if(tire[i].mag[0] == '1')
			ret += pow(2, i);
	return ret;
	
}

int main() {

	for(int i=0; i<4; i++) {
		cin >> tire[i].mag;
	}

	scanf("%d", &k);

	while(k--) {

		int tire_no, dir;
		scanf("%d %d", &tire_no, &dir);
		tire_no--;

		solve(tire_no, dir);
		initTire();
	}

	int res = count();

	printf("%d\n", res);

	return 0;
}
