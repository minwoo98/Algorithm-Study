#include<iostream>
#include<queue>

using namespace std;

int map[10];

//operator( T a, T b) // 비교할 두 값의 매개변수 정의
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
	// 크다 기호 -> 작은게 더 우선순위 높음
	// 작다 기호 -> 큰게 더 우선순위 높음(부호랑 반대로 기준)
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

//priority_queue 선언할 때 / priority_queue< T, vector<T> , cmp > pq;
//우선순위 제일 높은 값 확인 -> pq.top();
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