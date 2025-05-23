/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:34:10 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/03/26 19:41:47 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	*monitor_philo(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&(philo->datacpy->m_stop));
	pthread_mutex_lock(&(philo->datacpy->m_finish));
	while (!philo->datacpy->stop && (philo->datacpy->neat == -1
			|| philo->finished == 0))
	{
		pthread_mutex_unlock(&(philo->datacpy->m_finish));
		pthread_mutex_unlock(&(philo->datacpy->m_stop));
		pthread_mutex_lock(&philo->m_eating);
		if (!philo->is_eating && current_time()
			- philo->last_meal >= philo->datacpy->tdie)
		{
			my_print(philo->datacpy, philo->id, "died");
			pthread_mutex_unlock(&philo->m_eating);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->m_eating);
		pthread_mutex_lock(&(philo->datacpy->m_stop));
		pthread_mutex_lock(&(philo->datacpy->m_finish));
	}
	pthread_mutex_unlock(&(philo->datacpy->m_finish));
	pthread_mutex_unlock(&(philo->datacpy->m_stop));
	return (NULL);
}

static int	thread_handler_two(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
		{
			printf("Error waiting thread\n");
			return (1);
		}
		if (pthread_join(data->philos[i].monitor_thread_id, NULL) != 0)
			return (1);
		i++;
	}
	while (i < data->nphilos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].m_eating);
		i++;
	}
	free(data->philos);
	free(data->forks);
	return (0);
}

static int	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL,
				do_philo, &data->philos[i]) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		if (pthread_create(&data->philos[i].monitor_thread_id, NULL,
				monitor_philo, &data->philos[i]) != 0)
		{
			printf("Error creating monitor thread\n");
			return (1);
		}
		i++;
	}
	thread_handler_two(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Not the right arguments\n");
		return (1);
	}
	if (input_handler(argv) != 0)
		return (1);
	if (init_data(&data, argv) != 0)
		return (1);
	if (thread_handler(&data) != 0)
		return (1);
	return (0);
}
