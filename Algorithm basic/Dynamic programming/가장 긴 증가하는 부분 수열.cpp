#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000];
int d[1000];
int v[1000];

void go(int p)
{
	if(p==-1) return;
	
	go(v[p]);
	cout << a[p] << ' ';	
}

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++)
	{
 		cin >> a[i];
	}
	
	vector<int> d(N,1);
	for(int i=0; i<a.size(); i++)
	{	
		v[i] = -1;
		for(int j=0; j<i; j++)
		{
			if(a[i] > a[j] && d[j]+1 > d[i] )
			{
				d[i] = d[j]+1;
				v[i] = j;
			}
		}
	}	
	//cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
