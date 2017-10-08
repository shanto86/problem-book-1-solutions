"""
Problem: Timus 1319 - Hotel
Author: sjsakib
"""
n = int(input())

table = [[0]*n for j in range(n)]

k = 1
for i in range(n-1, -n-1, -1):
    j = max(i, 0)
    i = max(0, i*-1)
    while i < n and j < n:
        table[i][j] = str(k)
        k += 1
        i += 1
        j += 1

print('\n'.join([' '.join(line) for line in table]))
