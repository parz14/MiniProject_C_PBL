# declaring variables

# Name of the project
PROJECT_NAME = Auto_rec_gen

# All source code files
SRC = main.c\
src/source.c\
src/source2.c

# for testing
TEST_SRC = src/test_source.c\
src/test_source2.c\
test/test_bill.c\
unity/unity.c

# Path to header files
INC_HEADER = inc
INC_TEST = unity

#To check if the OS is windows or linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

TEST_OUTPUT = Test_$(PROJECT_NAME).$(EXEC)


# make commands

all:
	gcc -I $(INC_HEADER) $(SRC) -o $(call FixPath, ./$(PROJECT_NAME).$(EXEC))

run: all
	$(call FixPath, ./$(PROJECT_NAME).$(EXEC))

test:
	gcc -I $(INC_HEADER) -I $(INC_TEST) $(TEST_SRC) -o $(call FixPath, ./$(TEST_OUTPUT))
	$(call FixPath, ./$(TEST_OUTPUT))

coverageCheck:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_HEADER) -I $(INC_TEST) $(TEST_SRC) -o $(call FixPath, $(TEST_OUTPUT))
	$(call FixPath, ./$(TEST_OUTPUT))
	gcov -a $(call FixPath, ./test_bill.c) $(call FixPath, ./test_source.c) $(call FixPath, ./test_source2.c) $(call FixPath, ./source.c) $(call FixPath, ./source2.c)
	
cppcheck:
	cppcheck --enable=all -I $(INC_HEADER) $(SRC)	

valgrind:
	gcc -I $(INC_HEADER) -I $(INC_TEST) $(TEST_SRC) -o $(call FixPath, ./$(TEST_OUTPUT))
	valgrind ./$(TEST_OUTPUT)

clean:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_HEADER) -I $(INC_TEST) $(TEST_SRC) -o $(call FixPath, $(TEST_OUTPUT))
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.gcov
