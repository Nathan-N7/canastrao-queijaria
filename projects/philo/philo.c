#include "philo.h"

int init_mutex(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->philo_nbr)
    {
        if (pthread_mutex_init(&table->forks[i], NULL))
        {
            printf("Error: mutex init\n");
            return (1);
        }
    }
    if (pthread_mutex_init(&table->print, NULL) || pthread_mutex_init(&table->dead, NULL)
        || pthread_mutex_init(&table->wait, NULL))
    {
        printf("Error: mutex init\n");
        return (1);
    }
    return (0);
}

int init_philos(t_table *table)
{
    int i;

    if (!table->philos || !table->forks)
    {
        printf("malloc error\n");
        return (1);
    }
    if (init_mutex(table))
        return (1);
    i = -1;
    while (++i < table->philo_nbr)
    {
        table->philos[i].id = i;
        table->philos[i].meals = 0;
        table->philos[i].last_meal = time();
        table->philos[i].left_fork = &table->forks[i];
        table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
        table->philos[i].table = table;
        pthread_mutex_init(&table->philos[i].lock, NULL);
        pthread_mutex_init(&table->philos[i].meal, NULL);
    }
    return (0);
}

int starting_thread(t_table *table)
{
    int i;
    t_philo *philos;

    if (init_philos(table))
        return (1);
    i = -1;
    philos = table->philos;
    table->tm_start = time();
    pthread_creat(&table->monitor, NULL, monitoring, table);
    while ();
}