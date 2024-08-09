/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:00:08 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/09 11:15:48 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_herdoc_append(t_data **line)		/***************/
{
	t_list	*tmp;

	tmp = (*line)->token;
	while (tmp)
	{
		if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 2 && tmp->next->content)
		{
			tmp->type = -99;
			tmp = tmp->next;
			tmp->type = APPEND;
		}
		if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 2 && tmp->next->content)
		{
			tmp->type = -99;
			tmp = tmp->next;
			tmp->type = HEREDOC;
		}
		tmp = tmp->next;
	}
}

void	ft_in_out_pipe(t_data **line)		/***************/
{
	t_list	*tmp;

	tmp = (*line)->token;
	while (tmp)
	{
		if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 1 && tmp->next)
		{
			tmp->type = -99;
			tmp = tmp->next;
			tmp->type = INFILE;
		}
		else if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 1 && tmp->next)
		{
			tmp->type = -99;
			tmp = tmp->next;
			tmp->type = OUTFILE;
		}
		else if (tmp->content[0] == '|')
			tmp->type = PIPE;
		tmp = tmp->next;
	}
}

void ft_arguments(t_data **line)		/***************/
{
	t_list	*tmp;
	
	tmp = (*line)->token;
	while (tmp)
	{
		if (tmp->type == -1)
			tmp->type = ARG;
		tmp = tmp->next;
	}
}

void ft_commends(t_data **line)		/***************/
{
	t_list	*tmp;

	(*line)->process_count = 1;
	tmp = (*line)->token;
	while (tmp)
	{
		while (tmp && tmp->type != ARG)
			tmp = tmp->next;
		if (tmp && tmp->type == ARG)
			tmp->type = CMD;
		while (tmp && tmp->type != PIPE)
			tmp = tmp->next;
		if (tmp && tmp->type == PIPE)
			(*line)->process_count++;
		if(tmp)
			tmp = tmp->next;
	}
}

void ft_builtings(t_data **line)
{
	t_list	*tmp;

	(*line)->builtin_check = 0;
	tmp = (*line)->token;
	while (tmp)
	{
		if (ft_compare(tmp->content, "echo") || ft_compare(tmp->content, "export") || ft_compare(tmp->content, "pwd") || \
			ft_compare(tmp->content, "unset") || ft_compare(tmp->content, "env") || ft_compare(tmp->content, "exit") || \
			ft_compare(tmp->content, "cd"))
			{
				(*line)->builtin_check = 1;
				tmp->type = BUILTIN;
			}
		tmp = tmp->next;
	}
	
}

void	ft_token_tmp(t_data **line)		/***************/
{
	ft_in_out_pipe(line);
	ft_herdoc_append(line);
	ft_arguments(line);
	ft_commends(line);
	ft_builtings(line);
	// ft_print_token((*line)->token);
}

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
	ft_token_tmp(line);
	return (*line);
}

int ft_fill_token(t_data **line, char *read)
{
	read = ft_addspace(read);
	ft_create_token(line, read);
	if (!line)
	{
		printf(BOLD RED "token is empty! (ft_fill token)\n" RESET);
		return (0);
	}
	return (1);
}