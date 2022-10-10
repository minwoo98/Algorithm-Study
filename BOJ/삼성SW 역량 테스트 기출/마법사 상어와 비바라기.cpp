#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n, m;
int map[51][51];
int cloud[51][51]; //0:����x, 1:���� ���� �ִ� ��, 2: ���� �־��ٰ� ����� ��


pair<int, int> mov[101];

int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };

int cros_y[4] = { -1,-1,1,1 };
int cros_x[4] = { -1,1,1,-1 };

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			cloud[i][j] = 0;
		}
	}

	for (int k = 1; k <= m; k++)
	{
		cin >> mov[k].first >> mov[k].second;
	}

	int k = 1;
	cloud[n][1] = 1;
	cloud[n][2] = 1;
	cloud[n - 1][1] = 1;
	cloud[n - 1][2] = 1;
	while (m--)
	{
		//cout << "--------------------------" << '\n';
		int dir = mov[k].first;
		int s = mov[k].second;

		//cout << dir << ' ' << s << '\n';
		k += 1;
		//���� �˻�
		vector<pair<int, int>>  a;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cloud[i][j] == 1)
				{
					a.push_back({ i,j });
					cloud[i][j] = 0;
				}
			}
		}

		//���� �̵�
		for (int i = 0; i < a.size(); i++)
		{
			int y = a[i].first;
			int x = a[i].second;

			int ny = y + s * dy[dir];
			int nx = x + s * dx[dir];

			//index �Ѿ�� �� ����
			if (ny < 1)
			{
				while (1)
				{
					if (ny >= 1 && ny <= n)
					{
						break;
					}
					ny += n;
				}
			}
			else if (ny > n)
			{
				while (1)
				{
					if (ny >= 1 && ny <= n)
					{
						break;
					}
					ny -= n;
				}
			}
			if (nx < 1)
			{
				while (1)
				{
					if (nx >= 1 && nx <= n)
					{
						break;
					}
					nx += n;
				}
				
			}
			else if (nx > n)
			{
				while (1)
				{
					if (nx >= 1 && nx <= n)
					{
						break;
					}
					nx -= n;
				}
			}

			//cout << y << ' ' << x << "->" << ny << ' ' << nx << '\n';

			map[ny][nx] += 1;
			cloud[ny][nx] = 2;
			

		}

		//�밢�� ���� �˻� �� �� ����
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cloud[i][j] == 2)
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int ny = i + cros_y[k];
						int nx = j + cros_x[k];

						if (ny < 1 || ny > n || nx < 1 || nx > n)	continue;
						if (map[ny][nx] > 0)
						{
							cnt += 1;
						}
					}
					map[i][j] += cnt;
				}
			}
		}

		//������ �־��� ĭ(cloud�� 2)�� ������ ĭ �߿� ���� �� 2�̻��� �� �˻�
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cloud[i][j] == 2 || map[i][j] < 2)
				{
					cloud[i][j] = 0;
					continue;
				}
				if (cloud[i][j] != 2 || map[i][j] >= 2)
				{
					cloud[i][j] = 1;
					map[i][j] -= 2;
				}
			}
		}
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += map[i][j];
		}
	}
	cout << ans << '\n';

	

	return 0;
}