#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Globals.c"
#include "Clientes.c"
#include "Utils.c"
#include "Produto.c"
#include "CompraseVendas.c"
#include "Estoque.c"
#include "Relatorios.c"
// UI
#include "ui/UI.c"

// Array de Clientes

void init_files();

int main(){
  init_files();
  interface_usuario();
  // fprintf(clientes_file,"f");
  // rewind(clientes_file);
  // excluirCliente("0000023");
  // fprintf(clientes_file,"e");
  //printf("%s\n%s\n%s", produtos[1].nome, produtos[1].preco, produtos[1].qntd);
  // cadastrarProduto("penis", "4", "3");
  // cadastrarProduto("penis", "4", "3");
  // cadastrarProduto("penis", "4", "3");
  // cadastrarProduto("penis", "4", "3");
  // excluirProduto("penis     ");
  //fechar_files();
}


void init_files(){
  clientes_file = fopen("./data/Clientes.txt", "r+");
  produtos_file = fopen("./data/Produtos.txt", "r+");
  ler_cliente();
  ler_produto();
}













