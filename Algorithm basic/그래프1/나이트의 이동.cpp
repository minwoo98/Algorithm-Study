#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{	
		int l;
		cin >> l;
		
		int start_y, start_x;
		cin >> start_y >> start_x;	
		int end_y, end_x;
		cin >> end_y >> end_x;
		
		bool check[301][301] = {false,};
		int dist[301][301] = {0,};
		
		check[start_y][start_x] = true;
		queue<pair<int,int>> q;
		q.push(make_pair(start_y,start_x));
		dist[start_y][start_x] = 0;
		
		while(!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			if(y == end_y && x == end_x)
			{
				cout << dist[y][x] << '\n';
				break;
			}
			q.pop();
			
			for(int k=0; k<8; k++)
			{
				int y_ = y+dy[k];
				int x_ = x+dx[k];
				if(y_ >=0 && x_>=0 && y_<=l-1 && x_ <= l-1)
				{
					if(check[y_][x_] == false)
					{
						q.push(make_pair(y_,x_));
						check[y_][x_] = true;
						dist[y_][x_] = dist[y][x] + 1;
					
					}
				}
			}
		}
	}
		
	return 0;	
}

