#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "unistd.h"

//Recreación del printf con el objetivo de aprender a manejar los argumentos variables en una función.

void readFormat(va_list prt,char frmt){
    char aux[2];
    char* str;
    sprintf(aux,"%c%c",'%',frmt);
    char* buffer = malloc(sizeof (char*));
    switch (frmt){
        case 'd':
            sprintf(buffer, aux, va_arg(prt, int));
            write(STDOUT_FILENO, buffer, strlen(buffer));
            break;
        case 's':
            str = va_arg(prt, char*);
            write(STDOUT_FILENO,str, strlen(str));
            break;
        case 'c':
            sprintf(buffer, aux, va_arg(prt, int));
            write(STDOUT_FILENO,buffer,1);
            break;
        case 'f':
            sprintf(buffer, aux, va_arg(prt, double));
            write(STDOUT_FILENO, buffer, strlen(buffer));
            break;
        default:
            write(STDOUT_FILENO,aux,2);
    }
    free(buffer);
}

void myPrint(char* str,...){
    va_list args;
    va_start(args, str);
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i]=='%'){
            i++;
            readFormat(args, str[i]);
            va_arg(args, int);
            continue;
        }
        write(STDOUT_FILENO,&str[i],1);
    }
}

int main() {
    myPrint("%c%c%c%c%c%c%c%c%c%c%c%c",'E','s','t','o',' ','e','s',' ','t','e','s','t');
    return 0;
}
