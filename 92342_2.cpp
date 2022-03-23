#include <iostream>
#include <string>
#include <vector>
using namespace std;

int scoreResult = -1;
vector <int> ryan, apeach, ryanResult;

pair<int, int> calculate() {
	pair<int, int> score = {0, 0};

	for(int i=0; i<11; i++) {
		if(ryan[i] == apeach[i]) {
			if(ryan[i] == 0 && apeach[i] == 0) continue;
			else
				score.second += (10 -i);
		}
		else {
			if(ryan[i] > apeach[i])
				score.first += (10-i);
			else
				score.second += (10-i);
		}
	}
	return score;
}

void check() {
	pair <int, int> score = calculate();
	int ryanScore = score.first;
	int apeachScore = score.second;
	int diff = ryanScore - apeachScore;
	if(diff <= 0) return;

	if(scoreResult == -1) {
		scoreResult = diff;
		ryanResult = ryan;
	}
	else {
		if(scoreResult == diff) {
			for(int i=10; i>=0; i--) {
				if(ryan[i] != 0 && ryanResult[i] == 0) {
					ryanResult = ryan;
					break;
				}
				else if(ryan[i] == 0 && ryanResult[i] != 0)
					break;
				else if(ryan[i] != 0 && ryanResult[i] != 0) {
					if(ryan[i] > ryanResult[i]) {
						ryanResult = ryan;
						break;
					}
				}
			}
        }
		else if(scoreResult < diff){
            scoreResult = diff;
            ryanResult = ryan;
		}
	}

}
// cnt : 사용한 화살갯수
// idx : 과녁번호
// n : 총 화살갯수
void dfs(int cnt, int idx, int n) {
	if(cnt == n) {
		check();
		return;
	}
	int curArrow = n-cnt; // 화살 몇개 남았는지
	if(idx == 10) { // 마지막이라면 걍 다 화살 버려주는게 이득
		ryan[idx] = curArrow;
		dfs(n, idx+1, n);
		ryan[idx] = 0;
	}
	else {
		// 어피치가 그 점수에 쏜 화살의 개수+1 이 현재 남은 화살보다 적으면 쏴주자
		if(apeach[idx]+1 <= curArrow) {
			ryan[idx] = apeach[idx] + 1;
			dfs(cnt+apeach[idx]+1, idx+1, n);
			ryan[idx] = 0;
		}
		// 쏠 가치가 없는 과녁임
		dfs(cnt, idx+1, n);
	}
}


vector <int> solution(int n, vector <int> info) {
	ryan.resize(11, 0);
	apeach = info;

	dfs(0, 0, n);

	if(scoreResult == -1) {
		ryanResult.push_back(-1);
	}
	return ryanResult;
}