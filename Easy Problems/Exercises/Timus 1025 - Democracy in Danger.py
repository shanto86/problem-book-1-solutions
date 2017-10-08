"""
Problem: Timus 1025 - Democracy in Danger
Author: sjsakib
"""

n = int(input())

print(sum(sorted(map(lambda x: int(x)//2 + 1, input().split()))[:n//2 + 1]))
