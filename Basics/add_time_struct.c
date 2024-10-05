#include <stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    struct time t1 = {2, 30, 30};
    struct time t2 = {12, 50, 35};
    struct time sum;

    if (t1.seconds + t2.seconds >= 60)
    {
        sum.seconds = (t1.seconds + t2.seconds) % 60;
        sum.minutes = (t1.minutes + t2.minutes + 1) % 60;
    }
    else
    {
        sum.seconds = t1.seconds + t2.seconds;
        sum.minutes = t1.minutes + t2.minutes;
    }

    if (t1.minutes + t2.minutes >= 60)
    {
        sum.minutes = (t1.minutes + t2.minutes) % 60;
        sum.hours = (t1.hours + t2.hours + 1) % 24;
    }
    else
    {
        sum.minutes = t1.minutes + t2.minutes;
        sum.hours = t1.hours + t2.hours;
    }

    if (t1.hours + t2.hours >= 24)
    {
        sum.hours = (t1.hours + t2.hours) % 24;
    }
    else
    {
        sum.hours = t1.hours + t2.hours;
    }

    printf("Time 1: %d:%d:%d\n", t1.hours, t1.minutes, t1.seconds);
    printf("Time 2: %d:%d:%d\n", t2.hours, t2.minutes, t2.seconds);
    printf("Sum: %d:%d:%d\n", sum.hours, sum.minutes, sum.seconds);
}