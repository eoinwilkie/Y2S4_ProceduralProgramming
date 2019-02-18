#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define loopforever for(;;)
#define loopTest(A) for(int i = 0; i < (A);i++)

void swap(int *a, int *b);

void main()
{
	int x = max(2, 3);
	printf("MAX: %d\n", x);

	int a = 1, b = 2;
	//swap(a, b);
	//printf("%d, %d\n", a, b);
	int *c = 1, *d = 2;
	swap(&c, &d);
	printf("%d, %d\n", c, d);
}

void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
