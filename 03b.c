#include "online.h"

int res=0, i=0;
char lines[2][BSIZ];

int cvalue(char c)
{
	return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27;
}
void online(char *line)
{
	if (i != 2) {
		/* Collect previous 2 lines. */
		strcpy(lines[i++], line);
		return;		/* Continue online */
	}
	i = 0;
	/* Treat LINE as pointer to single char. */
	for (; *line; line += 1) {
		if (strchr(lines[0], *line) &&
		    strchr(lines[1], *line)) {
			res += cvalue(*line);
			break;
		}
	}
}
void onend()
{
	printf("%d\n", res);
}
