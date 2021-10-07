def heapify(a,n,i):
    min=i
    L=2*i+1
    R=2*i+2
    if(L<n and a[L]<a[min]):
        min=L
    if(R<n and a[R]<a[min]):
        min = R
    if(min!=i):
        a[i],a[min] = a[min],a[i]
        heapify(a,n,min)
def heapsort(a):
    for i in range(n//2,-1,-1):
        heapify(a, n, i)
    print("MINHEAP : ",a)
    for i in range(n-1,0,-1):
        a[0],a[i] = a[i],a[0]
        heapify(a, i, 0)
l = list(map(int,input("Enter the elements : ").split()))
n=len(l)
print("Before Sorting = ",l)
heapsort(l)
print("After Sorting = ",l)
