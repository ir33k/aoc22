/* NOTE: This solution implementation assumes that input file ends
 * with at least one empty line.  This small addition makes whole
 * program a lot simpler so I will allowe it ^-^ */

#include "online.h"

int cur = 0, max[3] = {0};

void online(char *line)
{
	if (line[0]) {
		cur += atoi(line);
		return;
	} else if (cur > max[0]) {
		max[2] = max[1];
		max[1] = max[0];
		max[0] = cur;
	} else if (cur > max[1]) {
		max[2] = max[1];
		max[1] = cur;
	} else if (cur > max[2]) {
		max[2] = cur;
	}
	cur = 0;
}
void onend()
{
	printf("%d\n", max[0] + max[1] + max[2]);
}
