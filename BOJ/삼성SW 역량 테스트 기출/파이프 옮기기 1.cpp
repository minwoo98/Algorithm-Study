#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int n;
int map[17][17];
//int pipe = 1; // 현재파이프 모양  => 1: 가로, 2: 세로, 3:대각 
int cnt = 0;

//오른, 아래, 대각 
int dx[3] = {1,0,1}; 
int dy[3] = {0,1,1};



 int main(void)
 {
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(1,2,1));
	
	while(!q.empty())
	{
		//벽 검사 x 버전
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int pipe = get<2>(q.front());
		
		if(y == n && x == n)
		{
			cnt += 1;
		}
		
		q.pop();
		
		if(pipe == 1)
		{
			for(int k=0; k<2; k++)
			{
				if(k== 0)
				{
					int ny = y;
					int nx = x+1;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1)	continue;
					q.push(make_tuple(ny,nx,1));
				
				}
				else if(k==1)
				{
					int ny = y+1;
					int nx = x+1;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1 || map[ny-1][nx] == 1 || map[ny][nx-1] == 1)	continue;
					
					q.push(make_tuple(ny,nx,3));
				}			 
			}
		}
		else if(pipe == 2)
		{
			for(int k=0; k<2; k++)
			{
				if(k== 0)
				{
					int ny = y+1;
					int nx = x;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1)	continue;
					
					q.push(make_tuple(ny,nx,2));

				}
				else if(k==1)
				{
					int ny = y+1;
					int nx = x+1;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1 || map[ny-1][nx] == 1 || map[ny][nx-1] == 1)	continue;
					
					q.push(make_tuple(ny,nx,3));
				}			
			}
		}
		else
		{
			for(int k=0; k<3; k++)
			{
				if(k== 0)
				{
					int ny = y;
					int nx = x+1;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1)	continue;
					
					q.push(make_tuple(ny,nx,1));
				}
				else if(k==1)
				{
					int ny = y+1;
					int nx = x;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1)	continue;
					
					q.push(make_tuple(ny,nx,2));
				}
				else
				{
					int ny = y+1;
					int nx = x+1;
					
					if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1 || map[ny-1][nx] == 1 || map[ny][nx-1] == 1)	continue;
					
					q.push(make_tuple(ny,nx,3));
				}	
			}	
		}
	}
	
	cout << cnt;

 	return 0;
 }
