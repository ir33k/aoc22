#include <stdio.h>
#include <err.h>

#define BSIZ    8		/* Buffer size */

int
main(int argc, char **argv)
{
	char buf[BSIZ];
	FILE *fp = stdin;
	int p1, p2, out, res = 0;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
		err(1, NULL);
	}
	while (fgets(buf, BSIZ, fp)) {
		p1   = buf[0] - 'A';	  /* Player1 shape number */
		p2   = buf[2] - 'X';	  /* Player2 shape number */
		res += p2 + 1;		  /* Player2 score */
		out  = (p1 - p2 + 2) % 3; /* Outcome number */
		res += out ? 6/out : 0;	  /* Outcome score */
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", res);
	return 0;
}
