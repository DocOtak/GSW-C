#
#  $Id: Makefile,v 1e5e75c749c2 2015/08/08 22:03:51 fdelahoyde $
#
               CFLAGS+=-O3
            CINCLUDES+=-Iinclude
             BUILDDIR:=build
               LIBDIR:=lib
               BINDIR:=bin
               SRCDIR:=src

              LIBNAME:=libgswteos-10.so

SRCFILES := $(wildcard $(SRCDIR)/*.c) 
OBJFILES := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCFILES)) 

.PHONY: all clean

all:$(LIBNAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c 
	mkdir -p $(BUILDDIR)
	$(CC) -fPIC -c $(CFLAGS) $(CINCLUDES) $< -o $@ 

$(LIBNAME): $(OBJFILES)
	$(CC) -shared -o $(LIBNAME) $(OBJFILES) -lm

clean:
	rm -rf $(BUILDDIR) $(LIBDIR) $(BINDIR) $(LIBNAME)
