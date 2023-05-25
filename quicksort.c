#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

int partition(int *array, int izq,  int der, size_t size)
{
    int i = izq;
    int j = i - 1; 
    int aux = 0;

    int pivot  = array[der];

    for (i ; i < der ; i++)
    {
        if (array[i] < pivot)
        {
            j++;

            if (array[j] != array[i])
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;

                print_array(array, size);
            }
        }
    }

    j++;

    if (array[j] != array[der])
    {
        aux = array[j];
        array[j] = array[der];
        array[der] = aux;

        print_array(array, size);
    }

    return (j);
}

void quick_s(int *array, int izq, int der, size_t size)
{
    int pivot;

    if (izq < der)
    {
        pivot = partition(array, izq, der, size);

        quick_s(array, izq, pivot - 1, size); /*indice derecha del final hasta principio*/
        quick_s(array, pivot + 1, der, size); /*indice izquierda del principio al final*/
    }
}

void quick_sort(int *array, size_t size)
{
	quick_s(array, 0, size - 1, size); /*size - 1 para controlar el indice del arreglo*/
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
