#include <iostream>
using namespace std;
int main () {

    int answer = 0;
    for(int i=0; i<5; i++) {
        int no;
        cin >>no;
        answer += (no*no);
    } 
    printf("%d\n", answer%10);
}