#Para escrever comentários ##
############################# Makefile ##########################
all: main

main: Clientes.o CompraseVendas.o Estoque.o Produto.o Relatorios.o main.o
			gcc -o main Clientes.o CompraseVendas.o Estoque.o Produto.o Relatorios.o main.o

#-----> Distancia com o botão TAB ### e não com espaços
Clientes.o: Clientes.c
			gcc -o Clientes.o -c Clientes.c
CompraseVendas.o: CompraseVendas.c
			gcc -o CompraseVendas.o -c CompraseVendas.c
Estoque.o: Estoque.c
			gcc -o Estoque.o -c Estoque.c
Produto.o: Produto.c
			gcc -o Produto.o -c Produto.c
Relatorios.o: Relatorios.c
			gcc -o Relatorios.o -c Relatorios.c
main.o: main.c
			gcc -o main.o -c main.c

clean:
			rm -rf *.o

mrproper: clean
			rm -rf main
