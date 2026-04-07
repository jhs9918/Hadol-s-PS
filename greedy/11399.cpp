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
 * Problem: ATM
 * Platform: BOJ
 * Problem Number: 11399
 * URL: https://www.acmicpc.net/problem/11399
 * Category: G
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    vector<int> v;
    while(n--) {
        int num; cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int cul = 0;
    for (auto& i : v) {
        sum = sum + i;
        cul += sum;
    }

    cout << cul;
    return 0;
}
