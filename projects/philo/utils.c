#include "philo.h"

long    time(void)
{
    t_timeval   time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}