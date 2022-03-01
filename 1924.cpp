#include <iostream>
#include <vector>
using namespace std;


int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string DAY[] = {"SUN", "MON","TUE", "WED", "THU", "FRI", "SAT"};

int main() {
	int month, day;
	scanf("%d %d", &month, &day);

	int total = 0;
	for(int i=0; i<month; i++)
		total += days[i];

	total += day;
	cout << DAY[total % 7];

	return 0;
}