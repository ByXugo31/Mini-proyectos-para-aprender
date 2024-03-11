#include <stdio.h>
#include "stdarg.h"
#define SUMA 0
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 3

//Funcion que aplica una operación a una cadena de números, hecho para introducirme en los argumentos variables.

char* operacionToString(int num){
    if(num==SUMA) return "sumar";
    if(num==RESTA) return "restar";
    if(num==MULTIPLICACION) return "multiplicar";
    if(num==DIVISION) return "dividir";
}

void calculadora(int option,int num,...){
    va_list args;
    va_start(args, num);
    int act;
    int valor=num;
    printf("El resultado de %s: ", operacionToString(option));
    printf("%d ",num);
    while ((act = va_arg(args, int)) != 0) {
        printf("%d ",act);
        if(option==SUMA) valor+=act;
        if(option==RESTA) valor-=act;
        if(option==MULTIPLICACION) valor*=act;
        if(option==DIVISION) valor/=act;
    }
    printf("es %d\n",valor);
}

int main() {
    //IMPORTANTE TERMINAR LOS ARGUMENTOS CON UN 0
    calculadora(MULTIPLICACION,2,3,4,0);
    calculadora(SUMA,2,3,4,0);
    return 0;
}
