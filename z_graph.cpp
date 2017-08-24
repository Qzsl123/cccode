/*
* a a a
* a b a
* a a a
*/
#include <iostream>
using namespace std;
int main(){
    char outbuf[82][82];
    char a = 'A', b = 'B';
    int n = 5;
    
    bool firstLine = true;
    if(firstLine == true) firstLine = false; 
    else cout << endl;//除第一行外，其他先輸出換行

    for(int i = 1, j = 1; i <= n; i += 2, j++){
        int x = n/2 + 1, y = x;  // 中间点
        x -= j - 1; y -= j -1;   //左上角的点
        char c = j % 2 == 1 ? a : b;
        for(int k = 1; k <= i; k++){
            outbuf[x + k -1][y] = c; //左边赋值
            outbuf[x][y + k -1] = c; //上边赋值
            outbuf[x + i -1][y + k - 1] = c;
            outbuf[x + k -1][y + i - 1] = c;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << outbuf[i][j];
        }
        cout << endl;
    }
    return 0;
}