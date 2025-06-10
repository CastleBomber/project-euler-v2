# Project Euler Forum by DuyenNH
lst = set()

def main():
    for i in range(1,100):
        for j in range(i,10000//i):
            if check(i, j, i*j):
                lst.add(i*j)

def check(a, b, c):
    lst = [a, b, c]
    check_lst = [False] * 10
    cnt_true = 0

    for n in lst:
        while n != 0:
            tmp = n % 10
            if tmp == 0:
                return False
            if check_lst[tmp] == True:
                return False
            check_lst[tmp] = True
            cnt_true += 1
            n //= 10

    return cnt_true == 9

if __name__ == '__main__':
    main()
    print(sum(lst))