all: main

Bloom.o: lib/Bloom/Bloom.h lib/Bloom/Bloom.c
	g++ -c lib/Bloom/Bloom.h lib/Bloom/Bloom.c

#busqueda_binaria.o: lib/BusquedaBinaria/busqueda_binaria.h lib/BusquedaBinaria/busqueda_binaria.c
#	g++ -c lib/BusquedaBinaria/busqueda_binaria.h lib/BusquedaBinaria/busqueda_binaria.c

hashL2.o: lib/HashSeparate/hashL2.h lib/HashSeparate/hashL2.c
	g++ -c lib/HashSeparate/hashL2.h lib/HashSeparate/hashL2.c

linear2.o: lib/HashOpen/linear2.h lib/HashOpen/linear2.c
	g++ -c lib/HashOpen/linear2.h lib/HashOpen/linear2.c

#main: Bloom.o busqueda_binaria.o hashL2.o linear2.o main.c
#	g++ -o main main.c Bloom.o busqueda_binaria.o hashL2.o linear2.o

main: Bloom.o hashL2.o linear2.o main.c
	g++ -o main main.c Bloom.o hashL2.o linear2.o

clean:
	rm *.o main