#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int target;
int err;
bool button[10];
int min_answer = 987654321;

// 버튼 누르기
void solve(int target) {

	string str_target = to_string(target);

	int choice = 0;
	int click = 0;

	for(int i=1; i<=str_target.size(); i++) {
		int target_tmp = stoi(str_target.substr(0, i));

		int diff = 987654321;
		int n_botton = -1;
		for(int i=0; i<10; i++) {
			if(button[i] == false) continue;
			if(diff > abs(target_tmp - ((choice*10) +i))) {
				n_botton = i;
				diff =  abs(target_tmp - ((choice*10) +i));
			}
		}
		if(n_botton != -1) {
			click++;
			choice = choice * 10 + n_botton;
		}
		else
			return;
	}

	int diff = abs(target - choice);

	min_answer = min(click+diff, min_answer);

}


int main() {
	scanf("%d", &target);

	min_answer = min(abs(target-100), min_answer);

	scanf("%d", &err);

	memset(button, true, sizeof(button));

	for(int i=0; i<err; i++) {
		int tmp;
		scanf("%d", &tmp);
		button[tmp] = false;
	}

	solve(target);

	printf("%d\n", min_answer);


}