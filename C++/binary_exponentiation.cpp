// Why do you need binary exponentiation?
// Suppose you want to calculate a^b, where a and b are integers.
// You can do this in O(log b) time using binary exponentiation.
// This is much faster than the naive O(b) approach.
// Also, using a proper modulo (eg. 1e9+7) can prevent integer overflow.

// It can even calculate answers like 10000^313812381 (mod 1e9 + 7) perfectly,
// but pow(base, exponent) in C++ will give you the wrong answer.

#include <iostream>
using namespace std;

// binary exponentiation or fast exponentiation
// Time Complexity: O(log (power))
// Space Complexity: O(1)

#define ll long long
ll MOD = 1e9 + 7; // [10^9 + 7] <--change this value according to the problem
ll binPow(ll base, ll power)
{
    ll res = 1;
    while (power > 0)
    {
        if (power & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        power >>= 1;
    }
    return res;
}

int main()
{
    int a, b;
    a = 18;
    b = 136;

    // or take as input
    // cin >> a >> b;
    cout << binPow(a, b) << endl;

    return 0;
}