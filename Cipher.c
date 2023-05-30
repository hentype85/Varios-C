#include <stdio.h>
#include <stdlib.h>

void cifrarCesar(char *mensaje, int clave)
{
    int i = 0;

    while (mensaje[i] != '\0') 
    {
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z') 
        {
          mensaje[i] = ((mensaje[i] - 'a' + clave) % 26) + 'a';
        }
        else if (mensaje[i] >= 'A' && mensaje[i] <= 'Z') 
        {
          mensaje[i] = ((mensaje[i] - 'A' + clave) % 26) + 'A';
        }

        i++;
    }
}

int main(void)
{
    char mensaje[100];
    int clave;

    printf("Ingrese el mensaje a cifrar: ");
    scanf("%s", mensaje);

    printf("Ingrese la clave de cifrado: ");
    scanf("%d", &clave);

    cifrarCesar(mensaje, clave);

    printf("Mensaje cifrado: %s\n", mensaje);

    return (0);
}
