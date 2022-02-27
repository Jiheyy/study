#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mal[4];
bool visit[34];
int res = 0;
int dice[10];

int move(int np, bool chking){
    if(np==5&&chking) return 26;
    else if(np==10&&chking) return 21;
    else if(np==15&&chking) return 29;
    else if(np==20) return 33;
    else if(np==26) return 27;
    else if(np==27) return 28;
    else if(np==28) return 23;
    else if(np==29) return 30;
    else if(np==30) return 31;
    else if(np==31) return 23;
    else if(np==25) return 20;
    else if(np==33) return 33;
    else return np+1;
}

int score(int pos){
    if(pos==26) return 13;
    else if(pos==27) return 16;
    else if(pos==28) return 19;
    else if(pos==21) return 22;
    else if(pos==22) return 24;
    else if(pos==23) return 25;
    else if(pos==24) return 30;
    else if(pos==25) return 35;
    else if(pos==29) return 28;
    else if(pos==30) return 27;
    else if(pos==31) return 26;
    else if(pos==33) return 0;
    else return pos*2;
}


void dfs(int cnt, int total) {
	if(cnt == 10) {
		res = max(total, res);
		return;
	}

	for(int i=0; i<4; i++) {
		int cur = mal[i];
		int next = cur;
		int dist = dice[cnt];
		// 방향 변경
		if(next == 5 || next == 10 || next == 15) {
			dist--;
			next = move(next, true);
		}
		while(dist--) {
			next = move(next, false);
		}
		// 말이 이동을 마치는 칸에 다른 말이 있으면 그 말은 고를 수 없다. 
		// 단 이동을 마치는 칸이 도착칸이면 고를수 있다
		if(next != 33 && visit[next]) continue;
		mal[i] = next;
		visit[cur] = false;
		visit[next] = true;

		dfs(cnt+1, total+score(next));

		mal[i] = cur;
		visit[cur] = true;
		visit[next] = false;
	}
}


int main() {

	for(int i=0; i<10; i++)
		scanf("%d", &dice[i]);

	dfs(0, 0);

	printf("%d\n", res);


}