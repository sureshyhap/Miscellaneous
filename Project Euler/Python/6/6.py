sum_ = 0
sqr_sum = 0

for i in range(1, 101):
    sum_ += (i ** 2)
    sqr_sum += i

sqr_sum = sqr_sum ** 2
print(sqr_sum - sum_)
