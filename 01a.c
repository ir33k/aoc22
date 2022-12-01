#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(int argc, char **argv)
{
	int cur = 0, max = 0;
	char buf[BUFSIZ];
	FILE *fp = stdin;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
		err(1, NULL);
	}
	while (fgets(buf, BUFSIZ, fp)) {
		if (buf[0] == '\n') {
			cur = 0;
		} else if ((cur += atoi(buf)) > max) {
			max = cur;
		}
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	printf("%d\n", max);
	return 0;
}
