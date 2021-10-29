def fib(n):
	f0=1
	f1=1
	if (n==0 or n==1):
		return f0
	if (n>1):
		f=fib(n-1)+fib(n-2);
		return f;

number = int(input())
print(fib(number))

