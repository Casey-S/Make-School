def naive(index):
    """
    ' naive(1) = 1
    ' naive(2) = 1
    ' naive(3) = 2
    ' naive(4) = 3
    ' naive(5) = 5
    ' naive(n) = ...
    """

    if index <= 2: return 1
    return naive(index - 1) + naive(index - 2)
    
print(naive(10))