#include <iostream>
using namespace std;

int N;
int A[499][499];
const int dy[]={0,1,0,-1};
const int dx[]={-1,0,1,0};
const int ratios[9]={1,1,2,7,7,2,10,10,5};
const int blowY[4][10]={
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {1,1,0,0,0,0,-1,-1,-2,-1}
};
const int blowX[4][10]={
    {1,1,0,0,0,0,-1,-1,-2,-1},
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {-1,1,-2,-1,1,2,-1,1,0,0}
};

bool inRange(int y, int x){
    return y>=0 && x>=0 && y<N && x<N;
}


int blowSand(int y, int x, int dir){
    int ret=0, init=A[y][x];

    for(int i=0;i<10;i++){
        int sand;
        // percentage
        if(i!=9){
            sand = init*ratios[i]/100;
            A[y][x]-=sand;
        }
        // a
        else sand=A[y][x];

        int by=y+blowY[dir%4][i];
        int bx=x+blowX[dir%4][i];

        if(!inRange(by,bx)){
            ret+=sand;
            continue;
        }

        A[by][bx]+=sand;
    }

    A[y][x]=0;

    return ret;
}

int solve(){
    int ret=0, y=N/2, x=N/2, dir=0;
    int move_cnt = 1;

    //  이 부분이 구현이 빡셌음. 진행방향 설정하는 부분 (가운데부터 설정을 해야한다.)
    // 기존에 끝에서부터 하려고 했는데 그럴 경우, 뒤집는 과정에서 고려해야할것들이 많아짐
    // https://yabmoons.tistory.com/601
    // 토네이도는 계속해서 움직이는 칸수가 증가하게 되는데, 몇 칸을 움직이던 간에, 해당 칸 수 만큼 움직이는 행위를 2번 반복한다는
    while (1) {
        for(double i=0; i<2; i++){
            for(int j=0; j<move_cnt; j++){
                y+=dy[dir%4];
                x+=dx[dir%4];

                ret+=blowSand(y,x,dir);

                if(y == 0 && x == 0)
                    return ret;
            }
            // 방향 전환
            dir++;
        }
        move_cnt++;
    }
    return ret;
}

int main(){

    scanf("%d", &N);;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &A[i][j]);

    printf("%d\n",solve());

    return 0;
}
