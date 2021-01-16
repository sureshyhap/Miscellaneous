def even_fib(limit):
    first = 1
    second = 2
    sum = 2
    next = first + second
    while next <= limit:
        if next % 2 == 0:
            sum += next
        first = second
        second = next
        next = first + second
    return sum

print(even_fib(4e6))
