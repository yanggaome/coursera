week 1: maximum pair wise product
the key idea is that the maximum product is actually the product of the first two largest numbers
but a few common mistakes
1. int type is not enough and may cause overflow when number is large
2. use sort and take the first two largest numbers makes the algorithm much more efficient, nlog(n) cost

week 2:
1. fibonacci sequence
  - loop start and loop end
  - no need to allocate a size N array/vector, 3 is enough
2. fibonacci sequence last digit
  - summation of the last digit is the last digit after summation
3. greatest common divider
  - the Euclidean algorithm
4. least common multiple
  - utilize the gcd function
  - \(a*b)/gcd(a,b)
