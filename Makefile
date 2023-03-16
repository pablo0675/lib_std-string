##
## MY_LIB PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME		= libstdstring.a

## ===========================[PATH]===========================
SRCS			=		src/get_infos.c
SRCS			+=		src/std_string.c
SRCS			+=		src/to_array.c
SRCS			+=		src/utils.c
SRCS			+=		src/utils_two.c

TESTS_SRCS		:= $(SRCS)
TESTS_SRCS		+= tests/test_std_string.c

OBJS			= $(SRCS:%.c=obj/build/%.o)
TESTS_OBJS		= $(TESTS_SRCS:%.c=obj/test/%.o)

## =========================[OPTIONS]=========================

CFLAGS		= -Werror -Wall -Wextra -fPIC -pedantic
CFLAGS		+= -I ./includes
LDFLAGS		= -shared
TESTS_LDFLAGS	= -lcriterion


GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

## ==========================[RULES]===========================

obj/build/%.o : %.c
	@mkdir -p $(dir $@)
	@$ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CFLAGS) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c

obj/test/%.o : %.c
	@mkdir -p $(dir $@)
	@$ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CFLAGS) $(T) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"

all: $(NAME)

$(NAME): $(OBJS)
	@$ $(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "$(CC) $(LDFLAGS) $(OBJS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"

val_run: CFLAGS += -g3
val_run: $(TESTS_OBJS)
	@$ $(CC) -lcriterion --coverage $(TESTS_OBJS) $(LIBS) -o $@
	@echo "$(CC) -lcriterion $(TESTS_OBJS) $(LIBS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"
	valgrind --trace-children=yes --quiet ./$@
	@$(RM) $@
	@$(RM) $(TESTS_OBJS)

tests_run: CFLAGS += -g3
tests_run: $(TESTS_OBJS)
	@$ $(CC) -lcriterion --coverage $(TESTS_OBJS) $(LIBS) -o $@
	@echo "$(CC) -lcriterion $(TESTS_OBJS) $(LIBS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"
	./$@
	@$(RM) $@
	@$(RM) $(TESTS_OBJS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) -r obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run debug install static