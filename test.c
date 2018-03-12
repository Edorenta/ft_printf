#include "include/ft_printf.h"
#include <stdio.h>

int main()
{
	int a = -10;
	char b[100] = "hello there!\0";
	double c = 100000;
	void *x;
	const char * restrict input =
	"it works !! %s\n";
	printf(input, b);
	ft_printf(input, b);
	return 0;
}
