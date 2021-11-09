
# Makefile for Old-CPP Module 00 ex02, updated Tue Nov  9 08:23:14 JST 2021

SRC := Account.cpp tests.cpp
OBJ := Account.o tests.o

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME     := a.out

CC       := clang++
CFLAGS   := -Wall -Wextra -Werror -std=c++98 --pedantic
RM       := rm -fr

SRC_DIR  := ./
OBJ_DIR  := obj
SRCS     := $(addprefix $(SRC_DIR)/, $(SRC))
OBJS     := $(addprefix $(OBJ_DIR)/, $(OBJ))
EXPECTED := 19920104_091532.log

.PHONY:	all
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: lint
lint:
	cpplint $(SRC)

.PHONY: leak
leak: CFLAGS += -g -fsanitize=leak
leak: re

.PHONY: address
address: CFLAGS += -g -fsanitize=address
address: re

.PHONY: clean
clean:
	$(RM) Makefile.bak $(NAME).dSYM $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) expected.txt res.txt

.PHONY: re
re: fclean all

.PHONY: valgrind
valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: test
test: re
	cat ./$(EXPECTED) | cut -f 2- -d "]" > expected.txt
	./$(NAME) | cut -f 2- -d "]" > res.txt
	diff expected.txt res.txt
	$(RM) expected.txt res.txt

.PHONY: source
source:
	@mv Makefile Makefile.bak
	@echo '' >> Makefile
	@echo "# Makefile for Old-CPP Module 00 ex02, updated `date`" >> Makefile
	@echo '' >> Makefile
	@echo SRC := `ls *.cpp` >> Makefile
	@echo OBJ := `ls *.cpp | sed s/cpp$$/o/` >> Makefile
	@echo '' >> Makefile
	@sed -n -e '/^# DO NOT ADD OR MODIFY/,$$p' < Makefile.bak >> Makefile
