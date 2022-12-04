#include "online.h"

int res = 0, i, j, len, half;
char sign;			/* Only for convenience */

void online(char *line)
{
	len = strlen(line);
	half = len/2;
	for (i = 0; i < half; i++) {
		sign = line[i];
		for (j = half; j < len; j++) {
			if (sign != line[j]) {
				continue;
			}
			if (sign >= 'a' && sign <= 'z') {
				res += sign - 'a' + 1;
			} else {
				res += sign - 'A' + 27;
			}
			/* Replace all instances of already found SIGN
			 * with '_' to avoid duplicates.  We want to
			 * cound each sign only once. */
			for (; j < len; j++) {
				if (sign == line[j]) {
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
