#include<iostream>
#include<vector>

using namespace std;
 
vector<int> a[20000];
int check[20001]; // 0 1 2

void dfs(int node, int c)
{
	check[node] = c;
	cout << node << ' ';
	for(int i=0; i<a[node].size(); i++)
	{
		int next = a[node][i];
		if(check[next] == 0)
		{
			dfs(next, 1);
		}
	}
}

 int main(void)
 {
	int t;
	cin >> t;
	
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++)
		{
			a[i].clear();
			check[i] = 0;
		}
		for(int i=0; i<m; i++)
		{
			int u,v;
			cin >> u >> v;
			
			a[u].push_back(v);
			a[v].push_back(u);
		}
			
		for(int i=1; i<=n; i++)
		{
			if(check[i] == 0)
			{
				dfs(i,1);
			}
		}
		
		bool ok = true;
		for(int i=1; i<=n; i++)
		{
			for(int k=0; k<a[i].size(); k++)
			{
				int j = a[i][k];
				if(check[i] == check[j])
				{
					ok = false;
				}
			}
		}
		if(ok)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	

 	return 0;
 }
