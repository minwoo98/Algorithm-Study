#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
	
int n,m;
bool check[10] = {false};
int arr[10];
vector<int> a;
int temp;

//cnt ��° ���� ä����� �Ѵ�. 
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
		if(check[i] == false)
		{
			arr[cnt] = a[i];
			check[i] = true;
			dfs(cnt+1);
			
			check[i] = false;
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
