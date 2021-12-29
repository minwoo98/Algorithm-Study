#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
char a[600000];

int main(void){

	scanf("%s", a);
	stack<char> left, right;
	int n = strlen(a);
	
	for(int i=0; i<n; i++)
	{
		left.push(a[i]);
	}
	
	int m;
	cin >> m;
	while(m--)
	{			
		char str;
		cin >> str;
		
		if(str == 'L')
		{
			if(!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if(str == 'D')
		{
			if(!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if(str == 'B')
		{
			if(!left.empty())
			{
				left.pop();
			}	
		}
		else if(str == 'P')
		{
			char c;
			cin >> c;
				
			left.push(c);
		}
	}	
		
	while(!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while(!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	}
	
	return 0;	
}
