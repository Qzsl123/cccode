/** 
* 回溯法解N皇后问题 
* 使用一个一维数组表示皇后的位置 
* 其中数组的下标表示皇后所在的行 
* 数组元素的值表示皇后所在的列 
* 这样设计的棋盘，所有皇后必定不在同一行，于是行冲突就不存在了 
* date  : 2017-3-7  
* author: zsl 
**/
#include <iostream>
#include <cmath>
using namespace std; 
#define INIT -100
int n;
int count = 0;						//init the num of the result
int queen[100];

void init(){
	for (int i = 0; i < 100; ++i)
	{
		queen[i] = INIT;
	}
}

int checkout(int row, int col){

	int mark = 1;
	for (int i = 0; i < row; ++i)
	{
		if (queen[i] == col || abs(i - row) == abs(queen[i] - col) )
		{
			mark = 0;
			break;
		}
	}
	return mark;
}

void fun(){

	int i = 0, j = 0;

	while (i < n)
	{
		while(j < n)
		{
			if (checkout(i,j))
			{
				queen[i] = j;
				j = 0;
				break;
			}else{
				++j;
			}
		}

		if (queen[i] == INIT)
		{
			if (i == 0)
			{
				break;
			}else{
				--i;
				j = queen[i] + 1;
				queen[i] = INIT;
				continue;
			}
		}

		if (i == n-1)
		{
			count++;
			j = queen[i] + 1;
			queen[i] = INIT;
			continue;
		}
		++i;
	}
}

int main(int argc, char const *argv[])
{
	init();
	
	cin >> n;

	fun();

	cout << count;

	return 0;
}

