#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
 
 int n;
 char a[20];
 bool check[10]= {false,};

 vector<string> ans;
 
 bool ok(string num)
 {
 	for(int i=0; i<n; i++)
 	{
 		if(a[i] == '<')
 		{
 			if(num[i] > num[i+1])
 			{
 				return false;
 			}
 		}
 		else if(a[i] == '>')
 		{
 			if(num[i] < num[i+1])
 			{
 				return false;
 			}
 		}
 	}
 	return true;
 }
 void go(int index, string num)
 {
 	if(index == n+1)
 	{
 		if(ok(num))
 		{
 			ans.push_back(num);
 		}
 		return;
 	}
 	for(int i=0; i<=9; i++)
 	{
 		if(check[i]==true) continue;
 		check[i] = true;
 		go(index+1, num+to_string(i));
 		check[i] = false;
 	}
 }
 
 int main(void)
 {
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	go(0, "");
	
	cout << *max_element(ans.begin(), ans.end()) << '\n';
	cout << *min_element(ans.begin(), ans.end()) << '\n';
	
 	return 0;
 }
