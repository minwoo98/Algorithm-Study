#include<iostream>
#include<cstdio>
#include<deque>
using namespace std; 

int n,m;
int map[101][101];
int visited[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	cin >> m >> n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%1d", &map[i][j]); //scanf %1d !!!!
			visited[i][j] = -1;
		}
	}
	
	deque<pair<int,int>> dq;
	dq.push_front(make_pair(1,1));
	visited[1][1] = 0;

	
	while(!dq.empty())
	{
		int y= dq.front().first;
		int x= dq.front().second;
		dq.pop_front();
		
		if(y == n && x == m)
		{
			cout << visited[y][x] << '\n';
			break;
		}
		
		for(int k=0; k<4; k++)
		{	
			int y_next = y+dy[k];
			int x_next = x+dx[k];
			
			if(y_next>=1 && y_next<=100 && x_next>=1 && x_next<=100)
			{     
				if(visited[y_next][x_next] == -1)
				{
					if(map[y_next][x_next] == 0)
					{
						//빈 방, 우선순위 높으므로 덱에 프로트 에 추가
						dq.push_front(make_pair(y_next,x_next));
						visited[y_next][x_next] = visited[y][x];	  
					}
					else
					{
						//벽 , 우선순위 낮으므로 덱에 백에 추가   
						dq.push_back(make_pair(y_next,x_next));
						visited[y_next][x_next] = visited[y][x] + 1;	  	
					}
				}
			}
		}
		
	}
	
	return 0;	
}
