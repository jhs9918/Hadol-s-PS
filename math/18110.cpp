#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

/*
 * Problem: solved.ac
 * Platform: BOJ
 * Problem Number: 18110
 * URL: https://www.acmicpc.net/problem/18110
 * Category: Math
 * Difficulty: Silver IV
 */
double trimmedMean(vector<int> arr, double trimRatio) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int trimCount = (int)round(n * trimRatio);
    int start = trimCount;
    int end = n - trimCount;

    double sum = accumulate(arr.begin() + start, arr.begin() + end, 0.0);
    double average = sum / (end - start);

    // 소수점 둘째 자리에서 반올림
    return (int)round(average);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;

    // 의견이 없으면 난이도 0
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int d;
    vector<int> v;
    while(n--) {
        cin >>d; v.push_back(d);
    }
    cout << trimmedMean(v, 0.15) << '\n';
    return 0;
}
