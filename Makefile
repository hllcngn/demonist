NAME	= demonist
CC	= /usr/bin/gcc
SRCFOLDER	= src/
SRCFILES	= \
		main.c \
		ass.c \
		draw.c \
		draw2.c \
		draw3.c \
		logic.c \
		player.c \
		player2.c \
		player3.c \

OBJFOLDER	= obj/
OBJ	= $(addprefix $(OBJFOLDER), $(SRCFILES:.c=.o))
INCFOLDER	= .
LIBFOLDER	= lib/
SDL2HEADERS	= $(LIBFOLDER)SDL2/

all: $(OBJFOLDER) demonist
$(OBJFOLDER):
	mkdir -p $(OBJFOLDER)
demonist: $(OBJ)
	$(CC) $^ -o $(NAME) -L. -lSDL2
$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	$(CC) -c $^ -o $@ -I$(INCFOLDER) -I$(SRCFOLDER) -I$(SDL2HEADERS)
hello:
	#this should create a black window
	#that you can close by pressing ESC
	$(CC) src/hello.c -I$(LIBFOLDER) -lSDL2 -L$(LIBFOLDER) -ohello
clean:
	rm -rf $(OBJFOLDER)
fclean: clean
	rm -f hello hello.exe hello.stackdump hello.exe.stackdump demonist demonist.exe demonist.stackdump demonist.exe.stackdump
re: fclean all
.PHONY:	hello
