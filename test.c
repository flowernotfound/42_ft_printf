#include <stdio.h>

int main (void)
{
	printf("%d\n", 123);
	printf("%i\n", 123);

	char *p = "hello";
	int i = 0;

	printf("%c\n", p[i]);
	printf("%c\n", i[p]);
	i++;
	return (0);
}
