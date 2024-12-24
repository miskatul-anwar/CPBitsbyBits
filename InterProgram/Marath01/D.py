import math


def catalan(n: int) -> int:
    n = int(n / 2)
    c = math.comb(2 * n, n)
    return c // (n + 1)


def main():
    n = int(input())
    print(catalan(n))


if __name__ == "__main__":
    main()
