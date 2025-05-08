CC = gcc 

CFLAGS = -Wall -g

SRC = Loader.c Menu.c Print.c main.c

all:

	$(CC) $(CFLAGS) $(SRC) -o Final
	
# Clean-up
clean:

	rm -f Final
