#include <iostream>
#include <string>
#include <map>

using namespace std;

void insert_mbti(map<string, int>& mbti_map, string mbti) {
    if(mbti_map.find(mbti) == mbti_map.end())
        mbti_map[mbti] = 1;
    else if(mbti_map[mbti] < 3)
        mbti_map[mbti]++;
}

int mbti_len(string& m1, string& m2) {
    int cnt = 0;
    for(int i = 0; i < 4; i++)
        cnt += (m1.at(i) == m2.at(i)) ? 0 : 1;
    return cnt;
}

void solve() {
    int n, _ans, ans = 1e9, cnt = 0;
    string input;
    map<string, int> mbti_map;
    string mbti_arr[48];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input;
        insert_mbti(mbti_map, input);
    }

    for(map<string, int>::iterator iter = mbti_map.begin(); iter != mbti_map.end(); iter++) {
        string mbti_val = iter->first;
        int mbti_cnt = iter->second;
        for(int i = 0; i < mbti_cnt; i++) mbti_arr[cnt++] = mbti_val; 
    }

    for(int i = 0; i < cnt; i++) {
        for(int j = i+1; j < cnt; j++) {
            for(int k = j+1; k < cnt; k++) {
                _ans = mbti_len(mbti_arr[i], mbti_arr[j])
                        + mbti_len(mbti_arr[j], mbti_arr[k])
                        + mbti_len(mbti_arr[k], mbti_arr[i]);
                ans = min(ans, _ans);
            }
        }
    }

    cout << ans << '\n';
}

int main(void)
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}