#include <stdio.h>
#include <stdlib.h>

#define SIZ	2056		/* Max number of Elfs */

int
main(int argc, char **argv)
{
	size_t i, arri = 0;
	unsigned long int arr[SIZ] = {0}, max[3] = {0};
	char buf[BUFSIZ];
	FILE *fp = stdin;

	if (argc > 1 && (fp = fopen(argv[1], "rb")) == NULL) {
		perror("fopen");
		return 1;
	}
	while (fgets(buf, BUFSIZ, fp)) {
		if (buf[0] != '\n') {
			arr[arri] += atoi(buf);
			continue;
		}
		arri++;
		if (arri > SIZ) {
			fprintf(stderr, "SIZ too small");
			return 1;
		}
	}
	if (fp != stdin && fclose(fp) == EOF) {
		perror("fclose");
		return 1;
	}
	for (i = 0; i <= arri; i++) {
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
