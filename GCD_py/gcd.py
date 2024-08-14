def gcd(a:int, b:int):
    _gcd = 1
    if a == 0:
        return b
    if b == 0:
        return b
    min_value = min (a, b)
    
    for i in range(2, min_value + 1): #(range 1, min_value + 1)
        if a % i == 0 and b % i == 0:
            _gcd = i
                 
    return _gcd

def main():
    a = 48
    b = 18
    result = gcd(a, b)
    print(result)
    
main()

