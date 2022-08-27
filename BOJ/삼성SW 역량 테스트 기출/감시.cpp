#include <iostream>
#include <vector>
using namespace std;

int n,m;
int map[8][8];

struct CCTV
{
	int x;
	int y;
	int type;
};

CCTV cctv[8];
int cctv_size;
int rot_size[5] = {4,2,4,4,1}; //1,2,3,4,5 cctv 

int ans = 987654321;

void map_copy(int temp[8][8], int a[8][8])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			temp[i][j] = a[i][j];
		}
	}
}

void update(int dir, CCTV cctv)
{
	//dir 0 , 1 ,2 ,3 -> 위 ,오 ,아, 왼 방향으로 update  
	dir = dir%4;
	
	if(dir == 0)
	{
		for(int y=cctv.y-1; y>=0; y--)
		{
			if(map[y][cctv.x] == 6)	break;
			
			map[y][cctv.x] = -1;
		}
	}	
	else if(dir == 1)
	{
		for(int x=cctv.x+1; x<m; x++)
		{
			if(map[cctv.y][x] == 6)	break;
			
			map[cctv.y][x] = -1;
		}
	}
	else if(dir == 2)
	{
		for(int y=cctv.y+1; y<n; y++)
		{
			if(map[y][cctv.x] == 6)	break;
			
			map[y][cctv.x] = -1;
		}	
	}
	else if(dir == 3)
	{
		for(int x=cctv.x-1; x>=0; x--)
		{
			if(map[cctv.y][x] == 6)	break;
			
			map[cctv.y][x] = -1;
		}
	}
}
void dfs(int cctv_index)
{
	//cctv_index 번 째 cctv로 탐색
	if(cctv_index == cctv_size)
	{
		//최소 감시 영역 구하기  
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(map[i][j] == 0)
				{
					cnt += 1;
				}
			}
		}
		ans = min(ans,cnt);
		
		return;
	}
	else
	{
		int backup[8][8]; //dfs 끝난 후 백업용  
		int type = cctv[cctv_index].type;
		//cctv type에 따라 dir 정하기
		for(int dir = 0; dir < rot_size[type]; dir++)
		{
			if(type == 0)
			{
				map_copy(backup,map);      //map beckup
				update(dir,cctv[cctv_index]);	//map update
				dfs(cctv_index+1);
				map_copy(map,backup);	//dfs 끝난 후 map re backup;
			}
			else if(type == 1)
			{
				map_copy(backup,map);      //map beckup
				update(dir,cctv[cctv_index]);	//map update
				update(dir+2,cctv[cctv_index]); //180도 방 향  
				dfs(cctv_index+1);
				map_copy(map,backup);	//dfs 끝난 후 map re backup;
			}
			else if(type == 2)
			{
				map_copy(backup,map);     //map beckup
				update(dir,cctv[cctv_index]);	//map update
				update(dir+1,cctv[cctv_index]);	//90도 만큼 오른쪽 방향  
				dfs(cctv_index+1);
				map_copy(map,backup);	//dfs 끝난 후 map re backup;
			}
			else if(type == 3)
			{
				map_copy(backup,map);      //map beckup
				update(dir,cctv[cctv_index]);	//map update
				update(dir+1,cctv[cctv_index]);	//map update
				update(dir+2,cctv[cctv_index]);	//map update
				dfs(cctv_index+1);
				map_copy(map,backup);	//dfs 끝난 후 map re backup;
			}
			else if(type == 4)
			{
				map_copy(backup,map);      //map beckup
				update(dir,cctv[cctv_index]);	//map update
				update(dir+1,cctv[cctv_index]);
				update(dir+2,cctv[cctv_index]);
				update(dir+3,cctv[cctv_index]);
				dfs(cctv_index+1);
				map_copy(map,backup);	//dfs 끝난 후 map re backup;
			}
		}
	}
}

int main(int argc, char** argv)
{		
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> map[i][j];
			
			if(map[i][j] !=0 && map[i][j] !=6)
			{
				cctv[cctv_size].y = i;
				cctv[cctv_size].x = j;
				cctv[cctv_size].type = map[i][j] - 1; //rot_size index에 맞추기 위해 -1  
				
				cctv_size+=1;
			}
		}
	}
	
	//cctv 갯수만큼 완전탐색 
	dfs(0);
	
	//사각지대 출력  
	cout << ans;
	
	return 0;	
}
