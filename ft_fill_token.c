/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:00:08 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/08 09:58:34 by ozahdi           ###   ########.fr       */
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
	(*line)->token = NULL;
	while (ptr[i])
	{
		(*line)->token = ft_lstadd_back((*line)->token, ptr[i]);
		if (!(*line)->token)
			return (NULL);
		i++;
	}
	// (*line)->token = token;
	return (*line);
}

int ft_fill_token(t_data **line, char *read)
{
	t_data *tmp;

	tmp = (*line);
	read = ft_addspace(read);
	// printf("read (ft_fill token) : %s\n", read);
	ft_create_token(line, read);
	printf("tmp : %s\n", tmp->token->content);
	if (!line)
	{
		printf(BOLD RED "token is empty! (ft_fill token)\n" RESET);
		return (0);
	}
	printf("token[0] (ft_fill token) : %s\n", tmp->token->content);
}