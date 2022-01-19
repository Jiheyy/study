#include <iostream>
#include <cmath>
using namespace std;
int n;
int r, c;
int no;

// y, x 탐색 시작 위치
// l 한 변의 길이
void divide_conquer(int y, int x, int l) {
    
    if(y == r && x == c) {
        printf("%d\n", no);
        exit(0);
    }
    // 영역 안에 존재하면 분할
    if(r < y+l && c < x+l) {
        divide_conquer(y, x, l/2);
        divide_conquer(y, x+l/2, l/2);
        divide_conquer(y+l/2, x, l/2);
        divide_conquer(y+l/2, x+l/2, l/2);
    }
    else 
        no += l*l;
}

int main() {
    scanf("%d", &n);
    
    scanf("%d %d", &r, &c);
    
    divide_conquer(0, 0, pow(2, n));
}