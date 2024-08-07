/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:03:02 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/07 19:21:26 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr -> content = content;
	ptr -> next = NULL;
	printf("ptr : %s\n", ptr->content);
	return (ptr);
}

t_list	*ft_lstadd_back(t_list *lst, char *ptr)
{
	t_list	*tmp;
	t_list	*new;
	int		i;

	// if (!lst)
	// 	return (NULL);
	tmp = lst;
	new = ft_lstnew(ptr);
	printf("+++++++++++++\n");
	printf("new : %s\n", new->content);
	if (!new)
		return (NULL);
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
	return (lst);
}

static char	*ft_space(char *read, char *ptr)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (read[i])
	{
		if ((ft_is_syntax(read[i]) || read[i] == ';') && \
			(read[i - 1] != ' ' || read[i + 1] != ' '))
		{
			ptr[k++] = ' ';
			while (ft_is_syntax(read[i]) || read[i] == ';')
				ptr[k++] = read[i++];
			ptr[k++] = ' ';
		}
		else
			ptr[k++] = read[i++];
	}
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_addspace(char *read)
{
	int		i;
	int		k;
	char	*ptr;

	i = -1;
	k = 0;
	while (read[++i])
		if ((ft_is_syntax(read[i]) && !ft_is_syntax(read[i - 1])) || \
			(read[i] == ';' && read[i - 1] != ';'))
			k++;
	ptr = malloc(i + (k * 2) + 1);
	ptr = ft_space(read, ptr);
	return (ptr);
}
