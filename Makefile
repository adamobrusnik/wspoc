CC=c++
CFLAGS=-g -Wall -lgsoap++
NAME=poc

all:
	$(CC) -o $(NAME).cgi $(NAME).cpp soapC.cpp soap$(NAME)Service.cpp $(CFLAGS)

clean:
	rm -rf *.o $(NAME).cgi	
