#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void){
	
	int n;
	
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	
	for(int i=1; i<n+1; i++){
		cin >> a[i];	
	}
	stack<int> s;
	
	for(int i=1; i<n+1; i++){
		
		s.push(a[i]); 
		while(!s.empty() && s.top() < a[i+1]){
			
			ans[i] = a[i+1];
			s.pop();	
		}
	}
	for(int i=1; i < n+1; i++)
	{
		cout << ans[i] << ' ';	
	}
	return 0;	
}
