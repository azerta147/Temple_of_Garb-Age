CC = g++
CFLAGS = -W -Wall
LDFLAGS =
EXEC = temple-app
SRC = fenetre.cpp
DEPS = collision.cpp player.cpp environement.cpp view.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = $(SRC: .cpp=.o)

main: $(OBJ)
	reset
	$(CC) -c $(DEPS) $(SRC)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

clean:
	rm -rf *.o *~
	clear

mrproper:
	cleanrm -rf $(EXEC)