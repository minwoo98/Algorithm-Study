#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[26][26];
int check[26][26];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int ans[26*26];
int n;

void dfs(int y, int x, int cnt)
{
	check[y][x] = cnt;
	for(int k=0; k<4; k++)
	{
		int x_ = x+dx[k];
		int y_ = y+dy[k];
		if(x_ >= 0 && y_ >= 0 && x_ <= n && y_ <= n)
		{
			if(a[y_][x_] == 1 && check[y_][x_] == 0)
			{
				dfs(y_, x_, cnt);
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[i][j] ==1 && check[i][j] == 0)
			{
				dfs(i,j, ++cnt);
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			ans[check[i][j]] += 1;
		}
	}
	
	cout << cnt << '\n';
	sort(ans+1, ans+1+cnt);
	
	for(int i=1; i<=cnt; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}
