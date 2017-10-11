PQ	:=	pq_new.c

OBJ	:= $(OBJ) $(PQ:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(INC)
	$(COMPIL)
