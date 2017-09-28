#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Produto.h"
#include "Estoque.h"

int realizarCompra(char produto[], char qntd[], char preco[], char* lastId[], char* actualId[]){

    int i, j, count;
    char produtoNormalized[41];
    FILE *produtof;
    produtof = fopen ("Produto.txt", "r+");

    for(i = 0; i < sizeof(produtoNormalized) - 1; i++){
        produtoNormalized[i] = '';
    }

    if(sizeof(name) > 41){
        return 1;
    }else{
        for(i = 0; i < (sizeof(produtoNormalized) - sizeof(produto)), i++){
            produtoNormalized[sizeof(produtoNormalized) - i] = produto[sizeof(produto) - i]; 
        }
    }

    count = 0;
    while(fgets(nameRsch, 41, produtof) != NULL){
        
        if(strcmp(nameRsch, nameCmp)){
            booleno = 0;
        }
        count ++;

    }
    if(!feof(produtof)){
        cadastrarProduto(preco, produto, lastId, actualId, qntd);
    }else{
        aumentarEstoque(produto, qntd);
    }

    fclose(produtof);

    return 0;
}

int realizarVenda(char produto[], char qntd[], char preco[], char* lastId[], char* actualId[]){
    
    int i, j, count;
    char produtoNormalized[41];
    FILE *produtof, *vendasf;

    produtof = fopen ("Produto.txt", "r+");
    vendasf = fopen ("Vendas.txt", "r+");

    for(i = 0; i < sizeof(produtoNormalized) - 1; i++){
        produtoNormalized[i] = '';
    }

    if(sizeof(produto) > 41){
        return 1;
    }else{
        for(i = 0; i < (sizeof(produtoNormalized) - sizeof(produto)), i++){
            produtoNormalized[sizeof(produtoNormalized) - i] = produto[sizeof(produto) - i]; 
        }
    }

    count = 0;
    while(fgets(nameRsch, 41, produtof) != NULL){
        
        if(strcmp(nameRsch, nameCmp)){
            booleno = 0;
        }
        count ++;

    }
    if(!feof(produtof)){
        return 0;
    }else{
        diminuirEstoque(produto, qntd);
        for(i = 0; i < qntd; i++)
            fputs(produtoNormalized, vendasf);
    }

    fclose(produtof);

}

int pesquisarVenda(char produto[]){

    int i, j, count;
    char produtoNormalized[41], nameRsch[41];
    FILE *vendasf;

    vendasf = fopen ("Vendas.txt", "r+");

    for(i = 0; i < sizeof(produtoNormalized) - 1; i++){
        produtoNormalized[i] = '';
    }

    if(sizeof(produto) > 41){
        return 1;
    }else{
        for(i = 0; i < (sizeof(produtoNormalized) - sizeof(produto)), i++){
            produtoNormalized[sizeof(produtoNormalized) - i] = produto[sizeof(produto) - i]; 
        }
    }

    while(fgets(nameRsch, 41, vendas) != NULL){
        if(strcmp(nameRsch, nameCmp)){
            fputs(nameRsch, stdout);
        }
    }

    fclose(vendasf);

    return 0;
}

int excluirVenda(){
    return 0;
}

int excluirCompra(){
    return 0;
}