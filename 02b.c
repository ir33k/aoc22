#include <stdio.h>
#include <err.h>

#define BSIZ    8		/* Buffer size */

enum { ROCK = 0, PAPER, SCISSORS, LOST, DRAW, WON };
int score[] = { 1, 2, 3, 0, 3, 6 }; /* Match enum */

/* Parse C char (A,B,C) to shape of ROCK, PAPER or SCISSORS. */
int
parse_shape(char c)
{
	return c - 'A';
}

/* Parse C char (X,Y,Z) to outcome of LOSE, DRAW or WON. */
int
parse_out(char c)
{
	return c - 'X' + LOST;	/* Add LOST offset from enum */
}

/* With given outcome OUT and first player shape P1 return proper
 * shape for second player that match OUT. */
int
out2shape(int out, int p1)
{
	switch (out) {
	case LOST: return (p1 + 2) % 3;
	case WON:  return (p1 + 1) % 3;
	}
	return p1;		/* DRAW */
}

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
		p1 = parse_shape(buf[0]);
		out = parse_out(buf[2]);
		res += score[out] + score[out2shape(out, p1)];
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", res);
	return 0;
}
