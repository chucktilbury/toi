
OBJS 	= 	file_stack.o \
			logging.o \
			lexer.o \
			parser.o \
			simple.o
HEADERS	=	sym_table.h \
			context.h \
			file_stack.h \
			logging.h \
			lexer.h \
			parser.h \
			simple.h
TARGET 	=	simple
CARGS	=	-Wall -Wextra -g

.cpp.o: 
	g++ $(CARGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJS) $(HEADERS)
	g++ -g -o $(TARGET) $(OBJS)

simple.o: simple.cpp $(HEADERS)
file_stack.o: file_stack.cpp $(HEADERS)
logging.o: logging.cpp $(HEADERS)
lexer.o: lexer.cpp $(HEADERS)
parser.o: parser.cpp $(HEADERS)
context.o: context.cpp $(HEADERS)

clean:
	rm -f $(TARGET) $(OBJS)