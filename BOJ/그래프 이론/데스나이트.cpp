#include <iostream>
#include <queue>

using namespace std;

int n;
int map[201][201];
bool visited[201][201] = {false,};
int cnt[201][201];

int dx[6] = {-2,-2,0,0,2,2};
int dy[6] = {-1,1,-2,2,-1,1};

int main(void)
{
	cin >> n;
	// r->x, c->y
	int start_y, start_x;
	int end_y, end_x;
	cin >> start_x >> start_y >> end_x >> end_y;
	
	queue<pair<int,int>> q;
	q.push({start_y,start_x});
	visited[start_y][start_x] = true;
	cnt[start_y][start_x] = 0;
	
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		if(y == end_y && x == end_x)
		{
			cout << cnt[y][x] << '\n';
			return 0;
		}
		
		for(int k=0; k<6; k++)
		{
			int next_y = y+dy[k];
			int next_x = x+dx[k];
			
			if(visited[next_y][next_x] == true)
			{
				continue;
			}
			if(next_y <0 || next_y >n-1 || next_x <0 || next_x >n-1)
			{
				continue;
			}
			
			visited[next_y][next_x] = true;
			q.push({next_y,next_x});
			cnt[next_y][next_x] = cnt[y][x] + 1;
					
		}
	}
	//
	cout << "-1";
	 
	return 0;
}
