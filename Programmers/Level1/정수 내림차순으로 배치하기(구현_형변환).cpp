#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<long long> b;

long long solution(long long n) {
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);
    return answer;
}