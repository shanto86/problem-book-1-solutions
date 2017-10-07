"""
Problem: UVa 1590 IP networks
Author: sjsakib

We need to find the bit until which all the IP addresses are same. We'll then take a number with all bits on (-1)
and turn off all the bits after that bit. That's our mask. And the network address is mask & any of
the addresses
"""
from math import log2


def to_decimal(ip):
    return sum([int(b) << ((3-i)*8) for i, b in enumerate(ip.split('.'))])


def to_ip(n):
    return '.'.join([str(n >> (i*8) & 255) for i in range(3, -1, -1)])


while True:
    try:
        n = int(input())
    except EOFError:
        break

    first = to_decimal(input())
    diff = 0

    for i in range(n-1):
        c = to_decimal(input())
        diff |= (first ^ c)
    try:
        mask = ((1 << int(log2(diff)+1)) - 1) ^ -1
    except ValueError:
        mask = ~diff
    print(to_ip(first & mask))
    print(to_ip(mask))
