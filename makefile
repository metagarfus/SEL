all:
	bison -d -v syntax.y
	flex syntax.lex
	gcc -O3  main.c tagtuple.c utils.c syntax.tab.c lex.yy.c syntax_utils.c type_checker.c errors.c datastructs/arraylist.c datastructs/hashtable.c -o sel