// 计算字符串最后一个单词的长度
// 输入：zsl gets   输出：4
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char buf[5000];
    int size = 0;
    gets(buf);

    for(int i = 0; buf[i] != 0; i++){
        size++;
        if(buf[i] == ' '){
            size = 0;
        }
    }
    cout << size << endl;
    return 0;
}