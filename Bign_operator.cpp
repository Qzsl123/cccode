#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 500;
struct bign
{
    int len, s[maxn];

    /*以下的构造函数是C++中特有的，作用是进行初始化。
     事实上，当定义bign x时，就会执行这个函数，把x.s清零，并赋x.len=1 。
     需要说明的是，在C++中，并不需要typedef就可以直接用结构体名来定义，而且
     还提供“自动初始化”的功能，从这个意义上说，C++比C语言方便
    */
    bign()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    bign(int num)
    {
        *this = num;
    }

    //定义为const参数，作用是 不能对const参数的值做修改
    bign(const char *num)
    {
        *this = num;
    }
    /*以上是构造方法，初始化时对执行相应的方法*/

    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    //函数定义后的const关键字，它表明“x.str()不会改变x”
    string str() const
    {
        string res = "";
        for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
        if(res == "") res = "0";
        return res;
    }

    void clean()
    {
        while(len > 1 && !s[len - 1]) len--;
    }


    /* 以下是重载操作符 */
    bign operator = (const char *num)
    {
        //逆序存储，方便计算
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
        return *this;
    }

    bign operator + (const bign &b) const
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    bign operator * (const bign &b)
    {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];
        for(int i = 0; i < c.len - 1; i++)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }

    bign operator - (const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < max(b.len, len); i++)
        {
            int x = s[i] - b.s[i] - g;
            if(x >= 0) g = 0;           //g 是进位数
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }

    bool operator < (const bign &b) const
    {
        if(len != b.len) return len < b.len;
        for(int i = len - 1; i >= 0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }

    bool operator > (const bign &b) const
    {
        return b < *this;
    }

    bool operator <= (const bign &b)
    {
        return !(b > *this);
    }

    bool operator == (const bign &b)
    {
        return !(b < *this) && !(*this < b);
    }

    bign operator += (const bign &b)
    {
        *this = *this + b;
        return *this;
    }
};

istream &operator >> (istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream &operator << (ostream &out, const bign &x)
{
    out << x.str();
    return out;
}

int main()
{

    bign a, b;

    //while(1)
    //{
        cin >> a >> b;
        if (a > b)
        {
            cout << a -b << endl;
        }else{
            cout << '-' << b - a << endl;
        }
      
    //}

    return 0;
}
