#include<iostream>
#include<vector>
using namespace std;

int n;
int s[20][20] = {};
bool check[20] = {false,};
int ans = 99999899;

void dfs(int cnt, int index)
{
	vector<int> team1;
	vector<int> team2;
	int sum_t1=0;
	int sum_t2=0;
	
	if(cnt == n/2)
	{	
		for(int i=0; i<n; i++)
		{
			if(check[i] == true)
			{
				team1.push_back(i);
			}
			else	team2.push_back(i);
		}
		for(int i=0; i<(n/2); i++)
		{
			for(int j=0; j<(n/2); j++)
			{
				sum_t1 += s[team1[i]][team1[j]];
				sum_t2 += s[team2[i]][team2[j]];
			}
		}

		int diff = sum_t1 - sum_t2;
		if(diff<0)	diff = -diff;
		if(diff<ans)	ans = diff;
		return;
	}
	
	for(int i=index; i<n; i++)
	{	
		if(check[i] == true) continue;
		else
		{
			check[i] = true; // true -> start_team, false -> link_team
			dfs(cnt+1, index+1);
			check[i] = false;
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> s[i][j];
		}
	}
	
	dfs(0,0);
	cout << ans;
	
	return 0;
}
