#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
int d, c;
char input[5];
int visit[10];
char visit2[26];
int number[10] = {0, 1, 2,3,4,5,6,7,8,9};
char alphabet[26];

vector <string> words;

void checker() {
	vector <int> d_c;
	for(int i=0; i<10; i++)
		if(visit[i] != -1) {
			d_c.push_back(visit[i]);
		}

	vector <char> c_c;
	for(int i=0; i<26; i++)
		if(visit2[i] != 0){
			c_c.push_back(visit2[i]);
		}

	int c_idx = 0; int d_idx = 0;

	string word = "";
	for(int i=0; i<int(strlen(input)); i++) {
		if(input[i] == 'd') {
			word += d_c[d_idx++];
		}
		else if(input[i] == 'c')
			word +=  c_c[c_idx++];
	}

	bool dup = false;
	for(int i=0; i<int(word.size())-1; i++)
		if(word[i] == word[i+1]) {
			dup = true;
			break;
		}

	if(dup == false)
		words.push_back(word);

}

void dfs2(int cnt, int target) {
	if(cnt == target) {
		for(int i=0; i<target; i++) {
			// 순서대로 만들기
			checker();

		}
		return;
	}
	for(int i=0; i<26; i++) {
		visit2[cnt] = alphabet[i];
		dfs2(cnt+1, target);
		visit2[cnt] = 0;
	}
}

void dfs(int cnt, int target) {
	if(cnt == target) {
		
		if(c > 0) {
			//알파벳 뽑기
			dfs2(0, c);
		}
		else
			checker();
		return;
		
	}
	for(int i=0; i<10; i++) {
		visit[cnt] = number[i];
		dfs(cnt+1, target);
		visit[cnt] = -1;
	}
}

int main() {

	cin >> input;

	for(char i=0; i<26; i++) {
		alphabet[i] = 'a'+i;
	}

	for(int i=0; i<int(strlen(input)); i++) {
		if(input[i] == 'd')
			d++;
		else if(input[i] == 'c')
			c++;
	}

	for(int i=0; i<10; i++)
		visit[i] = -1;

	for(int i=0; i<26; i++)
		visit2[i] = 0;
	
	if(d!= 0)
		dfs(0, d);
	else if(d == 0 && c > 0)
		dfs2(0, c);

	else if (d == 0 && c== 0){
		printf("1");
		exit(0);
	}

	// 중복제거
	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());

	printf("%lu\n", words.size());

}