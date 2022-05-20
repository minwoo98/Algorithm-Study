#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void)
{
	string str;
	cin >> str;
	vector<int> a;
	vector<char> cal;
	string temp;
	
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] != '-' && str[i] != '+')
		{
			temp += str[i];
			if(i==str.size()-1)
			{
				int num = stoi(temp);
				a.push_back(num);
			}
		}
		else
		{
			cal.push_back(str[i]);
			
			int num = stoi(temp);
			a.push_back(num);
			temp = "";	
		}
	}
	
	bool minus_flag = false;
	int ans = a[0];
	
	for(int i=0; i<cal.size(); i++)
	{
		if(cal[i] == '+')
		{
			if(minus_flag == true)
			{
				ans -= a[i+1];
			}
			else
			{
				ans += a[i+1];
			}
		}
		else if(cal[i] == '-')
		{
			minus_flag = true;
			ans -= a[i+1];
		}
	}
	
	cout << ans << '\n';

	
	return 0;	
}
