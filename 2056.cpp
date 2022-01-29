#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int t[10001];
int dp[10001];
int ancestor[10001];

int arr[101];
bool visit[101];
int answer = 987654321;

vector <int> A[10001];


int main() {

	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		int cnt;
		scanf("%d %d", &arr[i], &cnt);
		for(int j=0; j<cnt; j++) {
			int no;
			scanf("%d", &no);
			if(no != i)
				graph[i].push_back(no);
		}
	}

	for(int i=1; i<=n; i++) {
		if(visit[i] == false) 
		{
			//visit[i] = true;
			//st.push(i);
			dfs(graph, i);
			//visit[i] = false;
			//st.pop();
		}
	}

	while(!st.empty()) {
			int no = st.top();
			st.pop();
			printf("no : %d\n", no);

			//res += arr[no];
		}



	printf("%d\n", answer);


}