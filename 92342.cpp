#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
int apeach[11];
int max_score = -1;
int board[11];
vector <int> v;
int score[11];
int lion[11];

// 중복조합 dfs n 개를 뽑음
void dfs(int idx, int cnt, int n) {
    if(cnt == n) {
        int lion_score = 0;
        int apeach_score = 0;
        for(int i=0; i<11; i++) {
            if(apeach[i] == 0 && lion[i]== 0) continue;
            if(apeach[i] < lion[i])
                lion_score += (10-i);
            else
                apeach_score += (10-i);
        }
       
        if(lion_score <= apeach_score) return;
      
        if(lion_score > max_score) {
            max_score = (lion_score-apeach_score);
            for(int i=0; i<=10; i++) {
                board[i] = lion[i];
            }
        }
        else if((lion_score-apeach_score) == max_score) {
            bool exchage = false;
            for(int i=10; i>=0; i--) {
                if(lion[i] > board[i]) {
                   exchage = true;
                    break;
                }
            }
            if(exchage) {
                for(int i=0; i<=10; i++)
                    board[i] = lion[i];
            }
        }
        return;
    }
    
    for(int i=idx; i<11; i++) {
        lion[i]++;
        dfs(i, cnt+1, n);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
        
    int target = 0;
    for(int i=0; i<=10; i++) {
        apeach[i] = info[i];
        score[i] = i;
    }
    
    printf("%d\n", target);
    
    dfs(0, 0, n);
    
    for(int i=1; i<=10; i++)
        answer.push_back(board[i]);
    
    cout << max_score <<endl;
    return answer;
}

int main() {

    vector <int> info;
    info.push_back(2);
    info.push_back(1);
    info.push_back(1);
    info.push_back(1);
    info.push_back(0);
    info.push_back(0);
    info.push_back(0);
    info.push_back(0);
    info.push_back(0);
    info.push_back(0);
    
    vector<int> answer = solution(5, info);
    for(auto a: answer)
        cout << a <<endl;
}