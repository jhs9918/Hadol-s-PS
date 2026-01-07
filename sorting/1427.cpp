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
 * Problem: 소트인사이드
 * Platform: BOJ
 * Problem Number: 1427
 * URL: https://www.acmicpc.net/problem/1427
 * Category: Sorting
 * Difficulty: Silver V
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성
    int n; cin >> n;

    vector<int> arr;
    int tmp=0;
    while (n!=0) {
        tmp = n%10;
        arr.push_back(tmp);
        n/=10;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (auto &it : arr) {
        cout << it;
    }
    return 0;
}
