SRCS 	=	ft_atoi.c ft_bzero.c ft_calloc.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ${PRINTF} ${GNL}

SRCSB	=	ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c \
			ft_lstnew.c ft_lstsize.c

PRINTF	=	ft_printf_print.c print_arg1.c \
			print_arg2.c

GNL		=	get_next_line_bonus.c get_next_line_utils_bonus.c

# Objects and directories
OBJS	= ${SRCS:%.c=${OBJDIR}/%.o}
OBJSB	= ${SRCSB:%.c=${OBJDIR}/%.o}
OBJDIR	= objets

# Compiler and flags
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
NAME	= libft.a
AR		= ar rcs

# Colors and style
END		:= \033[0m
BOLD	:= \033[1m
GREEN	:= \033[32m
BLUE	:= \033[34m
CYAN	:= \033[36m
PURPLE	:= \033[35m
YELLOW	:= \033[33m

# Progress counter
TOTAL_FILES := $(words $(SRCS) + words $(SRCSB))
TOTAL_BONUS := $(words $(SRCSB))
CURRENT_FILE = 0

all: ${NAME}

${NAME}: ${OBJDIR} ${OBJS}
	@echo "${BOLD}${BLUE}📚 Creating library archive...${END}"
	@${AR} ${NAME} ${OBJS}
	@echo "${BOLD}${GREEN}✨ Library ${NAME} created successfully${END}"
	@echo "${BOLD}${CYAN}📊 Compiled ${TOTAL_FILES} files${END}"

${OBJDIR}/%.o: %.c
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "${BOLD}${PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -c -o $@ $<
	@echo "${BOLD}${GREEN}✓${END}"

${OBJDIR}:
	@mkdir -p ${OBJDIR}
	@echo "${BOLD}${BLUE}📁 Created objects directory${END}"

clean:
	@echo "${BOLD}${YELLOW}🧹 Cleaning objects...${END}"
	@rm -rf ${OBJDIR}
	@echo "${BOLD}${GREEN}✓ Clean complete${END}"

fclean:	clean
	@echo "${BOLD}${YELLOW}🗑️  Removing library...${END}"
	@rm -f ${NAME}
	@echo "${BOLD}${GREEN}✨ All clean ✨${END}"

re:	fclean all

bonus: ${OBJDIR} ${OBJS} ${OBJSB}
	@$(eval TOTAL_FILES=$(shell echo $$(($(TOTAL_FILES)+$(TOTAL_BONUS)))))
	@echo "${BOLD}${BLUE}🎲 Building with bonus...${END}"
	@${AR} ${NAME} ${OBJSB} ${OBJS}
	@echo "${BOLD}${GREEN}✨ Bonus features added successfully${END}"
	@echo "${BOLD}${CYAN}📊 Total files compiled: ${TOTAL_FILES}${END}"

.PHONY: all clean fclean re bonus