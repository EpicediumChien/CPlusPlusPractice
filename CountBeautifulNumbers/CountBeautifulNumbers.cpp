// CountBeautifulNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/count-beautiful-numbers/description/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <numeric> // for std::gcd
using namespace std;
//
//const auto a = std::cin.tie(nullptr)->sync_with_stdio(false);
//const auto b = []()
//    {
//        struct c
//        {
//            static void d() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//        };
//        std::atexit(&c::d);
//        return 0;
//    }();
class Solution {
public:
    int dp[9][82][82] = {};
    int powers[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
    // count zero free beautiful numbers
    int zero[9] = { 0, 1, 9, 171, 2439, 30951, 368559, 4217031, 46953279 };
    Solution() {
        /*
        for(int i = 0; i < 9; i++) {
            cout << countZero(i) << ", ";
        }
        cout << endl;
        */
    }

    int count(int digits, int sum, int product) {
        if (digits == 0) {
            return 0;
        }
        if (dp[digits - 1][sum][product] > 0) {
            return dp[digits - 1][sum][product] - 1;
        }
        if (digits == 1) {
            if (sum <= 9 && sum >= 1 && sum % product == 0) {
                dp[digits - 1][sum][product] = 1;
            }
            else {
                dp[digits - 1][sum][product] = 0;
            }
        }
        else {
            for (int i = 1; i <= 9 && sum - i > 0; i++) {
                int factor = std::gcd(i, product);
                dp[digits - 1][sum][product] += count(digits - 1, sum - i, product / factor);
            }
        }
        return dp[digits - 1][sum][product]++;
    }
    // count all zero free beautiful numbers
    int count(int digits) {
        int total = 0;
        for (int sum = 1; sum <= digits * 9; sum++) {
            total += count(digits, sum, sum);
        }
        return total;
    }
    // count k digit numbers containing at least one zero
    int countZero(int digits) {
        if (digits == 0) {
            return 0;
        }
        else if (digits == 1) {
            return 1;
        }
        else if (digits == 2) {
            return 9;
        }
        else {
            // assume there is no zero in the first or second position
            int total = 9 * countZero(digits - 1);
            // assume there is a zero in the second position
            total += 9 * powers[digits - 2];
            return total;
        }
    }
    // count all beautiful numbers with k digits or less
    int countBeautiful(int digits) {
        int total = 0;
        for (int i = 1; i <= digits; i++) {
            total += count(i) + zero[i];
        }
        return total;
    }

    // count all beautiful numbers less than or equal to x
    int beautiful(int x) {
        if (x == 0) {
            return 0;
        }
        // get the digits
        string digits = to_string(x);
        // count beautiful numbers with fewer digits
        int total = countBeautiful(digits.size() - 1);
        if (total > 0) {
            // don't count zero
            total--;
        }
        // keep track of sum and product for fixed digits
        int prefix_sum = 0;
        int prefix_product = 1;
        for (int i = 0; i < digits.size(); i++) {
            // for each digit, start by counting all zero free beautiful numbers 
            int start = i == 0 ? 1 : 0;
            int remaining_digits = digits.size() - i - 1;
            for (int digit = start; digit < digits[i] - '0'; digit++) {
                int sum = prefix_sum + digit;
                int product = prefix_product * digit;
                if (product == 0) {
                    // remaining digits are completely free
                    total += powers[remaining_digits];
                }
                else {
                    // count continuations that have a zero
                    total += zero[remaining_digits];
                    if (remaining_digits > 1) {
                        total += powers[remaining_digits - 1];
                    }
                    // count continuations without a zero
                    if (remaining_digits == 0 && product % sum == 0) {
                        total++;
                    }
                    for (int s = remaining_digits * 9; s > 0; s--) {
                        total += count(remaining_digits, s, (s + sum) / std::gcd(s + sum, product));
                    }
                }
            }
            // fix the current digit
            prefix_sum += (digits[i] - '0');
            prefix_product *= (digits[i] - '0');
        }
        if (prefix_product % prefix_sum == 0) {
            total++;
        }
        return total;
    }

    int beautifulNumbers(int l, int r) {
        return beautiful(r) - beautiful(l - 1);
    }
};

int main()
{
    vector<int> testCase{ 1, 2, 0 };
    int answer = 3;
    Solution sol;
    cout << to_string(sol.beautifulNumbers(10, 20));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file