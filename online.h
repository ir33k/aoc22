/* D: What is my purpose?
 * R: You pass lines.
 * D: Oh my god!
 * R: Yea, welcome to the club pal.
 *
 * Predefine MAIN function for programs that goes over each STDIN
 * line.  Define ONELINE function, called with each line, being null
 * terminated string without end '\n'.  Define ONEND function, called
 * once at the end of stdin. */
#include <stdio.h>
#include <string.h>

#ifndef BSIZ			/* Predefine BSIZ if needed */
#define BSIZ	BUFSIZ		/* LINE max buffer size */
#endif

void online(char *line);	/* Called on each STDIN line */
void onend(void);		/* Called once at the end of STDIN */

int main(void)
{
	char line[BSIZ];	/* Current STDIN line */
	size_t len;		/* LINE length */

	while (fgets(line, BSIZ, stdin) && (len = strlen(line))) {
		if (len >= BSIZ-2) {
			fputs("BSIZ is too small, read doc\n", stderr);
			return 1;
		}
		if (len && line[len-1] == '\n') {
			line[--len] = 0;
		}
		online(line);
	}
	onend();
	return 0;
}
