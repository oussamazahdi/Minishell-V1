/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:03:09 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:31:44 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <libc.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1b[37m"
# define ORANGE  "\x1b[38;5;214m"
# define RESET   "\x1b[0m"
# define BOLD     "\x1b[1m"

typedef enum    e_lexeme
{
    INFILE = 1,
    OUTFILE,
    HEREDOC,
    APPEND,
    PIPE,
    BUILTIN,
    CMD,
    ARG
} 	e_lexeme;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char		*prompt;
	char		*home;
	t_list		*env;
	t_list		*token;
	int			*lexer;
	// t_exec		*exec;
	int			has_cmd;
	int			has_builtin;
	int			process_count;
	int			builtin_check;
	// t_args		*args;
	int			exit_status;
	int			*fd_heredoc;
}			t_data;


#endif