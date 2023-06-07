#include <stdio.h>
#include <unistd.h>

int _putchar(char c)
{
    write(1,&c,1);
}

void triangles()
{
    int i , j , k, x, size = 10;
    
    for (int i = 0; i < size; i++)
    {
        /*cuadrado*/
        for(j = 0 ; j <= size * 2 ; j++)
        {
            _putchar('-');
        }
        
        /*triangulo invertido izquierda*/
        for (int x = 0; x < size - i; x++) {
             _putchar('-');
        }
        
        /*triangulo izquierda*/
        for (int j = 0; j < i ; j++) {
             _putchar('+');
        }
        
        /*triangulo derecha*/
        for (int k = 0; k < i ; k++) {
             _putchar('+');
        }
        
        /*cuadrado*/
        for(j = 0 ; j <= size * 2; j++)
        {
            _putchar('-');
        }
        
        //triangulo invertido derecha
        for (int x = 0; x < size - i; x++) {
             _putchar('-');
        }
        
        _putchar('\n');
    }
    
    for (int i = 0; i < size; i++)
    {
        /*triangulo invertido izquierda*/
        for (int x = 0; x < size - i; x++) {
             _putchar('-');
        }
        
        /*triangulo izquierda*/
        for (int j = 0; j < i ; j++) {
             _putchar('-');
        }
        
        /*triangulo invertido derecha*/
        for (int x = 0; x < size - i; x++) {
             _putchar('-');
        }
        
        /*triangulo invertido derecha*/
        for (int x = 0; x < i + 1; x++) {
             _putchar('+');
        }
        
        /*triangulo izquierda*/
        for (int j = 0; j < i ; j++) {
             _putchar('+');
        }
        
        /*triangulo invertido izquierda*/
        for (int x = 0; x < size - i; x++) {
             _putchar('0');
        }
        
        /*triangulo invertido derecha*/
        for (int x = 0; x < size - i; x++) {
             _putchar('0');
        }
        
        /*triangulo izquierda*/
        for (int j = 0; j < i ; j++) {
             _putchar('+');
        }
        
        /*triangulo derecha*/
        for (int x = 0; x < i + 1; x++) {
             _putchar('+');
        }
        
        /*triangulo invertido derecha*/
        for (int x = 0; x < size - i; x++) {
             _putchar('-');
        }
        
        /*cuadrado*/
        for(j = 0 ; j <= size; j++)
        {
            _putchar('-');
        }
        _putchar('\n');
    }
}

int main(void)
{
    triangles();
    return (0);
}
