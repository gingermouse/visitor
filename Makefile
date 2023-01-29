CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp cmd.cpp core.cpp pip.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test_app

all : $(OBJECTS) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean : 
	rm -f *.o $(EXECUTABLE)
