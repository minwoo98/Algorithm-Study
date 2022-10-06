#include<iostream>
#include<queue>

using namespace std;

int map[10];

//operator( T a, T b) // ���� �� ���� �Ű����� ����
struct cmp
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.first == p2.first)
		{
			return p1.second > p2.second;
		}
		else
		{
			return p1.first > p2.first;
		}
	}
	// ũ�� ��ȣ -> ������ �� �켱���� ����
	// �۴� ��ȣ -> ū�� �� �켱���� ����(��ȣ�� �ݴ�� ����)
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

//priority_queue ������ �� / priority_queue< T, vector<T> , cmp > pq;
//�켱���� ���� ���� �� Ȯ�� -> pq.top();
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;

		pq.push({ a,b });
	}

	cout << '\n';

	while (!pq.empty())
	{
		int a = pq.top().first;
		int b = pq.top().second;

		pq.pop();
		cout << a << ' ' << b << '\n';
	}



	return 0;
}