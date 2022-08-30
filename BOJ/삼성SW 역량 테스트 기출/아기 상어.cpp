#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//�ݷ�
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

//�켱������ ����� Ž�� ���� : ��,��,��,��  
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
		
		//��� �������� �˻��������  
		//��������: ���� �� �ִ� ����Ⱑ ���� ��� ���� 
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
				
			//�̵��� ĭ�� ��ĭ�̰ų� ����Ⱑ ���� ũ�Ⱑ ���� ��� 
			if(map[ny][nx] == 0 || map[ny][nx] == size)
			{
				q.push({ny,nx,e,size,time+1});
				check[ny][nx] = true;
			}
			//����Ⱑ ���� ũ�Ⱑ ���� ���  
			else if(map[ny][nx] < size)
			{
				//���� �Ÿ��� �ִ� ����� �� �ִ� �Ÿ��� �ִ� ����� Ž��
				//����������  cnt�� ���� �͵��� ��ǥ�� �� ��������� ���� �� ���� -> �ּڰ� ����? 
				 
				//����� ��� ����  
				/*
				e += 1;
				if(e == size)
				{	
					size+=1;
					e = 0;
				}
				
				//����⸦ �Ծ���  -> ť�� ��� �� push + �ٸ� �����̵��� �ʿ����(for�� k break) + ��� �湮üũ �ʱ�ȭ�������
				while(!q.empty())
				{
					q.pop();				
				}
				
				//cout << "����" << '\n'; 		
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
