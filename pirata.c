#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | bgColor);
}

void generarIsla(char map[8][8]){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            map[i][j] = 'x';
        }
    }
    for(i = 0; i < 8; i++){
        map[0][i] = '0';
        map[7][i] = '0';
        map[i][0] = '0';
        map[i][7] = '0';
    }
}

void imprimirIsla(char map[8][8], int pc, int pf, int tc, int tf){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if (map[i][j] == '0') {
                setColor(FOREGROUND_BLUE,BACKGROUND_BLUE); // Cambiar a azul
                printf("%c ", map[i][j]);
                setColor(15,0); // Restablecer al color normal
            }
            else if (i == pc && j == pf) {
                setColor(5,224); // Cambiar a MORADO
                printf("%c ", map[i][j]);
                setColor(15,0); // Restablecer al color normal
            }
            else if (map[i][j] == 'T') {
                setColor(14,224); // Cambiar a AMARILLO
                printf("x ");
                setColor(15,0); // Restablecer al color normal
            }
            else if (map[i][j] == '*'||map[i][j] == 'P'){
                setColor(0,224);
                printf("%c ",map[i][j]);
                setColor(15,0);
            }else{
              setColor(14,224);
                printf("%c ",map[i][j]);
                setColor(15,0);
            }
        }
        printf("\n");
    }
}

void moverPirata(char map[8][8], char direccion, int *pc, int *pf, int *intentos){
    switch(direccion){
        case 'N':
            (*pc)--;
            break;
        case 'S':
            (*pc)++;
            break;
        case 'O':
            (*pf)--;
            break;
        case 'E':
            (*pf)++;
            break;
        default:
            printf("No se reconoce ese comando\n");
            break;
    }
    if(map[*pc][*pf] == '0'){
        printf("Caiste al agua :(\n");
        exit(0);
    }
    setColor(5,224);
    map[*pc][*pf] = '*';
    setColor(15,0);
    (*intentos)++;
}

int main(){
    srand(time(NULL));
    char map[8][8];
    int intentos = 0;
    int pc, pf, tc, tf;
    
    generarIsla(map);
    
    for(int i = 0; i < 2; i++){
        int c = (rand() % 6) + 1;
        int f = (rand() % 6) + 1;
        if(i == 0){
            map[c][f] = 'T';
            tc = c; 
            tf = f;
        }
        else{
            map[c][f] = 'P';
            pc = c;
            pf = f;
        }
    }
    
    while(intentos < 50){
        imprimirIsla(map, pc, pf, tc, tf);
        printf("Te quedan :%d intentos\n",(50-intentos));
        printf("\nElegir: N, S, E, O\n");
        char opc;
        scanf(" %c", &opc);
        moverPirata(map, opc, &pc, &pf, &intentos);
        if(map[pc][pf] == map[tc][tf]){
            printf("¡Encontraste el tesoro!\n");
            exit(0);
        }
        system("cls");
    }
    printf("Llegaste a los 50 intentos!\n");
    return 0;
}
