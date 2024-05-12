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
            printf("Maquina:%d\n\n",em);
            switch (r){
                case 1:{
                    wins[i][j]=1;
                    printf("ganaste\n\n");
                    break;
                }
                case 2:{
                    wins[i][j]=2;
                    printf("perdiste\n\n");
                    break;
                }
                case 0:{
                    wins[i][j]=0;
                    printf("empate\n\n");
                    break;
                }
            }
            if(wins[i][0]==1 && wins[i][1] == 1){
                wins[i][3]=1;
                j=3;
            };
            if(wins[i][0]==2 && wins[i][1] == 2){
                wins[i][3]=2;
                j=3;
            };
        }
        //verifica si es empate (siempre da 0) y descarta que el primero de 1 por el caso 111
       /* int total= wins[i][0] + wins[i][1] + wins[i][2] ;
       	if(total == 3 && wins[i][0] != 1){
			wins[i][3]=0;
		} else if(total == 2 && wins[i][0] != 1 || wins[i][1] != 1){
			wins[i][3]=2;
		} else if(total >= 4){
			wins[i][3]=2;
		} else if(total == 2 && (wins[i][0] == 1 || wins[i][1] == 1)){
			wins[i][3]=1;
		} else if(total == 1){
			wins[i][3]=1;
		}*/
		int pm=0,pj=0;
		for(j=0; j<4; j++){
        	if(wins[i][j]==1){
			pj++;
			} else if(wins[i][j]==2){
			pm++;
			}
        }
        if(pm==pj){
         wins[i][3]= 0;
         emp++;
		} else if(pm>pj){
			wins[i][3]= 2;
         	m++;
		} else if(pm<pj){
			wins[i][3]= 1;
         	ju++;
		}
    }

    if(ju>m){
        printf("ganaste la partida\n");
    } else {
        printf("perdiste la partida\n");
    }
    printf("ganadas:%d perdidas:%d empate:%d\n",ju,m,emp);
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
        	printf("%d ",wins[i][j]);
        }
        printf("\n");
    }
}
