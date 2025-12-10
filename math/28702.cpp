#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;

/*
 * Problem: FizzBuzz
 * Platform: BOJ
 * Problem Number: 28702
 * URL: https://www.acmicpc.net/problem/28702
 * Category: Math
 * Difficulty: Bronze I
 */

int main() {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    int n = 0;
    for (int i = 0; i < 3; i++) {
        if (isdigit(s[i][0])) {
            n = stoi(s[i]) + 3 - i;
            break;
        }
    }

    if (n % 15 == 0) cout << "FizzBuzz";
    else if (n % 3 == 0) cout << "Fizz";
    else if (n % 5 == 0) cout << "Buzz";
    else cout << n;
}