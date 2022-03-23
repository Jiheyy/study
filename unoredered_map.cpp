#include <unordered_map>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

unordered_map <string, int> um;

int main() {

	if(um.empty()) printf("this is empty\n");

	um.insert(make_pair("key", 1));
	um["kakao"] = 2;
	um.insert({"melon", 3});

	printf("size : %lu\n", um.size());

	for(auto ele: um) {
		printf("key: %s, value: %d\n", ele.first.c_str(), ele.second);
	}

	if(um.find("kakao") != um.end()) {
		um.erase("kakao");
	}
	printf("size : %lu\n", um.size());

	for(auto ele: um) {
		printf("key: %s, value: %d\n", ele.first.c_str(), ele.second);
	}

	return 0;
}