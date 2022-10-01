"""
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

"""

N = 600851475143
def largest_prime_factor(N):
    i=2
    while i<N:
        if N%i == 0:
            N = N/i
        else:
            i = i+1
    return i
print(largest_prime_factor(N))
        