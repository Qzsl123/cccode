#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

bool isLeap(int year) //judge leap year or not 
{
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
int abs(int a)
{
    return a > 0 ? a : -a;
}
int dayOfMonth[13][2] = 
    {
        0, 0, 31, 31, 28, 29, 31, 31, 30, 30, 31, 31,
        30, 30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31};
char monthName[13][20] =
    {
        "", "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"};
char weekName[7][20] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
struct date
{
    int day;
    int month;
    int year;
    void nextDay() //get next day
    {
        day++;
        if (day > dayOfMonth[month][isLeap(year)])
        {
            month++;
            day = 1;
        }
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
};
int buf[5001][13][32];//store the days from 01/01/0000

int main()
{
    date tmp;
    tmp.day = 1;
    tmp.month = 1;
    tmp.year = 0;
    int cnt = 0;
    while (tmp.year < 5001)
    {
        buf[tmp.year][tmp.month][tmp.day] = cnt;
        tmp.nextDay();
        cnt++;
    }
    int y, d, count;
    char m[20];
    while(scanf("%d%s%d",&d, m, &y) != EOF){
        for(count = 1; count <13; count++){
            if(strcmp(m, monthName[count]) == 0)
               break;
        }
        int days = abs(buf[2017][4][12] - buf[y][count][d]);
        days += 3;//today is Wednesday
        cout << weekName[days % 7] << endl;
    }

    return 0;
}