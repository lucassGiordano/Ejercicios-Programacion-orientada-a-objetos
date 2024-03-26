#include<stdio.h>

int main(){
    int n1 ;
    printf("ingrese el numero");
    scanf("%d",&n1);
    if(n1>0){
        printf("positivo");
    } else if(n1<0){
        printf("negativo");
    }else if(n1==0){
        printf("es 0");
    }
    return 0;
}

int main(){
    int n1 ;
    printf("ingrese el numero");
    scanf("%d",&n1);
    if(n1%2==0){
        printf("es par");
    }else {
                printf("es inpar");
    }
    return 0;
}

#include <stdio.h>

int main(){
    int n1 ;
    printf("ingrese el numero\n");
    scanf("%d",&n1);
    if(n1%2==0 && n1%3==0 ){
        printf("es multiplo de 3 y 2");
    }else if(n1%2==0) {
                printf("es multiplo de 2");
    }else 
    if(n1%3==0)
    {
        printf("es multiplo de 3");
    }else {
        printf("no es multiplo de ninguno");
    }
    return 0;
}

int main(){
    int n1 ;
    int n2 ;
    int n3 ;
    printf("ingrese el numero1\n");
    scanf("%d",&n1);
    printf("ingrese el numero2\n");
    scanf("%d",&n2);
    printf("ingrese el numero3\n");
    scanf("%d",&n3);
    if(n1==n2 && n2==n3 ){
        printf("todos son iguales\n");
    }
    if(n1>=n2 && n1>=n3) {
    printf("%d es el mayor\n",n1);
    return 0;
    }
    if(n2>=n1 && n2>=n3) {
    printf("%d es el mayor\n",n2);
    return 0;
    }
    if(n3>=n2 && n3>=n1) {
    printf("%d es el mayor\n",n3);
    return 0;
    }
    return 0;
}