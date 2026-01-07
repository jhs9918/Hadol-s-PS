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
 * Problem: 리모컨
 * Platform: BOJ
 * Problem Number: 1107
 * URL: https://www.acmicpc.net/problem/1107
 * Category: Bruteforce
 * Difficulty: Gold IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int target; cin >> target;
    int m; cin >> m;

    bool broken[10] = {false};
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        broken[num] = true;
    }

    int ans = abs(target - 100);

    for (int ch = 0; ch <= 999999; ch++) {
        // 이 채널을 숫자 버튼으로 입력 가능한지 확인
        string s = to_string(ch);
        bool can_press = true;

        for (char c : s) {
            if (broken[c - '0']) {
                can_press = false;
                break;
            }
        }

        if (can_press) {
            // 숫자 버튼 클릭 수 + +/- 버튼으로 이동하는 클릭 수
            int clicks = s.length() + abs(ch - target);
            ans = min(ans, clicks);
        }
    }

    cout << ans << '\n';

    return 0;
}
