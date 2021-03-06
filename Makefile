#############################################################################
# Makefile for building: bin/QMatrixOperator
# Generated by qmake (2.01a) (Qt 4.5.2) on: ?? ????. 7 23:49:00 2009
# Project:  QMatrixOperator.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile QMatrixOperator.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -march=x86-64 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -march=x86-64 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++-64 -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -L/usr/lib -L/usr/X11R6/lib64 -pthread -lpng -lfreetype -lgobject-2.0 -lSM -lICE -pthread -pthread -lXrender -lfontconfig -lXext -lX11 -lQtCore -lz -lm -pthread -lgthread-2.0 -lrt -lglib-2.0 -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = form.cpp \
		main.cpp \
		matrix.cpp \
		qmatrixview.cpp moc_form.cpp \
		moc_qmatrixview.cpp \
		qrc_resources.cpp
OBJECTS       = obj/form.o \
		obj/main.o \
		obj/matrix.o \
		obj/qmatrixview.o \
		obj/moc_form.o \
		obj/moc_qmatrixview.o \
		obj/qrc_resources.o
DIST          = /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		QMatrixOperator.pro
QMAKE_TARGET  = QMatrixOperator
DESTDIR       = bin/
TARGET        = bin/QMatrixOperator

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: QMatrixOperator.pro  /usr/share/qt/mkspecs/linux-g++-64/qmake.conf /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile QMatrixOperator.pro
/usr/share/qt/mkspecs/common/g++.conf:
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/release.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile QMatrixOperator.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/QMatrixOperator1.0.0 || $(MKDIR) obj/QMatrixOperator1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/QMatrixOperator1.0.0/ && $(COPY_FILE) --parents form.h matrix.h qmatrixview.h obj/QMatrixOperator1.0.0/ && $(COPY_FILE) --parents resources/resources.qrc obj/QMatrixOperator1.0.0/ && $(COPY_FILE) --parents form.cpp main.cpp matrix.cpp qmatrixview.cpp obj/QMatrixOperator1.0.0/ && (cd `dirname obj/QMatrixOperator1.0.0` && $(TAR) QMatrixOperator1.0.0.tar QMatrixOperator1.0.0 && $(COMPRESS) QMatrixOperator1.0.0.tar) && $(MOVE) `dirname obj/QMatrixOperator1.0.0`/QMatrixOperator1.0.0.tar.gz . && $(DEL_FILE) -r obj/QMatrixOperator1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_form.cpp moc_qmatrixview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_form.cpp moc_qmatrixview.cpp
moc_form.cpp: matrix.h \
		qmatrixview.h \
		form.h
	/usr/bin/moc $(DEFINES) $(INCPATH) form.h -o moc_form.cpp

moc_qmatrixview.cpp: matrix.h \
		qmatrixview.h
	/usr/bin/moc $(DEFINES) $(INCPATH) qmatrixview.h -o moc_qmatrixview.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources/resources.qrc \
		resources/help-about.png \
		resources/document-open.png \
		resources/application-exit.png \
		resources/arrow-right.png \
		resources/document-new.png \
		resources/arrow-right-double.png \
		resources/document-save.png \
		resources/edit-paste.png \
		resources/edit-clear.png \
		resources/document-save-as.png \
		resources/edit-copy.png
	/usr/bin/rcc -name resources resources/resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

obj/form.o: form.cpp form.h \
		matrix.h \
		qmatrixview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/form.o form.cpp

obj/main.o: main.cpp form.h \
		matrix.h \
		qmatrixview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o main.cpp

obj/matrix.o: matrix.cpp matrix.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/matrix.o matrix.cpp

obj/qmatrixview.o: qmatrixview.cpp qmatrixview.h \
		matrix.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qmatrixview.o qmatrixview.cpp

obj/moc_form.o: moc_form.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_form.o moc_form.cpp

obj/moc_qmatrixview.o: moc_qmatrixview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_qmatrixview.o moc_qmatrixview.cpp

obj/qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/qrc_resources.o qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

