#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
int n_digit;            //입력받은 수를 d진법 변환 시 차지하는 자리수
bool halt_flag = false; //불가능할 시 작동하는 flag
void dec_to_d(int n, int d)
{
    int j = 0;
    for (int i = n; i > 0; i /= d)
    {
        num[j++] = (i % d);
    }
    n_digit = j;
}
void calc(int n, int d)
{
    int *getnum = new int[d];
    int i = 0;
    while (1)
    {
        for (int j = 0; j < d; j++)
            getnum[j] = 0;
        //저장된 숫자에서 1을 더한 수를 num에 저장되도록 함
        i = 0;
        num[i]++;
        //자리수 올림(carryout)
        while (num[i] == d)
        {
            num[i] = 0;
            if (i + 1 == d)
            {
                halt_flag = true;
                break;
            }
            num[i + 1]++;
            i++;
        }
        if (halt_flag)
            break;
        //0~d-1의 모든 수가 한번씩 등장했다면 loop escape
        int j;
        for (j = 0; j < d; j++)
        {
            if (getnum[num[j]] > 0)
                break;
            else
                getnum[num[j]]++;
        }
        if (j == d)
            break;
    }
    delete[] getnum;
    return;
}
int pow(int d, int k)
{
    int mul = 1;
    while (k--)
    {
        mul *= d;
    }
    return mul;
}
int d_to_dec(int d)
{
    int ans = 0;
    for (int i = 0; i < d; i++)
        ans += pow(d, i) * num[i];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    num.assign(50, 0);
    //d진법 변환
    dec_to_d(n, d);
    //변환한 수의 자리수가 d보다 클 경우 불가능하므로 -1 출력
    if (n_digit > d)
    {
        cout << "-1\n";
        return 0;
    }
    //문제의 답에 해당하는 d진법의 수를 찾는다.
    calc(n, d);
    if (halt_flag)
    {
        cout << "-1\n";
        return 0;
    }
    //d진법의 답을 10진수로 바꾸어 출력한다.
    cout << d_to_dec(d) << '\n';
    return 0;
}