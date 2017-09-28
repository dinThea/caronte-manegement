#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastrarProduto(char preco[], char name[], char* lastId[], char* actualId[], char estoque[]){

    int i, j, num;
    char produtoNormalized[41];
    char precoNormalized[9];
    char estoqueNormalized[13];
    FILE *produto, *idProduto, *estoqueProduto, *precoProduto;

    produto = fopen ("Produto.txt", "r+");
    idProduto = fopen ("idProduto.txt", "r+");
    precoProduto = fopen ("precoProduto.txt", "r+");
    estoqueProduto = fopen ("estoqueProduto.txt", "r+");

    for(i = 0; i < 9; i++){
        num += *actualId[i] - '0';
    }

    for(i = 0; i < sizeof(precoNormalized) - 1; i++){
        precoNormalized[i] = '';
    }

    for(i = 0; i < sizeof(estoqueNormalized) - 1; i++){
        estoqueNormalized[i] = '';
    }

    for(i = 0; i < sizeof(produtoNormalized) - 1; i++){
        produtoNormalized[i] = '';
    }

    if(sizeof(name) > 41){
        return 1;
    }else if(sizeof(preco) > sizeof(precoNormalized){
        return 1;
    }else if(sizeof(estoque) > sizeof(estoqueNormalized)){
        return 1;
    }else{
        for(i = 0; i < (sizeof(produtoNormalized) - sizeof(name)), i++){
            produtoNormalized[sizeof(produtoNormalized) - i] = name[sizeof(name) - i]; 
        }
        for(i = 0; i < (sizeof(estoqueNormalized) - sizeof(estoque)), i++){
            produtoNormalized[sizeof(estoqueNormalized) - i] = estoque[sizeof(estoque) - i]; 
        }
        for(i = 0; i < (sizeof(precoNormalized) - sizeof(preco)), i++){
            precoNormalized[sizeof(precoNormalized) - i] = preco[sizeof(name) - i]; 
        }
    }

    if(num == 0){
        fputs(precoNormalized, precoProduto);
        fputs(estoqueNormalized, estoqueProduto);
        fputs(produtoNormalized, produto);
        fputs(actualId, idProduto);
        *actualId = "00000001";
    }else{
        fputs(precoNormalized, precoProduto);
        fputs(estoqueNormalized, estoqueProduto);
        fputs(produtoNormalized, produto);
        fputs(actualId, idProduto);
        strcpy(*lastId, *actualId);
        incrementStrProduto(&actualId, 0); 
    }

    fclose(produto);
    fclose(precoProduto);
    fclose(estoqueProduto);
    fclose(idProduto);

    return 0;
}

int excluirProduto(char name[]){

    int i, j, booleno = 1;
    char nameCmp[41];
    char nameRsch[41];
    FILE *produto;
    FILE *preduto2;

    produto = fopen ("Produto.txt", "r+");
    produto2 = fopen ("ProdutosExcluidos.txt", "r+");
    
    for(i = 0; i < sizeof(nameCmp) - 1; i++){
        nameCmp[i] = '';
    }

    if(sizeof(nameCmp) > 41){
        return 1;
    }else{
        for(i = 0; i < (sizeof(nameCmp) - sizeof(name)), i++){
            nameCmp[sizeof(nameCmp) - i] = name[sizeof(name) - i]; 
        }
    }

    while(fgets(nameRsch, 41, produto) != NULL){
        if(strcmp(nameRsch, nameCmp)){
            booleno = 0;
        }
    }
    if(!feof(produto)){
        return 1;
    }else{
        fputs(produto2, nameCmp);
    }
    
    fclose(produto);
    fclose(produto2);

    return 0;
}

int incrementStrProduto(char* actualId[], int num){
    int atual, i;
    if(num == strlen(*actualId)){
        if(*actualId[num] == '9'){
            *actualId[num] = '0';
            return 1;
        }else{
            *actualId[num] += 1;
            return 0;
        }     
    } else if(incrementStr(char* actualId[], int num + 1)==1){
        if((*actualId[num] == '9'){}
            *actualId[num] = '0';
            return 1;
        }else if{
            *actualId[num] += 1;
            return 0;
        }
    }    
    return 0;
}