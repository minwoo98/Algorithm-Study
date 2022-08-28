#include <iostream>

using namespace std;

int r,c,t;
int map[51][51];
bool check[51][51] = {false};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int down_y;
int ans = 0;

void spread(int y, int x, int temp[51][51])
{
	int cy = y;
	int cx = x;
	int now = map[y][x];
	int sp = now/5;
	
	for(int k=0; k<4; k++)
	{
		int ny = cy+dy[k];
		int nx = cx+dx[k];
		
		if(map[ny][nx] == -1 || ny < 0 || ny > r-1 || nx < 0 || nx > c-1)	continue;
		
		temp[ny][nx] += sp;
		temp[cy][cx] -= sp;
	/*
		//debug	
		cout << '\n';
		
		cout << cy << ' ' << cx << ' ' << map[cy][cx] << '\n';
		cout << ny << ' ' << nx << ' ' << map[ny][nx] << '\n';
	*/				
	}	
}

void move()
{
//������ �ݽð� move
	int up_y = down_y - 1;
	
	//1) x=0 �� �Ʒ��� �̵�  
	for(int y=up_y-2; y>=0; y--)
	{
		map[y+1][0] = map[y][0];
	}
	
	//2) y=0 �� �������� �̵�
	for(int x=1; x<=c-1; x++)
	{
		map[0][x-1] = map[0][x];
	}
	
	//3) x=c-1�� ���� �̵�
	for(int y=1; y<=up_y; y++)
	{
		map[y-1][c-1] = map[y][c-1];
	}
	
	//4) y=up_y�� ���������� �̵�
	for(int x=c-2; x>=1; x--)
	{
		map[up_y][x+1] = map[up_y][x];
	}
	
	//�� �������� ��ĭ �̵� �� �����ڸ� 0����  
	map[up_y][1] = 0;
		
//�Ʒ����� �ð� move
	
	for(int	y=down_y+2; y <= r-1; y++)
	{
		map[y-1][0] = map[y][0];
	}
	
	for(int x=1; x<=c-1; x++)
	{
		map[r-1][x-1] = map[r-1][x];
	}
	
	for(int y=r-2; y >= down_y; y--)
	{
		map[y+1][c-1] = map[y][c-1];	
	}
		
	for(int x=c-2; x>=1; x--)
	{
		map[down_y][x+1] = map[down_y][x];
	}
		
	map[down_y][1] = 0;
	
}

int main(int argc, char** argv)
{	
	cin >> r >> c >> t;
	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin >> map[i][j];
			//if(map[i][j] > 0)	check[i][j] = true;	�Ʒ����� �ѹ���  
			if(map[i][j] == -1)
			{
				down_y = i;
			}
		}
	}
	
	for(int k=1; k<=t; k++)
	{	
		//�ð��� ������ ���� �ʱ� �̼������� �ִ� ��� check �� true�� �������
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				if(map[i][j] > 0)	check[i][j] = true;
			}
		}
	 
	 
		int temp[51][51] = {0}; //Ȯ��� �̼����� �� ����  
		
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				if(map[i][j] > 0 && check[i][j] == true)
				{
					spread(i,j,temp);
				}
			}
		}
		//Ȯ��� �̼����� �߰�  
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				map[i][j] += temp[i][j]; 
			}
		}
		//1ĭ�� �̵�  
		move();	
	}
	
	//t�ð� ���� �̼����� ��������
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(map[i][j] > 0)
			{
				ans+=map[i][j]; 
			}
		}
	} 
	
	cout << ans;
	
	return 0;	
}
