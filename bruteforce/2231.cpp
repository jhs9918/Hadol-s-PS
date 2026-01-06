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
 * Problem: 분해합
 * Platform: BOJ
 * Problem Number: 2231
 * URL: https://www.acmicpc.net/problem/2231
 * Category: Bruteforce
 * Difficulty: Bronze II
 */

int seperator(int n) {
    int org = n;
    int temp = 0;
    while (n != 0) {
        temp+=n%10;
        n=n/10;
    }
    return temp+org;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int target_num; cin >> target_num;
    int pos; pos = int(target_num/2);
    bool ans = false;

    while (pos<=target_num) {
        if (seperator(pos) == target_num) {
            ans = true;
            break;
        }
        pos++;
    }

    cout << (ans ? pos : 0);

    return 0;
}
