int printf(char const *format, ...);

int factorial(int n)
{
	if (n <= 0)
		return 1;
	else return n*factorial(n-1);
}

int fibonacci(int a, int b, int n)
{
	if (n <= 0)
		return a;

	while (n > 0) {
		int a1 = 2, b2 = 2;
		int t;
		t = b;
		b = a+b;
		a = t;
		n = n-1;
	}
	
	return b;
}

int main()
{
//   int a = fibonacci(factorial(1), factorial(2), factorial(5));
	int a = fibonacci(0,1,5);
  printf("%d", a);
  return a;
}
