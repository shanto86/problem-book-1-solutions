"""
Problem: UVa 232 - Crossword Answers
Author: sjsakib
"""
case = 1
while True:
    try:
        r, c = map(int, input().split())
    except ValueError:
        break

    board = []
    board.append('*'*(c+2))
    for i in range(r):
        board.append('*'+input()+'*')
    board.append('*'*(c+2))

    across = []
    down = []

    cnt = 0
    for i in range(1, r+1):
        for j in range(1, c+1):
            if (board[i][j-1] == '*' or board[i-1][j] == '*') and board[i][j] != '*':
                cnt += 1
            else:
                continue
            w = ''
            if board[i][j-1] == '*':
                k = j
                while(board[i][k] != '*'):
                    w += board[i][k]
                    k += 1
                across.append('{:3}.{}'.format(cnt, w))
            w = ''
            if board[i-1][j] == '*':
                k = i
                while(board[k][j] != '*'):
                    w += board[k][j]
                    k += 1
                down.append('{:3}.{}'.format(cnt, w))
    if case != 1:
        print('')
    print("puzzle #{}:".format(case))
    print("Across")
    if len(across):
        print('\n'.join(across))
    print("Down")
    if len(down):
        print('\n'.join(down))
    case += 1
