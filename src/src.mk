PQ	:=	pq_insert.c \
		pq_new.c

OBJ	:= $(OBJ) $(PQ:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(INC)
	$(COMPIL)
