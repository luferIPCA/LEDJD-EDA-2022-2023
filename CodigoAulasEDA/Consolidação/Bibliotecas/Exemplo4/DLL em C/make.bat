
#makefile
#by
#date:

gcc -c Funcs.c
#
#gcc -shared -o mylib.dll -Wl,--out-implib,libtstdll.a test_dll.o
#No mínimo
gcc -shared -o mylib.dll Funcs.o

#depois de criares o Main
gcc -o Prog Main.c -L. mylib.dll