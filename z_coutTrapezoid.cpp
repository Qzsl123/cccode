/*
* 输入： 给定n个数（-500000,500000），从大到小输出前m大的数（m,n < 100000）
*/
#include <iostream>
using namespace std;

int main()
{
    int h, maxLine;
    cin >> h;
    maxLine = h + (h-1) * 2;
    for(int i = 0; i < h; i++){
        for(int j = 0;j < maxLine; j++){
            if(j < maxLine - h - i *2) cout << " ";
            else cout << "*";
        }
        cout << endl;
    }    
    return 0;
}