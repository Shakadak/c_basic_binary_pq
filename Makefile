# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2017/10/16 12:27:59 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pq
FILENAME	:=	lib$(NAME).a

### DIRECTORIES ###

DIRSRC		:=	src
DIROBJ		:=	obj
DIRTST		:=	test
DIRLIB		:=	lib
DIRBIN		:=	bin
DIRPQ		:=	$(DIRSRC)/pq
DIRINC		:=	inc

### FILES ###

### FILES: SOURCES ###

include $(DIRSRC)/src.mk
#include $(DIRPQ)/src.mk
include $(DIRTST)/src.mk

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
# TESTOBJ		:= $(addprefix $(DIROBJ)/, $(TOBJ))
TESTSRC		:= $(addprefix $(DIRTST)/, $(TSRC))

### ARCHIVE ###

AR			:=	ar
AR_FLAG		:=	-crus
AR_EXEC		=	$(AR) $(AR_FLAG) $@ $^

### COMPILATION ###

CC			:=	clang
C_FLAG		:=	-Wall -Wextra -Werror -pedantic
I_FLAG		:=	-I $(DIRINC) -I .
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< $(I_FLAG)
COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)
L_FLAG		:= -L $(DIRLIB) -lpq

### RULES ###

all: $(DIRLIB)/$(FILENAME)

test: $(DIRLIB)/$(FILENAME)
	$(CC) $(C_FLAG) $(I_FLAG) -I test $(L_FLAG) -o $(DIRTST)/test.tst $(TESTSRC)
	./$(DIRTST)/test.tst
	

### RULES: ARCHIVE ###

$(DIRLIB)/$(FILENAME): $(POBJ) |$(DIRLIB)
	$(AR_EXEC)
	ranlib $@

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(DIRLIB):
	mkdir $(DIRLIB)

clean:
	rm -f $(POBJ)

fclean: clean
	rm -f $(DIRLIB)/$(NAME)
	rm -f $(DIRTST)/test.tst

re: fclean all

.PHONY: all test clean re fclean
