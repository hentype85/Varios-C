#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define H 10
#define V 10

void drawMap(char map[V][H])
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < H; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void clearScreen()
{
    printf("\033[H\033[J");
    fflush(stdout);
}

char getchNolineBreak()
{
    /*funcion para leer una tecla sin esperar un salto de linea*/
    struct termios oldattr, newattr;
    char ch;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return (ch);
}

int main(void)
{
    /*matriz*/
    char map[V][H] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    /*coordenadas iniciales*/
    int headX = H / 2;
    int headY = V / 2;
    int keyPressed;

    while (1)
    {
        clearScreen();

        /*actualizar posicion del punto(cabeza) en el mapa*/
        map[headY][headX] = '*';
        drawMap(map);
        map[headY][headX] = ' ';

        /*capturar tecla*/
        keyPressed = getchNolineBreak();

        switch (keyPressed)
        {
        case 65: /*control de colision y movimiento*/
            if (headY > 1)
                headY--;
            break;
        case 68: 
            if (headX > 1)
                headX--;
            break;
        case 66: 
            if (headY < V - 2)
                headY++;
            break;
        case 67:
            if (headX < H - 2)
                headX++;
            break;
        }

        if (keyPressed == 'z')
            break;
    }

    return 0;
}
