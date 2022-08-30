#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//반례
/*
5
0 0 0 0 0
0 0 0 0 0
0 0 9 0 1
0 1 0 0 0
0 2 2 0 0
*/ 
//answer : 8
int n;
int map[21][21];
bool check[21][21] = {false};
int time = 0;

//우선순위를 고려한 탐색 순서 : 위,왼,오,아  
int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};

struct SHARK
{
	int y;
	int x;
	int eat_cnt;
	int my_size;
	int time;
};

int can_eat;

SHARK a;

void bfs(SHARK a)
{
	queue<SHARK> q;
	q.push(a);
	check[a.y][a.x] = true;
	
	while(!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int e = q.front().eat_cnt;
		int size = q.front().my_size;
		int time = q.front().time;
		
		//cout << y << ' ' << x << ' ' << time << '\n';
		
		//계속 종료조건 검사해줘야함  
		//종료조건: 먹을 수 있는 물고기가 없을 경우 종료 
		int can_eat = 0; 
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(map[i][j] < size && map[i][j] != 0)
				{
					can_eat +=1;
				}
			}
		}	

		if(can_eat == 0)
		{
			cout << time << '\n';
			return;
		}
		
		q.pop();
		
		
		for(int k=0; k<4; k++)
		{
			int ny = y+dy[k];
			int nx = x+dx[k];
			
			if(ny < 1 || ny > n || nx < 1 || nx > n || check[ny][nx] == true)	continue; 
			if(map[ny][nx] > size)	continue;
				
			//이동한 칸이 빈칸이거나 몰고기가 상어와 크기가 같은 경우 
			if(map[ny][nx] == 0 || map[ny][nx] == size)
			{
				q.push({ny,nx,e,size,time+1});
				check[ny][nx] = true;
			}
			//물고기가 상어보다 크기가 작은 경우  
			else if(map[ny][nx] < size)
			{
				//같은 거리에 있는 물고기 중 최단 거리에 있는 물고기 탐색
				//이전까지의  cnt가 같은 것들의 좌표를 빈 저장공간에 넣은 후 정렬 -> 최솟값 도출? 
				 
				//물고기 잡아 먹음  
				/*
				e += 1;
				if(e == size)
				{	
					size+=1;
					e = 0;
				}
				
				//물고기를 먹었다  -> 큐를 비운 뒤 push + 다른 방향이동할 필요없음(for문 k break) + 모든 방문체크 초기화해줘야함
				while(!q.empty())
				{
					q.pop();				
				}
				
				//cout << "비우기" << '\n'; 		
				q.push({ny,nx,e,size,time+1});
				map[ny][nx] = 0;
				memset(check,0,sizeof(check));
				check[ny][nx] = true;
				break;
				*/
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
 			cin >> map[i][j];
 			if(map[i][j] == 9)
 			{
 				a.y = i;
 				a.x = j;
 			}
 		}
 	}
 	
 	a.eat_cnt = 0;
 	a.my_size = 2;
 	a.time = 0;
 	
 	bfs(a);
 	
	return 0;	
}
