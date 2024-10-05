def fun1(a):
    def fun2(b):
        return a*b
    return fun2


abc = fun1(2)
bcd = fun1(3)
print(abc(3))
print(bcd(3))
