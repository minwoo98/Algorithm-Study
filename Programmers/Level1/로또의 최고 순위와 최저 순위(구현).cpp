#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int cnt = 0;
    int rank = 0;

    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
        {
            cnt += 1;
            continue;
        }
        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                cnt += 1;
                break;
            }
        }
    }
    if (cnt > 1) rank = 7 - cnt;
    else rank = 6;
    answer.push_back(rank);
    cnt = 0;
    rank = 0;
    ////////////////////////////////
    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                cnt += 1;
                break;
            }
        }
    }
    if (cnt > 1) rank = 7 - cnt;
    else rank = 6;
    answer.push_back(rank);

    return answer;
}