## 수 나누기 게임

https://www.acmicpc.net/problem/27172

## 문제

은하는 "수 나누기 게임" 을 만들었다. (문제는 사이트 참고)

게임이 종료될 때 모든 플레이어의 최종 점수를 구해라.

## 제한

$2 \le N \le 10^5$

$1 \le x_{i} \le 10^6$

모든  $1 \le i < j \le N$에 대해  $x_i \ne x_j$이다.


## Difficulty
* 공식 난이도: Gold 5 (2023.06 기준)
* 체감 난이도: Gold 5


## 알고리즘
* 브루트포스
* 정수론


## 풀이

> 알고리즘 태그에는 소수판정과 에라토스테느스의 체가 있는데 이거에 낚여서 문제를 잘못 풀지 말자

내 카드의 숫자를 $a$라고 하고 다른 사람의 숫자를 $b$ 라고 하자.

$a$로 $b$를 나눠서 0이면 $a$가 승리한다는 것은 $b$가 $a$의 배수를 의미한다.

내 최종 점수의 공식은 다음과 같다

> $a = (a보다 작은 수들 중, 배수가 a인 수들의 갯수) - (a보다 큰 수 중 a의 배수인 수)$

나 포함 모든 플레이어의 최종 점수를 구하려면 이 로직을 구현하면 된다.

1. 모든 플레이어의 카드들을 순회한다.
2. 카드 하나를 잡고 $(카드 번호) * 2$ 부터 $1000000$ 까지 플레이어 카드 숫자의 배수들을 순회한다.
3. 해당 숫자를 가진 카드가 존재하면. 그 카드의 점수를 깎고, 플레이어의 카드의 점수를 추가한다.

```cpp
    for(int i = 1; i <= n; i++) {
        x = card[i];
        for(int p = x+x; p <= MAX; p += x) {
            if(loc[p]) {
                point[loc[p]]--;
                point[i]++;
            }
        }
    }
```