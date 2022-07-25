def is_prime(num):
    for i in range(2, int(num ** .5) + 1):
        if (num % i == 0):
            return False
    return True

def main():
    summation = 0 + 2
    bound = 2000000
    for i in range(3, bound):
        if (is_prime(i)):
            summation += i
    print(summation)

if __name__ == "__main__":
    main()

    
