"""
Problem: UVa 272 - TEX Quotes
Author: sjsakib
"""
from sys import stdin

text = stdin.read().split('"')
new_text = ''

for i, part in enumerate(text):
    if(i != len(text)-1):
        new_text += part + ("''" if i & 1 else "``")
    else:
        new_text += part

print(new_text, end='')
