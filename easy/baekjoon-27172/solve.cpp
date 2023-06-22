#include <iostream>
#include <string>

#define MAX 1000000

using namespace std;

int main(void)
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    int card[100001], point[100001];
    int loc[1000001];

    cin >> n;
    fill_n(loc, 1000001, 0);
    fill_n(point, n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> card[i];
        loc[card[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        x = card[i];
        for(int p = x+x; p <= MAX; p += x) {
            if(loc[p]) {
                point[loc[p]]--;
                point[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << point[i] << ' ';
    return 0;
}