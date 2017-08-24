/*
*贪心问题：有n个节目在相同的时间段播放，求能看到的最多的完整节目个数
*输入n  接下来n行 Pi.startTime  Pi.endTime
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct program
{
    int startTime;
    int endTime;
    bool operator<(const program &a) const
    {
        return endTime < a.endTime;
    }
} buf[1000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> buf[i].startTime >> buf[i].endTime;
    }
    sort(buf, buf + n);
    int currentTime = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(currentTime <= buf[i].startTime){
            currentTime = buf[i].endTime;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
