#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int ans = 0;
vector<int> time(15), money(15);

void dfs(int d, int sum)
{
	if(d == n+1)
	{
		if(ans < sum)
		{
			ans = sum;
			return;
		}
	}
	if(d > n)	return;
	
	//d날에 일하는 경우 
	dfs(d+time[d], sum+money[d]);	
	//d날에 일안하는 경우 
	dfs(d+1, sum);
}
int main(int argc, char** argv)
{		
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> time[i] >> money[i];
	}
	
	dfs(1,0);
	cout << ans;
	
	return 0;	
}
