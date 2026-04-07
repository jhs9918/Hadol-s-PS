#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
using namespace std;

/*
 * Problem: 단어의 개수
 * Platform: BOJ
 * Problem Number: 1152
 * URL: https://www.acmicpc.net/problem/1152
 * Category: String
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }


    cout << count;


    return 0;
}
