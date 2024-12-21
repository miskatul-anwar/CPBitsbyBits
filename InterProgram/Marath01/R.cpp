#include <iostream>
#include <unordered_map>
#include <vector>
#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
using ll = long long;

const int MOD = 1000000007;
const int MAX_A = 70;
std::vector<int> primes;

void initialize_primes() {
  std::vector<bool> is_prime(MAX_A + 1, true);
  for (int i = 2; i <= MAX_A; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= MAX_A; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int get_prime_mask(int x) {
  int mask = 0;
  for (int i = 0; i < primes.size(); ++i) {
    int count = 0;
    while (x % primes[i] == 0) {
      x /= primes[i];
      count++;
    }
    if (count % 2 != 0) {
      mask |= (1 << i);
    }
  }
  return mask;
}

int main() {
  fast initialize_primes();
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> masks(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    masks[i] = get_prime_mask(a[i]);
  }

  std::unordered_map<int, ll> dp;
  dp[0] = 1; // Empty subset

  for (int mask : masks) {
    std::unordered_map<int, ll> new_dp = dp;
    for (const auto &[state, count] : dp) {
      int new_state = state ^ mask;
      new_dp[new_state] = (new_dp[new_state] + count) % MOD;
    }
    dp = new_dp;
  }

  ll result = (dp[0] - 1 + MOD) % MOD;
  std::cout << result << '\n';

  return 0;
}
