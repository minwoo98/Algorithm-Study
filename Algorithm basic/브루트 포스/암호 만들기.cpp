#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool check(string &answer)
{
	int ja = 0;
	int mo = 0;
	for(char x : answer)
	{
		if(x == 'a' || x=='e' || x=='i' || x=='o' || x=='u')
		{
			mo += 1;
		}
		else
		{
			ja += 1;
		}
	}
	return (ja >= 2 && mo >=1);
}

void go(int l, vector<char> a, string answer, int i)
{
	if(answer.length() == l)
	{
		if(check(answer))
		{
			cout << answer << '\n';
		}
		return;
	}
	if(i == a.size()) return;
	
	go(l, a, answer + a[i], i+1);
	go(l, a, answer, i+1);
}

 int main(void)
 {
	int l, c;
	
	cin >> l  >> c;
	
	vector<char> a(c);
	for(int i=0; i<c; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	go(l, a, "", 0);
	
 	return 0;
 }
