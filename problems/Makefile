CXXFLAGS=-std=gnu++17 -Wall -Wextra -Wshadow -Og -static -ggdb
problem=A
progs=$(problem) 
progs+=$(problem)check 
progs+=$(problem)rand 
#progs+=$(problem)brut

all: $(progs)

%: %.c
	@echo "$@ <- $<"
	@g++ $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(progs)
