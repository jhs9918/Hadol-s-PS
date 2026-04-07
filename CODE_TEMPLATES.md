# 코딩 테스트 필수 코드 템플릿

> 시험장에서 빠르게 복사 붙여넣기 할 수 있도록 정리
> 자주 쓰는 코드는 외우기!

---

## 기본 세팅

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 코드 작성

    return 0;
}
```

---

## BFS (2차원 그리드)

```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문 체크
            if (visited[nx][ny]) continue;
            // 조건 체크 (예: 벽)
            if (board[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    bfs(0, 0);

    return 0;
}
```

---

## BFS (최단 거리)

```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[101][101];
int dist[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;  // 이미 방문
            if (board[nx][ny] == 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(dist, -1, sizeof(dist));  // -1로 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs(0, 0) << '\n';

    return 0;
}
```

---

## BFS (3차원 - 토마토 3D 스타일)

```cpp
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int h, n, m;
int board[101][101][101];
int dist[101][101][101];
int dz[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};

void bfs() {
    queue<tuple<int, int, int>> q;

    // 시작점 모두 추가
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[k][i][j] == 1) {
                    q.push({k, i, j});
                    dist[k][i][j] = 0;
                }
            }
        }
    }

    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nz][nx][ny] != -1) continue;
            if (board[nz][nx][ny] == -1) continue;

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
}
```

---

## DFS (2차원)

```cpp
#include <iostream>
using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) continue;
        if (board[nx][ny] == 0) continue;

        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}
```

---

## 다익스트라 (최단 경로)

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, start;
vector<pair<int, int>> graph[20001];  // {비용, 정점}
int dist[20001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;  // 이미 처리된 정점

        for (auto [next_cost, next] : graph[cur]) {
            int new_cost = cost + next_cost;
            if (new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({new_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> start;

    fill(dist, dist + n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
```

---

## 유니온 파인드 (Union-Find)

```cpp
#include <iostream>
using namespace std;

int parent[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);  // 경로 압축
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            unite(a, b);
        } else {
            if (same(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
```

---

## DP (1차원 - 1로 만들기 스타일)

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }

    cout << dp[n] << '\n';

    return 0;
}
```

---

## DP (2차원 - LCS)

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
```

---

## 백트래킹 (N과 M 1)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;
bool used[9];

void backtrack(int depth) {
    if (depth == m) {
        for (int x : result) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        used[i] = true;
        result.push_back(i);
        backtrack(depth + 1);
        result.pop_back();
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    backtrack(0);

    return 0;
}
```

---

## 이분 탐색 (lower_bound / upper_bound)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        // x 이상인 첫 번째 원소
        auto lb = lower_bound(arr.begin(), arr.end(), x);

        // x 초과인 첫 번째 원소
        auto ub = upper_bound(arr.begin(), arr.end(), x);

        // x의 개수
        int count = ub - lb;
        cout << count << ' ';
    }

    return 0;
}
```

---

## 이분 탐색 (직접 구현 - 파라메트릭 서치)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

bool check(int x) {
    // x가 조건을 만족하는지 확인
    int count = 0;
    for (int a : arr) {
        count += a / x;
    }
    return count >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);

    int left = 1, right = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }

    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
```

---

## 투 포인터

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = 0;
    int count = 0;

    while (right < n) {
        sum += arr[right];
        right++;

        while (sum > m) {
            sum -= arr[left];
            left++;
        }

        if (sum == m) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
```

---

## 자주 하는 실수 체크리스트

### 배열 크기
```cpp
// ❌ 틀림
#define MAX 100000
int arr[MAX];  // 0~99999

// ✅ 정답
#define MAX 100001
int arr[MAX];  // 0~100000
```

### 배열 초기화
```cpp
// memset (1바이트 단위)
memset(arr, 0, sizeof(arr));   // 0으로 초기화
memset(arr, -1, sizeof(arr));  // -1로 초기화

// fill (값 단위)
fill(arr, arr + n, 0);        // 0으로 초기화
fill(arr, arr + n, 1e9);      // INF로 초기화
```

### 문자열 입력
```cpp
// 공백 포함 입력
string s;
getline(cin, s);

// 공백 제외 입력
string s;
cin >> s;

// 문자열을 숫자로
int x = stoi("123");      // 123
long long x = stoll("123456789012");

// 숫자를 문자열로
string s = to_string(123);  // "123"
```

### 자주 쓰는 STL
```cpp
// 벡터
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
sort(v.begin(), v.end());
reverse(v.begin(), v.end());

// 큐
queue<int> q;
q.push(1);
q.pop();
int front = q.front();

// 우선순위 큐
priority_queue<int> pq;  // 최대 힙
priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙

// 맵
map<string, int> m;
m["hello"] = 1;
if (m.count("hello")) { }  // 존재 여부

// 셋
set<int> s;
s.insert(1);
s.erase(1);
if (s.count(1)) { }  // 존재 여부
```

---

**시험장에서 바로 복사 붙여넣기 하세요!**
