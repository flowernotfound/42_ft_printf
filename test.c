#include <stdio.h>

int main (void)
{
	int a = 123;
	int count = 0;
	char *s = "Hello";
	count = printf("[%10c]\n", 'a');

	printf("%d\n", count);
	return (0);
}
