#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

struct POSI {
	int y, x;
};

int n, m, type, answer;

vector <POSI> house, shop, pick;


void DFS(int pos) {

	if(pick.size() == m) {

		int ret = 0;
		for(const auto h: house) {
			int min_dis = INF;
			for(const auto p: pick){
				min_dis = min(min_dis, 
					abs(h.y - p.y) + abs(h.x - p.x));
			}
			ret += min_dis;
 		}

 		if (answer > ret)
 			answer = ret;

		return;
	}

	for(int i=pos; i<shop.size(); i++) {
		pick.push_back(shop[i]);
		DFS(i+1);
		pick.pop_back();
	}

}


int main() {

	scanf("%d %d", &n, &m);
	POSI target;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			scanf("%d", &type);
			target.y = i;
			target.x = j;

			if(type == 1) {
				house.push_back(target);
			}
			else if(type == 2) {
				shop.push_back(target);
			}
		}

	answer = INF;
	DFS(0);


	printf("%d\n", answer);
	return 0;
}