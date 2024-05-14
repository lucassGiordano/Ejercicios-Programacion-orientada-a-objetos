#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//verifica si gana ppp
int ppp(int a,int b){
	if(a==1&&b==3){return 1;}else
	if(a==2&&b==1){return 1;}else
	if(a==3&&b==2){return 1;}else
	if(a==b){return 0;}
	else{return 2 ;}
};

int main(){
    srand(time(NULL));
//almacena todo el sistema de puntuacion y el 4to es para quien ganó la ronda 
    int wins[5][4];
//varaibles eleccion para jugador y maquina
    int e,em;
    int ju=0, m=0, emp=0; // Aquí se inicializan j, m y emp
    int i; // Declaración de i fuera del bucle(sino el codigo da error por ver del compilador)
    int j;
//bucle que dice la ronda
    for(i=0; i<5; i++){
	//se dice la ronda
        printf("ronda:%d\n", i+1);
	    //bucle de partidas
        for(j=0; j<3; j++){
            printf("1 piedra 2 papel 3 tijera: ");
            scanf("%d",&e);
	//creamos rand para eleccion de maquina
            em=(rand()%3)+1;
            int r=ppp(e,em);
            printf("Maquina:%d\n\n",em);
	// r que es igual a respuesta dada por funcion ppp(hace return de 1,2,0) selecciona según el caso
		//con i j la variable se almacena en el array donde corresponde 
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
		//en caso que la primera y segunda ronda ganó una persona, se da valor 3 a j(para finalizar) y se asigna el 3 como punto directamente
		//ya que no tiene chance el otro
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
	    //no es viable, en empate y ganado 3 veces por el jugador coinciden en la suma y da problemas, por lo general no es buena idea
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
	    //creamos un bicle que va 1 por 1 en la ronda y va sumando puntos según quien tenga mas
		int pm=0,pj=0;
		for(j=0; j<4; j++){
		//si gana jugador
        	if(wins[i][j]==1){
			pj++;
			//si gana maquina
		} else if(wins[i][j]==2){
			pm++;
			}
        }
	    // con los puntos pm y pj se ve quien tiene mas y se da el punto final
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
	// dice el ganador por quien tiene mas puntos
    if(ju>m){
        printf("ganaste la partida\n");
    } else {
        printf("perdiste la partida\n");
    }
    printf("ganadas:%d perdidas:%d empate:%d\n",ju,m,emp);
//no es necesario pero es algo extra para ver los puntos
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
        	printf("%d ",wins[i][j]);
        }
        printf("\n");
    }
}
