#include <iostream>
#include <vector>
#define fast                                                                   \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);

typedef long long ll;
const int MOD = 1000000007;

using namespace std;

vector<ll> factorial(501, 1);
void computeFactorials() {
  for (int i = 2; i <= 500; ++i) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}

// Fermat's Little Theorem
ll modInverse(ll n, ll p) {
  ll res = 1, y = p - 2;
  while (y > 0) {
    if (y & 1)
      res = (res * n) % p;
    n = (n * n) % p;
    y >>= 1;
  }
  return res;
}

ll multinomial(int total, vector<int> &counts) {
  ll result = factorial[total];
  for (int count : counts) {
    result = (result * modInverse(factorial[count], MOD)) % MOD;
  }
  return result;
}

int main() {
  fast;
  computeFactorials();

  while (true) {
    int N;
    cin >> N;
    if (N == 0)
      break;

    vector<int> initial(N), target(N);
    for (int i = 0; i < N; ++i) {
      cin >> initial[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> target[i];
    }

    vector<int> moves(N);
    int totalMoves = 0;
    for (int i = 0; i < N; ++i) {
      moves[i] = target[i] - initial[i];
      totalMoves += moves[i];
    }

    cout << multinomial(totalMoves, moves) << '\n';
  }

  return 0;
}
