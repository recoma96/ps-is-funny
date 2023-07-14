#include <iostream>
#include <string>

#define MAX 1000000

using namespace std;

int main(void)
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, delta[1000], x, ans = 0;
    bool on = false;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> delta[i];
    for(int i = 0; i < n; i++) {
        cin >> x;
        delta[i] -= x;
    }

    for(int step = 1; step <= 80; step++) {
        on = false;
        for(int i = 0; i < n; i++) {
            if(delta[i] >= step) {
                on = true;
            } else {
                if(on) ans++;
                on = false;
            }
        }
        if(on) ans++;
    }

    for(int step = -1; step >= -80; step--) {
        on = false;
        for(int i = 0; i < n; i++) {
            if(delta[i] <= step) {
                on = true;
            } else {
                if(on) ans++;
                on = false;
            }
        }
        if(on) ans++;
    }
    
    cout << ans << '\n';

    return 0;
}