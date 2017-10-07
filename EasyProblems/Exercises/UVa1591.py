"""
Problem: UVa 1591 Data Mining
Author: sjsakib

We will go through all possible combinations of A and B and generate Qofs for maximum Pofs ( (N-1)*Sp )
and then we'll see which of them is the smallest, but greater than or equal (N-1)*Sq
"""
from sys import stdin

for line in stdin:
    n, sp, sq = map(int, line.split())
    minK = 1e10
    a = 0
    b = 0
    for i in range(35):
        for j in range(35):
            pofs = (n-1)*sp
            curK = (pofs + (pofs << i)) >> j
            if curK >= sq*(n-1) and curK < minK:
                minK = curK
                a = i
                b = j
    print(minK+sq, a, b)
