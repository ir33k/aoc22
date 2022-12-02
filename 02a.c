#include <stdio.h>
#include <err.h>

#define BSIZ    8		/* Buffer size */

enum shape { ROCK, PAPER, SCISSORS };
enum score_shape {
	SCORE_ROCK     = 1,
	SCORE_PAPER    = 2,
	SCORE_SCISSORS = 3
};
enum score_res {
	SCORE_LOST     = 0,
	SCORE_DRAW     = 3,
	SCORE_WON      = 6
};

enum shape
parse(char c)
{
	switch (c) {
	case 'A':
	case 'X':
		return ROCK;
	case 'B':
	case 'Y':
		return PAPER;
	case 'C':
	case 'Z':
		return SCISSORS;
	}
	errx(1, "Invalid shape '%c'", c);
}

enum score_shape
score_shape(enum shape s)
{
	switch (s) {
	case ROCK:     return SCORE_ROCK;
	case PAPER:    return SCORE_PAPER;
	case SCISSORS: return SCORE_SCISSORS;
	}
	errx(1, "Invalid shape '%c'", s);
}

enum score_res
score_res(enum shape p1, enum shape p2)
{
	if (p1 == p2) {
		return SCORE_DRAW;
	}
	if (p1 == ROCK) {
		return p2 == PAPER ? SCORE_WON : SCORE_LOST;
	}
	if (p1 == PAPER) {
		return p2 == SCISSORS ? SCORE_WON : SCORE_LOST;
	}
	if (p1 == SCISSORS) {
		return p2 == ROCK ? SCORE_WON : SCORE_LOST;
	}
	errx(1, "Unhandled case of %d vs %d", p1, p2);
}

int
main(int argc, char **argv)
{
	char buf[BSIZ];
	FILE *fp = stdin;
	enum shape p1, p2;	/* Player 1 and 2 shape */
	int score = 0;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
	}
	while (fgets(buf, BSIZ, fp)) {
		p1 = parse(buf[0]);
		p2 = parse(buf[2]);
		score += score_shape(p2);
		score += score_res(p1, p2);
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", score);
	return 0;
}
