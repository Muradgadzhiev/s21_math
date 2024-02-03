CC = gcc
CFLAGS = -Wall -Wextra -Werror
GCOVFLAGS = -fprofile-arcs -ftest-coverage
CHECKFLAGS = $(shell pkg-config --cflags --libs check)


all: clean s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rcs s21_math.a *.o
	ranlib s21_math.a

s21_math.o: s21_math.c
	$(CC) $(CFLAGS) -c s21_math.c

test: s21_math.o
	$(CC) $(CFLAGS) s21_math.c tests/*.c -o s21_math_test -lcheck

gcov_report: clean test
	$(CC) $(CFLAGS) $(CHECKFLAGS) $(GCOVFLAGS) s21_math.c tests/*.c -o s21_math_test -lcheck
	./s21_math_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html


clean:
	rm -rf report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt s21_math_test .clang-format
