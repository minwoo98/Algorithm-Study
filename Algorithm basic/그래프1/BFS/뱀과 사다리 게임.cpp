#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 
#include<cstring>
using namespace std; 

int n,m;
int map[101] = {0,}; 
//map index로 위치를 파악하고 뱀이나 사다리인 경우 이동해야할 위치를 배열 값에 저장  
int cnt[101]; //0으로는 초기화가 가능하지만 특정 값으로 할거면 memset 이용   
vector<int> temp;

queue<int> q;

int main(void)
{
	cin >> n >> m;
	for(int k = 1; k<=n; k++)
	{
		int now, next;
		cin >> now >> next;
		map[now] = next;

		
	}
	for(int k=1; k<=m; k++)
	{
		int now, next;
		cin >> now >> next;
		map[now] = next;
	}
	
	memset(cnt,-1,sizeof(cnt));
	
	q.push(1);
	cnt[1] = 0;
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for(int k=1; k<=6; k++)
		{
			int next = now + k;
			if(next > 100)	continue;
			
			//뱀 또는 사다리인 경우 이동 
			if(map[next] != 0)
			{		  
				next = map[next];
			}
			if( cnt[next] == -1)
			{
				cnt[next] = cnt[now] + 1;
				q.push(next);
			}
		}
	}
	cout << cnt[100] << '\n';

	return 0;	
}
