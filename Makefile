
OBJS 	= 	file_stack.o \
			logging.o \
			lexer.o \
			parser.o \
			parse_import.o \
			parse_method_def.o \
			parse_statements.o \
			toi.o

HEADERS	=	sym_table.h \
			context.h \
			file_stack.h \
			logging.h \
			lexer.h \
			parser.h \
			parse_import.h \
			parse_method_def.h \
			parse_statements.h \
			toi.h

TARGET 	=	toi
CARGS	=	-Wall -Wextra -g

.cpp.o: 
	g++ $(CARGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJS) $(HEADERS)
	g++ -g -o $(TARGET) $(OBJS)

toi.o: toi.cpp $(HEADERS)
file_stack.o: file_stack.cpp $(HEADERS)
logging.o: logging.cpp $(HEADERS)
lexer.o: lexer.cpp $(HEADERS)
parser.o: parser.cpp $(HEADERS)
context.o: context.cpp $(HEADERS)
parse_import.o: parse_import.cpp $(HEADERS)
parse_method_def.o: parse_method_def.cpp $(HEADERS)
parse_statements.o: parse_statements.cpp $(HEADERS)

clean:
	rm -f $(TARGET) $(OBJS)