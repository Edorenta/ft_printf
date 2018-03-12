#include "include/ft_printf.h"
#include "benchmark/include/printf.h"
#include <stdio.h>

int main()
{
	int a = -10;
	char b[100] = "hello there!\0";
	double c = 100000;
	void *x;
	const char * restrict input =
	"it works !! %o#\n";
	printf(input, a);
	bench_printf(input, a);
	ft_printf(input, a);
	return 0;
}
