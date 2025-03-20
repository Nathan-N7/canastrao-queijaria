#include "philo.h"

int has_dead(t_table    *table)
{
    int status;

    pthread_mutex_lock(&table->dead);
    status = table->has_dead;
    pthread_mutex_unlock(&table->dead);
    return (status);
}

void    check_dead(t_philo *philo)
{
    long    time;

    pthread_mutex_lock(&philo->table->wait);
    
}