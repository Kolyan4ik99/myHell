/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:03:53 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/21 22:23:36 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <sys/fcntl.h>

# define SYMB "|<>"

int	g_signal_code;

typedef struct one_cmd_s
{
	char	*cmd;
	char	**arg;
	int		flag;
	int		fd[2];
	char	*start_dir;
}	t_one_cmd_t;

typedef struct s_list_env
{
	char				*key;
	char				*value;
	int					i;
	struct s_list_env	*next;
}	t_list_env;

typedef struct s_fd
{
	int					orig_fd[2];
	int					pipe_fd[2];
}	t_fd;

typedef struct s_mix_args
{
	int	start;
	int	end;
	int	count;
	int	count_args;
	int	fl;
}	t_mix_args;

/*
int		flag;
0 = none
1 = >
2 = <
3 = >>
4 = <<
5 = |
*/

int			main_circle(t_list_env **envs_lsts);
void		catch_sig(int sig_num);
int			main(int argc, char **argv, char **env);
void		ft_make_map(char *str, char **map, int q_one_fl, int q_two_fl);
int			ft_check_map(char *map, int *count, int i);
t_list_env	*ft_lstnew_env(char *key, char *value);
void		ft_make_choice(char **cmd, t_list_env **envs_lsts,
				t_one_cmd_t **all);

/* fill_envs.c */
void		ft_fill_key_envs_lists(int *x, int i, char **key, char **env);
void		ft_fill_value_envs_lists(int *x, int i, char **value, char **env);
t_list_env	*ft_envs_lists(char **env, int i, int x);

t_one_cmd_t	**ft_do(char **str, t_list_env *envs_lsts, int count);

/* fill_args_from_process.c */
int			ft_exit(char *code, int err_code);
int			execute_program(t_one_cmd_t **all, t_list_env **list);

/* signal_handler.c */
int			signal_catch(void);

/* parse */
void		ft_input_ens(char **map, char **str, t_list_env *envs_lsts);
char		*ft_new_map_str(int *env_params, char **map,
				char *str, t_list_env *envs_lsts);
void		ft_fill_command(char *str, int count, char *map,
				t_one_cmd_t **command);
char		*ft_clean_fr_q(char *str, char **map);
int			ft_set_fl(char *map);
char		*ft_find_env(char *str, t_list_env *envs_lsts);
char		**ft_input_args(char *map, char *str, int count, int fl);
void		ft_input_cmd_arg(int *x, char *map, char *str,
				t_one_cmd_t *command);
void		ft_clean_do_map_res(char **map, char **res, int *count, int i);
int			ft_len_one_arg(char *map);
int			ft_input_one_arg_1(int *j, int x, char **args, char *str);
int			ft_move_map_fl(char *map, int *fl);
int			ft_check_map_char(char *map);
void		ft_get_key(int *env_params, char **env_key, char *str);
void		ft_add_map_res(char **res, char *env_value,
				char **map, int *env_params);
int			ft_make_map_check_q(int *q_one_fl, int *q_two_fl, char c);
int			ft_count_arg(char *map);
char		*ft_input_cmd(char *map, char *str);
int			ft_ft_make_map_check_env(char b, int q_one_fl, char c);
t_one_cmd_t	**ft_make_cmds(int count, char **map, char **str,
				t_list_env *envs_lsts);

/* fill_args_from_process.c */
int			ft_return(char *code, int err_code);
void		free_all(t_one_cmd_t **all);

/* find_linux_cmd.c */
void		ft_free(char *str);
int			find_linux_cmd(t_one_cmd_t *all, char *str);
int			fill_full_cmd(t_one_cmd_t *all, t_list_env *list);
int			find_our_cmd(t_one_cmd_t *all, t_list_env *list);

/* our_cmds.c*/
int			call_cd(t_one_cmd_t *all, t_list_env *list);
int			call_echo(t_one_cmd_t *all, int fl, int i);
int			call_env(t_list_env *list);
int			call_pwd(t_list_env *list);

/* open_file.c */
int			open_one_redirect(int *fd, char *filename);
int			open_double_redirect(int *fd, char *filename);
int			open_rev_redirect(int *fd, char *filename);
int			open_double_rev_redirect(int *fd, char *filename);

/* history_utils.c */
int			add_to_history(char *text, char *dir);
char		*fill_dir(t_list_env *envs_lsts);

void		rl_replace_line(const char *s, int i);

/* mix_args.c */
void		ft_mix(t_one_cmd_t **cmds);
void		ft_null_mix_args(t_mix_args *x);
void		ft_change_args(t_one_cmd_t **cmds, t_mix_args x);
int			ft_count_args(t_one_cmd_t *cmds);
void		ft_mix_count(t_one_cmd_t **cmds, t_mix_args *x, int i);
void		ft_free_start_args(t_one_cmd_t **cmds, t_mix_args x);
void		ft_fill_null_temp(int j, char **temp_args,
				t_one_cmd_t **cmds, t_mix_args *x);
void		ft_change_args_fill_temp(int j, char **temp_args,
				t_one_cmd_t **cmds, t_mix_args *x);

/* export_0.c */
int			change_list(t_list_env *list, char *value, char *key);
int			call_export(t_one_cmd_t *all, t_list_env *list);
void		ft_add_new_env(char *str, t_list_env *list);
t_list_env	*find_list(t_list_env *list, char *key);

/* export_1.c */
void		ft_make_new_env_kv(char **res, int len, char *start);
int			ft_parse_new_env(char *str, char **key, char **value);
int			ft_check_new_env(char *str, int i);
void		ft_make_new_env(char *temp, char *str, char **key, char **value);

/* unset.c */
t_list_env	*ft_del_one_env(t_list_env *lst);
t_list_env	*ft_find_del_env(t_list_env *lst, char *key);
int			ft_unset(t_one_cmd_t *all, t_list_env **list, int i);
int			ft_strcmp(char *str, char *ptr);

/*sort_envs.c */
void		ft_sort_print_envs(t_list_env *list, int count);
int			ft_lstsize_env(t_list_env *lst);
void		ft_fill_s_k(t_list_env *list, int i, char **s_k);
void		ft_print_export(int count, char **s_k, t_list_env *list);
void		ft_sort_export(int count, char **s_k);

/* fd_creator.c */
int			find_fdin(t_fd *f_fd, t_one_cmd_t *ar);
int			find_fdout(t_fd *f_fd, t_one_cmd_t *ar);
void		close_all_fd(t_one_cmd_t **all, t_fd *fd);
int			fill_fd(t_one_cmd_t **all);
void		close_fd(int *fd);

/* fd_handler */
void		create_fd(t_fd *fd);
void		fiff_fd(t_one_cmd_t *all, t_fd *f_fd);
void		fill_vopr(t_list_env *list);

/* execute_utils.c */
int			find_and_use_command(t_one_cmd_t *all, t_list_env **list, int mode);
int			catch_bad_cmnd(t_one_cmd_t *all);
void		free_all(t_one_cmd_t **all);
int			execute_program(t_one_cmd_t **all, t_list_env **list);

/* execute_utils2.c */
int			exec_child(t_one_cmd_t *all, t_list_env *list, t_fd *f_fd);
int			exec_batya(t_fd *f_fd);
int			execute_command(t_one_cmd_t *all, t_list_env *list, t_fd *f_fd);

#endif
