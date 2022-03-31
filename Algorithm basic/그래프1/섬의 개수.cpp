#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
 
int a[51][51];
int check[51][51];
int w, h;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

/*
void dfs(int y, int x, int cnt)
{
	check[y][x] = cnt;
	for(int k=0; k<8; k++)
	{
		int y_ = y+dy[k];
		int x_ = x+dx[k];
		
		if(y_ >= 0 && x>=0 && x_<=w && y_ <= h)
		{
			if( a[y_][x_] == 1 && check[y_][x_] == 0)
			{
				dfs(y_,x_,cnt);
			}
		}
	}
}*/
void bfs(int y, int x, int cnt)
{
	check[y][x] = cnt;
	
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++)
		{
			int y_ = y+dy[k];
			int x_ = x+dx[k];
			if( y_ >=0 && x_>=0 && y_<=h && x_<=w)
			{
				if(a[y_][x_] == 1 && check[y_][x_] == 0)
				{
					q.push(make_pair(y_,x_));
					check[y_][x_] = cnt;
				}
			}
		}
	}
}

 int main(void)
 {
 	while(1)
 	{		
 		cin >> w >> h;
 		if(w==0 && h == 0)
 		{
 			break;
 		}
 
 		for(int i=0; i<h; i++)
 		{
 			for(int j=0; j<w; j++)
 			{
 				scanf("%d", &a[i][j]);
 				check[i][j] = 0;
 			}
 		}
 		
 		int cnt = 0;
 		for(int i=0; i<h; i++)
 		{
 			for(int j=0; j<w; j++)
 			{
 				if(a[i][j] == 1 && check[i][j] == 0)
 				{
 					//dfs(i,j, ++cnt);
 					bfs(i,j, ++cnt);
 				}
 			}
 		}
 		
 		cout << cnt << '\n';
		
 	}
	
 	return 0;
 }
