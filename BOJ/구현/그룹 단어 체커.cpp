#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(int argc, char** argv)
{	
	int n;
	cin >> n;
	
	int cnt = 0;

	for(int i=0; i<n; i++)
	{	
		string word;
		cin >> word;
		
		int arr[26] = {0,};
		int flag = 0;
		
		for(int j=0; j<word.length(); j++)
		{
			int x = (int)(word[j]-'a');
			int pre_x = (int)(word[j-1]-'a');
			arr[x]++;
			
			if(x != pre_x && arr[x] > 1 && j>=1)
			{
				flag = 1; //not answer
				break;
			}
		}
		if(flag == 0)
		{
			cnt++;
		}
	}
	cout << cnt;

	return 0;	
}
