#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <list>
#include <sstream>

using namespace std;

bool check[1001];
stack <int> trash;
int cur;
int n;



void go_down(int dist) {
    cout << "go down" << dist <<endl;

    while(dist) {
        if(check[cur] == true) {
            dist--;
        }
        cur++;
        if(cur >= n)
            cur = 0;
    }
    
}

void go_up(int dist) {
    
    while(dist) {
        if(check[cur] == true) {
            dist--;
            cur--;
        }
        else {
            cur--;
        }
        if(cur == 0) {
            cur = n-1;
        }
    }
    
}

string solution(int N, int k, vector<string> cmd) {
    string answer = "";

    for(int i=0; i<N; i++)
        check[i] = true;
    
    cur = k;
    n = N;
    
    for(auto c: cmd) {
        printf("----------\n");
        for(int i=0; i<n; i++) {
            if(check[i] == true)
                printf("o\n");
            else
                printf("x\n");
        }
        if(c == "C") {
            check[cur] = false;
            trash.push(cur);
            go_down(1);
        }
        else if(c == "Z") {
            int recover_idx = trash.top(); trash.pop();
            check[recover_idx] = true;
        }
        else {
            string s[2];
            istringstream stt(c);
            stt >> s[0] >> s[1];
            
            if(s[0] == "D") {
                go_down(stoi(s[1]));
            }
            else if(s[0] == "U") {
                go_up(stoi(s[1]));
            }
        }
    }
        
    for(int i=0; i<n; i++) {
        if(check[i] == true) {
            answer += "O";
        }
        else
            answer += "X";
    }
    return answer;
}

int main() {
    int n = 8;
    int k = 2;
    vector <string> cmd;
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 4");
    cmd.push_back("C");
    cmd.push_back("U 2");
    cmd.push_back("Z");
    cmd.push_back("Z");

    string answer = solution(n, k, cmd);

    cout <<answer <<endl;
}
