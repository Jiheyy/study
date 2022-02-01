// 속이 차있는 (-1 이거나, 본인의 숫자이거나) 작사각형이 존재하는 지 확인 
// 	bfs -> visit 를 확인한다.
// answer queue 에 넣는다.
// 그 직사각형을 -1 로 변경한다.

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <char> cards;
char map[51][51];
bool visit[51][51];
bool checker[51][51];
vector <char> answer;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

struct CARD {
	char value;
	bool visit[51][51];
};

vector <CARD> card;

// 이걸 어떻게 하지...
bool checkSquare(bool tmp_visit[][51], char value) {

	int sy, sx;
	int x = 987654321;
	int y = 987654321;

	for(int i=0; i<n; i++){
		bool start = false;
		for(int j=0; j<m; j++){
			if(tmp_visit[i][j]) {
				sy = i; sx = j;
				start = true;
				break;
			}
		}
		if(start)
			break;
	}

	printf("%d %d\n", sy, sx);
	
	for(int i=0; i<n; i++){
		int row = 0;
		for(int j=0; j<m; j++){
			row += tmp_visit[i][j];
		}
		x = min(row, x);
	}

	for(int i=0; i<m; i++) {
		int height = 0;
		for(int j=0; j<n; j++) {
			height += tmp_visit[j][i];
		}
		y = min(height, y);
	}

	for(int i=0; i<y; i++)
		for(int j=0; j<x; j++) {
			if(map[sy+i][sx+j] != value && map[sy+i][sx+j] != '/') {
				printf("%c is not squre\n", value);
				return false;
			}
		}

	return true;
}

void deleteValue(bool tmp_visit[][51], bool checker[][51]) {
	printf("deleteValue\n");

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(tmp_visit[i][j]) {
				map[i][j] = '/';
				visit[i][j] = true;
			}
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d", tmp_visit[i][j]);
		}printf("\n");
	}
}

bool checkExist(bool visit[][51], char value) {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(visit[i][j] == false && map[i][j] == value)
				return true;

	return false;
}

void bfs(char value, int y, int x) {
	cout << "start bfs"<< value <<endl;

	CARD c;
	c.value = value;
	memset(c.visit, false, sizeof(c.visit));

	printf("\n---------\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	//bool tmp_visit[51][51];
	//memset(tmp_visit, false, sizeof(tmp_visit));

	queue <pair<int, int>> q;
	q.push(make_pair(y, x));

	//visit[y][x] = true;
	c.visit[y][x] = true; // 이건 단순하게...

	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		printf("%c : %d %d\n",value, cy, cx);
		q.pop();

		visit[cy][cx] = true;
		checker[cy][cx] = true;

		for(int i=0; i<4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(c.visit[ny][nx]) continue;

			if(map[ny][nx] == value || map[ny][nx] == '/') {
				c.visit[ny][nx] = true;
				//visit[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
	// 여러개일수도 있으니까 순서를 정해야한다.
	if(checkSquare(c.visit, value) && checkExist(c.visit, value) == false){
		printf("put %c\n", value);
		card.push_back(c);
	}
	
}
/*
bool checkCard() {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			if(map[i][j] != '/' && map[i][j] != '.') {
				if(visit[i][j] == false) // 탐색을 안했다.
					return false;
				return true;
			}
		}

	return false;
}
*/

bool compare(CARD a, CARD b) {
	return a.value < b.value;
}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++) {
		cin >> map[i];
		for(int j=0; j<m; j++) {
			cards.push_back(map[i][j]);
		}
	}

	sort(cards.begin(), cards.end());
	cards.erase(unique(cards.begin(), cards.end()), cards.end());
	int card_no = cards.size()-1;
	printf("card_no %d\n", card_no);

	//return 0;

	int idx = 0;
	while(card_no > idx++) {

		card.clear();
		memset(visit, false, sizeof(visit));

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(map[i][j] != '.' && map[i][j] != '/' && visit[i][j] == false) {
					bfs(map[i][j], i, j);	
				}

		sort(card.begin(), card.end(), compare);
		memset(checker, false, sizeof(checker));

		for(auto c: card) {
			printf("del!! %c\n", c.value);
			answer.push_back(c.value);
			deleteValue(c.visit, checker);

			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++)
					printf("%d ", checker[i][j]);
				printf("\n");
			}

		}
		//break;
	}

	for(int i=0; i<answer.size(); i++)
		cout << answer[i];

	if(answer.size() < 1)
		printf("-1");

}