#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct student
{
    char name[100];
    int age;
    int score;
} buf[100];

bool cmp(student a, student b)
{
    if (a.score != b.score)
        return a.score < b.score;
    int tmp = strcmp(a.name, b.name);
    if (tmp != 0)
        return tmp < 0;
    else
        return a.age < b.age;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buf[i].name >> buf[i].age >> buf[i].score;
    }

    sort(buf, buf + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << buf[i].name << " " << buf[i].age << " " << buf[i].score << endl;
    }

    return 0;
}