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
 * Problem: 수 정렬하기
 * Platform: BOJ
 * Problem Number: 2750
 * URL: https://www.acmicpc.net/problem/2750
 * Category: Sorting
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin >> n;
    vector<int> v;
    while (n--) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }


    return 0;
}
