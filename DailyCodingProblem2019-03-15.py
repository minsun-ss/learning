# SOLVED? I think this is a good job for pyspark

# The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

# Hint: The basic equation of a circle is x2 + y2 = r2.

import random

num_samples = 1000000
bound = (0,1)


def in_circle(x, y):
    return (x**2 + y**2) < 1

num_in_circle = 0
for _ in range(num_samples):
    x = random.random()
    y = random.random()
    # print(x,y)
    if in_circle(x,y):
        num_in_circle += 1

n = round(4 * (num_in_circle/num_samples), 3)

print(n)
