NAME = s21_math.a
HEADER = s21_math.h
TEST = unit_test_s21_math
REPORT = GcovReport

CC = gcc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -std=c11 -Wall -Werror -Wextra
OS = $(shell uname)
ifeq ($(OS), Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm
else
    CHECK_FLAGS = -lcheck
endif

SRCS_LIBS = s21_abs.c	\
            s21_acos.c	\
            s21_asin.c	\
            s21_atan.c	\
            s21_ceil.c	\
            s21_cos.c	\
            s21_exp.c	\
            s21_fabs.c	\
            s21_floor.c	\
            s21_fmod.c	\
            s21_log.c	\
            s21_pow.c	\
            s21_sin.c	\
            s21_sqrt.c	\
            s21_tan.c

SRCS = $(SRCS_LIBS)

OBJS = $(SRCS:.c=.o)

all: s21_math.a

s21_math.a: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $< $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

gcov_report:
	gcc $(GCOVFLAGS) $(TEST).c $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	@echo Code coverage report generated. To view the report via web-browser, enter the command \"open ./report/index.html\"

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h *.c
	@echo ---------------------CPPLINT----------------------
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	rm CPPLINT.cfg
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no leaks --atExit -- ./$(TEST)

check_valgrind: $(NAME)
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no valgrind --leak-check=full -s ./$(TEST)

clean:
	rm -rf $(OBJS) ./GcovReport ./*.gcov ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM ./$(TEST)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all test check check_valgrind clean fclean re
