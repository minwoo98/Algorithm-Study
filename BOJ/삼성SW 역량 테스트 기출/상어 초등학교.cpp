#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
//830 start
using namespace std;

int n;
int map[21][21];
int fr[21*21][5];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct cmp
{
	bool operator()(pair<int,int> c, pair<int,int> d)
	{
		if (c.first == d.first)
		{
			return c.second > d.second;
		}
		else
		{
			return c.first > d.first;
		}
	}
};

int main()
{
	cin >> n;
	//총 학생 수: n*n
	for (int i = 1; i <= n * n; i++)
	{
		cin >> fr[i][0] >> fr[i][1] >> fr[i][2] >> fr[i][3] >> fr[i][4];
	}

	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n * n; i++)
	{
		//조건1 검사
		int like_near[21][21];
		int empty_near[21][21];
		bool check[21][21];

		memset(like_near, 0, sizeof(like_near));
		memset(empty_near, 0, sizeof(empty_near));
		memset(check, false, sizeof(check));

		int max_like = -1;
		int max_empty = -1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> a;
		vector<pair<int, int>> a_temp;
		vector<pair<int, int>> temp;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> b;
		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				if (map[y][x] == 0)
				{
					//인접한 곳 
					int like_cnt = 0;
					int empty_cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny < 1 || ny > n || nx < 1 || nx > n)	continue;

						//인접한 곳 중 좋아하는 학생있는지 검사(1)
						for (int m = 1; m <= 4; m++)
						{
							if (map[ny][nx] == fr[i][m])
							{
								like_cnt += 1;
								break;
							}
						}
						//인접한 곳 중 empty 몇 칸인지 검사(2)
						if (map[ny][nx] == 0)
						{
							empty_cnt += 1;
						}

						like_near[y][x] = like_cnt;
						empty_near[y][x] = empty_cnt;
						//max값 찾기
						max_like = max(max_like, like_cnt);
						max_empty = max(max_empty, empty_cnt);
					}
				}
			}
		}
		//debug
		/*
		cout << "like_near" << '\n';
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << like_near[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "empty_near" << '\n';
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << empty_near[i][j] << ' ';
			}
			cout << '\n';
		}

		cout << '\n';
		
		//cout << max_like << ' ' << max_empty << '\n';
	*/
		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				if (like_near[y][x] == max_like && map[y][x] == 0)
				{
					a.push({ y,x });
					a_temp.push_back({ y,x });
					check[y][x] = true;
					//cout << "like" << y << ' ' << x << '\n';
				}
				if (empty_near[y][x] == max_empty && map[y][x] == 0)
				{
					temp.push_back({ y,x });
					//cout << "empty" << y << ' ' << x << '\n';
				}
			}
		}
		
		//a_temp에서 temp에 해당하는 좌표만 추출해서 b에 저장
		for (int i = 0; i < a_temp.size(); i++)
		{
			int ty = a_temp[i].first;
			int tx = a_temp[i].second;
			for (int j = 0; j < temp.size(); j++)
			{
				int ay = temp[j].first;
				int ax = temp[j].second;

				if (ty == ay && tx == ax)
				{
					b.push({ ay,ax });
				}
				else;
				//a를 만족하는 좌표중 temp에 없을 수도 있음 -> a좌표들의 empty_cnt 값 비교
			}
		}
		//a를 만족하는 좌표중 temp에 없는 경우
		if (b.empty())
		{
			//cout << "in" << '\n';
			int max_v = -1;
			for (int i = 0; i < a_temp.size(); i++)
			{
				max_v = max(empty_near[a_temp[i].first][a_temp[i].second], max_v);
			}

			//cout << max_v << '\n';
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (empty_near[i][j] == max_v && check[i][j] == true)
					{
						b.push({ i,j });
						//cout << i << ' ' << j << '\n';
					}
				}
			}
		}

		if (a.size() == 1)
		{
			map[a.top().first][a.top().second] = fr[i][0];
		}
		else if (a.size() > 1)
		{
			map[b.top().first][b.top().second] = fr[i][0];
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

		cout << "--------------------" << '\n';
		*/
	}

	//result
	int ans = 0;

	for (int i = 1; i <= n * n; i++)
	{
		int val = fr[i][0];
		int ans_cnt = 0;
		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				if (map[y][x] == val)
				{
					for (int k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						
						if (ny < 1 || ny > n || nx < 1 || nx > n)	continue;
						for (int m = 1; m <= 4; m++)
						{					
							if (map[ny][nx] == fr[i][m])
							{
								ans_cnt += 1;
							}
						}
					}
				}
			}
		}
		//cout  << ans_cnt << '\n';
		if (ans_cnt == 0)
		{
			ans += 0;
		}
		else if (ans_cnt == 1)
		{
			ans += 1;
		}
		else if (ans_cnt == 2)
		{
			ans += 10;
		}
		else if (ans_cnt == 3)
		{
			ans += 100;
		}
		else
		{
			ans += 1000;
		}
	}

	cout << ans << '\n';

	return 0;
}