#include "online.h"

int res = 0, i, j, half;

int cvalue(char c)
{
	return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27;
}
void online(char *line)
{
	half = strlen(line)/2;
	for (i = 0; i < half; i++) {
		for (j = half; line[j]; j++) {
			if (line[i] != line[j]) {
				continue;
			}
			res += cvalue(line[i]);
			/* Replace all instances of already found SIGN
			 * with '_' to avoid duplicates.  We want to
			 * cound each sign only once. */
			for (; line[j]; j++) {
				if (line[i] == line[j]) {
					line[j] = '_';
				}
			}
		}
	}
}
void onend()
{
	printf("%d\n", res);
}
