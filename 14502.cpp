#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n,m; // y, x
int tmp[10][10];


queue <pair <int, int>> q; 
int answer = 0;


void BFS();

int count_safe() {
	int no = 0;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(tmp[i][j] == 0)
				no++;

	return no;
}

/*
// set walls
void DFS(int cnt) {
	if (cnt == 3){
		BFS();
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				printf("%d ", tmp[i][j]);
			printf("\n");
		}

		answer = max(answer, count_safe());
		return;
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(tmp[i][j] == 0) {
				tmp[i][j] = 1;
				DFS(cnt+1);
				tmp[i][j] = 0;
			}
}
*/


// BFS
// spread
void BFS(int y, x) {

	q.push(make_pair(y, x));

	while(!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();


		for(int i=0; i<4; i++) {
			int new_y = y + dy[i];
			int new_x = x + dx[i];

			if(new_y < 0 || new_y >= n || new_x < 0 || new_x >= m)
				continue;

			if(tmp[new_y][new_x] == 0) {
				q.push(make_pair(new_y, new_x));
				tmp[new_y][new_x] = 2;
			}
		}

	}


}



int main() {

	scanf("%d %d", &n, &m);

	int arr[n+1][m+1];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d", &arr[i][j]);
			tmp[i][j] = arr[i][j];
		}

	for(int a1=0; a1<n; a1++)
		for(int a2=0; a2<m; a2++) {
			if(arr[a1][a2] != 0)
				continue;

			for(int b1=0; b1<n; b1++)
				for(int b2=0; b2<m; b2++) {
					if(arr[b1][b2] != 0)
						continue;

					for(int c1=0; c1<n; c1++)
						for(int c2=0; c2<m; c2++) {
							if(tmp[c1][c2] != 0)
								continue;

							if(a1 == b1 && a2 == b2)
								continue;
							if(a1 == c1 && a2 == c2 )
								continue;
							if(b1 == c1 && b2 == c2)
								continue;

							tmp[a1][a2] = 1;
							tmp[b1][b2] = 1;
							tmp[c1][c2] = 1;

							for(int i=0; i<n; i++)
								for(int j=0; j<m; j++) 
									if(tmp[i][j] == 2)
										BFS(i, j);

							answer = max(count_safe(), answer);
							set_init();
						}
				}
		}




	DFS(0);


	printf("%d\n", answer);
}
