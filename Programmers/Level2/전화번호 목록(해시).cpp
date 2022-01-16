#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str = "";
    unordered_map<string, int> hash_map;

    for (auto& i : phone_book)
    {
        str = "";
        for (int j = 0; j < i.size(); j++)
        {
            str += i[j];
            hash_map[str]++;
        }
    }
    for (auto& i : phone_book)
    {
        if (hash_map[i] > 1)
        {
            return false;
        }
    }
    return true;
}