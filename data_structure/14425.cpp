#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <unordered_set>
using namespace std;

/*
 * Problem: 문자열 집합
 * Platform: BOJ
 * Problem Number: 14425
 * URL: https://www.acmicpc.net/problem/14425
 * Category: Data_Structure
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin>>n>>m;

    unordered_set<string> my_set;

    while(n--) {
        string s; cin>>s;
        my_set.insert(s);
    }

    int count = 0;
    while(m--) {
        string s; cin>>s;
        if (my_set.count(s)) count++;
    }

    cout << count;


    return 0;
}
