#include <stdio.h>

int main(void)
{
	int i;
	char a[] = "Fizz";
	char b[] = "Buzz";
	char c[] = "FizzBuzz";

	for (i = 1 ; i <= 100 ; i++)
	{
		if (i == 100)
			printf("%s", b);
		else if (i % 15 == 0)
			printf("%s ", c);
		else if (i % 3 == 0)
			printf("%s ", a);
		else if (i % 5 == 0)
			printf("%s ", b);
		else
			printf("%i ", i);
	}

	printf("\n");

	return (0);
}
