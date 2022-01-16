#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> a;
int solution(int n) {
    int answer = 0;
    while (1)
    {
        a.push_back(n % 3);
        n = n / 3;
        if (n == 0) break;
    }
    int j = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        answer += a[i] * j;
        j *= 3;
    }

    return answer;
}