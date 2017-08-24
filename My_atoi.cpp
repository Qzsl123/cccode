#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

int myatoi(const char *p)
{
    assert(p != NULL);
    int res = 0;
    bool negflag = false;
    while(*p == ' ' || *p == '\t')
    {
        p++;
    }
    if (*p == '+' || *p == '-')
    {
        negflag = (*p++ == '-');
    }
    while(isdigit(*p))
        res = res * 10 + (*p++ - '0');

    return negflag ? (0 - res) : res;
}

int main(int argc, char const *argv[])
{
    char  a[] = " -123";

    cout << "atoi : " << 1 + atoi(a) << endl;
    cout << "myatoi : " << 1 + myatoi(a) << endl;
    cout << "4 % 3 : " << 4 % 3 << endl << "4 % (-3) : " << 4 % (-3) << endl;
    return 0;

}