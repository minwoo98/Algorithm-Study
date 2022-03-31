#include <iostream>
#include <vector>

 using namespace std;
 
 int main(void)
 {
 	int n;
 	cin >> n;
 	
 	int temp = 0;
 	int ans = 0;
 	bool check = false;
 	
 	vector<int> a(n);
 
 	for(int i=0; i<n; i++)
 	{
 		cin >> a[i];
 	}
 
 	for(int i=0; i<a.size()-1; i++)
 	{
 		if(a[i] < a[i+1])
 		{
 			check = true;
 			temp += a[i+1] - a[i];	
 			if(temp > ans)
 			{
 				ans = temp;
			}
			else;
		}
 		else
 		{
 			temp = 0;
		}
 	}	
 	
 	if(check)
 	{
		cout << ans << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
	
 	return 0;
 }
