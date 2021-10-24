n = 10
k = (n * 2) - 1
for i in range(1, 7):
    for j in range(0, k):
        print("", end=" ")
    c = (i*2) - 1
    for j in range(1, c - 1):
        if j == 1 or j == c - 2:
            print(i - 1, "", end=" ")
        else:
            print("# ", end=" ")
    print("\n")
    k = k - 2
