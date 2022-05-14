#include <iostream>
#include <cstdio>
#include <cstring> //memset

using namespace std;

int n;
char map[101][101];
bool check[101][101];

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int ans1 = 0;
int ans2 = 0;

void dfs(int y, int x)
{
	check[y][x] = true;
	
	for(int k=0; k<4; k++)
	{
		int y_ = y+dy[k];
		int x_ = x+dx[k];
		
		if(y_ >=1 && y_ <=100 && x_>=1 && x_<=100 && check[y_][x_] == false)
		{
			if(map[y_][x_] == map[y][x])
			{
				dfs(y_,x_);
			}
		}
	}
}

int main(void)
{
 	cin >> n;
 	for(int i=1; i<=n; i++)
 	{
 		for(int j=1; j<=n; j++)
 		{
 			scanf("%1s", &map[i][j]);
 			check[i][j] = false;
 		}
 	}
 	
 	for(int i=1; i<=n; i++)
 	{
 		for(int j=1; j<=n; j++)
 		{
 			if(check[i][j] == false)
 			{
 				dfs(i,j);
 				//dfs가 끝났다는 말은 다른 문자가 나왔기 때문에 구역이 1개 추가되는 것임
				ans1 +=1; 
 			}
 		}
 	}
 	cout << ans1 << ' ';
 	
 	memset(check,false,sizeof(check));
 	//적록색약 사람 기준 구역 갯 수  
 	for(int i=1; i<=n; i++)
 	{
 		for(int j=1; j<=n; j++)
 		{
 			if(map[i][j] == 'G')
 			{
 				map[i][j] = 'R';
 			}
 		}
 	}
 
 	for(int i=1; i<=n; i++)
 	{
 		for(int j=1; j<=n; j++)
 		{
 			
 			if(check[i][j] == false)
 			{
 				dfs(i,j);
 				//dfs가 끝났다는 말은 다른 문자가 나왔기 때문에 구역이 1개 추가되는 것임
				ans2 +=1; 
 			}
 		}
 	}
 	cout << ans2;

	return 0;	
}
