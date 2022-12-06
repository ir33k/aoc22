#include <stdio.h>
#include <string.h>

#define COUNT     9		/* Stacks count */
#define SIZ	128		/* Stack max size */

void
reverse(char *str)
{
	char c;
	size_t i, len = strlen(str);

	for (i = 0; i < len/2; i++) {
		c = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = c;
	}
}

void
push(char *str, char c)
{
	str[strlen(str)] = c;
}

char
pull(char *str)
{
	size_t len = strlen(str);
	char c = str[len-1];
	str[len-1] = 0;
	return c;
}

int
main(void)
{
	char line[BUFSIZ], stack[COUNT][SIZ]={""}, crate;
	int flag=0, move, from, to;
	size_t i, len;

	while (fgets(line, BUFSIZ, stdin)) {
		/* Toggle from first to second stage. */
		if (line[0] == '\n') {
			flag = 1;
			for (i = 0; i < COUNT; i++) {
				reverse(stack[i]);
			}
			continue;
		}
		/* Move crates. */
		if (flag) {
			sscanf(line, "move %d from %d to %d",
			       &move, &from, &to);
			for (i = 0; (int)i < move; i++) {
				push(stack[to-1], pull(stack[from-1]));
			}
			len = strlen(stack[to-1]);
			reverse(stack[to-1] + (len-move));
			continue;
		}
		/* Get stack map. */
		len = strlen(line);
		for (i = 0; i < len; i++) {
			crate = line[i*4+1];
			if (crate != ' ' && crate > '9') {
				push(stack[i], crate);
			}
		}
	}
	/* Print result. */
	for (i = 0; i < COUNT; i++) {
		len = strlen(stack[i]);
		if (len) {
			printf("%c", stack[i][len-1]);
		}
	}
	printf("\n");
	return 0;
}
