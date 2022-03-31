#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100];
bool check[100];

int main(void)
{
	int n, m;
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin >> u >> v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	check[1] = true;
	queue<int> q;
	q.push(1);
	
	int cnt = -1;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		cnt += 1;
		for(int i=0; i<a[node].size(); i++)
		{
			int next = a[node][i];
			if(check[next] == false)
			{
				q.push(next);
				check[next] = true;
			}
		}
	}
	cout << cnt;

	return 0;	
}
