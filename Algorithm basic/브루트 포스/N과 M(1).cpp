#include <iostream>
using namespace std;

int n,m;
int arr[9] = {0,};
bool visited[9] = {0,};
 
void dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i=0; i<m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(!visited[i]) //온적 없는 경우에만 배열에 저장한다. 
		{
			visited[i] = true;
			arr[cnt] = i;	
			dfs(cnt+1);
			visited[i] = false;
		}
	}
}

int main(void)
{	
	cin >> n >> m;
	
	dfs(0);
	return 0;	
}

