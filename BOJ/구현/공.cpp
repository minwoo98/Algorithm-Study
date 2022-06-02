#include <iostream>
using namespace std;
	
int main(void)
{
	int n;
	cin >> n;
	
	int cup[4]={0,1,2,3};
	int temp1,temp2,temp;
	
	for(int i=1; i<=n; i++)
	{
		int a,b,temp;
		cin >> a >> b;
		
		for(int j=1; j<=3; j++)
		{
			if(cup[j] == a)
			{
				temp1 = j;
			}
			else if(cup[j] == b)
			{
				temp2 = j;
			}
		}
		
		temp = cup[temp1];
		cup[temp1] = cup[temp2];
		cup[temp2] = temp;
	}
	
	cout << cup[1];
	
	return 0;	
}
