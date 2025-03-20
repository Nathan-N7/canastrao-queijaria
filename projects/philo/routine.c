#include "philo.h"

void    take_fork(t_philo *philo)
{
    if (philo->id % 2)
    {
        pthread_mutex_lock(philo->left_fork);
        printf("%ld %d has a taken a fork\n", time() - philo->table->tm_start, philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf("%ld %d has a taken a fork\n", time() - philo->table->tm_start, philo->id);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        printf("%ld %d has a taken a fork\n", time() - philo->table->tm_start, philo->id);
        pthread_mutex_lock(philo->left_fork);
        printf("%ld %d has a taken a fork\n", time() - philo->table->tm_start, philo->id); 
    }
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->meal);
    philo->meals += 1;
    pthread_mutex_unlock(&philo->meal);
    printf("%ld %d is eating\n", time() - philo->table->tm_start, philo->id);
    pthread_mutex_lock(&philo->lock);
    philo->last_meal = time();
    pthread_mutex_unlock(&philo->lock);
}