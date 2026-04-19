class Solution {
public:
    bool isPrime(int n) {

        // Prime numbers are greater than 1
        if (n <= 1) return false;

        int count = 0;

        // Check divisors only till sqrt(n)
        // because factors appear in pairs: (i, n/i)
        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                count++;   // divisor i found

                // Count paired divisor separately
                // avoid double count for perfect square
                if ((n / i) != i)
                    count++;
            }
        }

        // Prime means exactly two divisors: 1 and n
        return count == 2;
    }
};