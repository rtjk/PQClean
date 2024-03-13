# This Makefile can be used with GNU Make or BSD Make

LIB = libcross_clean.a

HEADERS = api.h CROSS.h csprng_hash.h fq_arith.h keccakf1600.h merkle.h merkle_tree.h pack_unpack.h parameters.h restr_arith.h seedtree.h sha3.h
OBJECTS = CROSS.o csprng_hash.o keccakf1600.o merkle.o pack_unpack.o seedtree.o sign.o

# TODO: flags
CFLAGS=
-I../../../common $(EXTRAFLAGS)
-std=c99 
-Wall 
-Wextra 
-Wpedantic 
-Werror 
-Wmissing-prototypes 
-Wredundant-decls 
-Wuninitialized 
-march=native 
-O3
-g3

all: $(LIB)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIB)