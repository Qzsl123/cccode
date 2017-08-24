//输入一组数据，输出要查找数据的下标
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main()
{
    int buf[5] = {1, 2, 3, 4, 5};
    int n, postion = -1;
    cin >> n;
    for(int i = 0; i < 5; i++){
        if(n == buf[i]){ 
          postion = i;
          break;
        }
    }
    cout << postion << endl;

    return 0;
}