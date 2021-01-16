num_longest = None
longest = 0
length_for_each_number = {}
for i in range(1, 1000000):
    count = 1
    n = i
    while n != 1:
        if n % 2 == 0:
            n /= 2
        else:
            n = 3 * n + 1
        count += 1
        check_if_old_num = length_for_each_number.get(n, None)
        if check_if_old_num:
            count += (length_for_each_number[n] - 1)
            break
    length_for_each_number[i] = count
    if count > longest:
        longest = count
        num_longest = i
    
print(num_longest)
