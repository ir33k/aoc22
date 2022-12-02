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
	case 'A': return ROCK;
	case 'B': return PAPER;
	case 'C': return SCISSORS;
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
score_res(char c)
{
	switch (c) {
	case 'X': return SCORE_LOST;
	case 'Y': return SCORE_DRAW;
	case 'Z': return SCORE_WON;
	}
	errx(1, "Invalid outcome '%c'", c);
}

enum score_shape
score_res_shape(enum score_res res, enum shape p1)
{
	switch (res) {
	case SCORE_LOST:
		switch (p1) {
		case ROCK:     return SCORE_SCISSORS;
		case PAPER:    return SCORE_ROCK;
		case SCISSORS: return SCORE_PAPER;
		}
	case SCORE_DRAW:
		return score_shape(p1);
	case SCORE_WON:
		switch (p1) {
		case ROCK:     return SCORE_PAPER;
		case PAPER:    return SCORE_SCISSORS;
		case SCISSORS: return SCORE_ROCK;
		}
	}
	errx(1, "Invalid res '%c'", res);
}

int
main(int argc, char **argv)
{
	char buf[BSIZ];
	FILE *fp = stdin;
	enum shape p1;		/* Player 1 shape */
	enum score_res res;
	int score = 0;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
	}
	while (fgets(buf, BSIZ, fp)) {
		p1 = parse(buf[0]);
		res = score_res(buf[2]);
		score += res;
		score += score_res_shape(res, p1);
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", score);
	return 0;
}
