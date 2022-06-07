#include <iostream>
#include <cstring>

using namespace std;

int n;
bool visited[1001];
int val[4] = {1,5,10,50};
int ans = 0;

void dfs(int cnt, int index, int sum)
{	
	if(cnt == n)
	{
		if(visited[sum] == false)
		{
			ans+=1;
			visited[sum] = true;
		}
		else	return;
	}
	else
	{
		for(int i=index; i<4; i++)
		{
			dfs(cnt+1,i,sum+val[i]);
		}
	}
}
	
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	memset(visited,false,sizeof(visited));
	dfs(0,0,0);
	
	cout << ans << '\n';
	 
	return 0;
}
