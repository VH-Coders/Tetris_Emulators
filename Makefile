.PHONY: all build clean run

CC           := clang
CFLAGS       := -g -Wall
BIN          := tetris

SRC_DIR=src
INCL_DIR=include
LIB_DIR=lib

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
INCL_FILES=$(wildcard $(INCL_DIR)/*.h)
OBJS=$(SRC_FILES:.c=.o)

# You'll need to install raylib's depedencies if you don't already have them
# If you're on Ubuntu/Debian, this can be done using the following command:
# sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
# See (https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) for more info

RAYLIB=$(LIB_DIR)/raylib/src/libraylib.a
RAYLIB_DEPEND := GL m pthread dl rt X11

LDFLAGS=$(foreach lib, $(RAYLIB_DEPEND), -l$(lib))

$(BIN): $(OBJS) $(RAYLIB)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(RAYLIB) $(LDFLAGS)

%.o: %.c $(INCL_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

$(RAYLIB):
	$(info Building raylib... This may take a second...)
	$(MAKE) -C $(LIB_DIR)/raylib/src/ PLATFORM=PLATFORM_DESKTOP
	$(info Raylib built!)

clean: 
	$(info Cleaning up raylib...)
	$(MAKE) -C $(LIB_DIR)/raylib/src/ clean
	$(info Cleaning up object files and binary)
	rm -f ./$(SRC_DIR)/*.o ./$(BIN)
