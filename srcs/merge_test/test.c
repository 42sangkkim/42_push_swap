#include <stdio.h>

static size_t	math_pow(size_t x, size_t n)
{
	size_t	pow;

	pow = 1;
	while(n--)
		pow *= x;
	return (pow);
}

size_t	calc_depth(size_t n)
{
	size_t	depth;

	depth = 0;
	while (n > 4)
	{
		depth++;
		n = n / 3 + (n % 3 > 0);
	}
	return(depth);
}

size_t	calc_amount(size_t pow, size_t i, size_t n)
{
	size_t prev;

	if (pow == 0)
		return (n);
	if (i < pow)
	{
		prev = calc_amount(pow / 3, i, n);
		return (prev / 3 + (prev % 3 > 0));
	}
	else if (i < 2 * pow)
	{
		prev = calc_amount(pow / 3, pow - 1 - i % pow, n);
		return (prev / 3 + (prev % 3 > 1));
	}
	else
	{
		prev = calc_amount(pow / 3, pow - 1 - i % pow, n);
		return (prev / 3);
	}
}

int main(void)
{
	size_t	pow;
	size_t	sum;
	size_t	tmp;
	size_t	n;

	n = 500;
	pow = math_pow(3, 1);//calc_depth(n));
	sum = 0;
	for(size_t i=0; i<pow; i++)
	{
		tmp = calc_amount(pow / 3, i, n);
		printf("%zu\n", tmp);
		sum += tmp;
	}
	printf("depth : %zu, sum : %zu\n", calc_depth(n), sum);
}