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
 * Problem: Z
 * Platform: BOJ
 * Problem Number: 1074
 * URL: https://www.acmicpc.net/problem/1074
 * Category: Miscellaneous
 * Difficulty: Gold V
 */


int f(int r,int c, int size) {
    if (size == 1) return 0;
    int half = size/2;
    if (r < half && c < half) {
        return 0+f(r,c,half);
    }
    else if (r < half && c >= half) {
        return half*half +f(r,c-half,half);
    }
    else if (r = half && c < half) {
        return 2*half*half+ f(r-half,c,half);
    }
    else if (r >= half && c >= half) {
        return 3*half*half+ f(r-half,c-half,half);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    n = pow(2, n);
    int r,c; cin >> r >> c;
    cout << f(r, c, n);
    return 0;
}
