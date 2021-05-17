#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOTEBOOK 3
float aplicarDescuento(float precioProducto);

int contarCaracteres(char cadena[], char caracterABuscar);

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;


int ordenarArray(eNotebook notebook[], int tamNotebook);

int main()
{
    char cad[20] = "Hola como estas";
    eNotebook notebooks[3] =
    {
      {0, "3100", "Intel", 350.50},
      {1, "3200", "Intel", 400},
      {2, "9100", "AMD" , 250}
    };

    //Punto 1
    printf("Punto 1: %.2f\n", aplicarDescuento(20));

    //Punto 2
    printf("\nPunto 2: %d\n",contarCaracteres(cad, 'o'));

    //Punto 3
    ordenarArray(notebooks, TAMNOTEBOOK);
    printf("\nLista de notebooks:\n");
    printf("ID  PROCESADOR      MARCA   PRECIO\n");
    for(int i = 0; i < TAMNOTEBOOK; i++)
    {
        printf("%d   %10s %10s   %5.2f\n", notebooks[i].id, notebooks[i].procesador,notebooks[i].marca, notebooks[i].precio);
    }

    system("pause");
    return 0;
}


float aplicarDescuento(float precioProducto)
{
    float precioConDescuento = precioProducto;

    precioConDescuento = (precioProducto * 0.05) + (precioProducto);

    return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracterABuscar)
{
    int contador = 0;

    int tam = strlen(cadena);

    for(int i = 0; i < tam; i++)
    {
        if(cadena[i] == caracterABuscar)
        {
            contador++;
        }
    }
    return contador;
}

int ordenarArray(eNotebook notebook[], int tamNotebook)
{
    eNotebook auxNotebook;

    for(int i = 0; i < tamNotebook - 1; i++)
    {
        for(int j = i + 1; j < tamNotebook; j++)
        {
            //Muestro la marca de la A-Z y despues muestro los precios del Menor a Mayor
            if( (strcmp(notebook[i].marca, notebook[j].marca)) > 0 || (strcmp(notebook[i].marca, notebook[j].marca) == 0 && (notebook[i].precio > notebook[j].precio)) )
            {
                auxNotebook = notebook[i];
                notebook[i] = notebook[j];
                notebook[j] = auxNotebook;
            }
        }
    }

    return 0;
}
