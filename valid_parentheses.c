#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*pila para almacenar los parantesis y corchetes abiertos*/
typedef struct stack_s
{
    char c;
    struct stack_s* next;
} stack_t;

/*verificar si la pila esta vacia*/
bool isEmpty(stack_t* stack)
{
    return (stack == NULL); /*true or false*/
}

/*insertar un elemento en la pila*/
void push(stack_t** stack, char element)
{
    stack_t *newNode = (stack_t*)malloc(sizeof(stack_t));
    if (newNode == NULL)
        exit(EXIT_FAILURE);

    newNode->c = element;
    newNode->next = *stack;

    *stack = newNode;
}

/*eliminar un elemento de la pila*/
char pop(stack_t** stack)
{
    char element;
    stack_t *temp = NULL;

    if (isEmpty(*stack))
    {
        printf("Error: pila vacia.\n");
        exit(EXIT_FAILURE);
    }

    element = (*stack)->c;
    temp = *stack;

    *stack = (*stack)->next;

    free(temp);
    return element;
}

/*verificar si los parentesis y corchetes estan correctamente cerrados*/
bool verifica(char* cadena) 
{
    stack_t *stack = NULL;
    int i = 0;

    while (cadena[i] != '\0') 
    {
        if (cadena[i] == '(' || cadena[i] == '{') 
        {
            push(&stack, cadena[i]);
        } 
        else if (cadena[i] == ')' || cadena[i] == '}') 
        {
            if (isEmpty(stack))
                return (0);
            if (cadena[i] == ')' && pop(&stack) != '(' || cadena[i] == '}' && pop(&stack) != '{')
                return (0);
        }

        i++;
    }

    return isEmpty(stack);
}

int main(void)
{
    char cadena[100];

    printf("ingrese una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);

    if (verifica(cadena) != 0)
        printf("cerrados\n");
    else 
        printf("No cerrados\n");

    return (0);
}
