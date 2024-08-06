/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:00:08 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 11:49:05 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_create_token(t_list **token, char *read)
{
	char		**ptr;
	int			i;

	ptr = ft_split(read, '|');
	i = 0;
	while (ptr[i])
	{
		(*token) = ft_lstadd_back(token, ptr[i++]);
		if (!(*token))
			return (NULL);
	}
	return (*token);
}

int ft_fill_token(t_list **token, char *read)
{
	read = ft_addspace(read);
	printf("read (ft_fill token) : %s\n", read);
	ft_create_token(token, read);
	if (!token)
	{
		printf(BOLD RED "token is empty! (ft_fill token)\n" RESET);
		return (0);
	}
	printf("token[0] (ft_fill token) : %s\n", (*token)->content);
}