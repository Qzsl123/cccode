#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct student
{
    char name[100];
    int age;
    int score;
    bool operator <(const student &b)
    {
        if (score != b.score)
            return score < b.score;
        int tmp = strcmp(name, b.name);
        if (tmp != 0)
            return tmp < 0;
        else
            return age < b.age;
    }
} buf[100];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buf[i].name >> buf[i].age >> buf[i].score;
    }

    sort(buf, buf + n); 

    for (int i = 0; i < n; i++)
    {
        cout << buf[i].name << " " << buf[i].age << " " << buf[i].score << endl;
    }

    return 0;
}