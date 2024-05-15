#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	srand(time(NULL));
	char map[8][8];
	int i;
	int j;
	int intentos=0;
	//genera la matriz donde va a estar la tierra
		for( i=0;i<8;i++){
			for( j=0;j<8;j++){
				map[i][j]='x';
			};
	//genera lo que vendria a ser el agua
	};
	for(i=0; i<8 ;i++){
		map[0][i]='0';
		map[7][i]='0';
		map[i][0]='0';
		map[i][7]='0';
	
	};
	int pc,pf;
	int tc,tf;
	//aca se definirian las posiciones del tesoro y el pirata en un lugar aleatorio
	for( i=0;i<2;i++){
	int c=(rand()%6)+1;
	int f=(rand()%6)+1;	
	if(i==0){map[c][f]='T'; tc=c; tf= f;}else
	{map[c][f]='P'; pc=c; pf= f;};
	};
	while(intentos<50){
		//aca se imprimirian el pirata y el tesoro
		char opc;
		for( i=0;i<8;i++){
			for( j=0;j<8;j++){
				if(map[i][j]!= 'T'){
				printf("%c ",map[i][j]);
				} else{
					printf("x ");
				}

			};
			printf("\n");
	};
	//acá se puede elegir donde podra ir el pirata
	printf("elegir: N, S, E, O\n");
	scanf("%c",&opc);
	getchar();
	switch(opc){
	case'N':{
		pc-=1;
		/*if(map[pc][pf]=='0'){
		printf("Caiste al agua :(");
		getchar();
  		esto hara que si el usuario al moverse a tal direccion se va al agua 
    		pierde el juego*/
		if(map[pc][pf]=='0'){
		printf("Caiste al agua :(");
		getchar();
		return 0;
		};
		map[pc][pf]='*';
		break;
	};
	case 'S':{
		pc+=1;if(map[pc][pf]=='0'){
		printf("Caiste al agua :(");
		getchar();
		return 0;
		};
		map[pc][pf]='*';
		break;
	};
	case 'O':{
		pf-=1;
		if(map[pc][pf]=='0'){
		printf("Caiste al agua :(");
		getchar();
		return 0;
		};
		map[pc][pf]='*';
		break;
	};
	case 'E':{
		pf+=1;
		if(map[pc][pf]=='0'){
		printf("Caiste al agua :(");
		getchar();
		return 0;
		};
		//esto marcara el recorrido del pirata
		map[pc][pf]='*';
		break;
	};
	default: printf("no se reconoce ese comando");
	};
	//si la posicion del pirata es igual al del tesoro se gana y termina el juego
	if(map[pc][pf]==map[tc][tf]){
	printf("encontraste el tesoro");
	getchar();
	return 0;
	};
	//esto limpiara cmd y nada mas quedara lo que se alla hecho recientemente
	system("cls");
	intentos++;
	};
}
