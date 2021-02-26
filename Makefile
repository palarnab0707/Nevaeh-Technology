MAKE=make
RM=rm
all:
        g++ server.cpp -o server
        g++ client.cpp -o client
clean:
        $(RM) server
        $(RM) client
