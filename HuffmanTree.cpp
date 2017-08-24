/*
* 哈夫曼树，第一行输入一个数n，第二行输入n个节点的值，输出节点的值与权值的乘积之和
*输入：5
*      1 2 2 5 9
*输出：37
*/
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        while(!Q.empty()) Q.pop();
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            Q.push(x);
        }
        int ans = 0;
        while(Q.size() > 1){
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a + b;
            Q.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}