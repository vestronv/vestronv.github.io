import random
n = 8
m = 8
print n, m
for i in range(n):
    for j in range(m):
        print random.randint(1,4),
    print ''
