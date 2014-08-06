CFLAGS		= -g -O3 -Wall -Wextra
LINKFLAGS	= -lpthread

DESTDIR		=
PREFIX		= /usr/local
SBINDIR		= $(PREFIX)/sbin

OSD		= osdep
LIBS		= -L$(OSD) -l$(OSD)
LIBOSD		= $(OSD)/lib$(OSD).so

FILES = mdk3.c tesla.c tesla.h

all: osd mdk3

osd:
	$(MAKE) -C $(OSD)

$(LIBOSD):
	$(MAKE) -C $(OSD)

mdk3: $(FILES) $(OSD)/libosdep.a
	$(CC) $(CFLAGS) $(LINKFLAGS) $^ -o $@ $(LIBS) 

install: mdk3
	$(MAKE) -C $(OSD) install
	install -D -m 0755 $^ $(DESTDIR)/$(SBINDIR)/$^

clean:
	rm -f mdk3
	$(MAKE) -C $(OSD) clean

distclean: clean
