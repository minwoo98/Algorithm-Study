#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> a[100001];
bool check[100001];
int depth[100001];
int parent[100001];

int main()
{
	cin >> n;
	for(int i=0; i<n-1; i++)
	{
		int x,y;
		cin >> x >> y;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	queue<int> q;
	q.push(1);
	check[1] = true; depth[1] = 0; parent[1] = 0;
	
	while(!q.empty())
	{
		int num = q.front();
		q.pop();
		
		for(int y : a[num]) //a는 벡터인데 만약에 a[1]에 6,4가 푸시백 되었다면 a[1] 벡터에 추가된 요소만큼 for문 반복 (2번)  
		{
			if(check[y] == false) //방문한 적 없으면  
			{
				check[y] = true;
				depth[y] = depth[num] + 1; //a[1] 에 있는 6과 4는 depth가 같으므로 같은 행에 있음을 알 수 있다.(부모가 같음) 
				parent[y] = num; //각 노드를 자식자리에 배치시키고 나서 
				q.push(y); //큐에 푸시  
			}
		}	
	}
	
	for(int k=2; k<=n; k++)
	{
		cout << parent[k] << '\n';
	}
	
	

	return 0;
}
