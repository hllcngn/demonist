all:
	gcc src/main.c src/draw.c src/logic.c src/ass.c src/player.c -I. -lSDL2 -L. -odemonist
hello:
	gcc src/hello.c -I. -lSDL2 -L. -ohello
clean:
	rm -f hello hello.exe demonist demonist.exe
re: clean all
.PHONY:	hello
