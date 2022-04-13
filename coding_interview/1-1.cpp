#include <iostream>
#include <cstring>
using namespace std;

bool visit[987654321];

int main() {
	//string a = "abcdefgha";// duplicate exist
	string a = "abc";

	bool duplicate = false;

	for(auto alphabet : a) {
		if(visit[alphabet] == true){
			duplicate = true;
			break;
		}
		visit[alphabet] = true;
	}
	if(duplicate)
		printf("duplicate\n");
	else
		printf("non-duplicate\n");
}