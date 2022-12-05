#include "online.h"

int res=0, a0, a1,  b0, b1;

void online(char *line)
{
	sscanf(line, "%d-%d,%d-%d", &a0, &a1, &b0, &b1);
	if ((a0 <= b0 && a1 >= b0) ||
	    (b0 <= a0 && b1 >= a0)) {
		res++;
	}
}
void onend()
{
	printf("%d\n", res);
}
