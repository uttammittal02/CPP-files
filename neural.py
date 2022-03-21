import numpy as np

def fun(w, a):
    d1 = d2 = 0
    for i in range(3):
        d1 += (a[i] - w[0][i]) ** 2
    for i in range(3):
        d2 += (a[i] - w[1][i]) ** 2
    print(d1, d2)
    return d1, d2

a = np.array([1, 0, 0])
b = np.array([0, 1, 0])
c = np.array([0, 0, 1])
w = np.array([[2, 2, 2], [0.1, 0.1, 0.1]])
l = 0.5
for i in range(10000):
    
    d1, d2 = fun(w, a)
    if (d1 >= d2):
        for j in range(3):
            w[0][j] = w[0][j] + l * (a[j] - w[0][j])
    else:
        for j in range(3):
            w[1][j] = w[1][j] + l * (a[j] - w[1][j])
    
    d1, d2 = fun(w, b)
    if (d1 >= d2):
        for j in range(3):
            w[0][j] = w[0][j] + l * (b[j] - w[0][j])
    else:
        for j in range(3):
            w[1][j] = w[1][j] + l * (b[j] - w[1][j])
    d1, d2 = fun(w, c)
    if (d1 >= d2):
        for j in range(3):
            w[0][j] = w[0][j] + l * (c[j] - w[0][j])
    else:
        for j in range(3):
            w[1][j] = w[1][j] + l * (c[j] - w[1][j])
            
    l /= 2
    print('\n')
    