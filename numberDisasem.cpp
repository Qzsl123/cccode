#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    int a1 = 123, a2 = 45; //1 * 4 + 1 * 5 + 2 * 4 + 2 * 5 + 3 * 4 + 3 * 5
    int buf1[20], buf2[20] , size1 = 0, size2 = 0;
    while(a1 != 0){
        buf1[size1++] = a1 % 10;
        a1 /= 10;
    }

    while(a2 != 0){
        buf2[size2++] = a2 % 10;
        a2 /= 10;
    }

    int ans = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            ans += buf1[i] * buf2[j];
        }
    }
    cout << ans << endl;
    return 0;

}