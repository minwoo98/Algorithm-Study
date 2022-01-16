#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> temp;
    for (string name : participant)
    {
        temp[name]++;
    }
    for (string name : completion)
    {
        temp[name]--;
    }

    for (string name : participant)
    {
        if (temp[name] == 1)
        {
            answer = name;
        }
    }

    return answer;
}