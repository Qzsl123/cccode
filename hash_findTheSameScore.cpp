/*
* 输入： N（N < 1000）
*       N个数
*       要找到的数(score < 100)
*       N = 0时结束
*/
#include <iostream>
using namespace std;
int main(){
    int n, m;
    int res[100], counter = 0;
    int a[n], buf[100] = {0};
    while(1){
        cin >> n;
        if(n == 0) break;
        else {
            for(int i = 0; i < n; i++){
                cin >> a[i];
                buf[a[i]]++;
            }
            cin >> m;
            res[counter++] = buf[m] ;
        }
    }
    for(int i = 0; i < counter; i++){
        cout << res[i] << endl;
    }
    return 0;
}