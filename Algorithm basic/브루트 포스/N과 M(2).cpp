#include <iostream>
using namespace std;

int temp = 0; 
int arr[9] = {0,};

void dfs(int index, int n, int m)
{
	if(index == m)
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
		if(i>temp)
		{
			temp = i;	
			arr[index] = i;
			dfs(index+1,n,m);
			temp = 0;
		}
	}
	
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	dfs(0,n,m);
	
	return 0;	
}

