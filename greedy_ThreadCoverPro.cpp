/*
Author  : zsl
Problem :  给定x轴上的N（0<N<100）条线段，每个线段由它的二个端点a_I和b_I确定，
		I=1,2,……N.这些坐标都是区间（－999，999）的整数。有些线段之间会相互交叠或覆盖。
		请你编写一个程序，从给出的线段中去掉尽量少的线段，使得剩下的线段两两之间没有
		内部公共点。所谓的内部公共点是指一个点同时属于两条线段且至少在其中一条线段的内部
		（即除去端点的部分）。
Solution: 使得小端点在左边，然后排序，然后从左边开始检查，无覆盖就选择留下
*/
#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
	int a,b;
}x[100];

int cmp(node x1, node x2){
	return x1.b < x2.b;
}
int main(int argc, char const *argv[])
{
	int n, aver, count = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i].a >>x[i].b;
		if(x[i].a > x[i].b) swap(x[i].a, x[i].b);
	}
	
	sort(x, x+n, cmp);
	
	int res = 0, max = -10000;
	for (int i = 0; i < n; ++i)
	{
		if (x[i].a >= max)
		{
			res++;
			max = x[i].b;
		}
	}
	cout << res;
	return 0;
}