#include <iostream>
#include <vector>
#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);

typedef long long ll;

// Function to compute gcd
ll gcd(ll a, ll b) {
  while (b) {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// Function to compute lcm
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main() {
  fast ll N, M;
  while (std::cin >> N >> M) {
    std::vector<ll> divisors(M);
    for (int i = 0; i < M; ++i) {
      std::cin >> divisors[i];
    }

    ll total = N;
    ll count = 0;

    // Inclusion-Exclusion principle
    for (int i = 1; i < (1 << M); ++i) {
      ll current_lcm = 1;
      int bits = 0;
      for (int j = 0; j < M; ++j) {
        if (i & (1 << j)) {
          current_lcm = lcm(current_lcm, divisors[j]);
          if (current_lcm > N)
            break;
          bits++;
        }
      }
      if (current_lcm <= N) {
        if (bits % 2 == 1) {
          count += N / current_lcm;
        } else {
          count -= N / current_lcm;
        }
      }
    }

    ll valid_tickets = total - count;
    std::cout << valid_tickets << '\n';
  }

  return 0;
}
