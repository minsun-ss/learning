# cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that
# pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

# Given this implementation of cons:

#def cons(a, b):
#    def pair(f):
#        return f(a, b)
#    return pair

#Implement car and cdr.

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

dispatcher = { 'cons' : cons}

def car(b):
    f = b.
    y = f.__code__
    print(y)
    return b

print(car(cons(3, 4)))

