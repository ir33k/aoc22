#include <stdio.h>
#include <err.h>

#define BSIZ    8		/* Buffer size */

enum { ROCK = 0, PAPER, SCISSORS, LOST, DRAW, WON };
int score[] = { 1, 2, 3, 0, 3, 6 };

int
parse(char c)
{
	switch (c) {
	case 'A': case 'X': return ROCK;
	case 'B': case 'Y': return PAPER;
	case 'C': case 'Z': return SCISSORS;
	}
	errx(1, "Invalid shape '%c'", c);
}

int
outcom(int p1, int p2)
{
	if (p1 == p2) return DRAW;

	if ((p1 == ROCK     && p2 == PAPER)    ||
	    (p1 == PAPER    && p2 == SCISSORS) ||
	    (p1 == SCISSORS && p2 == ROCK))
		return WON;

	return LOST;
}

int
main(int argc, char **argv)
{
	char buf[BSIZ];
	FILE *fp = stdin;
	int p1, p2, res = 0; /* Player 1, 2 shape, and final result */

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
	}
	while (fgets(buf, BSIZ, fp)) {
		p1 = parse(buf[0]);
		p2 = parse(buf[2]);
		res += score[p2];
		res += score[outcom(p1, p2)];
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", res);
	return 0;
}
