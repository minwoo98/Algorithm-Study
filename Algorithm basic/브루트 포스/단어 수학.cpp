#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main(void)
{
	char map[10][10];
	bool check[10] = {false,};
	int len[10];
	int var[26] = {0,};  //0-25 : a to z의 앞 계수  
	int ans=0;
	int n;
	cin >> n;	
	for(int i=0; i<n; i++)
	{
		cin >> map[i];
		len[i] = strlen(map[i]);	
	}
	
	for(int i=0; i<n; i++)
	{
		int num = 1;
		for(int j=len[i]-1; j>=0; j--)
		{
			var[map[i][j] -'A'] += num;
			num *= 10;
		}
	}
		
	sort(var, var+26, greater<int>());
/*	
	for(int i=0; i<26; i++)
	{
		cout << var[i] << ' ';
	}
*/	
	for(int i=0; i<10; i++)
	{
		ans += var[i] *(9-i);
	}
	
	cout << ans << '\n';

	return 0;	
}
