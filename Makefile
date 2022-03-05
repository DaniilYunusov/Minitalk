SERVER				=	server

CLIENT				=	client

SERVER_BONUS		=	server_bonus

CLIENT_BONUS		=	client_bonus

SRCS_SERVER			=	server.c	utils.c

SRCS_CLIENT			=	client.c	utils.c

SRCS_SERVER_BONUS	=	server_bonus.c	utils.c

SRCS_CLIENT_BONUS	=	client_bonus.c	utils.c

HEADER				=	minitalk.h

CC					=	gcc

FLAGS				=	-W -W -W

OBJS_SERVER			=	$(SRCS_SERVER:.c=.o)

OBJS_CLIENT			=	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS	=	$(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS	=	$(SRCS_CLIENT_BONUS:.c=.o)

%.o					:	%.c ${HEADER}
						gcc ${FLAGS} -c $< -o $@

all					:	${SERVER} ${CLIENT}

bonus				:	${SERVER_BONUS} ${CLIENT_BONUS}

${SERVER}			:   ${OBJS_SERVER}
						$(CC) $(FLAGS) ${OBJS_SERVER} -o $@

${CLIENT}			:	${OBJS_CLIENT}
						$(CC) $(FLAGS) ${OBJS_CLIENT} -o $@

${SERVER_BONUS}		:	${OBJS_SERVER_BONUS}
						$(CC) $(FLAGS) ${OBJS_SERVER_BONUS} -o $@

${CLIENT_BONUS}		:	${OBJS_CLIENT_BONUS}
						$(CC) $(FLAGS) ${OBJS_CLIENT_BONUS} -o $@

clean				:
						rm -f ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean				:	clean
						rm -f ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re					:	fclean all

.PHONY				:	all clean fclean re bonus