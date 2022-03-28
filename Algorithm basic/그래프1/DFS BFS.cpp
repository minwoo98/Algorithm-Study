#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> a[1002];
bool check[1002];
bool check_[1002];

void dfs(int node)
{
	check[node] = true;
	cout << node << ' ';
	
	for(int i=0; i<a[node].size(); i++)
	{
		int next = a[node][i];
		if(check[next] == false)
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	check_[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << ' ';
		for(int i=0; i<a[node].size(); i++)
		{
			int next = a[node][i];
			if(check_[next] == false)
			{
				check_[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n,m,v;
	cin >> n >> m >> v;
	
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0; i<m; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(v);
	cout << '\n';
	bfs(v);
/*	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	*/
	return 0;
}
