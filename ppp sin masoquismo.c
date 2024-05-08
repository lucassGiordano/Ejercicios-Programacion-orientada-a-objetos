#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ppp(int a,int b){
	if(a==1&&b==3){return 1;}else
	if(a==2&&b==1){return 1;}else
	if(a==3&&b==2){return 1;}else
	if(a==b){return 0;}
	else{return 2 ;}
};

int main(){
    srand(time(NULL));
    int wins[5][4];
    int e,em;
    int ju=0, m=0, emp=0; // Aquí se inicializan j, m y emp
    int i; // Declaración de i fuera del bucle
	int j;
	
    for(i=0; i<5; i++){
        printf("Ronda: %d \n", i+1);
        for(j=0; j<3; j++){
            printf("1 piedra 2 papel 3 tijera: ");
            scanf("%d",&e);
            em=(rand()%3)+1;
            int r=ppp(e,em);
            printf("Maquina:%d\n",em);
            switch (r){
                case 1:{
                    ju++;
                    printf("ganaste\n");
                    break;
                }
                case 2:{
                    m++;
                    printf("perdiste\n");
                    break;
                }
                case 0:{
                    emp++;
                    printf("empate\n");
                    break;
                }
            	}
            }
        }

    if(ju>m){
        printf("ganaste la partida\n");
    } else if (ju<m){
        printf("perdiste la partida\n");
    }else { printf("empate");}
    printf("ganadas:%d perdidas:%d empate:%d\n",ju,m,emp);
}
