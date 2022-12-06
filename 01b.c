/* NOTE: This solution implementation assumes that input file ends
 * with at least one empty line.  This small addition makes whole
 * program a lot simpler so I will allowe it ^-^ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
	char line[BUFSIZ];
	int cur=0, max[3]={0};

	while (fgets(line, BUFSIZ, stdin)) {
		if (line[0] != '\n') {
			cur += atoi(line);
			continue;
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
	printf("%d\n", max[0] + max[1] + max[2]);
	return 0;
}
