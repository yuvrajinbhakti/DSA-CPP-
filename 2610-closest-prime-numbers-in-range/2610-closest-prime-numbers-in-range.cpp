/*

Solution 1
Explanation
This solution uses the Sieve of Eratosthenes, which is much more efficient for finding prime numbers in a range:

Sieve of Eratosthenes Implementation:

Create a boolean array sieve of size right+1, initially all set to True
For each number i starting from 2 up to sqrt(right): If i is prime (sieve[i] is True), mark all its multiples as non-prime
After the sieve operation, sieve[i] is True if and only if i is prime
Collecting Primes:

We collect all numbers in the range [left, right] that are marked as prime in our sieve
Finding the Closest Pair:

Iterate through consecutive pairs of primes to find the minimum gap
If we find a pair with a smaller gap, update our result
Complexity
Time complexity: O(right * log(log(right)))

Space complexity: O(right)


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false;
        
        for (int i = 2; i * i <= right; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
        
        if (primes.size() < 2) {
            return {-1, -1};
        }
        
        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (int i = 1; i < primes.size(); ++i) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }
        
        return result;
    }
};


*/

/*
Solution 2 (Faster Brute-force)
Prime Checking Function: implemented is_prime function that efficiently checks if a number is prime by:

Handling base cases (1 is not prime, 2 and 3 are prime)
Quickly checking divisibility by 2 and 3
Using the 6k±1 optimization to check other potential divisors
Complexity
Time Complexity: O(right * sqrt(right))
Space Complexity: O(number of primes)


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        auto is_prime = [](int n) {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        vector<int> primes;
        for (int num = max(2, left); num <= right; ++num) {
            if (is_prime(num)) {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); ++i) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};

*/
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        auto is_prime = [](int n) {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        vector<int> primes;
        for (int num = max(2, left); num <= right; ++num) {
            if (is_prime(num)) {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); ++i) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};