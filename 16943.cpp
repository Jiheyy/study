#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// dfs
// 순열
int a, b;
long long answer = -1;
bool visit[10];
vector <int> arr;
vector <int> choice;

void dfs(int cnt, int target_no) {
	if(cnt == target_no) {
		long long ret = 0;
		int idx = 0;
		for(int i=choice.size()-1; i>=0; i--) {
			ret += choice[i]* pow(10,idx);
			idx++;
		}

		if(ret < pow(10, target_no-1))
			return;
		if(b>ret){
			answer = max(ret, answer);
		}
		return;
	}
	for(int i=0; i<arr.size(); i++) {
		if(visit[i]) continue;
		visit[i] = true;
		choice.push_back(arr[i]);
		dfs(cnt+1, target_no);
		visit[i] = false;
		choice.pop_back();
	}
}

int main() {

	scanf("%d %d", &a, &b);
	int tmp_a = a;
	int tmp_b = b;
	int length = 0;

	while(tmp_a > 0) {
		arr.push_back(tmp_a % 10);
		tmp_a/= 10;
		length++;
	}
	int start_b;
	while(tmp_b > 0){
		start_b = tmp_b % 10;
		tmp_b /= 10;
	}


	for(int i=0; i<arr.size(); i++) {
		if(arr[i] > start_b) continue;
		if(visit[i]) continue;
		visit[i] = true;
		choice.push_back(arr[i]);
		dfs(1, length);
		visit[i] = false;
		choice.pop_back();
	}
	printf("%lld\n",answer);


}