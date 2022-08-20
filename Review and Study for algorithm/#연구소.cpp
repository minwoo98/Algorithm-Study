#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n,m;
int map[9][9];
bool check[9][9];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int virus = 0;
int wall_cnt = 0;
int ans = 0;

vector<pair<int,int>> wall;
queue<pair<int,int>> q;

int bfs()
{
	memset(check,false,sizeof(check));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(map[i][j] == 2)
			{
				q.push({i,j});
			}
		}
	}
	
	int add_virus = virus;
	
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int ny = y+dy[k];
			int nx = x+dx[k];
			
			if(ny < 0 || ny > n-1 || nx < 0 || nx > m-1)	continue;
			if(map[ny][nx] == 0 && check[ny][nx] == false)
			{
				q.push({ny,nx});
				check[ny][nx] = true;
				add_virus += 1;
			}
		}	
	}
	
	//safe region count
	int safe_ = n*m-add_virus-(wall_cnt+3); 
	
	return safe_;
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 0)
			{
				wall.push_back({i,j});		
			}
			else if(map[i][j] == 1)
			{
				wall_cnt+=1;
			}
			else
			{
				virus+=1;
			}
		}
	}
	
	//벽3개 세우기 부르트포스 시뮬레이션	
	for(int w1=0; w1<wall.size(); w1++)
	{
		for(int w2=w1+1; w2<wall.size(); w2++)
		{
			for(int w3=w2+1; w3<wall.size(); w3++)
			{
				map[wall[w1].first][wall[w1].second] = 1;
				map[wall[w2].first][wall[w2].second] = 1;
				map[wall[w3].first][wall[w3].second] = 1;
				
				ans = max(bfs(),ans);
				
				map[wall[w1].first][wall[w1].second] = 0;
				map[wall[w2].first][wall[w2].second] = 0;
				map[wall[w3].first][wall[w3].second] = 0;			
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
