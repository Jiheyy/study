#include <string>
#include <vector>
#include <map>

using namespace std;

map <string, vector <string>> m;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    for(auto c : clothes) {
        m[c[1]].push_back(c[0]);
    }

    for(auto n: m) {
        if(answer == 0)
            answer += (n.second.size() +1);
        else
            answer *= (n.second.size() +1);
    }
    return answer-1;
}