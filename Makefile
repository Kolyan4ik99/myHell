
SRC_FILES = parse_0.c parse_1.c parse_2.c parse_3.c open_file.c history_utils.c mix_args_0.c mix_args_1.c unset.c parse_4.c parse_5.c \
			main.c fill_envs.c signal_handler.c find_cmd.c our_cmds.c fd_creator.c fd_handler.c execute_utils2.c \
			fill_args_from_process.c execute_utils.c ft_lstnew_env.c export_0.c export_1.c sort_envs.c

SRC_DIR = srcs/

HEAD_DIR = header

SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}
OBJS = ${SRCS:.c=.o}

ARRC = ranlib

NAME = minishell

LIBFT = libft

HEADER = $(HEAD_DIR)

INTEL_READLINE = -L/Users/$(USER)/.brew/Cellar/readline/8.1.1/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1.1/include/readline/

MAC_READLINE = -L/opt/homebrew/Cellar/readline/8.1.1/lib/ -I/opt/homebrew/Cellar/readline/8.1.1/readline/

FLAGS = -Wall -Wextra -Werror -g

all: compile_lib $(NAME) $(HEADER)

intel: compile_lib intel $(HEADER)

$(NAME): $(OBJS) $(HEADER)
		gcc $(FLAGS) $(MAC_READLINE) -lreadline $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME)

intel: $(OBJS) $(HEADER)
		gcc $(FLAGS) $(INTEL_READLINE) -lreadline $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME)

compile_lib:
	make -C $(LIBFT)

linux: $(OBJS) $(HEADER)
			make -C $(LIBFT)
			gcc $(FLAGS) $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME) -lreadline

.c.o:
		gcc $(FLAGS) -c -I $(HEADER) $< -o $(<:.c=.o)

clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT)

fclean: clean
		rm -rf $(NAME)
		rm -f history.txt .double-back.txt
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re