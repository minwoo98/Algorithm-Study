#include <iostream>
using namespace std;
	
int n,m;
int a[10];
bool check[10] = {false};
int temp;

void dfs(int cnt)
{
	if(cnt == m)
	{	
		for(int i=0; i<m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(check[i] == false && i>temp)
		{
			a[cnt] = i;
			check[i] = true;
			temp = i;
			dfs(cnt+1);
			check[i] = false;
			temp = 0;
		}
	}
}
	
	
	
int main(void)
{
	
	cin >> n >> m;
	
	dfs(0);
	
	return 0;	
}
