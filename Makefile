CC = gcc
CFLAGS = -std=c99 -pedantic-errors -Wall -Wextra -Werror -g -O0
LDLIBS = -lm -lpthread -lssl -lcrypto

$(shell mkdir -p bin)

SRCS = helloworld.c para_pass.c test_types.c test_local_var.c test_exited_func.c test_stack_heap.c \
       test_sp.c test_sp2.c test_stack.c test_static.c test_stack2.c test_stack_heap.c \
	   test_pointer2_b.c test_pointer2_g.c test_2d_arr.c test_3d_arr.c
TARGETS = $(addprefix bin/, $(basename $(SRCS)))

all: $(TARGETS)

bin/%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)
	@echo "Built $@"

clean:
	rm -f $(TARGETS)
	@echo "Cleaned $(TARGETS)"

.PHONY: all clean
