#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int mul5 = 0;
	int mul25 = 0;
	int mul125 = 0;

	mul5 = n/5;
	mul25 = n/25;
	mul125 = n/125;

	printf("%d\n", mul5 + mul25 + mul125);
}