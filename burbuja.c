#include <stdio.h>

int main(void)
{
    int vector[10] = {10, 2, 3, 35, 4, 7 ,8 ,11, 36, 6};
    int aux;

   /* imprimir vector desordenado */
    for (int i = 0; i < sizeof(vector) / sizeof(int); i++)
    {
        printf("%d ",vector[i]);
    }
    printf("\n");

    /* método de ordenamiento burbuja */
    for (int i = 0; i < 10 ; i++)
    {
        for (int j = 0; j < 9 ; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }

    /* imprimir vector ordenado */
    for (int i = 0; i < sizeof(vector) / sizeof(int); i++)
    {
        printf("%d ",vector[i]);
    }
    printf("\n");

    return (0);
}
