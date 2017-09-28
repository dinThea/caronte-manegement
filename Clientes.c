#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int cadastrarCliente(char name[], char* lastId[], char* actualId[]){
    
    int i, j, num;
    char nameNormalized[41];
    FILE *clientes, *idClientes;

    clientes = fopen ("Clientes.txt", "r+");
    idClientes = fopen ("IdClientes.txt", "r+");

    for(i = 0; i < sizeof(nameNormalized) - 1; i++){
        nameNormalized[i] = '';
    }

    if(sizeof(name) > 41){
        return 1;
    }else{
        for(i = 0; i < (sizeof(nameNormalized) - sizeof(name)), i++){
            nameNormalized[sizeof(nameNormalized) - i] = name[sizeof(name) - i]; 
        }
    }

    for(i = 0; i < 9; i++){
        num += *actualId[i] - '0';
    }

    if(num == 0){
        fputs(nameNormalized, clientes);
        fputs(actualId, idClientes);
        *actualId = "00000001";
    }else{
        fputs(nameNormalized, clientes);
        fputs(actualId, idClientes);
        strcpy(*lastId, *actualId);
        incrementStr(&actualId, 0); 
    }

    fclose(clientes);
    fclose(idClientes);

    return 0;
}

int excluirCliente(char type, char id[], char name[]){

    int i, j, booleno = 1;
    char nameCmp[41];
    char nameRsch[41];
    char idCmp[9];
    FILE *clientes, *clientes2, idClientes;

    clientes = fopen ("Clientes.txt", "r+");
    clientes2 = fopen ("ClientesExcluidos.txt", "r+");
    idClientes = fopen ("IdClientes.txt", "r+");

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

    switch(type){
        case 'i':
            while(fgets(idCmp, 9, idClientes) != NULL){
                if(strcmp(idCmp, id)){
                    booleno = 0;
                }
            }
            if(!feof(idClientes)){
                return 1;
            }else{
                fputs(clientes2, nameCmp);
            }
        break;
        case 'n':
            while(fgets(nameRsch, 41, clientes) != NULL){
                if(strcmp(nameRsch, nameCmp)){
                    booleno = 0;
                }
            }
            if(!feof(clientes)){
                return 1;
            }else{
                fputs(clientes2, nameCmp);
            }
        break;
    }
    
    fclose(clientes);
    fclose(clientes2);
    fclose(idClientes);

    return 0;
}

int incrementStr(char* actualId[], int num){
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