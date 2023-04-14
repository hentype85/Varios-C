#include <stdio.h>

/* sumar diagonales */

void print_diagsums(int *a, int size) {

   int i = 0, j = 0, sum1 = 0, sum2 = 0;
   

   for (i = 0; i < size; i++) 
   {
       for (j = 0; j < size; j++) {
           
           if(i == j)
                    sum1 += a[(i * size) + j];
                    
           if (i + j == size - 1)
                    sum2 += a[(i * size) + j];
       }
   }

   printf("%d, %d\n",sum1,sum2);
   
   printf("\n");
   
   for (i = 0; i < size; i++)
   {
       for (j = 0; j < size; j++) 
       {
           printf("(%d,%d)",i,j);
       }
       printf("\n");
   }
   
   printf("\n---------------------------------\n");
}


int main(void)
{
    int c3[3][3] = {
        {0, 1, 5},
        {10, 11, 12},
        {1000, 101, 102},
    };
    int c5[5][5] = {
        {0, 1, 5, 12124, 1234},
        {10, 11, 12, 123521, 12512},
        {1000, 101, 102, 12545, 214543435},
        {100, 1012451, 11102, 12545, 214543435},
        {10, 12401, 10452, 11542545, 1214543435},
    };
    
    print_diagsums((int *)c3, 3);
    print_diagsums((int *)c5, 5);
    return (0);
}
