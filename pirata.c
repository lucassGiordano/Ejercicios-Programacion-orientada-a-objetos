#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

//funcion para poner el color primera varaible, segunda para fondo
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | bgColor);
}
//funcion que genera isla
//utiliza de argumento la matriz como tal
void generarIsla(char map[8][8]){
    int i, j;
    //insertamos x en toda la matris
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            map[i][j] = 'x';
        }
    }
//ingresamos 0 en todas las filas y columnas de los extremos
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
        	//Todo caracter ='0',va a ser azul el caracter y fondo
            if (map[i][j] == '0') {
                setColor(FOREGROUND_BLUE,BACKGROUND_BLUE); // Cambiar a azul
                printf("%c ", map[i][j]);
                setColor(15,0); // Restablecer al color normal
            }
            //cuando LA UBICACION de la matriz es igual a la del pirata va a ser morado, haciendo 
            //un seguimiento con el color
            else if (i == pc && j == pf) {
                setColor(5,224); // Cambiar a MORADO
                printf("%c ", map[i][j]);
                setColor(15,0); // Restablecer al color normal
            }
            //escondemos el tesoro remplazando el tesoro con x 
            else if (map[i][j] == 'T') {
                setColor(14,224); // Cambiar a AMARILLO
                printf("x ");
                setColor(15,0); // Restablecer al color normal
            } // los * y p son pintados de color negro marcando que son "antiguos"
            else if (map[i][j] == '*'||map[i][j] == 'P'){
                setColor(0,224);
                printf("%c ",map[i][j]);
                setColor(15,0);
            }else{
            	//el resto se pinta  de amarillo escondiendo las x 
              setColor(14,224);
                printf("%c ",map[i][j]);
                setColor(15,0);
            }
        }
        printf("\n");
    }
}
// * entra al alacenamiento de la vareable y es actualizado constantemente 
//funcion de movimiento de 5 argumentos
//la matriz , direccion (caracter de direccion),pc y pf (GUARDA FILA  Y COLUMNA), intentos(CONTEO
// DE LOS INTENTOS)
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
    // en caso del movimiento caer en 0(agua) da como partida finalizada;
    if(map[*pc][*pf] == '0'){
        printf("Caiste al agua :(\n");
        exit(0);
    }
//Se dibuja en la matriz el * y se suma el intento
    setColor(5,224);
    map[*pc][*pf] = '*';
    setColor(15,0);
    (*intentos)++;
}

int main(){
	//srand para numeros random
    srand(time(NULL));
    char map[8][8];
    // en mi caso cuneto intentos de 0 a 50
    int intentos = 0;
    int pc, pf, tc, tf;
    //la funcion para generar la matriz(sin tesoro y pirata)
    generarIsla(map);
    
    for(int i = 0; i < 2; i++){
    	//genera los dos randoms dentro de 1 y 7(%6 porque son entre el 6x6 pueden aparecer 
		// y +1 porque no puede ser 0)
        int c = (rand() % 6) + 1;
        int f = (rand() % 6) + 1;
        //en los dos casos se guerda la ubicacion para tener en cuenta despues
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
    //esta dentro del bucle mientras este menos de 50
    while(intentos < 50){
    	//funcion que imprime la isla
        imprimirIsla(map, pc, pf, tc, tf);
        printf("Te quedan :%d intentos\n",(50-intentos));
        printf("\nElegir: N, S, E, O\n");
        char opc;
        scanf(" %c", &opc);
        //funcion para mover el pirata
        moverPirata(map, opc, &pc, &pf, &intentos);
        //en caso de encontrar el tesoro funciona este if y termina el juego
        if(map[pc][pf] == map[tc][tf]){
            printf("¡Encontraste el tesoro!\n");
            exit(0);
        }
        //limpia la terminal
        system("cls");
    }
    //llega a este caso si se termina el while (llega a 50 intentos)
    printf("Llegaste a los 50 intentos!\n");
    return 0;
}
