# get all the c files and store into a variable
SRC = $(wildcard */*.c)

compile_all:
	# compile all the files as such (gcc example.c)
	$(foreach var, $(SRC), gcc $(var) || exit;)

