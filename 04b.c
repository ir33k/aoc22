#include <stdio.h>

int
main(void)
{
	char line[BUFSIZ];
	int res=0, a0, a1, b0, b1;

	while (fgets(line, BUFSIZ, stdin)) {
		sscanf(line, "%d-%d,%d-%d", &a0, &a1, &b0, &b1);
		if ((a0 <= b0 && a1 >= b0) ||
		    (b0 <= a0 && b1 >= a0)) {
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
