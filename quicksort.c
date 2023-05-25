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

int partition(int *array, int inicio,  int fin, size_t size)
{
    int i = inicio;
    int j = i - 1; 
    int aux = 0;
    int pivot = array[fin];

    while (i < fin)
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
        i++;
    }

    j++;
    if (array[j] != array[fin])
    {
        aux = array[j];
        array[j] = array[fin];
        array[fin] = aux;

        print_array(array, size);
    }

    return (j);
}

void quick_s(int *array, int inicio, int fin, size_t size)
{
    int pivot;

    if (inicio < fin)
    {
        pivot = partition(array, inicio, fin, size);

        /*llamada recursiva a quick_s para ordenar la parte izquierda del pivote*/
        quick_s(array, inicio, pivot - 1, size);
        /*llamada recursiva a quick_s para ordenar la parte derecha del pivote*/
        quick_s(array, pivot + 1, fin, size);
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