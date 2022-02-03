#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char map[10];
bool visit[10];
int answer;
vector <char> v;
vector <string> words;
vector <bool> check;


bool wordCheck(char target) {

	vector <char> tmp = v;
	tmp.push_back(target);

	// 순열
	do {
		string word = "";
		for(int i=0; i<tmp.size(); i++) {
			word += tmp[i];

		}
		if(word == "LINT")
			printf("lint exists!!\n");
		//cout << word <<endl;
		
		for(int i=0; i<words.size(); i++) {
			if(word == words[i]) {
				cout << word <<endl;
				if(check[i] == false) {
					check[i] = true;
					return true;
				}
			}
		}

	}while(next_permutation(tmp.begin(), tmp.end()));


	return false;
}

bool vec_search(char target){
	for(auto ele : v)
		if(ele == target)
			return true;

	return false;
}

bool checker( int length, char target) {

	int cnt;

	for(int i=0; i<words.size(); i++) {
		//cout << words[i] <<endl;
		int cnt = 0;
		for(auto a : words[i]) {
			if(vec_search(a) == true)
				cnt++;
			else if(a == target)
				cnt++; 

		}
		if(cnt == length)
			return true;
	}

	for(auto ele: v)
		cout <<ele;

	cout <<"false"<<endl;
	printf("cnt : %d, length : %d\n", cnt, length);
	return false;
}

void dfs(int idx, int cnt) {
	
	if(cnt >= 4 && cnt < 10) {
		vector <char> 
		
		for(int i=0; i<9; i++)
			if(visit[i])
				word += map[i];

		// check weather it is word?
		if(wordCheck(v) == true)
			answer++;
	}

	else if(cnt == 10) return;

	for(int i=idx; i<9; i++) {
		if(visit[i]) continue;
		if(checker(cnt, target) == false) continue;

		visit[i] = true;
		// 조힙
		dfs(i, cnt+1);
		visit[i] = false;
	}
}

int main() {

	// 단어
	while(true) {
		string word;
		cin >> word;
		if(word == "-")
			break;
		words.push_back(word);
		check.push_back(false);
	}

	//sort(words.begin(), words.end(), compare);

	// Map
	while(true) {
		int max_answer = -1;
		int min_answer = 987654321;
		memset(map, '\0', sizeof(map));

		cin >> map;
		if(map[0] == '#')
			break;

		for(int i=0; i<1; i++) {
			//v.clear();
			answer = 0;	
			printf("target : %c\n", map[i]);
			visit[i] = true;
			dfs(i, 1);
			visit[i] = false;

			printf("answer : %d\n", answer);

			max_answer = max(answer, max_answer);
			min_answer = min(answer, min_answer);
			break;
		}
		printf("%d %d\n", min_answer, max_answer);

		break;
	}
}