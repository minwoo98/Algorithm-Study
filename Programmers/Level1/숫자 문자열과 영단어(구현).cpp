#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'z')
        {
            i += 3;
            num.push_back('0');
        }
        else if(s[i] == 'o')
        {
            i += 2;
            num.push_back('1');
        }
        else if(s[i] == 't')
        {
            if(s[i+1] == 'w')
            {
                i += 2;
                num.push_back('2');
            }
            else if(s[i+1] == 'h')
            {
                i += 4;
                num.push_back('3');
            }
        }
        else if(s[i] == 'f')
        {
            if(s[i+1] == 'o')
            {
                i += 3;
                num.push_back('4');
            }
            else if(s[i+1] == 'i')
            {
                i += 3;
                num.push_back('5');
            }
        }
        else if(s[i] == 's')
        {
            if(s[i+1] == 'i')
            {
                i += 2;
                num.push_back('6');
            }
            else if(s[i+1] == 'e')
            {
                i += 4;
                num.push_back('7');
            }
        }
        else if(s[i] == 'e')
        {
            i += 4;
            num.push_back('8');
        }
        else if(s[i] == 'n')
        {
            i += 3;
            num.push_back('9');
        } 
        else
        {
            num.push_back(s[i]);
        }
    }
    answer = stoi(num);
    
    return answer;
}
