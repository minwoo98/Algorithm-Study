#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

struct fireball
{
	int y;
	int x;
	int m;
	int s;
	int d;
};

//*�߿�* 2���� ���Ϳ� push�� ������ �߰��Ǵ� index�� ������ index��. ex) map[0][0][n] -> size of map[0][0] : n+1��(0~n)

vector<fireball> fireballs; //���̾ ���� 
vector<fireball> map[51][51]; //fireballs���� �� ���̾�� ���� ��ġ ���� �� map�� push_back

int n, m, k;

//01234567
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int ans = 0;

bool decide_dir(int y, int x)
{
	int first_dir = map[y][x][0].d % 2;
	bool ans = false;

	for (int s = 1; s < map[y][x].size(); s++)
	{
		int dir = map[y][x][s].d % 2;

		if (first_dir == dir)
		{
			ans = true;
		}
		else
		{
			ans = false;
			return ans;
		}
	}

	return ans;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		fireball fire;
		cin >> fire.y >> fire.x >> fire.m >> fire.s >> fire.d;
		
		fireballs.push_back(fire);
	}

	for (int t = 1; t <= k; t++)
	{
		//������ ������ map���� �ʱ�ȭ
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j].clear();
			}
		}

		//���̾ �̵�
		for (int i = 0; i < fireballs.size(); i++)
		{
			fireball cur = fireballs[i];
			
			int cx = cur.x;
			int cy = cur.y;

			int ny = cy + cur.s * dy[cur.d];
			int nx = cx + cur.s * dx[cur.d];
			while (ny < 1)	ny += n;
			while (ny > n)	ny -= n;
			while (nx < 1)	nx += n;
			while (nx > n)	nx -= n;

			map[ny][nx].push_back({ ny,nx,cur.m,cur.s,cur.d });
		}

		//���̾ �ɰ���
		vector<fireball> temp; //���纻
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int mass_sum = 0;
				int vel_sum = 0;
				if (map[i][j].size() == 0)	continue;
				if (map[i][j].size() == 1)
				{
					temp.push_back(map[i][j][0]);
				}
				else
				{
					for (int s = 0; s < map[i][j].size(); s++)
					{
						mass_sum += map[i][j][s].m;
						vel_sum += map[i][j][s].s;
					}

					int last_m = mass_sum / 5;
					int last_s = vel_sum / map[i][j].size();

					if (last_m == 0)	continue;

					//���� ���� �� temp push
					if (decide_dir(i, j) == true)
					{
						//��� ¦���ų� Ȧ���� ���
						temp.push_back({ i,j,last_m,last_s,0 });
						temp.push_back({ i,j,last_m,last_s,2 });
						temp.push_back({ i,j,last_m,last_s,4 });
						temp.push_back({ i,j,last_m,last_s,6 });
					}
					else
					{
						temp.push_back({ i,j,last_m,last_s,1 });
						temp.push_back({ i,j,last_m,last_s,3 });
						temp.push_back({ i,j,last_m,last_s,5 });
						temp.push_back({ i,j,last_m,last_s,7 });
					}
				}
			}
		}

		//vector copy
		fireballs = temp;
		/*
		//debug

		cout << '\n';
		for (int i = 0; i < fireballs.size(); i++)
		{
			int y = fireballs[i].y;
			int x = fireballs[i].x;
			int m = fireballs[i].m;
			int s = fireballs[i].s;
			int d = fireballs[i].d;

			cout << y << ' ' << x << ' ' << m << ' ' << s << ' ' << d << '\n';
		}
		*/

	}
	
	//���� ���ϱ�
	for (int i = 0; i < fireballs.size(); i++)
	{
		ans += fireballs[i].m;
	}

	cout << ans << '\n';
	

	return 0;
}