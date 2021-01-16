import math

def find_num_divisors(num):
    divisors = 0
    # Only have to check up to sqrt
    stop = int(math.sqrt(num))
    # From 1 to one number below sqrt
    for i in range(1, stop):
        if num % i == 0:
            divisors += 1
    # Count 1 more if num is a perfect square
    # and stop is the square root.
    # Times two because the divisor list is
    # symmetric
    if stop ** 2 == num:
        return divisors * 2 + 1
    else:
        return divisors * 2
    

def main():
    num_divisors = 500
    triang_num = 1
    i = 2
    while True:
        triang_num += i
        if find_num_divisors(triang_num) > num_divisors:
            print(triang_num)
            return
        i += 1
    

if __name__ == "__main__":
    main()
