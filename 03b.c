#include "online.h"

enum { FOUND = -1 };
int res = 0, i = 0, j;
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
	for (i = 0; line[i]; i++) {
		for (j = 0; lines[0][j]; j++) {
			if (line[i] != lines[0][j]) {
				continue;
			}
			for (j = 0; lines[1][j]; j++) {
				if (line[i] != lines[1][j]) {
					continue;
				}
				res += cvalue(line[i]);
				j = FOUND;
				break;
			}
			break;
		}
		if (j == FOUND) {
			break;
		}
	}
	i = 0;
}
void onend()
{
	printf("%d\n", res);
}
