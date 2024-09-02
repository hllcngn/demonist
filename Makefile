NAME	= demonist
CC	= /usr/bin/gcc
SRCFOLDER	= src/
SRCFILES	= \
		main.c \
		zone.c \
		ass.c \
		draw.c \
		draw2.c \
		logic.c \
		player.c \
		player2.c \

OBJFOLDER	= obj/
OBJ	= $(addprefix $(OBJFOLDER), $(SRCFILES:.c=.o))
INCFOLDER	= .

all: $(OBJFOLDER) demonist
$(OBJFOLDER):
	mkdir -p $(OBJFOLDER)
demonist: $(OBJ)
	$(CC) $^ -o $(NAME) -lSDL2 -L.
$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	$(CC) -c $^ -o $@ -I$(INCFOLDER)
hello:
	#this should create a black window
	#that you can close by pressing ESC
	$(CC) src/hello.c -I$(INCFOLDER) -lSDL2 -L. -ohello
clean:
	rm -rf $(OBJFOLDER)
fclean: clean
	rm -f hello hello.exe hello.stackdump hello.exe.stackdump demonist demonist.exe demonist.stackdump demonist.exe.stackdump
re: fclean all
.PHONY:	hello
