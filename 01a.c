#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define SIZ	1024		/* Max number of Elfs */

int
main(int argc, char **argv)
{
	size_t i = 0;
	int arr[SIZ] = {0}, max = 0;
	char buf[BUFSIZ];
	FILE *fp = stdin;

	if (argc > 1 && !(fp = fopen(argv[1], "rb"))) {
		err(1, NULL);
	}
	while (fgets(buf, BUFSIZ, fp)) {
		if (buf[0] != '\n') {
			arr[i] += atoi(buf);
			continue;
		}
		if (++i > SIZ-1) {
			errx(1, "SIZ too small");
		}
	}
	if (fp != stdin && fclose(fp) == EOF) {
		err(1, NULL);
	}
	for (; i; i--) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("%d\n", max);
	return 0;
}
