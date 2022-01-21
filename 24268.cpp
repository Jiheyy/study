#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> convert_no(long long no, int d) {
	vector <int> v;
	while(no != 0) {
		v.push_back(no % d);
		no /= d;
	}

	return v;
	
}

vector <int> answer;
bool visit[110];
long long new_n;
vector <long long> m;

void dfs (int idx, int cnt, int target) {
	if(cnt == target) {
		long long ret = 0;
		int idx = 0;
		for(int i=target-1; i>=0; i--) {
			//printf("%d", answer[i]);
			ret += answer[i] * pow(10, idx);
			idx++;
		}
		//printf("\n");ㄴ

		//printf("%llu\n", ret);


		if(ret > new_n) {

			m.push_back(ret);
			//MIN = min(MIN, ret);
		}
		return;
	}
	for(int i=0; i<target; i++) {
		if(visit[i] == true)continue;
		visit[i] = true;
		answer.push_back(i);
		dfs(i, cnt+1, target);
		visit[i] = false;
		answer.pop_back();
	}

}

int main() {

	unsigned long long n;
	int d;
	scanf("%llu %d", &n, &d);
	
	vector <int> v;
	v = convert_no(n, d);

	int idx = 0;
	for(int i=0; i<v.size(); i++) {
		new_n += v[i] * pow(10, i);
	}

	//printf("%d\n", v[v.size()-1]);
	//return 0;
	for(int i=1; i<d; i++) {
		if(v[v.size()-1] > i) continue;
		if(visit[i] == true) continue;
		visit[i] = true;
		answer.push_back(i);
		dfs(i, 1, d);
		visit[i] = false;
		answer.pop_back();
	}

	if(m.size() == 0){
		printf("-1\n");
		exit(0);
	}

	sort(m.begin(), m.end());

	printf("%lld\n", m[0]);
	
	v = convert_no(m[0], 10);
	long long result = 0;
	for(int i=v.size()-1; i>=0; i--) {
		result += v[i] * pow(d, i);
	}

	printf("%llu\n", result);

	return 0;
}