#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[26][26];
int last_map[26][26];
bool check[26][26];
int cnt = 0;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<int> ans;

void bfs(int y, int x, int cnt)
{
	check[y][x] = true;	
	last_map[y][x] = cnt;
	
	queue<pair<int,int>> q;
	q.push({y,x});
	
	while(!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		
		q.pop();
		
		for(int k=0; k<4; k++)
		{
			int next_y = cur_y + dy[k];
			int next_x = cur_x + dx[k];
			
			if(next_y < 0 || next_y > n-1 || next_x < 0 || next_x > n-1)	continue;
			if(map[next_y][next_x] == 1 && check[next_y][next_x] == false)
			{
				q.push({next_y,next_x});
				check[next_y][next_x] = true;
				last_map[next_y][next_x] = cnt;
			}
		}
	}
}
int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j] == 1 && check[i][j] == false)
			{
				bfs(i,j,++cnt);
			}
		}
	}
	
	cout << cnt << '\n';
	
	for(int c=1; c<=cnt; c++)
	{		
		int ans_cnt = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(last_map[i][j] == c)
				{
					ans_cnt += 1;
				}
			}	
		}
		ans.push_back(ans_cnt);
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i=0; i<ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	
		
	return 0;
}
