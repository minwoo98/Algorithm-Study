#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int a[52][52] = {0,};
int check[52][52] = {0,};
int m, n;
vector<int> ans;

void bfs(int y, int x, int cnt)
{	//bfs
	queue<pair<int,int>> q;
	check[y][x] = true;
	q.push(make_pair(y,x));
			
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int k=0; k<4; k++)
		{
			int y_ = y+dy[k];
			int x_ = x+dx[k];
			if(y_ >= 0 && x_ >= 0 && y_ <= n-1 && x_ <= m-1)
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
	int t;
	
	cin >> t;
	while(t--)
	{	
		int k;
		cin >> m >> n >> k;
		memset(check, 0, sizeof(check));
		memset(a, 0, sizeof(a));

		for(int i=0; i<k; i++)
		{
			int x,y;
			cin >> x >> y;
			a[y][x] = 1;

		}
		
		int cnt = 0;
		for(int i=0; i<=n-1; i++)
		{
			for(int j=0; j<=m-1; j++)
			{
				if(a[i][j] == 1 && check[i][j] == 0)
				{
					bfs(i,j,++cnt);
				}
			}
		}
		ans.push_back(cnt);
	}
	for(int i=0; i<ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;	
}

