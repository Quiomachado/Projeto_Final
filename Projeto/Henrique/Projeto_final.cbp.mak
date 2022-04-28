WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/Projeto_final

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/Projeto_final

OBJ_DEBUG = $(OBJDIR_DEBUG)/alg_cpu.o $(OBJDIR_DEBUG)/contar_pontos.o $(OBJDIR_DEBUG)/editabuleiro.o $(OBJDIR_DEBUG)/free_mem.o $(OBJDIR_DEBUG)/get_comando.o $(OBJDIR_DEBUG)/get_dicionario.o $(OBJDIR_DEBUG)/get_tabuleiro.o $(OBJDIR_DEBUG)/ini_tabuleiro.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/org_dicionario.o $(OBJDIR_DEBUG)/print_file.o $(OBJDIR_DEBUG)/printabuleiro.o $(OBJDIR_DEBUG)/verificar_palavra.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/alg_cpu.o $(OBJDIR_RELEASE)/contar_pontos.o $(OBJDIR_RELEASE)/editabuleiro.o $(OBJDIR_RELEASE)/free_mem.o $(OBJDIR_RELEASE)/get_comando.o $(OBJDIR_RELEASE)/get_dicionario.o $(OBJDIR_RELEASE)/get_tabuleiro.o $(OBJDIR_RELEASE)/ini_tabuleiro.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/org_dicionario.o $(OBJDIR_RELEASE)/print_file.o $(OBJDIR_RELEASE)/printabuleiro.o $(OBJDIR_RELEASE)/verificar_palavra.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/alg_cpu.o: alg_cpu.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c alg_cpu.c -o $(OBJDIR_DEBUG)/alg_cpu.o

$(OBJDIR_DEBUG)/contar_pontos.o: contar_pontos.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c contar_pontos.c -o $(OBJDIR_DEBUG)/contar_pontos.o

$(OBJDIR_DEBUG)/editabuleiro.o: editabuleiro.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c editabuleiro.c -o $(OBJDIR_DEBUG)/editabuleiro.o

$(OBJDIR_DEBUG)/free_mem.o: free_mem.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c free_mem.c -o $(OBJDIR_DEBUG)/free_mem.o

$(OBJDIR_DEBUG)/get_comando.o: get_comando.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c get_comando.c -o $(OBJDIR_DEBUG)/get_comando.o

$(OBJDIR_DEBUG)/get_dicionario.o: get_dicionario.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c get_dicionario.c -o $(OBJDIR_DEBUG)/get_dicionario.o

$(OBJDIR_DEBUG)/get_tabuleiro.o: get_tabuleiro.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c get_tabuleiro.c -o $(OBJDIR_DEBUG)/get_tabuleiro.o

$(OBJDIR_DEBUG)/ini_tabuleiro.o: ini_tabuleiro.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ini_tabuleiro.c -o $(OBJDIR_DEBUG)/ini_tabuleiro.o

$(OBJDIR_DEBUG)/main.o: main.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.c -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/org_dicionario.o: org_dicionario.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c org_dicionario.c -o $(OBJDIR_DEBUG)/org_dicionario.o

$(OBJDIR_DEBUG)/print_file.o: print_file.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c print_file.c -o $(OBJDIR_DEBUG)/print_file.o

$(OBJDIR_DEBUG)/printabuleiro.o: printabuleiro.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c printabuleiro.c -o $(OBJDIR_DEBUG)/printabuleiro.o

$(OBJDIR_DEBUG)/verificar_palavra.o: verificar_palavra.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c verificar_palavra.c -o $(OBJDIR_DEBUG)/verificar_palavra.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/alg_cpu.o: alg_cpu.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c alg_cpu.c -o $(OBJDIR_RELEASE)/alg_cpu.o

$(OBJDIR_RELEASE)/contar_pontos.o: contar_pontos.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c contar_pontos.c -o $(OBJDIR_RELEASE)/contar_pontos.o

$(OBJDIR_RELEASE)/editabuleiro.o: editabuleiro.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c editabuleiro.c -o $(OBJDIR_RELEASE)/editabuleiro.o

$(OBJDIR_RELEASE)/free_mem.o: free_mem.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c free_mem.c -o $(OBJDIR_RELEASE)/free_mem.o

$(OBJDIR_RELEASE)/get_comando.o: get_comando.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c get_comando.c -o $(OBJDIR_RELEASE)/get_comando.o

$(OBJDIR_RELEASE)/get_dicionario.o: get_dicionario.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c get_dicionario.c -o $(OBJDIR_RELEASE)/get_dicionario.o

$(OBJDIR_RELEASE)/get_tabuleiro.o: get_tabuleiro.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c get_tabuleiro.c -o $(OBJDIR_RELEASE)/get_tabuleiro.o

$(OBJDIR_RELEASE)/ini_tabuleiro.o: ini_tabuleiro.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ini_tabuleiro.c -o $(OBJDIR_RELEASE)/ini_tabuleiro.o

$(OBJDIR_RELEASE)/main.o: main.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.c -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/org_dicionario.o: org_dicionario.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c org_dicionario.c -o $(OBJDIR_RELEASE)/org_dicionario.o

$(OBJDIR_RELEASE)/print_file.o: print_file.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c print_file.c -o $(OBJDIR_RELEASE)/print_file.o

$(OBJDIR_RELEASE)/printabuleiro.o: printabuleiro.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c printabuleiro.c -o $(OBJDIR_RELEASE)/printabuleiro.o

$(OBJDIR_RELEASE)/verificar_palavra.o: verificar_palavra.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c verificar_palavra.c -o $(OBJDIR_RELEASE)/verificar_palavra.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

