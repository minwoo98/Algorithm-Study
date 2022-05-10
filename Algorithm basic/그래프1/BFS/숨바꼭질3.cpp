#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100001;
int map[MAX];
bool check[MAX];
int cnt[MAX];

int n,m;
int ans = 0;

int main(void)
{
 	cin >> n >> m;
	deque<int> dq;
	
	dq.push_front(n);
	check[n] = true;
	cnt[n] = 0;
	
	while(!dq.empty())
	{
		int x = dq.front();
		dq.pop_front();
		
		if(x==m)
		{
			cout << cnt[x] << '\n';
			break;
		}
		
		for(int k=0; k<3; k++)
		{
			if(k==0)
			{
				int x_next = x*2;                  //�����̵��� 0�ʰɸ��Ƿ� �켱������ ���� => ���� deque front�� �־��ش�.(�켱���� ��)  �������� ����(�켱������) 
				if(check[x_next] == false)
				{
					if(x_next>=0 && x_next<MAX)
					{
						check[x_next] = true;
						dq.push_front(x_next);
						cnt[x_next] = cnt[x];
					}
				}
			}
			else if(k==1)
			{
				int x_next = x+1;
				if(check[x_next] == false)
				{
					if(x_next>=0 && x_next<MAX)
					{
						check[x_next] = true;
						dq.push_back(x_next);
						cnt[x_next] = cnt[x] + 1;
					}
				}
			}
			else
			{	
				int x_next = x-1;
				if(check[x_next] == false)
				{
					if(x_next>=0 && x_next<MAX)
					{
						check[x_next] = true;
						dq.push_back(x_next);
						cnt[x_next] = cnt[x] + 1;
					}
				}
			}
		}
	}
	return 0;	
}
