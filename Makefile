MAKE=make
RM=rm
all:
        g++ server2.cpp -o server2
        g++ client2.cpp -o client2
clean:
        $(RM) server2
        $(RM) client2
