#include<stdio.h>
#include <stdlib.h>

int main() {
    while(1) {
        int opcion;
        printf("Que ejercicio quiere ver? : ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int a;
                int p;
                int t = 0;
                printf("Ingrese el numero de alumnos: ");
                scanf("%d", &a);
                if (a >= 100) {
                    p = 500;
                } else if (a <= 99 && a >= 50) {
                    p = 400;
                } else if (a <= 49) {
                    p = 300;
                    if (a < 30) {
                        t = t + 6000;
                    }
                }
                printf("Van a pagar %d\n", t + (a * p));
                break;
            }

            case 2: {
                int SB;
                int V1;
                int V2;
                int V3;
                printf("Ingrese el sueldo base: ");
                scanf("%d", &SB);
                printf("Ingrese cantidad de venta 1: ");
                scanf("%d", &V1);
                printf("Ingrese cantidad de venta 2: ");
                scanf("%d", &V2);
                printf("Ingrese cantidad de venta 3: ");
                scanf("%d", &V3);
                int comision = (V1 + V2 + V3) * 0.10;
                printf("Van a pagar %d\n", SB + comision);
                getchar();
                break;
            }

            case 3: {
                getchar();
                float nota1;
                float nota2;
                float nota3;
                float notafinal;
                printf("Ingrese la nota 1: ");
                scanf("%f", &nota1);
                printf("Ingrese la nota 2: ");
                scanf("%f", &nota2);
                printf("Ingrese la nota 3: ");
                scanf("%f", &nota3);
                notafinal = (nota1 * 0.55) + (nota2 * 0.30) + (nota3 * 0.15);
                printf("Su nota es %f\n", notafinal);
                break;
            }

            case 4: {
                int a;
                int b;
                printf("Ingrese qué numero quiere empezar: ");
                scanf("%d", &a);
                printf("Ingrese hasta qué numero quiere llegar: ");
                scanf("%d", &b);
                if ((a % 2) != 0) {
                    a = a - 1;
                }
                for (a; a <= b; a = a + 2) {
                    printf("%d  ", a);
                }
                printf("\n");
                break;
            }

            case 5: {
                int dis = 150 - 70;
                int vm1;
                int te;
                printf("Ingrese velocidad de los autos (km/h): ");
                scanf("%d", &vm1);
                te = dis / vm1;
                printf("Se van a encontrar en el kilometro %d\n", 70 + (vm1 * te));
                break;
            }
        }
        getchar();
        getchar(); 
        system("cls");
    }
    return 0;
}
