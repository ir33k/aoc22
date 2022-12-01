#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define SIZ	1024		/* Max number of Elfs */

int
main(int argc, char **argv)
{
	int i = 0;
	unsigned long int arr[SIZ] = {0}, max[3] = {0};
	char buf[BUFSIZ];
	FILE *fp = stdin;

	if (argc > 1 && (fp = fopen(argv[1], "rb")) == NULL) {
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
		if (arr[i] > max[0]) {
			max[2] = max[1];
			max[1] = max[0];
			max[0] = arr[i];
			continue;
		}
		if (arr[i] > max[1]) {
			max[2] = max[1];
			max[1] = arr[i];
			continue;
		}
		if (arr[i] > max[2]) {
			max[2] = arr[i];
			continue;
		}
	}
	printf("%lu\n", max[0] + max[1] + max[2]);
	return 0;
}
