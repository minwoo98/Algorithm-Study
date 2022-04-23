#include<iostream>
#include<vector>
using namespace std;

bool check[4] = {false,};
int num[4] = {1,2,3,4};
vector<int> a(2);

void dfs(int cnt, int index)
{
	if(cnt == 2)
	{
		for(int i=0; i<4; i++)
		{
			if(check[i] == true)
			{
				cout << num[i] << ' ';
			}
		}
		return;
	}
	
	for(int i=index; i<4; i++)
	{
		if(check[i] == true) continue;
		else
		{
			check[i] = true;
			dfs(cnt+1, i+1);
			check[i] = false;
		}
	}
}
int main(void)
{
	dfs(0,0);
}
