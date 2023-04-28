##
## EPITECH PROJECT, 2022
## Epitech
## File description:
## Makefile
##

########################
### COMPILER OPTIONS ###
########################

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g3 -Wno-unused-parameter
LIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

########################
### OPTIONS          ###
########################

BUILD_DIR = .
SRC_DIR = src
INC_DIR = include
RES_DIR = ressources
BONUS_DIR = bonus
LIB_DIR = lib

TARGET = ai

########################
### SOURCES FILES    ###
########################

SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

########################
### LIBRARY FILES    ###
########################

LIB_SRCS := $(shell find $(LIB_DIR) -type f -name '*.c')
LIB_OBJS := $(LIB_SRCS:%.c=$(BUILD_DIR)/%.o)
LIB_DEPS := $(LIB_OBJS:%.o=%.d)

########################
### BONUS FILES      ###
########################

BONUS_SRCS := $(shell find $(BONUS_DIR)/tests -type f -name '*.c')
BONUS_OBJS := $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS_DEPS := $(BONUS_OBJS:%.o=%.d)

########################
### INCLUDE FILES    ###
########################

INC_DIRS := $(INC_DIR) $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

########################
### FILE GENERATORS  ###
########################

.PHONY: all bonus clean fclean re

all: $(TARGET)
	@echo "Compilation of $(TARGET) succeeded."

bonus: $(BUILD_DIR)/tests
	@echo "Compilation of bonus tests succeeded."

$(TARGET): $(OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LIBS) -o $@
	@echo "Linking $(TARGET) succeeded."

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -MMD -c $< -o $@
	@echo "Compilation of $< succeeded."

$(BUILD_DIR)/tests: $(BONUS_OBJS) $(LIB_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIB_OBJS) $(LIBS) -o $@
	@echo "Linking bonus tests succeeded."

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -MMD -c $< -o $@
	@echo "Compilation of $< succeeded."

########################
### MAKE RULES       ###
########################

clean:
	$(RM) -r $(OBJS) $(DEPS) $(BONUS_OBJS) $(BONUS_DEPS) $(LIB_OBJS) $(LIB_DEPS)
	@echo "Cleaned up the build directory."

fclean: clean
	$(RM) $(TARGET) $(BUILD_DIR)/tests
	@echo "Removed $(TARGET) and bonus tests."

re: fclean all

-include $(DEPS) $(BONUS_DEPS)
