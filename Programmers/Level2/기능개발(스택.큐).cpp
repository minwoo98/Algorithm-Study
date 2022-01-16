#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] != 0) q.push((100 - progresses[i]) / speeds[i] + 1);
        else q.push((100 - progresses[i]) / speeds[i]);
    }
    while (!q.empty())
    {
        int cnt = 1;
        int current = q.front();
        q.pop();

        while (!q.empty() && q.front() <= current)
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }

    return answer;
}