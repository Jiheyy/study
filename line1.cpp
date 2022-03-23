#include <iostream>
#include <cstring>
using namespace std;

long long n;
long long answer = 987654321;
long long final_no;

void dfs(int cnt, string no) {
	if(no.size() == 1) {
		if(cnt < answer) {
			answer = cnt;
			final_no = stoi(no);
		}
		return;
	}

	for(long long i=1; i<=no.size()-1; i++) {
		string no1 = no.substr(0, i);
		string no2 = no.substr(i);

		if(no2[0] == '0') continue;
		long long new_no = stoi(no1) + stoi(no2);
		dfs(cnt+1, to_string(new_no)); 
	}

}


int main() {
	scanf("%lld", &n);

	string str_no = to_string(n);
	dfs(0, str_no);

	printf("%lld %lld\n",  answer, final_no);

}