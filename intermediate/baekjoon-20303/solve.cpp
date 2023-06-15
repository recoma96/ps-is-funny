#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct _Element {
    int child_cnt;
    int candy_cnt;
} Element;

int main(void)
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, ans = 0;
    int candy[30001], napsack[3001];
    bool visited[30001];
    vector<int> children[30001];
    stack<int> s;
    vector<Element> arr;

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> candy[i];
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u);
    }

    // 한번에 뺏을 수 있는 아이들의 수와 캔디합 구해서 배열에 넣기
    fill_n(visited, n+1, false);
    for(int root = 1; root <= n; root++) {
        if(!visited[root]) {
            Element element = {0, 0};
            s.push(root);
            visited[root] = true;
            element.candy_cnt = candy[root];
            element.child_cnt += 1;

            while(!s.empty()) {
                int u = s.top();
                s.pop();
                for(int i = 0; i < (int)children[u].size(); i++) {
                    int v = children[u][i];
                    if(!visited[v]) {
                        s.push(v);
                        visited[v] = true;
                        element.candy_cnt += candy[v];
                        element.child_cnt += 1;
                    }
                }
            }
            if(element.child_cnt < k)
                arr.push_back(element);
        }
    }
    
    if(arr.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    // 배낭문제원리로 최댓값 구하기
    fill_n(napsack, k, 0);
    for(int i = 0; i < (int)arr.size(); i++) {
        int child_cnt = arr[i].child_cnt;
        int candy_cnt = arr[i].candy_cnt;
        for(int j = k - child_cnt - 1; j > 0; j--) {
            if(napsack[j])
                napsack[j+child_cnt] = max(napsack[j+child_cnt], napsack[j] + candy_cnt);
        }
        napsack[child_cnt] = max(napsack[child_cnt], candy_cnt);
    }

    for(int i = 1; i < k; i++) ans = max(ans, napsack[i]);
    cout << ans << '\n';

    return 0;
}