# The c compiler
CC = gcc

# The filename
FILENAME = ProcessHierarchy

# The build target executable:
BINARY = ProcessHierarchy

all: $(BINARY)

$(BINARY): $(BINARY).c
	$(CC)  -o $(BINARY) $(FILENAME).c

clean: 
	rm $(BINARY)
