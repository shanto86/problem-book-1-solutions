"""
Problem: UVa 201 Squares
Author: sjsakib
"""


def inp():
    try:
        i = input()
        while not i:
            i = input()
        return i
    except EOFError:
        return -1


def find(r, c):
    for i, row in enumerate(tb):
        try:
            j = row.index((r, c))
            return i+1, j+1
        except ValueError:
            pass
    return -1, -1


def exchange(r1, c1, r2, c2):
    tb[r1-1][c1-1], tb[r2-1][c2-1] = tb[r2-1][c2-1], tb[r1-1][c1-1]


def insert_col(cols):
    global col
    for i, c in enumerate(cols):
        for j in range(row):
            tb[j].insert(c+i-1, (0, 0))
    col += len(cols)


def delete_col(cols):
    global col
    for i, c in enumerate(cols):
        for j in range(row):
            del tb[j][c-i-1]
    col -= len(cols)


def insert_row(rows):
    global row
    for i, r in enumerate(rows):
        tb.insert(r+i-1, [(0, 0) for j in range(col)])
    row += len(rows)


def delete_row(rows):
    global row
    for i, r in enumerate(rows):
        del tb[r-i-1]
    row -= len(rows)


case = 1

while True:
    row, col = map(int, inp().split())
    if row == 0:
        break

    tb = [[(j+1, i+1) for i in range(col)] for j in range(row)]

    n = int(inp())

    for i in range(n):
        op = inp().split()
        cmd = op[0]
        args = list(map(int, op[1:]))

        if cmd == "EX":
            exchange(*args)
            continue
        args = sorted(args[1:])
        if cmd == 'DR':
            delete_row(args)
        elif cmd == 'DC':
            delete_col(args)
        elif cmd == 'IC':
            insert_col(args)
        elif cmd == 'IR':
            insert_row(args)

    x = int(inp())

    if case != 1:
        print('')
    print("Spreadsheet #", case, sep='')
    for i in range(x):
        r, c = map(int, inp().split())

        nr, nc = find(r, c)
        if nr == -1:
            ans = 'GONE'
        else:
            ans = "moved to ({},{})".format(nr, nc)
        print("Cell data in ({},{})".format(r, c), ans)
    case += 1
