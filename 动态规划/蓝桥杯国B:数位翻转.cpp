#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
long long arr[N], tmp[N];
long long dp[N][N]; // dp[i][j]表示前j个元素取出i个区间的最大和
bool st[N];
int func(int a){
    string str;
    while (a){
        if (a % 2 == 1)
            str.push_back('1');
        else
            str.push_back('0');
        a /= 2;
    }
    int t = 1, ret = str[str.size() - 1] - '0';
    for (int i = str.size() - 2; i >= 0; i--){
        if (str[i] == '1')
            ret = ret + 2 * t;
        t *= 2;
    }
    return ret;
}

int main(){
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = LLONG_MIN;
    cin >> n >> m;
    int i = 0, j;
    for (i = 1; i <= n; i++){
        scanf("%lld", arr + i);
        tmp[i] = func(arr[i]) - arr[i];
    }
    dp[0][0] = 0; // 选 0 段前 0 个数为合法状态

    for (int i = 1; i <= m; ++i){
        for (int j = i; j <= n; ++j){
            long long sum = 0;
            long long maxSeg = LLONG_MIN;
            for (int k = j; k >= i; --k){
                sum += tmp[k];
                maxSeg = max(maxSeg, sum);
                if (dp[i - 1][k - 1] != LLONG_MIN)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + maxSeg);
            }
        }
    }

    long long ans = LLONG_MIN;
    for (int i = 1; i <= m; ++i){
        for (int j = i; j <= n; ++j){
            ans = std::max(ans, dp[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        ans += arr[i];

    printf("%lld", ans);
    return 0;
}