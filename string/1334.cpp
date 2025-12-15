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
 * Problem: 다음 팰린드롬 수
 * Platform: BOJ
 * Problem Number: 1334
 * URL: https://www.acmicpc.net/problem/1334
 * Category: String
 * Difficulty: Gold V
 */

string nextPalindrome(string n) {
    int len = n.length();

    // 모두 9인 경우 (999 -> 1001)
    bool all9 = true;
    for (char c : n) {
        if (c != '9') {
            all9 = false;
            break;
        }
    }
    if (all9) {
        return "1" + string(len - 1, '0') + "1";
    }

    // 왼쪽 절반을 오른쪽에 미러링
    string palin = n;
    for (int i = 0; i < len / 2; i++) {
        palin[len - 1 - i] = palin[i];
    }

    // 만든 팰린드롬이 n보다 크면 바로 반환
    if (palin > n) {
        return palin;
    }

    // 작거나 같으면 중간 부분을 1 증가
    int mid = (len - 1) / 2;
    int carry = 1;

    // 중간부터 왼쪽으로 1씩 더하면서 캐리 처리
    while (mid >= 0 && carry) {
        int digit = (palin[mid] - '0') + carry;
        palin[mid] = (digit % 10) + '0';
        carry = digit / 10;
        mid--;
    }

    // 캐리가 남으면 자릿수 증가 (999 -> 1001)
    if (carry) {
        return "1" + string(len - 1, '0') + "1";
    }

    // 왼쪽을 오른쪽에 다시 미러링
    for (int i = 0; i < len / 2; i++) {
        palin[len - 1 - i] = palin[i];
    }

    return palin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n;
    cin >> n;

    cout << nextPalindrome(n) << '\n';

    return 0;
}
