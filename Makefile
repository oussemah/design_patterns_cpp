CC  := gcc
CPP := g++
CPP_FLAGS := -g -IInc
OBJ_DIR   := build
TARGET    := test_dp

CLASSES  = $(wildcard Src/*.cpp)
OBJS     = $(patsubst Src/%.cpp,%.o,$(CLASSES)) main.o

%.o:
	@if [[ $@ = main.o ]]; then \
	echo "Building main program"; \
	$(CC) -c -o $(OBJ_DIR)/$@ $(subst .o,.c, $@); \
	else \
	echo "Building $* class"; \
	$(CPP) $(CPP_FLAGS) -c -o $(OBJ_DIR)/$@ Src/$(subst .o,.cpp,$@); \
	fi

all: $(OBJ_DIR)|$(OBJS)
	@$(CPP) $(OBJ_DIR)/*.o -o $(TARGET)

clean:
	@rm -rf build/*.o $(TARGET)

run:$(TARGET)
	@$(TARGET)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

list:
	@echo "Classes to build :"$(patsubst Src/%.cpp,%,$(CLASSES))
