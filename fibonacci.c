#include <stdio.h>

int main (void)
{
  int a = 0, b = 1;
  int i = 0;

  for(i = 0 ; i < 5; i++)
  {
    printf("%d ",a);
    printf("%d ",b);

    a += b;
    b += a;
  }
  
  return 0;
}
