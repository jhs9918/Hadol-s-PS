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
 * Problem: 피보나치 함수
 * Platform: BOJ
 * Problem Number: 1003
 * URL: https://www.acmicpc.net/problem/1003
 * Category: Dp
 * Difficulty: Silver III
 */

//bfs 로 풀긴 했는데 정해는 dp라고함. 나는 1부터 시작해서 가장 먼저 x에 도착하는 경우를 찾는 bfs를 생각했는데
//코드가 간단해지는 것 외에 왜 dp가 정해인지 생각이 필요해보임.
// 시간복잡도는 둘 다 O(N)으로 같음. DP가 정해인 건
//   성능 때문이 아니라 문제 구조를 더 직접적으로 모델링하기 때문이라 함.


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int one[41] = {0, 1};
    int zer[41] = {1, 0};

    for (int i = 2; i <= 40; i++) {
        one[i] = one[i-1] + one[i-2];
        zer[i] = zer[i-1] + zer[i-2];
    }
    int n; cin >> n;
    while (n--) {
        int num; cin >> num;
        cout << zer[num] << " " << one[num] << endl;
    }
    return 0;
}
