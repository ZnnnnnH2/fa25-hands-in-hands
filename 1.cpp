// 计算 Fibonacci 第 n 项的后四位：F[0]=0, F[1]=1, F[n]=F[n-1]+F[n-2]
// 使用快速倍增法，时间复杂度 O(log n)，并对 10000 取模以避免大数与超时。
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 10000;

// 返回一对 (F(n), F(n+1))，均为 mod MOD 的值
static pair<int, int> fib_pair(long long n)
{
    if (n == 0)
        return {0, 1};
    auto p = fib_pair(n >> 1);
    long long a = p.first;  // F(k)
    long long b = p.second; // F(k+1)

    // 使用恒等式：
    // F(2k)   = F(k) * (2*F(k+1) - F(k))
    // F(2k+1) = F(k)^2 + F(k+1)^2
    long long two_b_minus_a = (2 * b - a) % MOD;
    if (two_b_minus_a < 0)
        two_b_minus_a += MOD;
    long long c = (a * two_b_minus_a) % MOD;             // F(2k)
    long long d = ((a * a) % MOD + (b * b) % MOD) % MOD; // F(2k+1)

    if ((n & 1LL) == 0)
    {
        return {(int)c, (int)d};
    }
    else
    {
        return {(int)d, (int)((c + d) % MOD)};
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n))
        return 0;

    cout << fib_pair(n).first % MOD;
    return 0;
}
