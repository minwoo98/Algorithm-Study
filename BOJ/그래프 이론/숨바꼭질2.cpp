#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

bool check[100001] = {false};

int main(void)
{
	int n,k;
	cin >> n >> k;

	int ans = 0;
	int temp = 0;
	
	queue<pair<int,int>> q;
	q.push({n,0});
	
	while(!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;

		q.pop();	
		check[now] = true; //pop할 때 방문처리 -> 다음 cnt에 반영됨  
		
		if(ans!=0 && now==k && time == temp)	ans+=1;
		if(now == k && ans == 0)
		{
			temp = time;
			ans +=1;
		}
		
		if(now -1 >=0 && now-1 <= 100000 && check[now-1] == false)	q.push({now-1,time+1});
		if(now+1 >=0 && now+1 <= 100000 && check[now+1] == false)	q.push({now+1,time+1});
		if(now*2 >=0 && now*2 <= 100000 && check[now*2] == false)	q.push({now*2,time+1});
		
	}

	cout << temp << '\n' << ans << '\n';
	
	return 0;	
}
