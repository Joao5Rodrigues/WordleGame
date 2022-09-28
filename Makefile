OUTPUT_FILE = game
CXXFLAGS = -O3

$(info Identifing OS...)
ifdef OS
$(info $(shell echo %OS%))
RM = del /q
FIND = dir /s /b
EXEC= .exe
else
ifeq ($(shell uname -o), GNU/Linux)
$(info $(shell uname -o))
RM = rm -f
FIND = find . -name
EXEC=
else
$(error OS not supported.)
endif
endif

OBJS = $(patsubst %.cpp, %.o, $(shell $(FIND) "*.cpp"))

.PHONY: all
all: $(OBJS)
	$(CXX) -o $(OUTPUT_FILE) $^ $(CXXFLAGS)

%.o: %.cpp %.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: debug
debug: CXXFLAGS = -DDEBUG -g -Wall #-fsanitize=address incompatitble with s7c-console lib
debug: all

.PHONY: clean
clean:
	$(RM) $(shell $(FIND) "*.o") $(OUTPUT_FILE)$(EXEC)
