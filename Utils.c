#include <string.h>


int incrementStr(char id[], int num){
    int atual, i;
    if(num == strlen(id)-1){
        if(id[num] == '9'){
            id[num] = '0';
            return 1;
        }else{
            id[num] += 1;
            return 0;
        }     
    } else if( incrementStr(id, num + 1) == 1 ){
        if(id[num] == '9'){
            id[num] = '0';
            return 1;
        } else {
            id[num] += 1;
            return 0;
        }
    }    
    return 0;
}

int normalize(int size, char value[], char normalizedValue[]){
    int padLen = size - strlen(value);
    if(padLen < 0) padLen = 0;
    const char * padding = "                                                         ";
    sprintf(normalizedValue, "%s%*.*s", value, padLen, padLen, padding);
    return 0;
}

int gotoend(FILE * fp){

    do{
        fgetc(fp);
    } while (!feof(fp));

    return 0;
}