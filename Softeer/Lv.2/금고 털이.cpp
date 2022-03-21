#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(const pair<int,int> a, const pair<int,int> b)
{
	return a.second > b.second;
}
int main(int argc, char** argv)
{
	int w,n;
	cin >> w >> n;
	int ans = 0;

	vector<pair<int, int>> v;
	for(int i=0; i<n; i++)
	{
		int metal = 0;
		int price = 0;

		cin >> metal;
		cin >> price;

		v.push_back(pair<int,int>(metal, price));
	}

	sort(v.begin(),v.end(), cmp);

	for(int i=0; i<v.size(); i++)
	{
		int n = v[i].first; //first: °¹¼ö
		int p = v[i].second; //second: kg´ç °¡°Ý

		if(w > n)
		{
			w = w - n;
			ans += n * p;
		}
		else
		{
			for(int i=0; i<w; i++)
			{
				ans += p;
			}
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
