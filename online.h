/* A: What is my purpose?
 * B: You pass lines.
 * A: Oh my god!
 * B: Yea, welcome to the club pal.
 *
 * Template for programs that goes over each file line.  By default
 * standard input is used but if path to file is provided as first
 * program argument then this file will be used instead.
 *
 * When template is used then MAIN function is predefined.  User has
 * to define ONLINE and ONEND functions.  First is called each time
 * line from file is read and takes one argument that is pointer to
 * current line being null terminated string without end '\n'.  Second
 * is called once when all lines has been read and takes no arguments.
 * Program will exit with 1 if there is any problem with file. */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>		/* Not used, left for convenience */

/* Predefine BSIZ if you need more than default BUFSIZ of stdio.h for
 * reading input stream lines. */
#ifndef BSIZ
#define BSIZ	BUFSIZ
#endif

void online(char *line);
void onend(void);

/* Stolen from https://git.suckless.org/dwm/file/util.c.html */
void die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

int main(int argc, char **argv)
{
	size_t len;
	char buf[BSIZ];
	FILE *fp = stdin;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
		die("fopen:");
	}
	while (fgets(buf, BSIZ, fp)) {
		len = strlen(buf);
		/* String could actually end right on BSIZ limit but
		 * with this condition I'm making whole thing simpler
		 * by loosing only one potential character. */
		if (len == BSIZ-1) {
			die("Line longer than BSIZ, read doc");
		}
		if (buf[len-1] == '\n') {
			buf[len-1] = 0;
		}
		online(buf);
	}
	onend();
	if (fp != stdin && fclose(fp) == EOF) {
		die("fclose:");
	}
	return 0;
}
