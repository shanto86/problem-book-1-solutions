"""
Problem: UVa 815 Flooded!
Author: sjsakib

We will sort the blocks according to height and keep pouring water until we run out of water or all the blocks
are drowned.
"""
case = 1

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    blocks = []
    for i in range(n):
        blocks.extend(list(map(int, input().split())))
    total = int(input())
    blocks.sort()
    blocks.append(1e10)

    idx = 0
    height = blocks[0]
    drowned = 0

    while True:
        if idx > n*m:
            break
        while blocks[idx+1] == blocks[idx]:
            idx += 1

        h = blocks[idx+1] - blocks[idx]
        if(h*100*(idx+1) <= total):
            total -= h*100*(idx+1)
            drowned = idx + 1
            height += h
            idx += 1
        elif total > 0:
            drowned = idx+1
            height += total/(100*(idx+1))
            break
        else:
            break
    print("Region {}\nWater level is {:.2f} meters.\n{:.2f} percent of the region is under water.\n"
          .format(case, height, drowned/(n*m)*100))
    case += 1
