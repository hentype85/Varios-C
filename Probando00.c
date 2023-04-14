#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define RED printf("\033[0;31m");
#define BLUE printf("\033[0;34m");
#define GREEN printf("\033[0;32m");
#define RESET printf("\033[0m");

typedef struct sFunc
{
    int id;
    int (*f)(va_list);
}newSfun;


int printChar(va_list vl)
{
	char c = va_arg(vl, int);
	write(1, &c, 1);
	return (1);
}

int printString(va_list s)
{
	char *c = va_arg(s, char *);
	int i = 0;

	if (c != NULL)
	{
		for (i = 0; c[i] ; i++)
		{
			write(1, &c[i], 1);
		}
	}
	else
	{
	   write(1,"(null)",6);
	   return (6);
	}
	
   return (i);
}

int printInteger(va_list c)
{
    long int n = va_arg(c, int);
    char buffer[20];
    int i = 0;
    int count = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        count++;
    }
  
    if (n < 0) 
    {
        write(1,"-",1);
        n *= -1;
        count++;
    }

    while (n > 0) 
    {
        buffer[i] = n % 10 + '0';
        n /= 10;
        
        count++;
        i++;
    }

    i--;
    while (i >= 0) 
    {
        write(1,&buffer[i],1);
        i--;
    }

    return (count);
}

int printUnsigned(va_list c)
{
   unsigned int n = va_arg(c, int);
   char buffer[20];
   int i = 0;
   int count = 0;

   if (n == 0)
   {
     write(1, "0", 1);
     count++;
   }

   while (n > 0) 
   {
      buffer[i] = n % 10 + '0';
      n /= 10;
        
      count++;
      i++;
   }
   i--;
    
   while (i >= 0) 
   {
     write(1,&buffer[i],1);
     i--;
     count++;
   }
    
   return (count);
}

int printOctal(va_list c)
{
   unsigned int n = va_arg(c, int);
   char buffer[20];
   int i = 0;
   int count = 0;

   if (n == 0)
   {
     write(1, "0", 1);
     count++;
   }

   while (n > 0) 
   {
      buffer[i] = n % 8 + '0';
      n /= 8;
        
      count++;
      i++;
   }
   i--;
    
   while (i >= 0) 
   {
     write(1,&buffer[i],1);
     i--;
     count++;
   }
    
   return (count);
}

int printHexadecimalUpper(va_list c)
{
   unsigned int n = va_arg(c, int);
   char buffer[20];
   int i = 0;
   int count = 0;

   if (n == 0)
   {
     write(1, "0", 1);
     count++;
   }

   while (n > 0) 
   {
      int h = n % 16;
      
      if (h < 10) 
            buffer[i] = h + '0';
      else if(h < 16)
            buffer[i] = h + ('A' - 10);
            
      n /= 16;
        
      count++;
      i++;
   }
   i--;
    
   while (i >= 0) 
   {
     write(1,&buffer[i],1);
     i--;
     count++;
   }
    
   return (count);
}

int printHexadecimal(va_list c)
{
   unsigned int n = va_arg(c, int);
   char buffer[20];
   int i = 0;
   int count = 0;

   if (n == 0)
   {
     write(1, "0", 1);
     count++;
   }

   while (n > 0) 
   {
      int h = n % 16;
      
      if (h < 10) 
            buffer[i] = h + '0';
      else if(h < 16)
            buffer[i] = h + ('a' - 10);
            
      n /= 16;
        
      count++;
      i++;
   }
   i--;
    
   while (i >= 0) 
   {
     write(1,&buffer[i],1);
     i--;
     count++;
   }
    
   return (count);
}

int (*get_op_func(char c))(va_list)
{
    int i = 0;
    newSfun arr[] = {
        {'c', printChar},
        {'i', printInteger},
        {'d', printInteger},
        {'s', printString},
        {'u', printUnsigned},
        {'o', printOctal},
        {'x', printHexadecimal},
        {'X', printHexadecimalUpper},
        {'\0', NULL}
    };
    
    while (arr[i].id != '\0')
    {
         if(arr[i].id == c)
            return arr[i].f;
         
         i++;
    }
    
    return (NULL);
}

int Checker(char c)
{
	char s[10] = "cidsuoxX";
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	
	return (0);
}

int _printf(const char *format, ...)
{
    va_list vlist;
    int i = 0;
    int count = 0;
    va_start(vlist, format);
    
    if (format == NULL)
        return (-1);
    
    for (i = 0 ; format[i] != '\0' ; i++)
    {
        if(format[i] == '%' && format[i + 1] == '\0')
            return (-1);
         
        if (format[i] == '%')
        {
            i++;
            
            if (format[i] == '%')
            {
               write(1,"%",1);
               count++;
            }
            else
            {
               if (Checker(format[i]) == 0)
               {
                  write(1,"%",1);
                  write(1,&format[i],1);
                  count+=2;
               }
               else if (Checker(format[i]) == 1)
               {
                  count += (*get_op_func(format[i]))(vlist);
               }
            }
        }
        else
        {
            write(1,&format[i],1);
            count++;
        }
    }
    
    va_end(vlist);
    return (count);
}

/*
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
   
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
   _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
   
    return (0);
}

*/
/**
 * output - check expected and obtained code.
 * Return: 0 for success, 1 for error.
 */
 
int output(int a, int b)
{
	printf("\n");
	if (a == b)
	{
		GREEN;
		printf("Success: %d chars printed.", a);
		RESET;
		return (0);
	}
	RED;
	printf("Error: expected %d, obtained %d.", a, b);
	RESET;
	return (1);
}
/**
 * main - test collection for _printf.
 * Return: nothing
 */
 
int main(void)
{
	int a, b, cont = 0;
	BLUE;
	printf("\nTEST WITHOUT ARGUMENTS:\n\n");
	RESET;
	printf("Test 1");
	printf("\nexpected: ");
	a = printf("Buenas Noches America");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("Buenas Noches America");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 2");
	printf("\nexpected: ");
	a = printf(" ");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf(" ");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 3");
	printf("\nexpected: ");
	a = printf("");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 4");
	printf("\nexpected: ");
	a = printf(NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf(NULL);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 5");
	printf("\nexpected: ");
	a = printf("%%");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 6");
	printf("\nexpected: ");
	a = printf("%%s%");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%s%");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 7");
	printf("\nexpected: ");
	a = printf("%%s");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%s");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 8");
	printf("\nexpected: ");
	a = printf("s%%s%%cc");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("s%%s%%cc");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 9");
	printf("\nexpected: ");
	a = printf("%%s%%r%1buelaaaaaas%%s%%%%%%%%%%sali de %k");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%s%%r%1buelaaaaaas%%s%%%%%%%%%%sali de %k");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 10");
	printf("\nexpected: ");
	a = printf("%N&&S%%s%%ID%%");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%N&&S%%s%%ID%%");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 11");
	printf("\nexpected: ");
	a = printf(NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf(NULL);
	cont = cont + output(a,b);
	printf("\n===============\n");
	BLUE;
	printf("\nTEST USING %%c SPECIFIER:\n\n");
	RESET;
	printf("Test 12");
	printf("\nexpected: ");
	a = printf("%%c%c", 'B');
	printf("obtained: ");
	fflush(stdout);
	b = _printf("%%c%c", 'B');
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 13");
	printf("\nexpected: ");
	a = printf("Comiend%c oreja af", 'o');
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("Comiend%c oreja af", 'o');
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 14");
	printf("\nexpected: ");
	a = printf("%c%c%c%c", 'c', 'a', 'c', 'a');
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%c%c%c%c", 'c', 'a', 'c', 'a');
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 15");
	printf("\nexpected: ");
	a = printf("%%c%c%%c", 90);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%c%c%%c", 90);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 16");
	printf("\nexpected: ");
	a = printf("%cantidad inecesaria de texto", 40);
	printf("\nobtained: ");
	fflush(stdout);
	b =_printf("%cantidad inecesaria de texto", 40);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 17");
	printf("\nexpected: ");
	a = printf("%%%%c%%c%c", 90, NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%%%c%%c%c", 90, NULL);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 18");
	printf("\nexpected: ");
	a = printf("%c", NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%c", NULL);
	cont = cont + output(a,b);
	printf("\n===============\n");
	BLUE
		printf("\nTEST USING %%s SPECIFIER:\n");
	RESET;
	printf("Test 19");
	printf("\nexpected: ");
	a = printf("TENGO TREMENDO %s", "CALOOOOOOOOOOR%");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("TENGO TREMENDO %s", "CALOOOOOOOOOOR%");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 20");
	printf("\nexpected: ");
	a = printf("%s", "Perfe%k%t%o%");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%s", "Perfe%k%t%o%");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 21");
	printf("\nexpected: ");
	a = printf("%%%s%%%", "No me quiero ir Sr. Stark :(");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%%%s%%%", "No me quiero ir Sr. Stark :(");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 22");
	printf("\nexpected: ");
	a = printf("%s%c%c%c%c%s", "Pan ", 'c', 'a', 'c', 'a', " Pan");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%s%c%c%c%c%s", "Pan ", 'c', 'a', 'c', 'a', " Pan");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 23");
	printf("\nexpected: ");
	a = printf("D%s Ellia%s", "enis", "s");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("D%s Ellia%s", "enis", "s");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 24");
	printf("\nexpected: ");
	a = printf("%s%", "sabeloko");
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%s%", "sabeloko");
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 25");
	printf("\nexpected: ");
	a = printf("%s", NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%s", NULL);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 26");
	printf("\nexpected: ");
	a = printf("Le dicen %c%c la rompe corazones, %s %s", 'l', 'a', "falsas", NULL);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("Le dicen %c%c la rompe corazones, %s %s", 'l', 'a', "falsas", NULL);
	cont = cont + output(a,b);
	printf("\n===============\n");
	BLUE;
	printf("\nTEST USING %%d or %%i SPECIFIER:\n");
	RESET;
	printf("Test 27");
	printf("\nexpected: ");
	a = printf("%i", 0);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%i", 0);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 28");
	printf("\nexpected: ");
	a = printf("%i", INT_MAX);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%i", INT_MAX);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 29");
	printf("\nexpected: ");
	a = printf("%i", INT_MIN);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%i", INT_MIN);
	cont = cont + output(a,b);
	printf("\n---------------\n");
	printf("Test 30");
	printf("\nexpected: ");
	a = printf("%d %d", INT_MIN + 34, INT_MAX - 33);
	printf("\nobtained: ");
	fflush(stdout);
	b = _printf("%d %d", INT_MIN + 34, INT_MAX - 33);
	cont = cont + output(a,b);
	printf("\n===============\n");
	if (cont == 0)
	{
		GREEN;
		printf ("\n\n30 CASES CHECKED, 0 ERRORS.\n\n");
		RESET;
	}
	else
	{
		RED;
		printf ("\n\n30 CASES CHECKED, %d ERRORS.\n\n", cont);
		RESET;
	}
	return (cont);
}
