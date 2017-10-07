"""
Problem: UVa 1583 Digit Generator
Author: sjsakib

We go through all numbers from 0 to MAX and calculate it's digit_sum. Then we save the number as one of the
digit_sums generator. Then for all input we return the minimum of it's saved generators

A generator can never be greater than the number itself. So if we get a digit_sum greater than
MAX, we don't need to save it
"""

from sys import stdin

MAX = 100010


def digit_sum(n):
    ret = n
    while n:
        ret += n % 10
        n //= 10
    return ret


input()
ans = [[] for i in range(MAX)]
for i in range(MAX):
    try:
        ans[digit_sum(i)].append(i)
    except IndexError:  # digit_sum(i) is greater than MAX
        pass

for line in stdin:
    x = int(line)
    try:
        print(min(ans[x]))
    except ValueError:
        print(0)
