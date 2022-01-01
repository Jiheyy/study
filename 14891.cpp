#include <iostream>
#include <vector>
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
		tire[no].mag[1] = copy_mag[0];
		tire[no].mag[2] = copy_mag[1];
		tire[no].mag[3] = copy_mag[2];
		tire[no].mag[4] = copy_mag[3];
		tire[no].mag[5] = copy_mag[4];
		tire[no].mag[6] = copy_mag[5];
		tire[no].mag[7] = copy_mag[6];

	}
	else if(dir == -1){
		tire[no].mag[7] = copy_mag[0];
		tire[no].mag[0] = copy_mag[1];
		tire[no].mag[1] = copy_mag[2];
		tire[no].mag[2] = copy_mag[3];
		tire[no].mag[3] = copy_mag[4];
		tire[no].mag[4] = copy_mag[5];
		tire[no].mag[5] = copy_mag[6];
		tire[no].mag[6] = copy_mag[7];
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

	if(tire[0].mag[0] == '1')
		ret += 1;
	if(tire[1].mag[0] == '1')
		ret+= 2;
	if(tire[2].mag[0] == '1')
		ret+= 4;
	if(tire[3].mag[0] == '1')
		ret+= 8;

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
