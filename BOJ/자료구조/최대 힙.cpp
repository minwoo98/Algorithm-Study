#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> a;

int main(void)
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin >> n;
	priority_queue<int> q;
	
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		
		if(x==0)
		{
			if(q.size() == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n'; // priority queue top => queue front
				q.pop();
			}
		}
		else if(x>0)
		{
			q.push(x);
		}
	}

	return 0;	
}
