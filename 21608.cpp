#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

struct Student {
	int no;
	int y, x;
	int friends[4];
};

int n, answer;
int arr[21][21];
vector <Student> st;


int count_friend(int std_idx, int y, int x) {

	int result = 0;
	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;

		if (arr[ny][nx] == -1)
			continue;

		for(int f=0; f<4; f++) {
			int friend_no = arr[ny][nx];
			if (friend_no == st[std_idx].friends[f]) {
				result++;
			}
		}

	}
	return result;

}


int count_blank(int y, int x) {

	int result = 0;
	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;
		
		if(arr[ny][nx] == -1)
			result++;

	}
	return result;

}

bool compare (pair<int, int> a, pair<int, int> b) {

	if(a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;

}



void solve() {

	// init 
	memset(arr, -1, sizeof(arr));

	for(int s=0; s<st.size(); s++) {
		int student_no = st[s].no;
		int tmp_arr[n][n];


		// memcpy(tmp_arr, arr, sizeof(tmp_arr)) -> 이거 왜 안되노

		// copy 때려주기
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				tmp_arr[i][j] = arr[i][j];
			}

		// check map
		int max_f_value = -1;
		vector <pair<int, int>> v;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {

				// if not empty skip!
				if(tmp_arr[i][j] != -1)
					continue;

				// case1 > 친구인접 최대 위치 max_y, max_x
				tmp_arr[i][j] = count_friend(s, i, j);
				if(tmp_arr[i][j] > max_f_value) {
					v.clear(); // 초기화
					v.push_back(make_pair(i, j));
					max_f_value = tmp_arr[i][j];
				}
				else if(tmp_arr[i][j] == max_f_value) {
					v.push_back(make_pair(i, j));
				}

			}


		// case 1
		if (v.size() == 1) {
			arr[v[0].first][v[0].second] = student_no;
			st[s].y = v[0].first;
			st[s].x = v[0].second;
			continue;
		}
		int v_size = v.size();
		int max_blank = -1;
		vector <pair<int, int>> b;
		// 인접빈칸개수
		for(int i=0; i<v.size(); i++) {
			int cy = v[i].first;
			int cx = v[i].second;

			int tmp_blank = count_blank(cy, cx);

			if(tmp_blank > max_blank) {
				max_blank = tmp_blank;
				b.clear();
				b.push_back(make_pair(cy, cx));
			}
			else if(tmp_blank == max_blank) {
				b.push_back(make_pair(cy, cx));
			}

		}

		// case 2
		if(b.size() == 1) {
			arr[b[0].first][b[0].second] = student_no;
			st[s].y = b[0].first;
			st[s].x = b[0].second;
			continue;
		} 

		sort(b.begin(), b.end(), compare);

		// case 3
		arr[b[0].first][b[0].second] = student_no;
		st[s].y = b[0].first;
		st[s].x = b[0].second;

	}


}


void calculate() {

	for(int i=0; i<n*n; i++) {
		//int std_no = st[i].no;
		int cy = st[i].y;
		int cx = st[i].x;

		int f_cnt = count_friend(i, cy, cx);

		f_cnt = pow(10, (f_cnt-1));
		if (f_cnt >= 1)
			answer += f_cnt;
	}
}


int main() {

	scanf("%d", &n);

	for(int i=0; i<n*n; i++) {
		Student tmp;
		int a, b, c, d, e;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		a--; b--; c--; d--; e--;

		tmp.no = a;
		tmp.friends[0] = b;
		tmp.friends[1] = c;
		tmp.friends[2] = d;
		tmp.friends[3] = e;
		st.push_back(tmp);
	}


	solve();
	
	calculate();

	printf("%d\n", answer);

	return 0;
}