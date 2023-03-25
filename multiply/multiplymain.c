#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial mult_poly(polynomial a, polynomial b)

{

	int i, j;

	polynomial p;

	for (i = 0; i < a.degree + b.degree + 1; i++)              //배열 초기화

		p.coef[i] = 0;



	p.degree = a.degree + b.degree; 



	for (i = 0; i < a.degree + 1; i++)

		for (j = 0; j < b.degree + 1; j++)

			p.coef[i + j] += a.coef[i] * b.coef[j];



	return p;

}
void print_poly(polynomial p)

{

	int i;

	for (i = 0; i < p.degree; i++) {

		printf("%0.1fx^%d ", p.coef[i], p.degree - i);

		if (p.coef[i + 1] > 0)

			printf("+ ");

	}

	printf("%0.1f\n", p.coef[p.degree]);

}

int main(void)
{
	polynomial a = { 3,{4,3,2,1} };
	polynomial b = { 2,{3,2,8} };
	polynomial c;

	c = mult_poly(a, b);
	printf("----------------------------------------\n");
	print_poly(c);
	return 0;
}