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
int n;
int count = 0;						//init the num of the result
int queen[100];

int checkout(int row, int col)     //check (i,j) is valid or not
{

    int mark = 1;
    for (int i = 0; i < row; ++i)
    {
        if (queen[i] == col || abs(i - row) == abs(queen[i] - col) )
        {
            mark = 0;
            break;					//decrease unnecessary check
        }
    }
    return mark;
}

void recur(int row, int nn)
{
    if (nn == row)
    {
        count++;
        return;              //the last line, print the result
    }
    else
    {
        for (int i = 0; i < nn; ++i)
        {
            if (checkout(row, i))
            {
                queen[row] = i;
                recur(row + 1, nn);
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    cin >> n;

    recur(0, n);

    cout << count;

    return 0;
}

