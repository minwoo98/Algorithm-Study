#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
	
int n,m;
bool check[10] = {false};
int arr[10];
vector<int> a;
int temp = 0;

//cnt 번째 값을 채우려고 한다. 
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
	
	for(int i=0; i<a.size(); i++)
	{
		if(check[i] == false && a[i] > temp)
		{
			arr[cnt] = a[i];
			check[i] = true;
			temp = a[i];
			dfs(cnt+1);
			
			check[i] = false;
			temp = 0;
		}
	}
}	
	
int main(void)
{

	cin >> n >> m;
	a.resize(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	
	sort(a.begin(),a.end());
	
	dfs(0);
	
	return 0;	
}
