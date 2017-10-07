"""
Problem: UVa 201 Squares
Author: sjsakib
"""
case = 1

while True:
    try:
        n = int(input())
        m = int(input())
    except EOFError:
        break
    except ValueError:
        break
    lines = [[[False, False] for i in range(n)] for j in range(n)]

    for k in range(m):
        d, i, j = input().split()
        i = int(i) - 1
        j = int(j) - 1
        if d == 'H':
            lines[i][j][0] = True
        else:
            lines[j][i][1] = True

    ans = [0]*n

    for i in range(n):
        for j in range(n):
            for k in range(1, n-max(i, j)):
                for x in range(k):
                    if not (lines[i][j+x][0] and lines[i+k][j+x][0] and lines[i+x][j][1] and lines[i+x][j+k][1]):
                        break
                else:
                    ans[k-1] += 1
    if case != 1:
        print("\n**********************************\n")

    print("Problem #", case, '\n', sep='')

    if sum(ans) == 0:
        print("No completed squares can be found.")
    else:
        for i, v in enumerate(ans):
            if v:
                print(v, "square (s) of size", i+1)

    case += 1
