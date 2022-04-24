#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[9][9];
int n,m;
bool check[9][9];
vector<pair<int,int>> way;
queue<pair<int,int>> q;
int virus, wall;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int ans = 0;

int bfs()
{	//bfs새로 돌리면 방문 초기화  
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			check[i][j] = false;
		}
	} 
	
	int add_virus = virus;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(map[i][j] == 2)
			{
				q.push(make_pair(i,j));
			}
		}
	}

	while(!q.empty())
	{
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int next_y = now_y + dy[k];
			int next_x = now_x + dx[k];
			
			if(next_y > n || next_y < 1 || next_x > m || next_x < 1)	continue;
			if(check[next_y][next_x] == false && map[next_y][next_x] == 0) //맵 안에 있으면서 길(0)인 경우 바이러스 전파  
			{
				check[next_y][next_x] = true;
				q.push(make_pair(next_y, next_x));
				add_virus += 1;	
			}
		}
	}
	return n*m-(wall+3+add_virus);
}

int main(void)
{
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 0)
			{
				way.push_back(make_pair(i,j)); 
			}
			else if(map[i][j] == 1)
			{
				wall+=1;
			}
			else
			{
				virus+=1;
			}	
		}
	}
	// 벽 3개 세우기 시뮬레이션 진행(크기가 8x8밖에 안되서 브루트포스 가능)
	for(int i=0; i<way.size(); i++)
	{
		for(int j=i+1; j<way.size(); j++)
		{
			for(int k=j+1; k<way.size(); k++)
			{
				map[way[i].first][way[i].second] = 1;
				map[way[j].first][way[j].second] = 1;
				map[way[k].first][way[k].second] = 1;
				
				ans = max(ans,bfs());

				map[way[i].first][way[i].second] = 0;
				map[way[j].first][way[j].second] = 0;
				map[way[k].first][way[k].second] = 0;
			}
		}
	}
	cout << ans;
	
	return 0;
}

