#!/usr/bin/env python3
import sys

def fizzbuzz(n: int) -> None:
    out = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            out.append("FizzBuzz")
        elif i % 3 == 0:
            out.append("Fizz")
        elif i % 5 == 0:
            out.append("Buzz")
        else:
            out.append(str(i))
    print(" ".join(out))

if __name__ == "__main__":
    if len(sys.argv) >= 2:
        try:
            n = int(sys.argv[1])
        except ValueError:
            print(f"Usage: {sys.argv[0]} N")
            sys.exit(1)
    else:
        n = 100
    fizzbuzz(n)
