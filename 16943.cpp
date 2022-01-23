#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// dfs
// 순열
long long a, b;
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
	}n
}

int main() {

	scanf("%lld %lld", &a, &b);
	long long tmp_a = a;
	long long tmp_b = b;
	int length = 0;

	while(tmp_a > 0) {
		arr.push_back(tmp_a % 10);
		tmp_a/= 10;
		length++;
	}


	for(int i=0; i<int(arr.size()); i++) {
		if(visit[i]) continue;
		visit[i] = true;
		choice.push_back(arr[i]);
		dfs(1, length);
		visit[i] = false;
		choice.pop_back();
	}
	
	printf("%lld\n",answer);


}