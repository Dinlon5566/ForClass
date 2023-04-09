# Gaussian Elimination
import random
import copy
import sys

debug=False

def makeArr(minSize=20, maxSize=30, n=0, m=0):
    # make n*m array
    if n == 0 and m == 0:
        n = random.randint(minSize, maxSize)
        m = n
    arr = [[0 for i in range(m)] for j in range(n)]
    for i in range(n):
        for j in range(m):
            arr[i][j] = random.randint(-10, 20)
    return arr


def printArr(arr):
    if arr == None:
        print("No solution | Infinite solutions")
        return

    for i in range(len(arr)):
        for j in range(len(arr[i])):
            # rounding
            print(round(arr[i][j], 3), end=' ')
        print()


def gaussianElimination(arr, arrB):
    n = len(arr)
    m = len(arr[0])
    root = [0 for i in range(m)]
    t = min(n, m)

    # forward elimination
    for i in range(t):
        # find max element
        maxElement = abs(arr[i][i])
        maxRow = i
        for k in range(i+1, n):
            if abs(arr[k][i]) > maxElement:
                maxElement = abs(arr[k][i])
                maxRow = k

        # swap max row with current row
        for k in range(i, m):
            temp = arr[maxRow][k]
            arr[maxRow][k] = arr[i][k]
            arr[i][k] = temp
            arrB[maxRow][0], arrB[i][0] = arrB[i][0], arrB[maxRow][0]

        # make all rows below this one 0 in current column
        for k in range(i+1, n):
            c = -arr[k][i]/arr[i][i]
            for j in range(i, m):
                if i == j:
                    arr[k][j] = 0
                else:
                    arr[k][j] += c*arr[i][j]
            arrB[k][0] += c*arrB[i][0]

    # backward substitution

    # if no solution
    if arr[n-1][m-1] == 0:
        return None

    # if infinite solutions
    if arr[n-1][m-1] == 0 and arrB[n-1][0] != 0:
        return None

    # if one solution
    root[m-1] = arrB[n-1][0]/arr[n-1][m-1]
    for i in range(n-2, -1, -1):
        root[i] = arrB[i][0]
        for j in range(i+1, m):
            root[i] -= arr[i][j]*root[j]
        root[i] /= arr[i][i]

    return root


def main():
    # Ax=b
    arrA = makeArr()
    arrB = makeArr(n=len(arrA), m=1)

    arrA_c=copy.deepcopy(arrA)
    arrB_c=copy.deepcopy(arrB)

    sol = gaussianElimination(arrA_c, arrB_c)
    
    if debug:
        print("A: ")
        printArr(arrA)
        print("b: ")
        printArr(arrB)
        print("A|: ")
        printArr(arrA_c)
        print("|b: ")
        printArr(arrB_c)
    print("SOL:")
    for i in range(len(sol)):
        print("x"+str(i+1)+"="+str(sol[i]))


if __name__ == '__main__':
    # args = debug mode
    if len(sys.argv) > 1:
        debug=True

    main()
