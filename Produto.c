#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int ler_produto(){

    int i, flag = 1;
    char c;
    do{
        for(i = 0; i < PRECO_SIZE - 1; i++){
            c = fgetc(produtos_file);
            if(c == -1) flag = 0;
            if(flag)
                produtos[num_produtos].preco[i] = c;
        }
        if(flag){
            produtos[num_produtos].preco[PRECO_SIZE] = '\0';

            fgetc(produtos_file);
            for(i = 0; i < PRODUTO_SIZE - 1; i++){
                c = fgetc(produtos_file);
                produtos[num_produtos].nome[i] = c;
            }
            produtos[num_produtos].nome[PRODUTO_SIZE] = '\0';

            fgetc(produtos_file);
            for(i = 0; i < ESTOQUE_SIZE - 1; i++){
                c = fgetc(produtos_file);
                produtos[num_produtos].qntd[i] = c;
            }
        
            // Pula caracteres de quebra
            fgetc(produtos_file);

            // Pega o Status
            c =  fgetc(produtos_file);
            produtos[num_produtos].status = c - '0';
            c =  fgetc(produtos_file);
            fgetc(produtos_file);
            
            num_produtos++;
        }
    }
    while(flag && !feof(produtos_file));
    for(i = 0; i < num_produtos; i++){
        if(!produtos[i].status) num_produtos_del++;
    }
    rewind(produtos_file);
    return 0;
}

int cadastrarProduto(char name[], char preco[], char qntd[]){

    char normalized_name[PRODUTO_SIZE],  normalized_preco[PRECO_SIZE], normalized_qntd[QNTD_SIZE];
    int i;
    int name_len = strlen(name);

    gotoend(produtos_file);
    
    normalize(PRODUTO_SIZE - 1, name , normalized_name);
    normalize(PRECO_SIZE - 1, preco, normalized_preco);
    normalize(QNTD_SIZE, qntd , normalized_qntd);
    produtos[num_produtos].status = 1;
    
    fprintf(produtos_file, "%s;%s;%s;1\n", normalized_preco, normalized_name, normalized_qntd);
    num_produtos++;

    return 0;
}

int excluirProduto(char name[]){

    int i, j, booleno = 1;
    char nameCmp[strlen(name)];
    char c;
    //voltar cursor para o início
    rewind(produtos_file);
    //le o primeiro preco
    for(i = 0; i < PRECO_SIZE + 1; i++) fgetc(produtos_file);
    for(i = 0; i < strlen(name); i++){
        c = fgetc(produtos_file);
        nameCmp[i] = c;
    }
    nameCmp[strlen(name)] = '\0';
    
    while(!feof(produtos_file) && booleno){
        printf("\n|%s|\n", nameCmp);
        //compara o valor lprecoo com o parametro
        if(!strcmp(nameCmp, name)){
            booleno = 0;
        }else{
            for(i = 0; i < QNTD_SIZE + PRECO_SIZE + 4; i++) fgetc(produtos_file);
            fgets(nameCmp, strlen(name), produtos_file);
        }
    }
    if(feof(produtos_file)){
        return 1;
    } else {
        for(i = 0; i < QNTD_SIZE + 2; i++)
            fgetc(produtos_file);
        fprintf(produtos_file, "0");
        num_produtos--;
        num_produtos_del++;
    }


    return 0;
}
