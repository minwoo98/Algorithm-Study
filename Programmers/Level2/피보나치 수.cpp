#include <string>
#include <vector>
#include <iostream>

using namespace std;
int memo[100000];

int solution(int n) {

    if (n <= 1)    return n;
    else
    {
        if (memo[n] != 0)
        {
            return memo[n];
        }
        memo[n] = (solution(n - 1) + solution(n - 2)) % 1234567;
    }
    return memo[n];
}