all:
	leg syntax.leg > syntax.c
	gcc main.c tagtuple.c utils.c syntax.c syntax_utils.c -o sel