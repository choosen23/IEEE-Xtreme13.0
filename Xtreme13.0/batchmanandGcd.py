# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy
import scipy
import math 


n = get_number()
k = get_number()
a = []

for i in range (n):
    tmp = get_number()
    a.append(tmp)
    
s = set()

if (k == n):
    for i in range (0,n):
        for j in range (i,n):
            if ( math.gcd(a[i],a[j]) not in s):
                s.add( math.gcd(a[i],a[j]) )
else:  #thelw tis n-k pithanes periptwswis

    for i in range (0,n-):
        for j in range (i,l):
            if ( math.gcd(a[i],a[j]) not in s):
                s.add( math.gcd(a[i],a[j]) )

print(len(s))
