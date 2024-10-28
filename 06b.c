/* Same code as in first part except the value of SIZ macro.

Playing around after watching "This Algorithm is 1,606,240% FASTER" [1] by ThePrimeagen.

[1] https://www.youtube.com/watch?v=U16RnpV48KQ

Initial speed tests on MacOS of current solution:

	$ cc -Wall -Wextra -Wshadow -Wswitch-enum -pedantic -std=c89 06b.c -o 06b && time ./06b <06.in5
	3986
	
	real	0m0.161s
	user	0m0.001s
	sys	0m0.001s

2024.10.28 Mon 13:58

Yep, improvement works but on MacOS it's not that noticeable because
original implementation was already very fast.  Only with calls to
clock() function I was able to see the difference.  Old code took
around 218 clock cycles but new implementation takes around 7 to 9.
That's significant.

*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int
main(void)
{
	unsigned mask=0, b;
	char buf[4096], *pt=buf;
	/* clock_t since; */
	read(0, buf, sizeof(buf));
	/* since = clock(); */
start:	mask = 0;
	b = 1 << (pt[13]-'a');  /* First char is always unique */      mask |= b;
	b = 1 << (pt[12]-'a');  if (mask & b) { pt+=13; goto start; }  mask |= b;
	b = 1 << (pt[11]-'a');  if (mask & b) { pt+=12; goto start; }  mask |= b;
	b = 1 << (pt[10]-'a');  if (mask & b) { pt+=11; goto start; }  mask |= b;
	b = 1 << (pt[ 9]-'a');  if (mask & b) { pt+=10; goto start; }  mask |= b;
	b = 1 << (pt[ 8]-'a');  if (mask & b) { pt+= 9; goto start; }  mask |= b;
	b = 1 << (pt[ 7]-'a');  if (mask & b) { pt+= 8; goto start; }  mask |= b;
	b = 1 << (pt[ 6]-'a');  if (mask & b) { pt+= 7; goto start; }  mask |= b;
	b = 1 << (pt[ 5]-'a');  if (mask & b) { pt+= 6; goto start; }  mask |= b;
	b = 1 << (pt[ 4]-'a');  if (mask & b) { pt+= 5; goto start; }  mask |= b;
	b = 1 << (pt[ 3]-'a');  if (mask & b) { pt+= 4; goto start; }  mask |= b;
	b = 1 << (pt[ 2]-'a');  if (mask & b) { pt+= 3; goto start; }  mask |= b;
	b = 1 << (pt[ 1]-'a');  if (mask & b) { pt+= 2; goto start; }  mask |= b;
	b = 1 << (pt[ 0]-'a');  if (mask & b) { pt+= 1; goto start; }  mask |= b;
	/* printf("%lu\n", clock() - since); */
	printf("%lu\n", pt - buf + 14);
	return 0;
}
