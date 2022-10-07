#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n;
int map[21][21];
bool check[21][21];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int ans = 0;

struct shark
{
	int y;
	int x;
	int eating;
	int size;
	int time;

};

struct compare
{
	bool operator()(shark a, shark b)
	{
		if (a.time == b.time)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			else
			{
				return a.y > b.y;
			}
		}
		else
		{
			return a.time > b.time;
		}
	}
};


void bfs(shark s)
{
	priority_queue<shark, vector<shark>, compare> q;
	q.push(s);

	while (!q.empty())
	{
		shark now = q.top();
		q.pop();
		
		//상어가 물고기를 잡아먹을 조건
		if (map[now.y][now.x] > 0 && map[now.y][now.x] < now.size)
		{
			map[now.y][now.x] = 0;
			memset(check, false, sizeof(check));
			check[now.y][now.x] = true;

			now.eating += 1;
			if (now.eating == now.size)
			{
				now.eating = 0;
				now.size += 1;
			}

			ans = now.time;

			while (!q.empty())
			{
				q.pop();
			}
		}

		for (int k = 0; k < 4; k++)
		{
			int ny = now.y + dy[k];
			int nx = now.x + dx[k];

			if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1)	continue;
			if (check[ny][nx] == true || map[ny][nx] > now.size)	continue;

			q.push({ ny,nx,now.eating,now.size,now.time + 1 });
			check[ny][nx] = true;
		}
	}

	cout << ans << '\n';
	return;
	
}

shark s;

int main(void)
{
	cin >> n;

	s.eating = 0;
	s.size = 2;
	s.time = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				s.y = i;
				s.x = j;
				map[s.y][s.x] = 0;
				check[s.y][s.x] = true;
			}
		}
	}

	bfs(s);


	return 0;
}