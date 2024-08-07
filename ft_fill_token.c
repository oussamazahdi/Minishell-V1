/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:00:08 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/07 18:18:31 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_data	*ft_create_token(t_data **line, char *read)
{
	t_list		*token = NULL;
	char		**ptr;
	int			i;

	ptr = ft_split(read, ' ');
	i = 0;
	while (ptr[i])
	{
		ft_lstadd_back(token, ptr[i]);
		// printf("+++++++++++++++++++++++\n");
		if (!token)
			return (NULL);
		i++;
	}
	(*line)->token = token;
	return (*line);
}

int ft_fill_token(t_data **line, char *read)
{
	t_data *tmp;

	tmp = (*line);
	read = ft_addspace(read);
	// printf("read (ft_fill token) : %s\n", read);
	tmp = ft_create_token(line, read);
	// printf("9999999999999999\n");
	if (!line)
	{
		printf(BOLD RED "token is empty! (ft_fill token)\n" RESET);
		return (0);
	}
	printf("token[0] (ft_fill token) : %s\n", (*line)->token->content);
}