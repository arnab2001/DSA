#!/usr/bin/env python3


"""
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""
def is_palindrome(n):
    return str(n) == str(n)[::-1]
L = []
for i in range(1000):
    for x in range(1000):
        if is_palindrome(i*x) == True:
            L.append(i*x)
        else:
            continue
print(max(L))