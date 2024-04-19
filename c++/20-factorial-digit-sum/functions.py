import numpy as np

# Add up all the digits in a very large string (100!) (w/o NumPy)
def SumOfDigits(number):
    sum = 0

    num_str = str(number)

    # Iterate over each character (digit) in the string
    for num_char in num_str:
        sum += int(num_char)

    return sum

# Add up all the digits in a very large NumPy array
def SumOfDigitsNumpy(numpy_num):
    sum = 0

    num_str = np.array_str(numpy_num)

    # Iterate over each character (digit) in the string
    for num_char in num_str:
        # Convert character back to an int and add it to the sum
        if num_char.isdigit():
            sum += int(num_char)

    return sum

