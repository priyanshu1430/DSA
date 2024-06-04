#define mod 1000000007

class Solution {
public:
    long long powMod(long long x, long long n) {
        if (n == 0)
            return 1;
        x = x % mod;
        if (n % 2 == 0) // even n
            return powMod((x * x) % mod, n / 2);
        else // odd n
            return (x * powMod((x * x) % mod, n / 2)) % mod;
    }

    int countGoodNumbers(long long n) {
        long long odd = n / 2; // number of odd places
        long long even = n / 2 + n % 2; // number of even places
        int eno = 5; // number of even numbers from 0-9
        int ono = 4; // number of odd numbers from 0-9
        return (powMod(eno, even) * powMod(ono, odd)) % mod;
    }
};
