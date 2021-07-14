#Makefile
all: add-nbo

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

clean:
	rm -f add-nbo
