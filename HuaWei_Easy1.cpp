/*写出一个程序，接受一个有字母和数字以及空格组成的字
**符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
**输入：absA a  输出：2
**/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char buf[5000];
    int size = 0;
    char a;
    gets(buf);
    scanf("%c", &a);
    for(int i = 0; buf[i] != 0; i++){
        
        if(buf[i] == a || (buf[i] - 32) == a || (buf[i] + 32) == a){
            size++;
        }
    }
    cout << size << endl;
    return 0;
}