#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
 	int k;
 	cin >> k;
 	
 	queue<int> q;
 
 	for(int i=0; i<k; i++)
 	{
 		int num;
 		cin >> num;
		q.push(num);
 	}
 	
 	int ans = 0;
 	vector<int> v(100000);
 	while(!q.empty())
 	{
 		int x = q.front();
 		if(x != 0)
 		{
 			v.push_back(x);
 			q.pop();
 		}
 		else if(x == 0)
 		{
 			v.erase(v.end()-1);
 			q.pop();
 		} 		
 	}
 
 	for(int i=0; i<v.size(); i++)
 	{
 		ans += v[i];
 	}
 	cout << ans;
	
	return 0;	
}
