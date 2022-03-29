#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int a[26][26];
int check[26][26];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int ans[26];

void bfs(int y, int x, int cnt)
{
	check[y][x] = cnt;
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	
	while(!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int x_ = x+dx[k];
			int y_ = y+dy[k];
			if(x_ >= 0 && y_ >= 0 &&  x_<=n && y_ <=n)
			{
				if(a[y_][x_] == 1 && check[y_][x_] == 0)
				{
					q.push(make_pair(y_,x_));
					check[y_][x_] = cnt;
				}
			}
		}
	}
}

int main(void)
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
			if(a[i][j] == 1 && check[i][j] == 0)
			{	
				bfs(i,j, ++cnt);
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			ans[check[i][j]]++;
		}
	}
	
	cout << cnt << '\n';
	sort(ans+1, ans+1+cnt);
	
	for(int i=1; i<=cnt; i++)
	{
		cout << ans[i] << '\n';
	}
	
	
/*	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << check[i][j] << ' ';
		}
		cout << '\n';
	}
*/	
	
	
	return 0;	
}
