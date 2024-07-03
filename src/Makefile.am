## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet-finall

projet_finall_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	utilisateur.c utilisateur.h\
	ficheDonneur.c ficheDonneur.h\
	gestionDons.c gestionDons.h \
	gestionEts.c gestionEts.h

projet_finall_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

