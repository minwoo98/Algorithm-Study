#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int a[101][101];
bool check[101][101];
int dist[101][101];
int n,m;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


void bfs(int y, int x)
{
	check[y][x] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	dist[y][x] = 1;
	
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) // right, up, down
		{
			int y_ = y+dy[k];
			int x_ = x+dx[k];
			if(y_>=1 && x_ >=1 && y_ <=n && x_ <= m)
			{
				if(a[y_][x_] == 1 && check[y_][x_] == false)
				{
					q.push(make_pair(y_,x_));
					dist[y_][x_] = dist[y][x] + 1; 
					check[y_][x_] = true;
					
				}
			}
		}
	}
	
}

int main(void)
{
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	
	bfs(1,1);
	/*
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}*/	
	cout << dist[n][m];

	return 0;	
}
