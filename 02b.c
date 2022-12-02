#include <stdio.h>
#include <err.h>

#define BSIZ    8		/* Buffer size */

int
main(int argc, char **argv)
{
	char buf[BSIZ];
	FILE *fp = stdin;
	int res = 0, p1, out;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
		err(1, NULL);
	}
	while (fgets(buf, BSIZ, fp)) {
		p1   = buf[0] - 'A'; /* Player1 shape number */
		out  = buf[2] - 'X'; /* Outcome number */
		res += out * 3;	     /* Outcome score */
		res += (p1 + 2 + out) % 3 + 1; /* Player2 shape score */
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", res);
	return 0;
}
