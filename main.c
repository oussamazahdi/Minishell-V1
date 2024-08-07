/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:55:01 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/07 19:13:30 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit(char *read)
{
	if (!read)
	{
		printf("exit\n");
		exit(1);
	}
}

static void ft_readline(t_data **line)
{
	char	*read;
	
	read = readline("➜ Minishell$ ");
	ft_exit(read);
	if (ft_strlen(read) > 0)
		add_history(read);
	read = ft_strtrim(read, " \t\n");
	read = ft_chifr(read);
	printf("read : %s\n", read);
	if (ft_parsing(read))
	{
		ft_fill_token(line, read);
		printf("******************\n");
	}
}

int	main(int ac, char **av, char **env)
{
	t_data		*line;

	if (ac != 1)
		return (1);
	line = malloc(sizeof(t_data));
	// line = malloc(sizeof(t_data));
	while (1)
	{
		ft_readline(&line);
	}
}
