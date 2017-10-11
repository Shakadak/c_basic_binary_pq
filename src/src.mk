PQ	:=	pq_insert.c \
		pq_new.c \
		pq_pop.c

OBJ	:= $(OBJ) $(PQ:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(INC)
	$(COMPIL)
