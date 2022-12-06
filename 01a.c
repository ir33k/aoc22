#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	char line[BUFSIZ];
	int cur, max=0;

	while (fgets(line, BUFSIZ, stdin)) {
		if (line[0] == '\n') {
			cur = 0;
		} else if ((cur += atoi(line)) > max) {
			max = cur;
		}
	}
	printf("%d\n", max);
	return 0;
}
