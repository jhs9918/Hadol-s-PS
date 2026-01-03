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
 * Problem: 개표
 * Platform: BOJ
 * Problem Number: 10102
 * URL: https://www.acmicpc.net/problem/10102
 * Category: String
 * Difficulty: Bronze III
 */



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    string line; cin>>line;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if (line[i] == 'A') ans++;
        else ans--;
    }
    cout << ((ans > 0) ? "A" : (ans == 0) ? "Tie" : "B");

    return 0;
}
