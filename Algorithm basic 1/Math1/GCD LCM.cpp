#include <iostream>
using namespace std;

int GCD(int x, int y)
{
	if(y==0) return x;
	return GCD(y, x%y);	
}

int main(int argc, char** argv) {
	
	int a,b, g;
	
	cin >> a >> b;
	g = GCD(a,b);
		
	cout << GCD(a,b) << '\n' << a*b/g << '\n';
	
	return 0;
}
