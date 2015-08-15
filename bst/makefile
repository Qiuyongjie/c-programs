

CC=gcc
FLAGS=-lm -Wall
DEBUG=-g
OBJS=tree.o mtree.o
APP=bstree

$(APP):$(OBJS)
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)
%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:
clean:
	rm -rf $(APP) $(OBJS)
pre:
	indent -kr -i8 *.c *.h 
	sleep 5s
	rm *.*~

