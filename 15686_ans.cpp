#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;
 
struct POSI {
    int y, x;
};
 
int n, m, type, ret;
vector<POSI> house, shop, pick;
 
void dfs(int pos) {
    if (pick.size() == m) {
 
        int candi = 0;
        for(const auto h: house) {

            int min_dist = 1000000;
            for(const auto p: pick) {
                min_dist = min(min_dist,
                    abs(h.y - p.y) + abs(h.x - p.x));
            }
            candi += min_dist;
        }
 
        if (ret > candi) {
            ret = candi;
        }
 
        return;
    }
 
    for (int i = pos; i < shop.size(); ++i) {
        pick.push_back(shop[i]);
        dfs(i + 1);
        pick.pop_back();
    }
}
 
 
int main()
{
    POSI target;
    scanf("%d %d", &n, &m);


    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            scanf("%d", &type);
            target.y = y;
            target.x = x;
            if (type == 1) {
                house.push_back(target);
            }
            else if (type == 2) {
                shop.push_back(target);
            }
        }
    }
 
    ret = INF;
    dfs(0);
    printf("%d\n", ret);
 
    return 0;
}
