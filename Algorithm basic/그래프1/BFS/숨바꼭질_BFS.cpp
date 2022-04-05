#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

const int MAX = 100001;
int n,m;
int cnt[MAX]={0,};
bool check[MAX]={false,};

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = true;
	cnt[x] = 0;
	
	while(!q.empty())
	{
		int x = q.front();
		//cout << x << ' ';
		if(x==m)
		{
			//cout << "good" << '\n';
			cout << cnt[x];
			return;
		}
		
		q.pop();
		for(int k=0; k<3; k++)
		{
			if(k==0)
			{
				int x_next = x-1;
				if(check[x_next] == false)
				{
					if(x_next >= 0 && x_next < MAX)
					{
						q.push(x_next);
						cnt[x_next] = cnt[x] + 1;
						check[x_next] = true;
					}
				}
				else;
			}
			else if(k==1)
			{
				int x_next = x+1;
				if(check[x_next] == false)
				{
					if(x_next >= 0 && x_next < MAX)
					{
						q.push(x_next);
						cnt[x_next] = cnt[x] + 1;
						check[x_next] = true;
					}
				}
				else;
			}
			else
			{
				int x_next = 2*x;
				if(check[x_next] == false)
				{
					if(x_next >= 0 && x_next < MAX)
					{
						q.push(x_next);
						cnt[x_next] = cnt[x] + 1;
						check[x_next] = true;
					}
				}
				else;
			}
		}
	}	
}

 int main(void)
 {
	cin >> n >> m;
	bfs(n);
	
 	return 0;
 }
