#include <stdio.h>

int
main(void)
{
	char line[BUFSIZ];
	int res = 0, p1, out;

	while (fgets(line, BUFSIZ, stdin)) {
		p1   = line[0] - 'A';	       /* Player1 shape number */
		out  = line[2] - 'X';	       /* Outcome number */
		res += out * 3;		       /* Outcome score */
		res += (p1 + 2 + out) % 3 + 1; /* Player2 shape score */
	}
	printf("%d\n", res);
	return 0;
}
