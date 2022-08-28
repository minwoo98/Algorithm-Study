#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l,r,c;
char map[31][31][31];
bool check[31][31][31] = {false};
int time[31][31][31] = {0};

int sz,sy,sx;
int ez,ey,ex;

//동서남북상하  
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {1,-1,0,0,0,0};

int t;

struct pos
{
	int z;
	int y;
	int x;
};

int bfs(int z, int y, int x)
{
	queue<pair<pos,int>> q;
	
	q.push({{z,y,x},0});
	check[z][y][x] = true;
	
	//cout << z << y << x << '\n';

	while(!q.empty())
	{
		int z_ = q.front().first.z;
		int y_ = q.front().first.y;
		int x_ = q.front().first.x;
		int time = q.front().second;
		
		//cout << z_ << ' ' << y_ << ' ' << x_ << '\n';
		
		if(map[z_][y_][x_] == 'E')
		{
			cout << "Escaped in" << ' ' << time << ' ' << "minute(s)." << '\n';
			return -1;
		}	
		
		q.pop();
		
		for(int k=0; k<6; k++)
		{
			int nz = z_+dz[k];
			int ny = y_+dy[k];
			int nx = x_+dx[k];
			
			if(nz < 1 || nz > l || ny < 1 || ny > r || nx < 1 || nx > c)	continue;
			if(map[nz][ny][nx] == '#' || check[nz][ny][nx] == true)	continue;
			
			q.push({{nz,ny,nx},time+1});
			check[nz][ny][nx] = true;
		}
	}
	return 987654321;
}

int main(void)
{
	
	
	while(1)
	{
		cin >> l >> r >> c;
		
		memset(check,false,sizeof(check));
		memset(time,0,sizeof(time));
		
		if(l == 0 && r ==0 && c==0)	break;
		
		for(int i=1; i<=l; i++)
		{
			for(int j=1; j<=r; j++)
			{
				for(int m=1; m<=c; m++)
				{
					cin >> map[i][j][m];
	
					if(map[i][j][m] == 'S')
					{
						sz = i;
						sy = j;
						sx = m;
					}
					else if(map[i][j][m] == 'E')
					{
						ez = i;
						ey = j;
						ex = m;
					}
				}
			}
		}
		
		int ans = bfs(sz,sy,sx);
		
		if(ans == -1)	continue;
		else
		{
			cout << "Trapped!" << '\n';
		}
	}	
	return 0;	
}
