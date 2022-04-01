#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int m,n;
int a[1000][1000];
int check[1000][1000];
int dist[1000][1000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> q;

void bfs(int y, int x)
{
	check[y][x] = true;
	dist[y][x] = 0;
		
	while(!q.empty())
	{	
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int y_ = y+dy[k];
			int x_ = x+dx[k];
			if(y_>= 0 && x_>= 0 && y_<= n-1 && x_<=m-1)
			{
				if(a[y_][x_] == 0 && check[y_][x_] == false)
				{
					q.push(make_pair(y_,x_));
					check[y_][x_] = true;
					dist[y_][x_] = dist[y][x] + 1;
				}
			}
		}
		
	}
		
}

int main(int argc, char** argv)
{		
	cin >> m >> n;
	 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{	
			cin >> a[i][j];
			if(a[i][j] == 1)
			{
				q.push(make_pair(i,j));
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i][j] == 1)
			{
				bfs(i,j);
				break;
			}
		}
	}
	
	int ans = 0;
	int temp = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(check[i][j] == 0 && a[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				temp = dist[i][j];
				if(temp > ans)
				{
					ans = temp;
				}
			}
			
		}	
	}
	cout << ans;
	
	return 0;	
}
