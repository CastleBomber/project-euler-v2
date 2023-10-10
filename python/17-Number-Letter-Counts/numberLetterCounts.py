dictionary = {
    0: 0,  # handle special cases
    1: 3,
    2: 3,
    3: 5,
    4: 4,
    5: 4,
    6: 3,
    7: 5,
    8: 5,
    9: 4,
    10: 3,
    11: 6,
    12: 6,
    13: 8,
    14: 8,
    15: 7,
    16: 7,
    17: 9,
    18: 8,
    19: 8,
    20: 6,
    30: 6,
    40: 5,
    50: 5,
    60: 5,
    70: 7,
    80: 6,
    90: 6,
    100: 7,  # Hundred
    1000: 8,  # Thousand
}
"""
Sums up the letters from numbers 1 through 1000
"""
def solution(highestNumber):
  sum = 0

  for i in range(1, highestNumber + 1):
    sum += getLetterCount(i)
    print(i, getLetterCount(i), sum)

  return sum


"""
Gets the number of letters making up the given number

Check how large the number is by dividing
it by 1000, 100, 10
"""
def getLetterCount(number):
  letters = 0
  thousands = number // 1000  # Floor divison
  hundreds = number // 100
  tens = number // 10
  ones = number % 10

  if (thousands >= 1):
    letters = dictionary[hundreds] + dictionary[1000] + getLetterCount(
        number % 1000)
  elif (hundreds >= 1):
    letters = dictionary[hundreds] + dictionary[100] + getLetterCount(
        number % 100)
  elif ((tens >= 1) and (number > 20)):
    letters = dictionary[tens * 10] + dictionary[ones]
  elif (number <= 20):
    letters = dictionary[number]

  # Handle Keyword 'and'
  if ((number > 1000) and (number % 1000 != 0)):
    letters += 3
  if ((number > 100) and (number % 100 != 0)):
    letters += 3

  return letters
