"""
Problem: UVa 213 Message Decoding
Author: sjsakib
"""
k_count = [2*(2**i - 1) - i for i in range(8)]  # k_count[i] holds how many keys are there of size i or less than i


def extend_line(line, cur, k):
    while cur + k > len(line):
        line += input()
    return line[cur:], 0


while True:
    try:
        header = input()
    except EOFError:
        break

    line = ''
    cur = 0
    message = ''

    while True:
        line, cur = extend_line(line, cur, 3)
        k = int(line[cur:cur+3], 2)
        if k == 0:
            break
        cur += 3
        while True:
            line, cur = extend_line(line, cur, k)
            key = int(line[cur:cur+k], 2)
            cur += k
            if key == 2**k - 1:
                break
            else:
                message += header[k_count[k-1] + key]
    print(message)
