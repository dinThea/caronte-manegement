#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int ler_cliente(){

    int i, flag = 1;
    char c;
    do{
        for(i = 0; i < ID_SIZE - 1; i++){
            c = fgetc(clientes_file);
            if(c == -1) flag = 0;
            if(flag)
                clientes[num_clientes].id[i] = c;
        }
        if(flag){
            clientes[num_clientes].id[ID_SIZE] = '\0';
            strcpy(actual_id, clientes[num_clientes].id);

            fgetc(clientes_file);
            for(i = 0; i < NAME_SIZE - 1; i++){
                c = fgetc(clientes_file);
                clientes[num_clientes].nome[i] = c;
            }
            clientes[num_clientes].nome[NAME_SIZE] = '\0';

        
            // Pula caracteres de quebra
            fgetc(clientes_file);

            // Pega o Status
            c =  fgetc(clientes_file);
            clientes[num_clientes].status = c - '0';
            c =  fgetc(clientes_file);
            
            num_clientes++;
        }
    }
    while(flag && !feof(clientes_file));
    incrementStr(actual_id, 0);
    for(i = 0; i < num_clientes; i++){
        if(!clientes[i].status) num_clientes_del++;
    }
    rewind(clientes_file);
    return 0;
}

int cadastrarCliente(char name[]){
    char normalized_name[NAME_SIZE];
    int i;
    int name_len = strlen(name);

    gotoend(clientes_file);

    if(name_len > NAME_SIZE) return 1;
    strcpy(normalized_name, name);
    
    for(i = name_len; i < NAME_SIZE; i++){
        normalized_name[i] = ' ';
    }
    normalized_name[NAME_SIZE - 1] = '\0';

    strcpy(clientes[num_clientes].nome, normalized_name); 
    strcpy(clientes[num_clientes].id  , actual_id); 
    clientes[num_clientes].status = 1;
    
    fprintf(clientes_file, "%s;%s;1\n", actual_id, normalized_name);
    num_clientes++;

    incrementStr(actual_id, 0);
    return 0;
}

int excluirCliente(char id[]){

    int i, j, booleno = 1;
    char idCmp[strlen(id)];
    char c;
    //voltar cursor para o início
    rewind(clientes_file);
    //le o primeiro id
    for(i = 0; i < strlen(id); i++){
        c = fgetc(clientes_file);
        idCmp[i] = c;
    }
    idCmp[strlen(id)] = '\0';
    
    while(!feof(clientes_file) && booleno){
        //compara o valor lido com o parametro
        if(!strcmp(idCmp, id)){
            booleno = 0;
        }else{
            for(i = 0; i < 13; i++) fgetc(clientes_file);
            fgets(idCmp, 8, clientes_file);
        }
    }
    if(feof(clientes_file)){
        return 1;
    } else {
        for(i = 0; i < NAME_SIZE + 1; i++)
            fgetc(clientes_file);
        fprintf(clientes_file, "0");
        num_clientes_del++;
    }


    return 0;
}
