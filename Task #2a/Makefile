
CC=gcc
CFLAGS=-Icode
OBJ=code/main.o code/platform.o code/post.o code/comment.o code/reply.o
OUT=run

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

code/main.o: code/main.c code/platform.h
	$(CC) $(CFLAGS) -c code/main.c -o code/main.o

code/platform.o: code/platform.c code/platform.h code/post.h code/comment.h code/reply.h
	$(CC) $(CFLAGS) -c code/platform.c -o code/platform.o

code/post.o: code/post.c code/post.h
	$(CC) $(CFLAGS) -c code/post.c -o code/post.o

code/comment.o: code/comment.c code/comment.h
	$(CC) $(CFLAGS) -c code/comment.c -o code/comment.o

code/reply.o: code/reply.c code/reply.h
	$(CC) $(CFLAGS) -c code/reply.c -o code/reply.o

clean:
	rm -f $(OBJ) $(OUT)

