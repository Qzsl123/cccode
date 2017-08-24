/*
Author  : zsl
Problem : p1212 进制转换 n进制 to 10进制
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	//char n[16];
	int m, ans = 0;
	cin >> n >> m;
	//char array[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int n_cvt = strtol(n, NULL, m);
	
	cout << n_cvt << endl;

	return 0;
}

