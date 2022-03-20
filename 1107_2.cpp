#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int target;
int err;
bool button[10];
int min_answer = 987654321;


void find(string no) {
	for(int i=0; i<10; i++) {
		if(button[i] == false) continue;
		string tmp_no = no + to_string(i);

		int tmp_click = abs(target-stoi(tmp_no)) + tmp_no.size();
		min_answer = min(min_answer, tmp_click);

		if(tmp_no.size() < 6)
			find(tmp_no);
	}
}


int main() {
	scanf("%d", &target);

	scanf("%d", &err);

	memset(button, true, sizeof(button));

	for(int i=0; i<err; i++) {
		int tmp;
		scanf("%d", &tmp);
		button[tmp] = false;
	}

	min_answer = min(abs(target-100), min_answer);

	find("");

	printf("%d\n", min_answer);


}