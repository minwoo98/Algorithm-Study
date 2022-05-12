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
		
		for(int y : a[num]) //a�� �����ε� ���࿡ a[1]�� 6,4�� Ǫ�ù� �Ǿ��ٸ� a[1] ���Ϳ� �߰��� ��Ҹ�ŭ for�� �ݺ� (2��)  
		{
			if(check[y] == false) //�湮�� �� ������  
			{
				check[y] = true;
				depth[y] = depth[num] + 1; //a[1] �� �ִ� 6�� 4�� depth�� �����Ƿ� ���� �࿡ ������ �� �� �ִ�.(�θ� ����) 
				parent[y] = num; //�� ��带 �ڽ��ڸ��� ��ġ��Ű�� ���� 
				q.push(y); //ť�� Ǫ��  
			}
		}	
	}
	
	for(int k=2; k<=n; k++)
	{
		cout << parent[k] << '\n';
	}
	
	

	return 0;
}
