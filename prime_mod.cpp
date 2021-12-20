#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

bool prime(int no) {
	if(no <= 1)
		return false;
	if(no == 2)
		return true;

	for(int i=2; i<sqrt(no); i++)
		if(no % i == 0)
			return false;

	return true;
}


int solution(string numbers) {

	int ret = 0;

	vector <int> answer;

	// 순열 구하고
	do {

		for(int i=1; i<=numbers.size(); i++) {
			int sub = stoi(numbers.substr(0, i));

			answer.push_back(sub);

		}

	}while(next_permutaion(numbers.begin(), numbers.end()));

	// 증복제거
	sort(answer.begin(). answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	// prime 판별
	for(auto n: answer)
		if(prime(n))
			ret++;

	printf("%d\n", ret);

	return 0;
}