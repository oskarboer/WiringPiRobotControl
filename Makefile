NAME := robot

CC := gcc

SOURCES_DIRECTORY := src/
HEADERS_DIRECTORY := includes/

HEADERS_LIST := main.h rotaryencoder.h motor.h pid.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST := main.c rotaryencoder.c motor.c pid.c utility.c
SRC := $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
#OBJ := $(patsubst $(SOURCES_DIRECTORY)%.c, %.o, $(SRC))

LIB_FLAG := -lwiringPi -lpthread
#CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	@$(CC) -I $(HEADERS_DIRECTORY) -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(SRC)
	@echo "Done"

clean:
	rm $(NAME)
	
re: clean all

start: all
	./encoder
