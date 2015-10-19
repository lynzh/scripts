#!/usr/bin/python2.7
# Filename : fib.py

def fib(n):	# write Fibonacci series up to n
	"Print a  Fibonacci series up to n"
	a, b = 0, 1
	while b < n:
		print b,
		a, b = b, a+b

print fib(2000)
