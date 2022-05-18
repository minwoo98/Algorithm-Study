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
	
	vector<int> a,a_copy;
	vector<char> cal, cal_copy;
	
	int arr[5] = {0,};
	
	string temp;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] != '+' && str[i] != '-')
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
			int num = stoi(temp);
			a.push_back(num);
			temp = "";
			cal.push_back(str[i]);
		}
	}
	a_copy.assign(a.begin(), a.end());
	cal_copy.assign(cal.begin(), cal.end());
	
	bool open[50] = {false,};
	bool close[50] = {false,};

	int ans_temp = 0;
	int ans= 99999999;
	for(int i=0; i<a.size()-1; i++)
	{
		open[i]  = true; 
		for(int j=i+1; j<a.size(); j++)
		{
			a_copy.assign(a.begin(), a.end());
			cal_copy.assign(cal.begin(), cal.end());
			close[j] = true;
			cout << i << ',' << j << '\n';
			int garo = a[i];		 
			for(int k=i; k<j; k++)
			{
				if(cal[k] == '+')
				{
					garo = garo + a[k+1];
				}
				else if(cal[k] == '-')
				{
					garo = garo - a[k+1];
				}
				a_copy.erase(a_copy.begin()+k);
				cal_copy.erase(cal_copy.begin()+k);
				if(k==j-1)
				{
					a_copy.erase(a_copy.begin()+k+1);
				}
			}
			a_copy.insert(a_copy.begin()+i, garo);
 			for(int i=0; i<a_copy.size(); i++)
			{
				cout << a_copy[i] << ' ';
			}	 
			cout << '\n';
		}
	}
	
	/*
	for(int i=0; i<a.size(); i++)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
	for(int i=0; i<cal.size(); i++)
	{
		cout << cal[i] << ' ';
	}
	*/
	 
	
	return 0;	
}
