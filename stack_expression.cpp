/*
*输入表达式 + - * / 和非负整数  4 + 2 * 5 - 7 / 11
*输出运算结果 保留两位小数      13.36
*/
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
char str[200];
stack <int> op;
stack <double> in;

int mat[][5]={
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
}; 
void getOp(bool &reto, int &retn, int &i){
    if(i == 0 && op.size() == 0 || str[i] == 0){
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] >= '0' && str[i] <= '9'){
        reto = false;
        retn = 0;
        for(;str[i] != 0 && str[i] != ' ';i++){
            retn *= 10;
            retn += str[i] - '0'; 
        }
    }else {
        //cout << " helo" << endl;
        reto = true;
        switch(str[i]){
            case '+': retn = 1;i += 2;
                break;
            case '-': retn = 2;i += 2;
                break;
            case '*': retn = 3;i += 2;
                break;
            case '/': retn = 4; i += 2;
                break;
        }
        return;
    }
     
    if(str[i] == ' ') i++;
        return;
}

int main(){
    while(gets(str)){
        if(str[0] == '0' && str[1] == 0)  break;
        while(!in.empty()) in.pop();
        while(!op.empty()) op.pop();
        bool retop;
        int retnum;
        int idx = 0;
        while(true){
            getOp(retop, retnum, idx);
            if(retop == false){
                in.push((double) retnum);
            }else{
                double tmp;
                if(op.empty() || mat[retnum][op.top()] == 1){
                    op.push(retnum);
                }else{
                    while(mat[retnum][op.top()] == 0){
                        int ret = op.top();
                        op.pop();
                        double a = in.top();
                        in.pop();
                        double b = in.top();
                        in.pop();
                        switch(ret){
                            case 1 : tmp = a + b; break;
                            case 2 : tmp = a - b; break;
                            case 3 : tmp = a * b; break;
                            case 4 : tmp = b / a; break;
                        }
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }
          if(op.size() == 2 && op.top() == 0) break;
        }
        printf("%.2f\n", in.top());
    }

    return 0;
}