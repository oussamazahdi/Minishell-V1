/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:55:01 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:59:50 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_initialises(t_data **line)
{
	t_data	*tmp;

	tmp = (*line);
	tmp = NULL;
	tmp->token = NULL;
}

static void	ft_exit(char *read)
{
	if (!read)
	{
		printf("exit\n");
		exit(1);
	}
}

static void ft_readline(t_data **line, t_list **token)
{
	char	*read;
	
	read = readline("➜ Minishell$ ");
	ft_exit(read);
	if (ft_strlen(read) > 0)
		add_history(read);
	read = ft_strtrim(read, " \t\n");
	read = ft_chifr(read);
	if (ft_parsing(read))
	{
		ft_fill_token(token);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data		*line;

	if (ac != 1)
		return (1);
	ft_initialises(&line);
	while (1)
	{
		ft_readline(&line, &line->token);
	}
}
