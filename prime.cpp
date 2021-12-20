#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define MAX 9999999999
using namespace std;

bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    bool isPrime = true;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number% i == 0)
            return false;
    }

    return isPrime;
}

bool compare(char a, char b)
{
    return a > b;
}

int solution(string numbers) {
    int answer = 0;

    string temp;
    temp = numbers;

/************/
    // 만들수 있는 가장 큰 수 -> temp
    sort(temp.begin(), temp.end(),compare);

    // 1. 소수판별
    // prime temp+1 의 길이 만큼 세팅
    vector<bool> prime(stoi(temp)+1);

    // 모든 수를 소수 판별한다.
    prime[0] = false;
    for (long long i = 1; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }

/*******************/
    string s, sub;

    s = numbers;
    // 오름차순 정렬
    sort(s.begin(), s.end());
    vector <int> primes; // set 말고 vector 사용해도 될듯


    int l = s.size();

    // 무조건 do 먼저 실행한 후 while 판별
    do {

        // 1 개 ~ l 모든 순열
        for (int i = 1; i <= l; i++)
        {
            sub = s.substr(0, i);

            // 소수이면
            if (prime[stoi(sub)])
            {
                primes.push_back(stoi(sub));
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    //cout << primes.size();
    answer = primes.size();
    return answer;
}