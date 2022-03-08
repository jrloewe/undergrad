A = [ 4, 3, 6, 7, 10, 34, 9, -3, 4, 1 ]

for i in range(1, 10):
    if (A[i] > A[i-1]):
        print(A[i], end = " ")
    else:
        print(i, end = " ")
