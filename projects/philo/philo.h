#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mtx;
typedef struct timeval t_timeval;

typedef struct s_philo
{
    int             id;
    int             meals;
    long            last_meal;
    t_mtx           *left_fork;
    t_mtx           *right_fork;
    t_mtx           lock;
    t_mtx           meal;
    pthread_t       thread;
    struct s_table  *table;
}   t_philo;

typedef struct s_table
{
    int         philo_nbr;
    int         tm_sleep;
    int         num_eats;
    int         time_eats;
    int         time_die;
    int         has_dead;
    long        tm_start;
    t_mtx       *forks;
    t_mtx       print;
    t_mtx       dead;
    t_mtx       wait;
    t_philo     *philos;
    pthread_t   monitor;
}   t_table;

long    time(void);
void    monitoring(void *arg);


#endif