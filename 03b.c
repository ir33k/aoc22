#include <stdio.h>
#include <string.h>

int
cvalue(char c)
{
	return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27;
}

int
main(void)
{
	char line[BUFSIZ];
	int res=0, i=0;
	char lines[2][BUFSIZ];

	while (fgets(line, BUFSIZ, stdin)) {
		if (i != 2) {
			/* Collect previous 2 lines. */
			strcpy(lines[i++], line);
			continue;
		}
		/* Treat LINE as pointer to single char. */
		for (i = 0; line[i]; i++) {
			if (strchr(lines[0], line[i]) &&
			    strchr(lines[1], line[i])) {
				res += cvalue(line[i]);
				break;
			}
		}
		i = 0;
	}
	printf("%d\n", res);
	return 0;
}
