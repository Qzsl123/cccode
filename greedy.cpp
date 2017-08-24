#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct good
{
    double j;
    double f;
    double jf;
    bool operator<(const good &a) const
    {
        return jf > a.jf;
    }
} buf[1000];

int main()
{
    double m;
    int n;
    while (1)
    {
        cin >> m >> n;
        if (m == -1 && n == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> buf[i].j >> buf[i].f;
            buf[i].jf = buf[i].j / buf[i].f;
        }
        sort(buf, buf + n);
        int idx;
        double ans;
        while(m > 0 && idx < n){
            if(m > buf[idx].f){
                ans += buf[idx].j;
                m -= buf[idx].f;
            }else{
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx ++;
        }
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}
