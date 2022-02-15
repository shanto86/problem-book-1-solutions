"""
Problem: Timus 1209 - 1, 10, 100, 1000...
Author: sjsakib
Approach: Math
"""
from math import sqrt
from sys import stdin


def f(s):
    return int((sqrt(1 + 8*s) - 1)/2)


def ans(k):
    k = int(k)
    n = f(k)
    if k == 1 or k - (n*(n+1))//2 == 1:
        return '1'
    return '0'


n = input()

print(' '.join(map(ans, stdin.read().split())))
