import math
import random
from tqdm import tqdm


def calc(i: int, j: int) -> int:
    if j <= -1 or j > i:
        return 0
    elif i == 0 and j == 0:
        return 1
    return calc(i - 1, j - 1) + calc(i - 1, j)


def main() -> None:
    event_space = int(0)
    t = int(input("Enter the number of Trials: "))
    for _ in tqdm(range(t)):
        n = random.randint(0, t)
        m = random.randint(0, t)
        if n <= m:
            if calc(n, m) == math.comb(n, m):
                event_space += 1
    probability = float(event_space / t)
    print(f"The probability: {probability}")


if __name__ == "__main__":
    main()
