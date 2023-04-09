# Gaussian Elimination
import random

def makeArr(minSize=20, maxSize=30):
    # make n*m array
    n = random.randint(minSize,maxSize)
    m = random.randint(minSize, maxSize)
    arr = [[0 for i in range(m)] for j in range(n)]
    for i in range(n):
        for j in range(m):
            arr[i][j] = random.randint(-10, 20)
    return arr



def printArr(arr):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            # rounding
            print(round(arr[i][j], 3), end=' ')
        print()

def gaussianElimination(arr):

    n=len(arr)
    m=len(arr[0])
    t=min(n, m)
    # forward elimination
    for i in range(t):
        # find max element
        maxElement=abs(arr[i][i])
        maxRow=i
        for k in range(i+1, n):
            if abs(arr[k][i]) > maxElement:
                maxElement=abs(arr[k][i])
                maxRow=k

        # swap max row with current row
        for k in range(i, m):
            temp=arr[maxRow][k]
            arr[maxRow][k]=arr[i][k]
            arr[i][k]=temp

        # make all rows below this one 0 in current column
        for k in range(i+1, n):
            c=-arr[k][i]/arr[i][i]
            for j in range(i, m):
                if i==j:
                    arr[k][j]=0
                else:
                    arr[k][j]+=c*arr[i][j]

    return arr

def main():
    # Ax=b
    arrA=makeArr()
    arrB=makeArr()
    print('Size of array: ', len(arrA), 'x', len(arrA[0]))
    print('A:')
    printArr(arrA)

    sol=gaussianElimination(arrA)
    print('Solution:')
    printArr(sol)



if __name__ ==  '__main__' :
    main()
