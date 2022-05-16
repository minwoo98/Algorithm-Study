#include<iostream>
#include<queue>
#include<cstring> 
using namespace std;

int n,m;
char map[51][51];
bool check[51][51];
int cnt[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int ans = -1;

int bfs(int y, int x, int count)
{
	//새로 bfs들어올 떄 마다 방문 초기화 해즐 것
	memset(check,false,sizeof(check));
	
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	
	check[y][x] = true;
	cnt[y][x] = count; 
	
	while(!q.empty())
	{
		int now_y = q.front().first;
		int now_x = q.front().second;
		
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int next_y = now_y + dy[k];
			int next_x = now_x + dx[k];
			
			if(check[next_y][next_x] == false)
			{
				if(map[next_y][next_x] == 'L' && next_y >= 0 && next_y <= n-1 && next_x >=0 && next_x <= m-1 )
				{
					q.push(make_pair(next_y,next_x));
					check[next_y][next_x] = true;
					cnt[next_y][next_x] = cnt[now_y][now_x] + 1;
				}
			}
		}
		if(q.empty())
		{
			return cnt[now_y][now_x];
		}
	}
}
int main(void)
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(map[i][j] == 'L')
			{
				int temp = bfs(i,j,0);
				if(ans < temp)
				{
					ans = temp;
				}
			}
		}
	}
	
	cout << ans;
	
	return 0;	
}
