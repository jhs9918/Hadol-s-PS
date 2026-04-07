#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;

/*
 * Problem: 나는야 포켓몬 마스터 이다솜
 * Platform: BOJ
 * Problem Number: 1620
 * URL: https://www.acmicpc.net/problem/1620
 * Category: Data Structure
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, int> num_to_name;
    unordered_map<int, string> name_to_num;
    int n,m; cin>>n>>m;
    for (int i = 1 ; i <= n ; i++) {
        string s; cin>>s;
        num_to_name[s] = i;
        name_to_num[i] = s;
    }
    for (int i = 1; i <= m; i++) {
        string s; cin>>s;
        if (num_to_name.find(s) != num_to_name.end() && !isdigit(s[0])) {
            cout << num_to_name[s] << "\n";
        }
        else {
            cout << name_to_num[stoi(s)] << "\n";
        }
    }

    return 0;
}
