/*
Author  : zsl
Problem : p1212　Prime Number
*/
#include <iostream>
using namespace std;
int MaxCD(int x,int y);
int main(int argc, char const *argv[])
{
	int input, mark = 0;
	cin >> input ;
	if (input == 1)
	{
	   mark = 0;
	}
	else{
		for (int i = 2; i < input; ++i){
			if (MaxCD(i,input) != 1)
			{
			   mark = 1;
			}
		}
	}
	if (mark == 0)
	{
		cout << "\\t" << endl;
	}
	else cout << "\\n" << endl;
	return 0;
}

int MaxCD(int x, int y){
	int tmp;
	if(x > y){
		tmp = x;
		x = y;
		y = tmp;
	}
	int r = x;
	while(r != 0){
		r = y % x;
		y = x;
		x = r;
	}
	return y;
}
