all : main 
OBJS = // all files .o 
CC = clang
CFLAGS = -Wall

main : $(OBJS)
	$(CC) -o main  $(CFLAGS) $(OBJS)

rods.o: rods.c max_rod.h print_rod.h lru_cache.h rand_replace.h

max_rod.o : max_rod.c print_rod.h lru_cache.h rand_replace.h

print_rod.o : print_rod.c lru_cache.h rand_replace.h

lru_cache.o : lru_cache.c rand_replace.h

rand_replace.o : rand_replace.c


clean:
	rm -f $(OBJS)