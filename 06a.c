#include <stdio.h>
#include <string.h>

#define LAST	4		/* Number of chars we compare */

/* Remove first LIST item and move everything -1 index to make place
 * at the end for NEW char. */
void
push(char *list, size_t siz, char new)
{
	size_t i;

	for (i = 1; i < siz; i++) {
		list[i-1] = list[i];
	}
	list[i-1] = new;
}

/* Return non 0 value if all values in LIST of SIZ are different. */
int
diff(char *list, size_t siz)
{
	size_t i, j;

	for (i = 0;   i < siz; i++)
	for (j = i+1; j < siz; j++) {
		if (list[i] == list[j]) {
			return 0;
		}
	}
	return 1;
}

int
main(void)
{
	size_t i;
	char sign, last[LAST];

	/* Fill LAST list with first character so it's not empty. */
	sign = getchar();
	for (i = 0; i < LAST; i++) {
		last[i] = sign;
	}
	for (i = 2; (sign = getchar()) != EOF; i++) {
		push(last, LAST, sign);
		if (diff(last, LAST)) {
			break;
		}
	}
	printf("%lu\n", i);
	return 0;
}
