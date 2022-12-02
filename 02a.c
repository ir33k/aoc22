#include "online.h"

int p1, p2, out, res = 0;

void online(char *line)
{
	p1   = line[0] - 'A';	  /* Player1 shape number */
	p2   = line[2] - 'X';	  /* Player2 shape number */
	res += p2 + 1;		  /* Player2 score */
	out  = (p1 - p2 + 2) % 3; /* Outcome number */
	res += out ? 6/out : 0;	  /* Outcome score */
}
void onend()
{
	printf("%d\n", res);
}
