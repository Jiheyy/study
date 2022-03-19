#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MOD = 1234567891;
long long R = 1;

int main() {
	int n;
	long long hash_value = 0;
	cin >>n;

	string word;
	cin >> word;

	for(int i=0; i<n; i++) {
		hash_value = (hash_value + (word[i] - 'a' + 1) * R) % MOD;

		R = (R*31) % MOD;
	}

	cout << hash_value <<endl;
}