CC=gcc
APP=dlink
OBJS=main.o fun.o
DEBUG=-g

$(APP):$(OBJS)
	$(CC) $^ -o $@ $(DEBUG)

*.o:*.c
	$(CC) $^ -c $@

.PHONY:
clean:
	rm -rf $(OBJS) $(APP)
