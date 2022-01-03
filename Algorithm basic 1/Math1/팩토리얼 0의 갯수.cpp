#include <iostream>
using namespace std;

//calculate n! func
int factorial(int n)
{
	if(n==0) return 1;
				
	return n*factorial(n-1);	
}

int main(int argc, char** argv)
{		
	int N;
	cin >> N;
	int zero_cnt = 0;
	//cout << factorial(num) << '\n';
	for(int i=5; i<=N; i*=5) // facto result zero count is equal to '5' count
	{	
		zero_cnt += N/i; 
	}
	
	cout << zero_cnt << '\n';
	
	return 0;	
}
