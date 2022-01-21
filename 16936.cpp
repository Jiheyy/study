#include <iostream>
#include <vector>
#include <algorithm>
// 시간초과

using namespace std;
int N;

vector <long long> v;
bool visit[110];
vector <long long> choice;
// 순열을 구하고 이게 되는지 검증

void dfs(int cnt, int target) {
	if(cnt == target) {
		for(int i=0; i<choice.size(); i++) 	
            printf("%lld ", choice[i]);
        exit(0);
	}
	for(int i=0; i<v.size(); i++) {
		if(visit[i] == true) continue;
		
		if(choice.size() >= 1) {
			long long before = choice[cnt-1];
			long long cur = v[i];

			if(before * 2 != v[i] && (before % 3 != 0 || before /3 != v[i])){
				continue;
			}
		}
		
		visit[i] = true;
		choice.push_back(v[i]);
		dfs(cnt+1, target);
		choice.pop_back();
		visit[i] = false;
		
	}
}

int main() {
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}
	
	dfs(0, N);

}