def factR(n):
    if n == 1:
        return n
    else:
        return n*factR(n - 1)
