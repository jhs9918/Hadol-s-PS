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
 * Problem: 요세푸스 문제 2
 * Platform: BOJ
 * Problem Number: 1168
 * URL: https://www.acmicpc.net/problem/1168
 * Category: Data_Structure
 * Difficulty: Platinum III
 */

int N, K;
vector<int> tree;

// 세그먼트 트리 빌드: 각 위치에 사람이 있으면 1
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;  // 초기에는 모든 사람이 남아있음
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// pos 위치의 사람을 제거 (1 -> 0)
void update(int node, int start, int end, int pos) {
    if (pos < start || pos > end) return;

    tree[node]--;  // 구간 내 남은 사람 수 감소

    if (start == end) return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, pos);
    update(node * 2 + 1, mid + 1, end, pos);
}

// k번째로 남아있는 사람의 인덱스 찾기
int query(int node, int start, int end, int k) {
    if (start == end) return start;

    int mid = (start + end) / 2;
    int left_count = tree[node * 2];  // 왼쪽 자식에 남아있는 사람 수

    if (k <= left_count) {
        // k번째 사람이 왼쪽에 있음
        return query(node * 2, start, mid, k);
    } else {
        // k번째 사람이 오른쪽에 있음
        return query(node * 2 + 1, mid + 1, end, k - left_count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    tree.resize(N * 4);
    build(1, 1, N);

    cout << "<";

    int idx = 1;  // 현재 위치 (1-indexed)
    for (int i = 0; i < N; i++) {
        int size = N - i;  // 남은 사람 수
        idx = (idx + K - 1 - 1) % size + 1;  // K번째로 이동

        int person = query(1, 1, N, idx);  // idx번째 사람 찾기

        if (i < N - 1) {
            cout << person << ", ";
        } else {
            cout << person;
        }

        update(1, 1, N, person);  // 제거
    }

    cout << ">\n";

    return 0;
}
