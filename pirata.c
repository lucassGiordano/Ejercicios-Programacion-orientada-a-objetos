#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL));
	char *map[8][8];
	int i;
	int j;
	for(i=0; i<8 ;i++){
		map[0][i]=0;
		map[8][i]=0;
		map[i][0]=0;
		map[i][8]=0;
	};
	int pc,pf;
	int tc,tf;
	for( i=0;i<2;i++){
	int c=(rand()%6)+1;
	int f=(rand()%6)+1;
	if(i==0){map[c][f]="T"; tc=c; tf= f;}else
	{map[c][f]="P"; pc=c; pf= f;};
	};
	char opc;
	printf("hola :D");
	while(1){
		for( i=0;i<8;i++){
			for( j=0;j<8;j++){
				printf("%s",map[i][j]);
			};
			printf("/n");
	};
	printf("elegir: N, S, E, O");
	scanf("%c",&opc);
	switch(opc){
	case'N':{
		pc-=1;
		map[pc][pf]="*";
		break;
	};
	case 'S':{
		pc+=1;
		map[pc][pf]="*";
		break;
	};
	case 'E':{
		pf-=1;
		map[pc][pf]="*";
		break;
	};
	case 'O':{
		pf+=1;
		map[pc][pf]="*";
		break;
	};
	default: printf("no se reconoce ese comando");
	};
	if(map[pc][pf]==map[tc][tf]){
	printf("encontraste el tesoro");
	getchar();
	return 0;
	};
	if(map[pc][pf]== 0){
	printf("Caiste al agua :(");
	getchar();
	return 0;
	};
	};
}
