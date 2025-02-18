CC              := gcc
CFLAGS 			:= -std=c11 -Wall -Werror -Wextra
FUNC_DIR        := ./functions/
FUNC_TEST_DIR   := tests/
OBJ_DIR         := ./
TEST_FLAGS      := -lcheck -lm -lpthread
GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
LIB_STATIC      := s21_string.a

FUNC_SRCS       := $(addprefix $(FUNC_DIR), s21_atof.c \
                                            s21_strtol.c \
                                            s21_itoa.c \
                                            s21_ftoa.c \
                                            s21_sprintf_aux.c \
                                            s21_sscanf_aux.c \
											s21_memchr.c \
                                            s21_memcmp.c \
                                            s21_memcpy.c \
                                            s21_memset.c \
                                            s21_strchr.c \
                                            s21_strcspn.c \
                                            s21_strerror.c \
                                            s21_strlen.c \
                                            s21_strncat.c \
                                            s21_strncmp.c \
                                            s21_strncpy.c \
                                            s21_strpbrk.c \
                                            s21_strrchr.c \
                                            s21_strstr.c \
                                            s21_strtok.c \
                                            s21_sprintf.c \
                                            s21_sscanf.c \
                                            s21_to_upper.c \
                                            s21_to_lower.c \
                                            s21_insert.c \
                                            s21_trim.c)

FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)
FUNC_OBJS = $(subst $(FUNC_DIR), $(OBJ_DIR), $(FUNC_OBJS_WITHOUT_OBJECT_DIRNAME))


all: rebuild test gcov_report

$(LIB_STATIC):$(FUNC_SRCS)
	$(CC) $(CFLAGS) -c $(FUNC_SRCS)
	ar -rcs $@ *.o
	make clean_obj


build:
	make $(LIB_STATIC)

OPEN_COMMAND =open
rebuild: clean build
ifeq ($(OS), Linux)
	OPEN_COMMAND=xdg-open
else
	OPEN_COMMAND=open
endif

gcov_report:
	mkdir report
	gcc ../tests/main_test.c $(FUNC_DIR)*.c $(TEST_FLAGS) $(GCOV_FLAGS) -o ./$@.out
	./$@.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	${OPEN_COMMAND} ./report/index.html

test:
	@mkdir -p ../tests/build
	gcc ../tests/main_test.c $(LIB_STATIC) $(TEST_FLAGS) -o ./test.out
	./test.out
test_valgrind:
	@mkdir -p ../tests/build
	gcc ../tests/main_test.c $(LIB_STATIC) $(TEST_FLAGS) -g -o ./test.out
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./test.out

clean: clean_static_lib clean_log clean_exec clean_obj clean_gcov clean_lcov clean_lcov_report
	@echo "Clean finished"

clean_after_building:
	@rm -rf ${OBJ_DIR}
clean_static_lib:
	@find . -type f -name "*.a" -exec rm {} \;
clean_log:
	@find . -type f -name "*.log" -exec rm {} \;
clean_exec:
	@find . -type f -name "*.out" -exec rm {} \;
clean_obj:
	@find . -type f -name "*.o" -exec rm {} \;
clean_gcov:
	@find . -type f -name "*.gcda" -exec rm {} \;
	@find . -type f -name "*.gcno" -exec rm {} \;
clean_lcov:
	@find . -type f -name "*.info" -exec rm {} \;
clean_lcov_report:
	@rm -rf report

cppcheck:
	@find .. -type f -name "*.c" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@find .. -type f -name "*.c" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@find .. -type f -name "*.h" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@echo "Cppcheck is finished"
style:
	@find .. -type f -name "*.c" -exec clang-format -i -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -i -style=Google {} \;
	@echo "Clang format style apply is finished"
style_check:
	@find .. -type f -name "*.c" -exec clang-format -n -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -n -style=Google {} \;
	@echo "Clang format style check is finished"

dev_%:
	make -f dev_Makefile.mk $@