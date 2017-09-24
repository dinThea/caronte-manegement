#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int cadastrarCliente(char name[], char* lastId[], char* actualId[]){
    
    int i, j, num;
    FILE *fp;

    fp = fopen ("Clientes.txt", "r+");

    for(i = 0; i < 9; i++){
        num += *actualId[i] - '0';
    }

    if(num == 0){
        fprintf(fp, "%s %s\n", *actualId, name);
        *actualId = "00000001";
    }else{
        fprintf(fp, "%s %s\n", *actualId, name);
        strcpy(*lastId, *actualId);
        incrementStr(&actualId, 0); 
    }

    fclose(fp);

    return 0;
}

int excluirCliente(char type, char id[], char name[]){

    int i, j, booleno = 1;
    char nameCmp[strlen(name)];
    char idCmp[strlen(id)];
    FILE *fp;
    FILE *fp2;

    fp = fopen ("Clientes.txt", "r+");
    fp2 = fopen ("ClientesExcluidos.txt", "r+");
    switch(type){
        case 'i':
            for(i = 0; i < strlen(id); i++){
                idCmp[i] = fgetc(fp);
            }
            while(feof(fp) || booleno){
                if(strcmp(idCmp, id)){
                    booleno = 0;
                }else{
                    for(i = 1; i < strlen(id); i++){
                        idCmp[i-1] = idCmp[i];
                    }
                    idCmp[strlen - 1] = fgetc(fp);
                }
            }
            if(!feof(fp)){
                return 1;
            }else{
                fprintf(fp, "%s %s\n", id, name);
            }
        break;
        case 'n':
            for(i = 0; i < strlen(name); i++){
                nameCmp[i] = fgetc(fp);
            }
            while(feof(fp) || booleno){
                if(strcmp(nameCmp, name)){
                    booleno = 0;
                }else{
                    for(i = 1; i < strlen(name); i++){
                        nameCmp[i-1] = nameCmp[i];
                    }
                    nameCmp[strlen - 1] = fgetc(fp);
                }
            }
            if(!feof(fp)){
                return 1;
            }
            else{
                fprintf(fp, "%s %s\n", id, name);
            }
        break;
    }
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