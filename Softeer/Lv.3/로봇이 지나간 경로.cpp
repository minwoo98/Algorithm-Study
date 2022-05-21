#include<iostream>
#include<cstring>

using namespace std;

int h,w;
char map[26][26];
bool visited[26][26];
int dx1[4] = {0,1,0,-1}; //��,��,��,��
int dy1[4] = {-1,0,1,0};
int dx2[4] = {0,2,0,-2}; //��,��,��,��
int dy2[4] = {-2,0,2,0};
char initial_pose;

string ans = "";

char assign_initial(int k)
{
	if(k==0) return '^';
	else if(k==1)	return '>';
	else if(k==2)	return 'v';
	else return '<';
}

string decide_turn(int k, int pose)
{
	if(pose == 0) //���� ���� ���϶�
	{
		if(k==0)
		{
			return "A";
		}
		else if(k==1)
		{
			return "RA";
		}
		
		else if(k==3)
		{
			return "LA";
		}
	}
	else if(pose == 1) //���� ���� ������
	{
		if(k==0)
		{
			return "LA";
		}
		else if(k==1)
		{
			return "A";
		}
		else if(k==2)
		{
			return "RA";
		}
	}
	else if(pose == 2) //���� ���� �Ʒ�
	{
		if(k==1)
		{
			return "LA";
		}
		else if(k==2)
		{
			return "A";
		}
		else if(k==3)
		{
			return "RA";
		}
	}
	else if(pose == 3) //���� ���� ����
	{
		if(k==0)
		{
			return "RA";
		}
		else if(k==2)
		{
			return "LA";
		}
		else if(k==3)
		{
			return "A";
		}
	}
}

void dfs(int y, int x, int pose)
{	
	//pose: -1-> �ʱ� ���� ����, pose: 0,1,2,3 -> ���� �����ƿ�
	visited[y][x] = true;

	for(int k=0; k<4; k++)
	{
		int ny1 = y+dy1[k];
		int nx1 = x+dx1[k];
		int ny2 = y+dy2[k];
		int nx2 = x+dx2[k];

		if( (ny2 >=1 && ny2 <= h && nx2 >=1 && nx2 <= w) && (ny1 >=1 && ny1 <= h && nx1 >=1 && nx1 <= w) )
		{
			if( (visited[ny1][nx1] == 0 && map[ny1][nx1] == '#') && (visited[ny2][nx2] == 0 && map[ny1][nx2] == '#'))
			{
				visited[ny1][nx1] = true;
				visited[ny2][nx2] = true;

				if(pose == -1)
				{
					initial_pose = assign_initial(k); //���� ���� ����
					ans += "A"; //ó������ ������ ������. ���⸸ �����ָ� ��
					pose = k;
					dfs(ny2,nx2,pose);
				}
				else
				{
					ans += decide_turn(k,pose); //ȸ�� �Ǵ� ���� �� ȸ���ϸ� ����pose�� �����.
					pose = k;
					dfs(ny2,nx2, pose);
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> h >> w;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			cin >> map[i][j];
			visited[i][j] = 0;
		}
	}

	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(map[i][j] == '#')
			{
				cout << i << ' ' << j << '\n';
				dfs(i,j,-1);
				cout << initial_pose << '\n';
				cout << ans;
				return 0;
			}
		}
	}
	return 0;
}
