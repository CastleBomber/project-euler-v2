#!/usr/bin/env python3

# This is a precomputed list of factorials for digits 0–9: [0!, 1!, 2!, ..., 9!]
f = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
s = 0

for n in range(3, 100000):
    # Example for 145: sum([f[1], f[4], f[5]]) → 1 + 24 + 120 = 145 ✅ match
    if n == sum(f[int(d)] for d in str(n)):
        s += n

print(s) # 40730
