"""
Problem: UVa 1589 Xiangqi
Author: sjsakib

We mark all the positions attacked by the given pieces and then check if it's a checkmate
"""
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]


def inside(r, c):
    return r > 0 and r <= 10 and c > 0 and c <= 9


def palace(r, c, pos):
    if pos == 1:
        return r > 0 and r < 4 and c > 3 and c < 7
    return r < 11 and r > 7 and c > 3 and c < 7


def blank(r, c):
    return board[r][c][0] == 'X' or board[r][c][0] == '-'


def general(r, c):
    for ri, ci in zip(dr, dc):
        for j in range(1, 11):
            rr = r + ri*j
            cc = c + ci*j
            if not inside(rr, cc):
                break
            elif not blank(rr, cc):
                board[rr][cc] += 'X'
                break
            else:
                board[rr][cc] = 'X'


def canon(r, c):
    for ri, ci in zip(dr, dc):
        found = 0
        for j in range(1, 11):
            rr = r + ri*j
            cc = c + ci*j
            if not inside(rr, cc):
                break
            elif (not blank(rr, cc) and found == 1):
                board[rr][cc] += 'X'
                break
            elif (not blank(rr, cc) and found == 0):
                found = 1
            elif found == 1:
                board[rr][cc] = 'X'


def horse(r, c):
    for ri, ci in zip(dr, dc):
        rr, cc = r + ri, c + ci
        if blank(rr, cc):
            rr += ri
            cc += ci
            if not inside(rr, cc):
                break
            rrr, ccc = rr + ci, cc + ri
            if inside(rrr, ccc) and blank(rrr, ccc):
                board[rrr][ccc] = 'X'
            elif inside(rrr, ccc):
                board[rrr][ccc] += 'X'
            rrr, ccc = rr - ci, cc - ri
            if inside(rrr, ccc) and blank(rrr, ccc):
                board[rrr][ccc] = 'X'
            elif inside(rrr, ccc):
                board[rrr][ccc] += 'X'


def checkmate(r, c):
    if r > 5:
        pos = -1
    else:
        pos = 1
    for ri, ci in zip(dr, dc):
        rr, cc = r + ri, c + ci
        if inside(rr, cc) and palace(rr, cc, pos) and board[rr][cc][-1] != 'X':
            return False
    for i in range(1, 10):
        rr = r + (i*pos)
        if inside(rr, c) and board[rr][c][0] == 'G':
            return False
        if inside(rr, c) and not blank(rr, c):
            break
    return True


while True:
    board = [['-']*10 for i in range(11)]
    n, gr, gc = map(int, input().split())
    if n == 0:
        break
    pcs = []
    for i in range(n):
        pcs.append(input().split())
        r = int(pcs[-1][1])
        c = int(pcs[-1][2])
        board[r][c] = pcs[-1][0]
        pcs[-1][1] = r
        pcs[-1][2] = c
    for p in pcs:
        if p[0] == 'G':
            general(*p[1:])
        elif p[0] == 'R':
            general(*p[1:])
        elif p[0] == 'H':
            horse(*p[1:])
        else:
            canon(*p[1:])
    print("YES" if checkmate(gr, gc) else "NO")
    input()
