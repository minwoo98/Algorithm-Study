#include <iostream>
#include <queue>
using namespace std;

int n;
int map[1001+100];
bool visited[1001+100] = {false};

int main(int argc, char** argv)
{		
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> map[i];
	}
	
	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	visited[1] = true;
	
	while(!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		//cout << now << '\n';
		q.pop();
		
		if(now == n)
		{
			cout << time << '\n';
			return 0;
		}

		for(int i=0; i<=map[now]; i++)
		{
			int next = now+i;
			if(visited[next] == false && next >=1 && next <=1000)
			{
				q.push({next,time+1});
				visited[next] = true;
			}
			else;
		}
	}
	cout << "-1";
	
	return 0;	
}
