#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	int n;
	scanf("%d", &n);

	int *no;
	no = new int [n];
	for(int i=0; i<n; i++)
		scanf("%d", &no[i]);

	sort(no, no+n);
	for(int i=0; i<n; i++)
		printf("%d\n", no[i]);
}