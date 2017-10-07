"""
Problem: UVa 20815 - Andy's First Dictionary
Author: sjsakib
"""

from sys import stdin
from re import split

words = set(split(r'[^a-z]', stdin.read().strip().lower()))

print('\n'.join([w for w in sorted(words) if w]))
