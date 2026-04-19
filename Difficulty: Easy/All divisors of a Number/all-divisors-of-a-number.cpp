class Solution {
public:
    void print_divisors(int n) {
        vector<int> v;

        // Instead of checking till n, we only go till sqrt(n)
        // because divisors always come in pairs: (i , n/i)
        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                // First divisor of the pair
                v.push_back(i);

                // Second divisor of the pair
                // Avoid duplicate when n is a perfect square
                if ((n / i) != i) {
                    v.push_back(n / i);
                }
            }
        }

        // Pairs are not inserted in sorted order, so sort at end
        sort(v.begin(), v.end());

        for (auto i : v) {
            cout << i << " ";
        }
    }
};