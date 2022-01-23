#include <iostream>
#include <vector>
using namespace std;

long long arr[100010];
vector <long long> choice;
int n;
int answer = 987654321;
const int cal[3] = {0, -1, 1};

bool checker(long long no, long long diff, int cnt) {

	if(diff == no - choice[cnt-1])
		return true;
	return false;
}


void dfs(int idx, int cnt, int add, int target) {

	if(cnt == target) {
		if(answer > add)
			answer = add;
		return;
	}

	if(cnt < 2){
		for(int j=0; j<3; j++) {
			choice.push_back(arr[idx]+cal[j]);

			if(j != 0)
				dfs(idx+1, cnt+1, add+1, target);
			else
				dfs(idx+1, cnt+1, add, target);
			choice.pop_back();
		}
	}
	else {
		// check diff
		long long diff = choice[1] - choice[0];
		long long last_v = choice[cnt-1];

		for(int i=0; i<3; i++) {
			long long next_v = arr[idx] + cal[i];
			if(diff == next_v - last_v) {
				choice.push_back(next_v);
				if(i != 0)
					dfs(idx+1, cnt+1, add+1, target);
				else
					dfs(idx+1, cnt+1, add, target);
				choice.pop_back();
			}
		}

	}


}



int main() {
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%lld", &arr[i]);
	}

	int idx = 0;
	for(int i=0; i<3; i++) {
		long long next_v = arr[0] + cal[i];
		choice.push_back(next_v);
		if(cal[i] != 0)
			dfs(1, 1, 1, n);
		else
			dfs(1, 1, 0, n);
		choice.pop_back();
	}

	if(answer == 987654321) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", answer);
}