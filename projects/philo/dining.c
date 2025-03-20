#include "philo.c"

void    pause(int    id)
{
    if (id % 2 == 0)
        usleep(600);
}

void    dinner_one(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    print();
    pthread_mutex_unlock(philo->left_fork);
}

void    dinner(t_philo  *philo)
{
    if (philo->table->philo_nbr == 1)
    {
        dinner_one (philo);
        return (NULL);
    }
    pause(philo->id);
    while (!has_dead(philo->table) && philo->meals != philo->table->num_eats)
    {
        take_fork(philo);
        eat(philo);
        philo_sleep(philo);
        think(philo);
    }
    usleep(1000);
    return (NULL);
}