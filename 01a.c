#include "online.h"
#include <stdlib.h>

int cur, max = 0;

void online(char *line)
{
	if (!line[0]) {
		cur = 0;
	} else if ((cur += atoi(line)) > max) {
		max = cur;
	}
}
void onend()
{
	printf("%d\n", max);
}
