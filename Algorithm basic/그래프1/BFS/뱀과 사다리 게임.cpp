#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 
#include<cstring>
using namespace std; 

int n,m;
int map[101] = {0,}; 
//map index�� ��ġ�� �ľ��ϰ� ���̳� ��ٸ��� ��� �̵��ؾ��� ��ġ�� �迭 ���� ����  
int cnt[101]; //0���δ� �ʱ�ȭ�� ���������� Ư�� ������ �ҰŸ� memset �̿�   
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
			
			//�� �Ǵ� ��ٸ��� ��� �̵� 
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
