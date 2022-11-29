SHELL = bash

CPPFLAGS = -MP -MD -I$(INC_DIR)

CFLAGS = \
	-std=c11 \
	-Wall \
	-Wextra \
	-Wcast-align=strict \
	-Wshadow \
	-Wstrict-prototypes \
	-Wstrict-overflow=5 \
	-Wwrite-strings \
	-Waggregate-return \
	-Wcast-qual \
	-Wswitch-enum \
	-Wunreachable-code \
	-Wpointer-arith \
	-Warray-bounds \
	-Wno-sign-compare \
	-Wno-aggregate-return

LDFLAGS =
LDLIBS =

BIN_DIR = bin
BUILD_DIR = build
INC_DIR = include
OBJ_DIR = $(BUILD_DIR)/obj
LIB_DIR = $(BUILD_DIR)/lib

HLIB_SRC = $(shell find hlib -name \*.c)
HLIB_OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(HLIB_SRC))
HLIB_LIB = $(LIB_DIR)/hlib.a

CFLAGS += -fsanitize=undefined,address -ggdb -coverage
LDFLAGS += -fsanitize=undefined,address -ggdb -coverage

.PHONY: all clean hlib test

.PHONY: all
all: hlib

.PHONY: clean
clean:
	$(RM) -r build

.PHONY: hlib
hlib: $(HLIB_LIB)

.PHONY: hlib_test
test: $(HLIB_TEST_BIN)

# Build Rules

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(LIB_DIR)/%.a:
	@mkdir -p $(@D)
	$(AR) rcs $@ $^

$(LIB_DIR)/%.so:
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(LDLIBS) -shared -o $@ $^

$(BIN_DIR)/%:
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

# Build Dependencies

$(HLIB_LIB): $(HLIB_OBJ)

$(HLIB_TEST_BIN) : $(BIN_DIR)/% : $(OBJ_DIR)/%.o $(HLIB_LIB)

-include $(shell find build -name \*.d 2>/dev/null)
