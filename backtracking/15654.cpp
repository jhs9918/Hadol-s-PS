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
 * Problem: N과 M (5)
 * Platform: BOJ
 * Problem Number: 15654
 * URL: https://www.acmicpc.net/problem/15654
 * Category: Backtracking
 * Difficulty: Silver III
 */

int n,m;
vector<int> result;
bool used[9];

vector<int> num_list;


void backtraking(int depth) {
    if (depth == m) {
        for (auto &it : result) {
            cout << it << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;


        used[i] = true;
        result.push_back(num_list[i]);

        backtraking(depth + 1);

        result.pop_back();
        used[i] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        num_list.push_back(num);
    }
    sort(num_list.begin(), num_list.end());

    backtraking(0);

    return 0;
}
