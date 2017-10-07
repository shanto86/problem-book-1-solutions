"""
Problem: UVa1592 Database
Author: sjsakib
"""

from sys import stdin


def find_dup(c1, c2):
    mem = {}
    for r in range(n):
        pair = (tb[r][c1], tb[r][c2])
        try:
            r1 = mem[pair]+1
            print("NO")
            print(r1, r+1)
            print(c1+1, c2+1)
            return True
        except KeyError:
            mem[pair] = r
    return False


while True:
    line = stdin.readline()
    if not line:
        break
    n, m = map(int, line[:-1].split())

    tb = []
    for i in range(n):
        line = stdin.readline()
        tb.append(list(line[:-1].split(',')))

    found = False
    for i in range(m):
        for j in range(i+1, m):
            found = find_dup(i, j)
            if found:
                break
        if found:
            break
    if not found:
        print("YES")
