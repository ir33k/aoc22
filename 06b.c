/* Same code as in first part except the value of SIZ macro.

Playing around after watching "This Algorithm is 1,606,240% FASTER" [1] by ThePrimeagen.

[1] https://www.youtube.com/watch?v=U16RnpV48KQ

Initial speed tests on MacOS of current solution:

	$ cc -Wall -Wextra -Wshadow -Wswitch-enum -pedantic -std=c89 06b.c -o 06b && time ./06b <06.in5
	3986
	
	real	0m0.161s
	user	0m0.001s
	sys	0m0.001s

*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZ	14		/* Number values to compare */

/* Return non 0 value if all values in LIST of SIZ are different. */
int
diff(char *list, int siz)
{
	int i, j;

	for (i = 0;   i < siz-1; i++)
	for (j = i+1; j < siz;   j++) {
		if (!list[j] || list[i] == list[j]) {
			return 0;	/* Not different */
		}
	}
	return 1;	/* All different */
}


int
main(void)
{
	unsigned i=0;
	char c, last[SIZ]={0};
	while ((c = getchar()) != EOF && !diff(last, SIZ)) {
		last[i++ % SIZ] = c;
	}
	printf("%u\n", i);
	return 0;
}
