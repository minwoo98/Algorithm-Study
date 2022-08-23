#include <iostream>
using namespace std;
	
int n,m;
int a[10];
bool check[10] = {false};
void dfs(int cnt)
{
	if(cnt == m)
	{	
		for(int i=0; i<10; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(check[i] == false)
		{
			a[cnt] = i;
			check[i] = true;
			dfs(cnt+1);
			check[i] = false;
		}
	}
}
	
	
	
int main(void)
{
	
	cin >> n >> m;
	
	dfs(0);
	
	return 0;	
}
