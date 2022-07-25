def largest_palindrome_prod(num_digits_each):
    max_num = (10 ** num_digits_each) - 1
    min_num = 10 ** (num_digits_each - 1)
    palindromes = []
    for i in range(max_num, min_num - 1, -1):
        for j in range(max_num, min_num - 1, -1):
            product = i * j
            if check_palindrome(product):
                palindromes.append(product)
    return max(palindromes)


def check_palindrome(num):
    s_num = str(num)
    length = len(s_num)
    # Finding the index where we will stop checking matches
    max_check = length // 2
    for i in range(1, max_check + 1):
        if s_num[i - 1] != s_num[-i]:
            return False
    return True
            

print(largest_palindrome_prod(3))
