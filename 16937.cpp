#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int h, w;
int n;

// 너비로 단순희 생각을 해서 될게 아니네...
// 사실 제일 큰거를 붙인다고 정석인 건 아니지
// 조합을 구하고 그 다음 크기들을 확인해주어야함
bool visit[100];
int answer = 0;
struct Sticker
{
	int y, x, no;	
};
vector <Sticker> v;

int choose[2];
void dfs(int idx, int cnt, int target_no) {
	if(cnt == target_no) {
		int ax = v[choose[0]].x;
		int ay = v[choose[0]].y;
		int bx = v[choose[1]].x;
		int by = v[choose[1]].y;
		int dimen = (ax*ay) + (bx*by);
		// put sticker
		if(ax + bx <= h) {
			if(max(ay, by) <= w)
				answer = max(dimen, answer);
		}
		if(ay + by <= w){
			if(max(ax, bx) <= h)
				answer = max(dimen, answer);
		}
		return;
	}
	for(int i=idx; i<v.size(); i++) {
		int sticker_no = v[i].no; 
		if(visit[sticker_no] == true) continue;
		visit[sticker_no] = true;
		choose[cnt] = i;
		dfs(i, cnt+1, target_no);
		visit[sticker_no] = false;
	}
}

int main() {

	scanf("%d %d", &h, &w);

	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int r, c;
		Sticker st;
		scanf("%d %d", &r, &c);
		st.y = c;
		st.x = r;
		st.no = i;
		v.push_back(st);
		if(r != c) {
			st.y = r;
			st.x = c;
			st.no = i;
 			v.push_back(st);
		}
	}

	dfs(0, 0, 2);

	printf("%d\n", answer);

	
}
