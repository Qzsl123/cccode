//输入一组数据，输出要查找数据的下标
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct student{
    char no[100];
    char name[100];
    int age;
    char sex[10];
    bool operator <(const student &a) const{
        return strcmp(no, a.no) < 0;
    }
}buf[1000];

int main()
{
    int res;
    int n, m, store[m];
    char x[10];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> buf[i].no >> buf[i].name >> buf[i].sex >> buf[i].age;
    }

    sort(buf, buf + n);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        res = -1;
       
        int top = n-1, base = 0;
        while(top >= base){
            int mid = (top + base)/2;
            int tmp = strcmp(buf[mid].no, x);
            if(tmp == 0){
                res = mid;
                break;
            }else if(tmp > 0) top = mid - 1;
            else base = mid + 1;
        }

        store[i] = res;
    }
    for(int i = 0; i < m; i++){
        if(store[i] == -1) cout << "No Answer" << endl;
        else cout << buf[store[i]].no << " " << buf[store[i]].name << " " << buf[store[i]].age << " " << buf[store[i]].sex <<endl;
    }

    return 0;
}