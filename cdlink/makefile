CC=gcc
APP=link_cd
OBJS=main.o cdlfunc.o
DEBUG=-g -Wall

$(APP):$(OBJS)
	$(CC) $^ -o $@ $(DEBUG)

*.o:*.c
	$(CC) $^ -c $@

.PHONY:
clean:
	rm -rf $(OBJS) $(APP)
run: 
	./$(APP)
