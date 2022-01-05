#include <iostream>
#include <time.h>
using namespace std;

int memo[10000];
// meme[i] = 0 -> 값이 계산된 적이 없음을 의 미
 
int fibonacci_memo(int n)
{
	if(n<=1) return n;
	else
	{	
		if(memo[n]> 0)
		{
			return memo[n];
		}
		memo[n] =  fibonacci_memo(n-1) + fibonacci_memo(n-2);
		return memo[n];
	} 
}
int fibonacci(int n)
{
	if(n<=1) return n;
	else
	{	
		return fibonacci(n-1) + fibonacci(n-2);
	} 
}
int main(void)
{
	int n;
	cin >> n;
	int ans;
	
	clock_t start, end;
	
	start = clock();
	ans = fibonacci(n);
	cout << ans << '\n';
	
	end = clock();
	int ms = (end - start);
	cout << ms << "ms" << '\n';
	 
	return 0;
}
