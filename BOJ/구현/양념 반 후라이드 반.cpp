#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
 	int a,b,c,x,y;
	int ans = 9876543210;
 	
 	cin >> a >> b >> c >> x >> y;
 	
 	if(2*c < a+b)
 	{
 		if(x>y)
 		{
 			for(int i=y; i<=x; i++)
 			{
 				int money = 2*c*i+(x-i)*a;
 				if(ans > money)
 				{
 					ans = money;
 				}
 			}
 		}
 		else
 		{
 			for(int i=x; i<=y; i++)
 			{
 				int money = 2*c*i+(y-i)*b;
 				if(ans > money)
 				{
 					ans = money;
 				}
 			}
 		}
 	}
 	else
 	{
 		ans = a*x+b*y;
 	}
 	
 	cout << ans;
	
	return 0;	
}
