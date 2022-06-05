#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int len = 0;
	int ans = 1;

	bool flag = false; //0->문자, 1->숫자  

	while(str[len])
	{
		len +=1;
	}
	
	int c = 26;
	int d = 10;
	
	for(int i=0; i<len; i++)
	{
		char ch = str[i];
		if(i==0)
		{
			if(ch == 'c')
			{
				ans = c;
				c -= 1;
				flag = false;
			}
			else
			{
				ans = d;
				d -= 1;
				flag = true;
			}
		}
		else
		{
			if(ch == 'c')
			{	
				d=10;	
				if(c==26)
				{
					ans*=c;
					c-=1;	
				}
				else if(c == 25)
				{
					if(flag == false)
					{
						ans *= c;
					}
					else
					{
						c=26;
						ans*=c;
					}
				}
				flag = false;
			}		
			else
			{
				c=26;
	
				if(d==10)
				{
					ans*=d;
					d-=1;	
				}
				else if(d==9)
				{
					if(flag == true)
					{
						ans*=d;
					}
				}
				flag = true;		
			}
		}		
	}

	cout << ans;

	return 0;	
}
