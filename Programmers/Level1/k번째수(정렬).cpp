#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array1, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            temp.push_back(array1[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp.at(commands[i][2] - 1));
    }
    return answer;
}