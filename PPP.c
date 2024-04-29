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
        printf("ronda:%d\n", i+1);
        for(j=0; j<3; j++){
            printf("1 piedra 2 papel 3 tijera: ");
            scanf("%d",&e);
            em=(rand()%3)+1;
            int r=ppp(e,em);
            printf("Maquina:%d\n",em);
            switch (r){
                case 1:{
                    wins[i][j]=1;
                    printf("ganaste\n");
                    break;
                }
                case 2:{
                    wins[i][j]=2;
                    printf("perdiste\n");
                    break;
                }
                case 0:{
                    wins[i][j]=3;
                    printf("empate\n");
                    break;
                }
            }
            if(wins[i][1]==wins[i][2]){
                wins[i][3]=wins[i][1];
                break;
            }
        }
        wins[i][4]=wins[i][3];
        if(wins[i][4]==1){ju+=1;}
        else if(wins[i][4]==2){m+=1;}
        else emp+=1;

        if(ju>=3||m>=3){
            break;
        }
    }

    if(ju>m){
        printf("ganaste la partida\n");
    } else {
        printf("perdiste la partida\n");
    }
    printf("ganadas:%d perdidas:%d empate:%d\n",ju,m,emp);
}

