#include <iostream>
#include <queue>

using namespace std;

int main(void)
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d, k, c, x, prev_x, i;
    int eaten[3001], first_susis[3000];
    int cnt = 0, max_cnt = 0;
    queue<int> q = queue<int>();

    // input
    cin >> n >> d >> k >> c;
    fill_n(eaten, 3001, 0);
    fill_n(first_susis, 3000, 0);


    for(i = 0; i < k; i++) {
        cin >> x;
        q.push(x);
        first_susis[i] = x;
        if(!eaten[x]) cnt++;
        eaten[x]++;
    }
    if(!eaten[c]) cnt++;
    
    max_cnt = cnt;

    for(int i = k; i < k + n; i++) {
        // 보너스 제거
        if(!eaten[c]) cnt--;

        // 이전 초밥 제거
        prev_x = q.front(); q.pop();
        eaten[prev_x]--;
        if(!eaten[prev_x]) cnt--;
        
        // 새 초밥 보급
        if(i < n) cin >> x;
        else x = first_susis[i%n];

        // 새 초밥 저장
        if(!eaten[x]) cnt++;
        eaten[x]++;
        q.push(x);

        // 보너스 추가
        if(!eaten[c]) cnt++;

        // 맥시멈 갱신
        max_cnt = max(cnt, max_cnt);
    }
    
    cout << max_cnt << '\n';

    return 0;
}