#include<iostream>

using namespace std;

int map[10][10];
int ans = 0;
int ans_cnt = 0;

int main(void)
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int t, y, x;
		cin >> t >> y >> x;

		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				map[i][j] = 0;
			}
		}

		if (t == 1)
		{
			map[y][x] = 1;

			//�Ķ��� ĭ���� ��� �̵�
			bool flag = false;
			for (int i = x; i <= 8; i++)
			{
				if (map[y][i + 1] == 1)
				{
					map[y][i] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)	map[y][9] = 1;

			//�ʷϻ� ĭ���� ��� �̵�
			flag = false;
			for (int i = y; i <= 8; i++)
			{
				if (map[i + 1][x] == 1)
				{
					map[i][x] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)	map[9][x] = 1;

		}
		else if (t == 2)
		{
			map[y][x] = 1;
			map[y][x+1] = 1;

			//�Ķ��� ĭ���� ��� �̵�
			bool flag = false;
			for (int i = x+1; i <= 8; i++)
			{
				if (map[y][i + 1] == 1)
				{
					map[y][i] = 1;
					map[y][i - 1] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				map[y][8] = 1;
				map[y][9] = 1;
			}

			//�ʷϻ� ĭ���� ��� �̵�(���� 2ĭ �� �ϳ��� ������ ���̴� �� ����)
			flag = false;
			for (int i = y; i <= 8; i++)
			{
				if (map[i + 1][x] == 1 || map[i + 1][x + 1] == 1)
				{
					map[i][x] = 1;
					map[i][x + 1] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				map[9][x] = 1;
				map[9][x + 1] = 1;

			}
		}
		else
		{
			map[y][x] = 1;
			map[y + 1][x] = 1;

			//�Ķ��� ĭ���� ��� �̵�
			bool flag = false;
			for (int i = x + 1; i <= 8; i++)
			{
				if (map[y][i + 1] == 1 || map[y+1][i + 1] == 1)
				{
					map[y][i] = 1;
					map[y+1][i] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				map[y][9] = 1;
				map[y+1][9] = 1;
			}

			//�ʷϻ� ĭ���� ��� �̵�	
			flag = false;
			for (int i = y+1; i <= 8; i++)
			{
				if (map[i + 1][x] == 1 )
				{
					map[i][x] = 1;
					map[i-1][x] = 1;
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				map[8][x] = 1;
				map[9][x] = 1;
			}
		}

//�� �� or ���� ��á���� �˻�
		int cnt = 0;
		int ry = 0; //�������� ��,�� y,x�� ���� 
		int rx = 0;

		//���ֱ� ���� ����ĭ �ʱ�ȭ
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				map[i][j] = 0;
			}
		}

	//1)�Ķ��� �� �˻�
		
		for (int x = 9; x >= 4; x--)
		{
			int temp = 0;
			for (int y = 0; y < 4; y++)
			{
				if (map[y][x] == 1)
				{
					temp += 1;
					if (temp == 4)
					{
						cnt += 1;
						rx = x;
						ry = y;
					}
				}
			}
		}
		
		//��n�� ���ְ�, rx���� ĭ n��ŭ�� ���������� �̵�, ���� n�� ȹ��
		if (cnt == 1 || cnt == 2)
		{
			for (int x = rx - 1; x >= 4; x--)
			{
				for (int y = 0; y <= 3; y++)
				{
					map[y][x+cnt] = map[y][x];			
				}
			}
		
			ans += cnt;
		}
		
	
		cnt = 0;
		
	//2)�ʷϻ� �� �˻�	
		for (int i = 9; i >= 4; i--)
		{	
			int temp = 0;
			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] == 1)
				{
					temp += 1;
					if (temp == 4)
					{
						cnt += 1;
						ry = i;
						rx = j;
					}
				}
			}	
		}

		
		//��n�� ���ְ�, ry���� ĭ n��ŭ�� �Ʒ��� �̵�, ���� n�� ȹ��
		if (cnt == 1 || cnt == 2)
		{
			for (int y = ry - 1; y >= 4; y--)
			{
				for (int x = 0; x <= 3; x++)
				{
					map[y+cnt][x] = map[y][x];
				}
			}

			ans += cnt;

		}
		else;

//���� ���� ĭ ó��
	//1) �Ķ��� ���� ĭ ó��
		
		int cnt2 = 0;
		for (int x = 4; x <= 5; x++)
		{
			int temp = 0;
			for (int y = 0; y <= 3; y++)
			{
				if (map[y][x] == 1)
				{
					temp += 1;
					if (temp > 0)
					{
						cnt2 += 1;
						break;
					}
				}
			}
		}

		if (cnt2 == 1 || cnt2 == 2)
		{
			for (int x = 9-cnt2; x >= 2; x--)
			{
				for (int y = 0; y <= 3; y++)
				{
					map[y][x + cnt2] = map[y][x];
				}
			}
		}

		cnt2 = 0;

	//2) �ʷϻ� ���� ĭ ó��
		for (int y = 4; y <= 5; y++)
		{
			int temp = 0;
			for (int x = 0; x <= 3; x++)
			{
				if (map[y][x] == 1)
				{
					temp += 1;
					if (temp > 0)
					{
						cnt2 += 1;
						break;
					}
				}
			}
		}

		if (cnt2 == 1 || cnt2 == 2)
		{
			if (cnt2 == 1)
			{
				for (int y = 8; y >= 2; y--)
				{
					for (int x = 0; x <= 3; x++)
					{
						map[y + 1][x] = map[y][x];
					}
				}
			}
			else
			{
				for (int y = 7; y >= 2; y--)
				{
					for (int x = 0; x <= 3; x++)
					{
						map[y + 2][x] = map[y][x];
						
					}
				}
			}
		}
		

		/////////////////////////////////////////////////////////////////////////////
		//display
	/*
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}

		for (int i = 4; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
	}

	//�ʷ�+�Ķ� Ÿ�� ����ִ� ĭ ���� ����
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 5; j <= 9; j++)
		{
			if (map[i][j] == 1)
			{
				ans_cnt += 1;
				//cout << i << "," << j << '\n';
			}
		}
	}

	for (int i = 4; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == 1)
			{
				ans_cnt += 1;
			}
		}

	}
	cout << ans << '\n';
	cout << ans_cnt << '\n';

	return 0;
	
}