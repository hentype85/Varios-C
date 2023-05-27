#include <stdio.h>
/*
Burbuja: Consiste en comparar pares de elementos adyacentes e intercambiarlos 
entre sí hasta que estén todos ordenados. Con el array anterior, {40,21,4,9,10,35}:

Primera pasada:
{21,40,4,9,10,35} <-- Se cambia el 21 por el 40.
{21,4,40,9,10,35} <-- Se cambia el 40 por el 4.
{21,4,9,40,10,35} <-- Se cambia el 9 por el 40.
{21,4,9,10,40,35} <-- Se cambia el 40 por el 10.
{21,4,9,10,35,40} <-- Se cambia el 35 por el 40.

Segunda pasada:
{4,21,9,10,35,40} <-- Se cambia el 21 por el 4.
{4,9,21,10,35,40} <-- Se cambia el 9 por el 21.
{4,9,10,21,35,40} <-- Se cambia el 21 por el 10.

Ya están ordenados, pero para comprobarlo habría que acabar esta segunda 
comprobación y hacer una tercera.

Si el array tiene N elementos, para estar seguro de que el array está ordenado, 
hay que hacer N-1 pasadas, por lo que habría que hacer (N-1)*(N-i-1) comparaciones, 
para cada i desde 1 hasta N-1. El número de comparaciones es, por tanto, N(N-1)/2, 
lo que nos deja un tiempo de ejecución, al igual que en la selección, en O(n2).
*/

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