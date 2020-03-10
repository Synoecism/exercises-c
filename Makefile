# get all the c files and store into a variable
SRC = $(wildcard */*.c)

compile_all:
	# compile all the files as such (gcc example.c)
	# reads as follow, foreach file in SRC, compile with gcc 
	# if file does not compile, exit will result in fail of ci
	$(foreach var, $(SRC), gcc $(var) || exit;)
