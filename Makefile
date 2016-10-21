CPPFLAGS=-Wall -Wextra -pedantic -o timestable 
 

all:
	$(CC) $(CPPFLAGS) timestable.c 


clean:
	rm -f ./timestable 
