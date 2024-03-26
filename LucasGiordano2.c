
#include<stdio.h>

int main(){
    int a ;
    int p ;
    int t ;
    printf("ingrese el numero de alumnos");
    scanf("%d",&a);
    if(a>=100){
        p=500;
    } else if(a<=99 && a>=50){
        p=400;
    } else if(a<=49){
        p=300;
    if(a<30){
        t=t+6000;
    }
    }
    printf("van a pagar %d",t+(a*p));
    return 0;
};

int main(){
    int SB ;
    int V1 ;
    int V2 ;
    int V3 ;
    printf("ingrese el sueldo base\n");
    scanf("%d",&SB);
    printf("ingrese cantidad de venta 1\n");
    scanf("%d",&V1);
    printf("ingrese cantidad de venta 2\n");
    scanf("%d",&V2);
    printf("ingrese cantidad de venta 3\n");
    scanf("%d",&V3);
    int comision = (V1+V2+V3)*0.10;
    printf("van a pagar %d",SB+comision);
    return 0;
};

int main(){
    float nota1 ;
    float nota2 ;
    float nota3 ;
    float notafinal;
    printf("ingrese la nota 1\n");
    scanf("%f",&nota1);
    printf("ingrese la nota 2\n");
    scanf("%f",&nota2);
    printf("ingrese la nota 3\n");
    scanf("%f",&nota3);
    notafinal = (nota1*0.55)+(nota2*0.30)+(nota3*0.15);
    printf("su nota es %f",notafinal);
    return 0;
};


int main(){
    float nota1 ;
    float nota2 ;
    float nota3 ;
    float notafinal;
    printf("ingrese la nota 1\n");
    scanf("%f",&nota1);
    printf("ingrese la nota 2\n");
    scanf("%f",&nota2);
    printf("ingrese la nota 3\n");
    scanf("%f",&nota3);
    notafinal = (nota1*0.55)+(nota2*0.30)+(nota3*0.15);
    printf("su nota es %f",notafinal);
    return 0;
};

int main(){
    int a ;
    int b ;
    printf("ingrese que numero quiere empezar\n");
    scanf("%d",&a);
    printf("ingrese hasta que numero quiere llegar\n");
    scanf("%d",&b);
    if((a%2)!=0){
	a=a-1;
	};
    for(a; a<=b;a=a+2){
         printf("%d  ",a);
    };
    return 0;
};

