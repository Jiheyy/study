#include <iostream>
#include <vector>
#include <cstdlib>
/*
C++에서는 함수 오버로딩(overloading)이 존재하기 때문에 abs 함수 이름 하나만 존재하지만,,,

이게 좀 이상합니다.

int 타입의 정수 절대값 함수(abs)의 오버로딩은 <cstdlib>에 존재하고,

float, double 타입의 실수 절대값 함수(abs)의 오버로딩은 <cmath>에 존재합니다.



출처: https://blockdmask.tistory.com/335 [개발자 지망생]
*/
using namespace std;

int n;
int arr[21][21];
int res = 987654321;
bool visit[21];
vector <int> team1;
vector <int> team2;


int calculate(vector<int> team) {
	int ret = 0;

	for(int i=0; i<int(team.size())-1; i++) {
		int p1 = team[i];
		for(int j=i+1; j<int(team.size()); j++) {
			int p2 = team[j];
			ret += arr[p1][p2];
			ret += arr[p2][p1];
		}
	}
	return ret;
}
	
		


void DFS(int idx, int cnt, int target_no) {

	if(cnt == target_no) {
		team1.clear();
		team2.clear();
		
		for(int i=0; i<n; i++) {
			if(visit[i]) {
				team1.push_back(i);
			}
			else {
				team2.push_back(i);
			}
		}

		int total1 = calculate(team1);
		int total2 = calculate(team2);

		res = min(res, abs(total1-total2));

		return;
	}

	for(int i=idx; i<n; i++) {
		if(visit[i]) continue;
		visit[i] = 1;
		DFS(i, cnt+1, target_no);
		visit[i] = 0;
	}
	
}


// 조합
int main() {

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);


	DFS(0, 0, n/2);

	printf("%d\n", res);


	return 0;
}