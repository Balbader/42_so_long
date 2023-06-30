LIBDIR	= libft/

LIB		= libft.a

MINIDIR	:= minilibx-linux/

MINILIB	:= libmlx.a

SRCSDIR	:= sources/

SRCS	:= so_high.c gui.c map.c msg.c img.c els.c key.c chk.c drw.c
SRCS	:= $(addprefix ${SRCSDIR},$(SRCS))

OBJS	:= ${SRCS:.c=.o}

TXTS	:= 00 10 20 30 40 41 42 43 50 51 52 53 54 55 56 57 58 59

TXTS	:= $(addprefix textures/,$(addsuffix .png,$(TXTS)))

BNSRCS	:= anm.c enm.c
BNSRCS	:= $(addprefix ${SRCSDIR},$(BNSRCS))

BNOBJS	:= ${BNSRCS:.c=.o}

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

CTRLS	?= -D KEYS_WASD=1 # -D KEYS_ZQSD=1

CCFLAGS	:= -Iincludes -I/usr/include -Iminilibx-linux -g -O3 ${CTRLS}

LFLAGS	:= -L/usr/lib -lXext -lX11 -lm -lz

DEBUG	:= -fsanitize=address -g3

MMDEBUG	:= -g

RM		:= rm -f

NAME	:= so_long

#################### RULES ####################

${NAME}:	${MINIDIR}${MINILIB} ${LIBDIR}${LIB} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${MINIDIR}${MINILIB} ${LIBDIR}${LIB} ${LFLAGS} -o ${NAME}

bonus: CCFLAGS += -D BONUS=1
bonus: OBJS += ${BNOBJS}
bonus: fclean ${MINIDIR}${MINILIB} ${LIBDIR}${LIB} ${OBJS} ${BNOBJS}
		${CC} ${CFLAGS} ${OBJS} ${MINIDIR}${MINILIB} ${LIBDIR}${LIB} ${LFLAGS} -o ${NAME}

%.o:	%.c
	${CC} ${CFLAGS} ${CCFLAGS} -c $< -o $@

${LIBDIR}${LIB}:
		cd ${LIBDIR} && $(MAKE)

${MINIDIR}${MINILIB}:
	cd ${MINIDIR} && $(MAKE)

# ${MINI}:	

all:		${NAME}

norminette:
	norminette ${SRCSDIR}

man:
	man ./mlx/man/man3/mlx.3

xpm:
	mogrify -format xpm -- ${TXTS}

rmxpm:
	rm $(addsuffix .xpm,$(basename ${TXTS}))

clean:
		${RM} ${OBJS}
		${RM} ${BNOBJS}
		cd ${LIBDIR} && $(MAKE) clean
		# cd ${MINIDIR} && $(MAKE) clean

# bonusclean:
# 		${RM} ${BNOBJS}
# 		cd ${LIBDIR} && $(MAKE) fclean
# 		${RM} ${BNNAME}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re%