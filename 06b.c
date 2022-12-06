/* Same code as in first part except the value of SIZ macro. */
#include <stdio.h>

#define SIZ	14		/* Number values to compare */

/* Return non 0 value if all values in LIST of SIZ are different. */
int
diff(char *list, int siz)
{
	int i, j;

	for (i = 0;   i < siz-1; i++)
	for (j = i+1; j < siz;   j++) {
		if (!list[j] || list[i] == list[j]) {
			return 0; /* Not different */
		}
	}
	return 1;		/* All different */
}

int
main(void)
{
	int i;
	char c, last[SIZ]={0};

	while ((c = getchar()) != EOF && !diff(last, SIZ)) {
		last[i++ % SIZ] = c;
	}
	printf("%d\n", i);
	return 0;
}
