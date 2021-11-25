# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroxann <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 04:50:12 by rroxann           #+#    #+#              #
#    Updated: 2020/11/13 01:30:47 by rroxann          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c	ft_calloc.c ft_isascii.c ft_memccpy.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstsize.c

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} libft.h
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJS_B} libft.h
			ar rc ${NAME} ${OBJS} ${OBJS_B}
			ranlib ${NAME}

all:		${NAME}

clean:		${OBJC} ${OBJC_B} libft.h
			rm -f ${OBJS} ${OBJS_B}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		clean all fclean re bonus
