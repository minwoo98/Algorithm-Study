#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

	
int main(void)
{
	int score[11] = {0};
	int mush[11];
	int a[11];
	int ans = 999;
	int idx;

	for(int i=0; i<10; i++)
	{
		cin >> mush[i];
		if(i==0)
		{
			score[i] = mush[i];
		}
		else
		{
			score[i] = score[i-1]+mush[i];
		}
		a[i] = abs(score[i] - 100);
	}
	
	for(int i=0; i<10;i++)
	{
		ans = min(a[i],ans);
	}
	
	for(int i=0; i<10; i++)
	{
		if(a[i] == ans)
		{
			idx = i;
		}
	}
	
	cout << score[idx];

	return 0;	
}
