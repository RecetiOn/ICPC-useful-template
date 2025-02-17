// Jamhus Tao / GreatLiangpi
// Start at 2022/10/6
// Please using int32_t and int64_t to replace the int and long long.
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

// 乱七八糟
namespace l78z
{
    // 1 的 一阶前缀和: n
    // 1 的 二阶前缀和: n * (n + 1) / 2
    // 1 的 三阶前缀和: n * (n + 1) * (n + 2) / 6
    // 1 的 k 阶前缀和: C(n + k - 1, k) = fac[n + k - 1] * inv[k] % MOD * inv[n - 1] % MOD
    // n 的 一阶前缀和: n * (n + 1) / 2
    // n^2 的 一阶前缀和: n * (n + 1) * (2 * n + 1) / 6
    // n^3 的 一阶前缀和: n * n * (n + 1) * (n + 1) / 4
    // pi = M_PI = acos(-1)
    // e  = M_E  = exp(1)
    double log(double x);             // ln x
    double log2(double x);            // ln x / ln 2
    double log10(double x);           // ln x / ln 10
    double hypot(double x, double y); // sqrt(x * x, y * y)

    int atoi(const char *_Str);                                // char * -> int
    long long atoll(const char *_Str);                         // char * -> long long
    double atof(const char *_Str);                             // char * -> double
    int sscanf(const char *_source, const char *_format, ...); // similar to scanf but read from _source
    int sprintf(char *__stream, const char *__format, ...);    // similar to printf but write to __stream

    void *memset(void *_Dst, int _Val, size_t _Size);                                 // set the same value in the memory byte by byte
    void iota(vector<int>::iterator _first, vector<int>::iterator _last, int _value); // set increasing value started from _value
}

// STL
namespace stl
{
    namespace pair_
    {
        std::pair<int, int> p;
        void demo()
        {
            int &ff = p.first;  // 返回键的引用
            int &ss = p.second; // 返回值的引用
        }
    }

    namespace vector_
    {
        std::vector<int> vec;
        std::vector<int> vec2;
        std::set<int> st;
        int a[] = {9, 6, 3, 7, 1};
        void demo()
        {
            vec = vector<int>();                                                  // 匿名对象.
            vec = std::vector<int>(5, 2);                                         // 初始化: {2, 2, 2, 2, 2}
            vec = vector<int>{9, 6, 3, 7, 1};                                     // 初始化: {9, 6, 3, 7, 1}
            vec = vec2;                                                           // 拷贝而非引用.
            vec.assign(5, 2);                                                     // 重置: {2, 2, 2, 2, 2}
            vec.assign(begin(a), end(a));                                         // 重置: {9, 6, 3, 7, 1}
            vec.assign(st.begin(), st.end());                                     // 从其他类型拷贝.
            vec.at(0);                                                            // 检测越界的访问.
            int &x = vec.back();                                                  // 返回尾值的引用.
            std::vector<int>::iterator it = vec.begin();                          // 返回头迭代器.
            unsigned long long siz = vec.capacity();                              // 返回容器容量.
            vec.clear();                                                          // 清空容器.
            int *p = vec.data();                                                  // 返回内存指针.
            bool flag = vec.empty();                                              // 返回布尔: 为空.
            std::vector<int>::iterator it = vec.end();                            // 返回尾后迭代器.
            std::vector<int>::iterator it = vec.erase(it);                        // 移除迭代器, 返回下一个迭代器.
            std::vector<int>::iterator it = vec.erase(it, it + 2);                // 移除区间迭代器, 返回区间的下一个迭代器.
            int &x = vec.front();                                                 // 返回头值的引用.
            std::vector<int>::iterator it = vec.insert(it, 2);                    // 插入数值, 返回插入值的迭代器.
            std::vector<int>::iterator it = vec.insert(it, 5, 2);                 // 插入重复数值, 返回第一个插入值的迭代器.
            std::vector<int>::iterator it = vec.insert(it, st.begin(), st.end()); // 插入区间迭代器, 返回第一个插入值的迭代器. 这里的迭代器可以是任意容器的迭代器.
            vec.pop_back();                                                       // 删除最后一个元素
            vec.push_back(2);                                                     // 追加一个元素
            vec.reserve(100);                                                     // 设置容器容量, 如果容量设置为 < .capacity() 将是无效的.
            vec.resize(100);                                                      // 设置长度, 不足补0, 多余删除.
            vec.shrink_to_fit();                                                  // 缩减容器容量, 使之 == .size().
            unsigned long long siz = vec.size();                                  // 返回容器长度.
        }
    }

    namespace deque_
    {
        // 对比 vector
        // deque 具有头尾移除与追加的权限, 而 vector 只有尾部追加与移除的权限.
        // vector 具有 capacity() 与 reserve() 的方法, deque 中不支持使用.
        std::deque<int> deq;
        std::deque<int> deq2;
        std::set<int> st;
        int a[] = {9, 6, 3, 7, 1};
        void demo()
        {
            deq = std::deque<int>();                                             // 参考 vector
            deq = std::deque<int>(5, 2);                                         // 参考 vector
            deq = std::deque<int>{9, 6, 3, 7, 1};                                // 参考 vector
            deq = deq2;                                                          // 参考 vector
            deq.assign(5, 2);                                                    // 参考 vector
            deq.assign(begin(a), end(a));                                        // 参考 vector
            deq.assign(st.begin(), st.end());                                    // 参考 vector
            deq.at(0);                                                           // 参考 vector
            int &x = deq.back();                                                 // 参考 vector
            std::deque<int>::iterator it = deq.begin();                          // 参考 vector
            deq.clear();                                                         // 参考 vector
            bool flag = deq.empty();                                             // 参考 vector
            std::deque<int>::iterator it = deq.end();                            // 参考 vector
            deque<int>::iterator it = deq.erase(it);                             // 参考 vector
            deque<int>::iterator it = deq.erase(it, it + 2);                     // 参考 vector
            int &x = deq.front();                                                // 参考 vector
            std::deque<int>::iterator it = deq.insert(it, 2);                    // 参考 vector
            std::deque<int>::iterator it = deq.insert(it, 5, 2);                 // 参考 vector
            std::deque<int>::iterator it = deq.insert(it, st.begin(), st.end()); // 参考 vector
            deq.pop_back();                                                      // 移除尾值.
            deq.pop_front();                                                     // 移除头值.
            deq.push_back(2);                                                    // 追加头值.
            deq.push_front(2);                                                   // 追加头值.
            deq.resize(100);                                                     // 设置长度, 不足后补0, 多余删除后部.
            deq.shrink_to_fit();                                                 // 参考 vector
            unsigned long long siz = deq.size();                                 // 参考 vector
        }
    }

    namespace queue_
    {
        // 对比 deque
        // queue 是一个权限受限的 deque, 裁剪大量方法, 利于便捷使用.
        std::queue<int> que;
        std::queue<int> que2;
        void demo()
        {
            que = std::queue<int>();             // 参考 deque
            que = que2;                          // 参考 deque
            int &x = que.back();                 // 参考 deque, 该方法事实上不是 queue 应当拥有的.
            bool flag = que.empty();             // 参考 deque
            int &x = que.front();                // 参考 deque
            que.pop();                           // 参考 deque.pop_front()
            que.push(2);                         // 参考 deque.push_back()
            unsigned long long siz = que.size(); // 参考 deque
        }
    }

    namespace stack_
    {
        // 对比 deque
        // stack 是一个权限受限的 deque, 裁剪大量方法, 利于便捷使用.
        std::stack<int> stk;
        std::stack<int> stk2;
        void demo()
        {
            stk = std::stack<int>();             // 参考 deque
            stk = stk2;                          // 参考 deque
            bool flag = stk.empty();             // 参考 deque
            stk.pop();                           // 参考 deque.pop_back()
            stk.push(2);                         // 参考 deque.push_back()
            unsigned long long siz = stk.size(); // 参考 deque
            int &x = stk.top();                  // 参考 deque.back()
        }
    }

    namespace priority_queue_
    {
        // 对比 queue
        // 事实上 priority_queue 是一个堆, 实时排序的 queue, 两者在方法上基本一致.
        template <typename T>
        class cmp
        {
            bool operator()(const T &x, const T &y) { return x < y; } // 自定义排序函数
        };
        std::priority_queue<int> heap;                             // 大顶堆
        std::priority_queue<int, vector<int>, less<int>> heap2;    // 大顶堆
        std::priority_queue<int, vector<int>, greater<int>> heap3; // 小顶堆
        std::priority_queue<int, vector<int>, cmp<int>> heap4;     // 自定义排序堆
        void demo()
        {
            heap = std::priority_queue<int>();    // 参考 queue
            heap = heap2;                         // 参考 queue
            bool flag = heap.empty();             // 参考 queue
            heap.pop();                           // 参考 queue
            heap.push(2);                         // 参考 queue
            unsigned long long siz = heap.size(); // 参考 queue
            int x = heap.top();                   // 参考 queue.front(), 注意这里返回值不是一个引用.
        }
    }

    namespace set_
    {
        std::set<int> S;
        std::set<int> S2;
        void demo()
        {
            S = std::set<int>();                    // 匿名对象.
            S = std::set<int>{9, 6, 3, 7, 1};       // 初始化: {1, 3, 6, 7, 9}
            S = S2;                                 // 拷贝而非引用.
            std::set<int>::iterator it = S.begin(); // 返回头迭代器.
            S.clear();                              // 清空容器.
            int count = S.count(2);                 // 返回值出现数量.
            bool flag = S.empty();                  // 返回布尔: 为空.
            std::set<int>::iterator it = S.end();   // 返回尾后迭代器.
            std::pair<std::set<int>::iterator, std::set<int>::iterator> p = S.equal_range(2);
            // 返回相等区间指针, 等价于 make_pair(S.lower_bound(2), S.upper_bound(2)).
            std::set<int>::iterator it = S.erase(it);                  // 移除迭代器, 返回下一个迭代器.
            std::set<int>::iterator it = S.erase(it, ++ ++it);         // 移除区间迭代器, 返回区间的下一个迭代器.
            unsigned long long siz = S.erase(2);                       // 移除所有指定值, 返回移除数量.
            std::set<int>::iterator it = S.find(2);                    // 查找数值, 返回值迭代器, 未找到返回尾后迭代器.
            std::pair<std::set<int>::iterator, bool> it = S.insert(2); // 插入数值, 返回插入值的迭代器.
            std::set<int>::iterator it = S.lower_bound(2);             // 返回第一个大于等于值的迭代器.
            unsigned long long siz = S.size();                         // 返回容器大小.
            std::set<int>::iterator it = S.upper_bound(2);             // 返回第一个大于值的迭代器.
        }
    }

    namespace map_
    {
        std::map<int, int> mp;
        std::map<int, int> mp2;
        void demo()
        {
            mp = std::map<int, int>();                                       // 匿名对象.
            mp = std::map<int, int>{{9, 1}, {6, 0}, {3, 0}, {7, 8}, {1, 6}}; // 初始化: {{1, 6}, {3, 0}, {6, 0}, {7, 8}, {9, 1}}
            mp = mp2;                                                        // 参考 set
            std::map<int, int>::iterator it = mp.begin();                    // 参考 set
            mp.clear();                                                      // 参考 set
            int count = mp.count(2);                                         // 参考 set
            bool flag = mp.empty();                                          // 参考 set
            std::map<int, int>::iterator it = mp.end();                      // 参考 set
            std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> p = mp.equal_range(2);
            // 参考 set
            std::map<int, int>::iterator it = mp.erase(it);                                     // 参考 set
            std::map<int, int>::iterator it = mp.erase(it, ++ ++it);                            // 参考 set
            unsigned long long siz = mp.erase(2);                                               // 参考 set
            std::map<int, int>::iterator it = mp.find(2);                                       // 参考 set
            std::pair<std::map<int, int>::iterator, bool> it = mp.insert(pair<int, int>(2, 2)); // 参考 set
            std::map<int, int>::iterator it = mp.lower_bound(2);                                // 参考 set
            unsigned long long siz = mp.size();                                                 // 参考 set
            std::map<int, int>::iterator it = mp.upper_bound(2);                                // 参考 set
        }
    }

    namespace list_
    {
        bool cmp(int x, int y) { return x > y; }
        std::list<int> ls;
        std::list<int> ls2;
        std::set<int> st;
        int a[] = {9, 6, 3, 7, 1};
        void demo()
        {
            ls = std::list<int>();                                             // 参考 vector
            ls = std::list<int>(5, 2);                                         // 参考 vector
            ls = std::list<int>{9, 6, 3, 7, 1};                                // 参考 vector
            ls = ls2;                                                          // 参考 vector
            ls.assign(5, 2);                                                   // 参考 vector
            ls.assign(begin(a), end(a));                                       // 参考 vector
            ls.assign(st.begin(), st.end());                                   // 参考 vector
            int &x = ls.back();                                                // 参考 vector
            std::list<int>::iterator it = ls.begin();                          // 参考 vector
            ls.clear();                                                        // 参考 vector
            bool flag = ls.empty();                                            // 参考 vector
            std::list<int>::iterator it = ls.end();                            // 参考 vector
            list<int>::iterator it = ls.erase(it);                             // 参考 vector
            list<int>::iterator it = ls.erase(it, ++ ++it);                    // 参考 vector
            int &x = ls.front();                                               // 参考 vector
            std::list<int>::iterator it = ls.insert(it, 2);                    // 参考 vector
            std::list<int>::iterator it = ls.insert(it, 5, 2);                 // 参考 vector
            std::list<int>::iterator it = ls.insert(it, st.begin(), st.end()); // 参考 vector
            ls.merge(ls2);                                                     // 合并序列.
            ls.merge(ls2, cmp);                                                // 合并排序序列.
            ls.pop_back();                                                     // 移除尾值.
            ls.pop_front();                                                    // 移除头值.
            ls.push_back(2);                                                   // 追加头值.
            ls.push_front(2);                                                  // 追加头值.
            ls.remove(2);                                                      // 移除所有与值相等的元素
            ls.resize(100);                                                    // 设置长度, 不足后补0, 多余删除后部.
            ls.sort();                                                         // 排序序列.
            ls.sort(cmp);                                                      // 自定义排序序列.
            unsigned long long siz = ls.size();                                // 参考 vector
        }
    }
}

// 高精度
// !!!!!! 此高精度乘法与除法为朴素的高精度与高精度运算, 平方效率
// Source: https://blog.csdn.net/xiji333/article/details/120812406
class BigInteger
{
private:
    vector<int32_t> nums;    // 低位到高位存储
    bool isPositive = 1;     // 符号位
    int32_t length = 0;      // 位数
    const int32_t digit = 8; // 存储元位数
    const int32_t mod = 1e8;

    size_t size() const { return nums.size(); }
    void cutLeadZero()
    {
        while (nums.size() > 1 && nums.back() == 0)
            nums.pop_back();
        if (nums.empty())
            length = 0;
        else
        {
            length = (nums.size() - 1) * digit + to_string(nums.back()).size();
        }
    }
    bool isZero() const { return nums.size() == 1 && nums.back() == 0; }
    BigInteger absValue() const { return move(BigInteger(nums)); }
    BigInteger e(size_t n) const
    {
        if (n <= 0)
            return move(BigInteger(vector<int32_t>(1, 1)));
        int32_t m = n / digit;
        n -= m * digit;
        vector<int32_t> ans(m);
        string s = "1";
        s += move(string(n, '0'));
        ans.push_back(stoi(s));
        return move(BigInteger(ans));
    }

public:
    BigInteger(){};
    BigInteger(const string &s)
    {
        int32_t n = s.size(), minIdx = 0;
        if (s[0] == '-')
            isPositive = false, minIdx = 1;
        else if (s[0] == '+')
            isPositive = true, minIdx = 1;
        for (int32_t i = n - 1; i >= minIdx; i -= digit)
        {
            int32_t beg = max(minIdx, i - digit + 1);
            nums.push_back(stoi(s.substr(beg, i - beg + 1)));
        }
        cutLeadZero();
    }
    BigInteger(int64_t a) : BigInteger(to_string(a)) {}
    BigInteger(const BigInteger &bInt) : nums(bInt.nums), isPositive(bInt.isPositive), length(bInt.length) {}
    BigInteger(BigInteger &&bInt) noexcept : nums(move(bInt.nums)), isPositive(bInt.isPositive), length(bInt.length) {}
    BigInteger(const vector<int32_t> &vec, bool sign = true) : nums(vec), isPositive(sign) { cutLeadZero(); }

    friend istream &operator>>(istream &is, BigInteger &bInt)
    {
        string s;
        is >> s;
        bInt = move(BigInteger(s));
        return is;
    }
    friend ostream &operator<<(ostream &os, const BigInteger &bInt)
    {
        os << (string)bInt;
        return os;
    }

    operator string() const
    {
        string ans;
        if (!isPositive)
            ans += "-";
        int32_t n = nums.size();
        for (int32_t i = n - 1; i >= 0; i--)
        {
            string s = to_string(nums[i]);
            if (i != n - 1)
                ans += string(digit - s.size(), '0');
            ans += s;
        }
        return ans;
    }

    BigInteger operator+() const { return *this; }
    BigInteger operator-() const
    {
        BigInteger tmp(*this);
        if (!tmp.isZero())
            tmp.isPositive = !isPositive;
        return tmp;
    }

    bool operator<(const BigInteger &bInt) const
    {
        if (isPositive && !bInt.isPositive)
            return false;
        if (!isPositive && bInt.isPositive)
            return true;
        bool flag = true;
        if (!isPositive)
            flag = false; // 都为负数
        if (length < bInt.length)
            return flag;
        else if (length > bInt.length)
            return !flag;
        int32_t n = size();
        for (int32_t i = n - 1; i >= 0; i--)
        {
            if (nums[i] < bInt[i])
                return flag;
            else if (nums[i] > bInt[i])
                return !flag;
        }
        return false;
    }
    bool operator<=(const BigInteger &bInt) const
    {
        if (isPositive && !bInt.isPositive)
            return false;
        if (!isPositive && bInt.isPositive)
            return true;
        bool flag = true;
        if (!isPositive)
            flag = false; // 都为负数
        if (length < bInt.length)
            return flag;
        else if (length > bInt.length)
            return !flag;
        int32_t n = size();
        for (int32_t i = n - 1; i >= 0; i--)
        {
            if (nums[i] < bInt[i])
                return flag;
            else if (nums[i] > bInt[i])
                return !flag;
        }
        return true;
    }
    bool operator==(const BigInteger &bInt) const
    {
        if (length != bInt.length)
            return false;
        int32_t n = size();
        for (int32_t i = 0; i < n; i++)
            if (nums[i] != bInt[i])
                return false;
        return true;
    }

    BigInteger operator+(const BigInteger &bInt) const
    {
        if (!bInt.isPositive)
            return *this - (-bInt); // 加上负数 = 减去其绝对值
        if (!isPositive)
            return bInt - (-*this); // 负数+正数 = 整数-(-负数)
        // 要么都正 要么都负
        vector<int32_t> ans;
        int32_t n = size(), m = bInt.size(), sum = 0, i = 0, j = 0;
        while (i < n || j < m || sum)
        {
            if (i < n)
                sum += nums[i++];
            if (j < m)
                sum += bInt[j++];
            ans.push_back(sum % mod);
            sum /= mod;
        }
        return move(BigInteger(ans, isPositive));
    }
    BigInteger operator-(const BigInteger &bInt) const
    {
        if (!bInt.isPositive)
            return *this + (-bInt); // 减去负数 = 加上其绝对值
        if (!isPositive)
            return -((-*this) + bInt); // 负数-正数 = -(-负数 + 正数)
        if (*this < bInt)
            return -(bInt - *this);
        // 只计算大数减去小数
        vector<int32_t> ans;
        int32_t i = 0, j = 0, n = size(), m = bInt.size(), sum = 0;
        while (i < n || j < m || sum)
        {
            if (i < n)
                sum += nums[i++];
            if (j < m)
                sum -= bInt[j++];
            int32_t flag = 0;
            if (sum < 0)
            {
                flag = -1;
                sum += mod;
            }
            ans.push_back(sum);
            sum = flag;
        }
        return move(BigInteger(ans));
    }
    BigInteger operator*(const BigInteger &bInt) const
    {
        int32_t n = size(), m = bInt.size();
        vector<int32_t> ans(n + m);
        using int64_t = long long;
        for (int32_t i = 0; i < n; i++)
        {
            for (int32_t j = 0; j < m; j++)
            {
                int64_t tmp = ans[i + j] + nums[i] * 1ll * bInt[j];
                ans[i + j] = tmp % mod;
                ans[i + j + 1] += tmp / mod;
            }
        }
        return move(BigInteger(ans, isPositive == bInt.isPositive));
    }
    pair<BigInteger, BigInteger> operator/(const BigInteger &bInt) const
    {
        BigInteger a = absValue();
        BigInteger b = bInt.absValue();
        if (b.isZero())
            return pair<BigInteger, BigInteger>(*this, move(b));
        if (a < b)
            return pair<BigInteger, BigInteger>(move(BigInteger(0)), *this);
        int32_t len = a.length - b.length + 1;
        string ans;
        if (isPositive != bInt.isPositive)
            ans = "-";
        for (int32_t i = 0; i < len; i++)
        {
            BigInteger tmp = e(len - i - 1) * b;
            int32_t times = 0;
            while (tmp <= a)
            {
                a = a - tmp;
                ++times;
            }
            ans += times + '0';
        }
        a.isPositive = isPositive;
        return pair<BigInteger, BigInteger>(move(BigInteger(ans)), move(a));
    }

    int32_t operator[](int32_t idx) const { return nums[idx]; }

    BigInteger &operator=(const BigInteger &bInt)
    {
        if (bInt == *this)
            return *this;
        nums = bInt.nums;
        isPositive = bInt.isPositive;
        length = bInt.length;
        return *this;
    }
    BigInteger &operator=(BigInteger &&bInt) noexcept
    {
        nums = move(bInt.nums);
        isPositive = bInt.isPositive;
        length = bInt.length;
        return *this;
    }
};

// 数学算法
namespace math
{
    // 质数
    namespace prime
    {
        // 判断素数.
        bool is_prime(int x)
        {
            for (int i = 2; i <= x / i; i++)
            {
                if (x % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        // 分解因数
        namespace divisors
        {
            // 分解质因数.
            namespace prime_divisors
            {
                const int MAX = 100000;
                const int MAXP = MAX + 10;

                bool vis[MAXP] = {0};
                int prime[MAXP];               // 质数
                pair<int, int> divisors[MAXP]; // {质因数, 个数}

                // 欧拉筛
                int prime_sieve_euler(int n)
                {
                    int cnt = 0;
                    vis[1] = true;
                    for (int i = 2; i <= n; i++)
                    {
                        if (not vis[i])
                            prime[cnt++] = i;
                        for (int j = 0; j < cnt and prime[j] * i <= n; j++)
                        {
                            vis[prime[j] * i] = true;
                            if (i % prime[j] == 0)
                                break;
                        }
                    }
                    return cnt;
                }

                // 分解质因数. 参数: x: 原数. 返回: 互异质因数个数.
                int prime_divisors(int x)
                {
                    int cnt = 0;
                    for (int i = 0; prime[i] <= x / prime[i]; i++)
                    {
                        if (x % prime[i] == 0)
                        {
                            divisors[cnt] = {prime[i], 0};
                            while (x % prime[i] == 0)
                            {
                                x /= prime[i];
                                divisors[cnt].second++;
                            }
                            cnt++;
                        }
                    }
                    if (x > 1)
                        divisors[cnt++] = {x, 1};
                    return cnt;
                }

                void solve()
                {
                    prime_sieve_euler(MAX);
                    int t;
                    cin >> t;
                    while (t--)
                    {
                        int x;
                        cin >> x;
                        int cnt = prime_divisors(x);
                        for (int i = 0; i < cnt; i++)
                        {
                            cout << divisors[i].first << ' ' << divisors[i].second << endl;
                        }
                    }
                }
            }

            // 枚举因数. 参数: x: 原数, res: 因数结果. 返回: 因数个数. 复杂度: O(x^0.5).
            int enum_divisors(int x, int res[])
            {
                int cnt = 0;
                int oth[128]; // 足够大
                int len = 0;
                for (int i = 1; i <= x / i; i++)
                {
                    if (x % i == 0)
                    {
                        res[cnt++] = i;
                        oth[len++] = x / i;
                    }
                }
                if (res[cnt - 1] == oth[len - 1])
                    len--; // 如果是完全平方数
                for (int i = len - 1; i >= 0; i--)
                    res[cnt++] = oth[i];
                return cnt;
            }
        }

        // 素数筛法
        namespace sieve
        {
            const int MAX = 1000005;
            bool vis[MAX] = {0};
            int prime[MAX];

            // 埃氏筛(优化朴素筛). 参数: 筛上界. 返回: 质数个数. 复杂度: O(nloglogn).
            int prime_sieve_eratosthenes(int n)
            {
                int cnt = 0;
                vis[1] = true;
                for (int i = 2; i <= n; i++)
                {
                    if (not vis[i])
                    {
                        prime[cnt++] = i;
                        for (int j = i * i; j <= n; j += i)
                        {
                            vis[j] = true;
                        }
                    }
                }
                return cnt;
            }

            // 欧拉筛(线性筛). 参数: 筛上界. 返回: 质数个数. 复杂度: O(n)
            int prime_sieve_euler(int n)
            {
                int cnt = 0;
                vis[1] = true;
                for (int i = 2; i <= n; i++)
                {
                    if (not vis[i])
                        prime[cnt++] = i; // 质数
                    for (int j = 0; j < cnt and prime[j] * i <= n; j++)
                    {
                        vis[prime[j] * i] = true; // 标记i的质数倍为合数
                        // 该语句在 prime[j] * i 访问共其 不重复质因子数 次.
                        if (i % prime[j] == 0)
                            // 该语句在 prime[j] * i 访问共其 (总质因子数 - 不重复质因子数) 次.
                            break;
                        /*  解析:
                            如果 i 的质因集包含 prime[j],
                            则对于任意 prime[jj] (j < jj < cnt, 即 prime[jj] > prime[j]),
                            必有 ii = prime[jj] * i / prime[j] 为整数 且 ii > i,
                            这个值 ii (如果 ii <= n) 将在将来被同样的操作,
                            因此该做法不会遗漏任何值.

                            这个操作保证了所有质数标记操作 vis[prime[j] * i] = true 中,
                            prime[j] 是 prime[j] * i 的最小质因数,
                            然而每个数 (非1正整数) 有且仅有一个最小质因数,
                            因此每个 vis 元素仅被访问一次,
                            复杂度为 O(n).  */
                    }
                }
                return cnt;
            }
        }

        // 区间互质 O(log(n)) -> O(n^0.5).
        namespace interval_coprime
        {
            // 区间互质计数. 区间 [1, n] 中与 x 互质的数的个数. 复杂度: O(min(n, x)) -> O(2^(min(n, x)^0.5))
            namespace normal
            {
                vector<int> factor;
                int dfs(int level, int count, int value)
                {
                    if (level == factor.size())
                    {
                        return count % 2 ? -value : value;
                    }
                    else
                    {
                        int res = 0;
                        res += dfs(level + 1, count, value);
                        res += dfs(level + 1, count + 1, value / factor[level]);
                        return res;
                    }
                }
                int interval_coprime(int n, int x)
                {
                    factor.clear();
                    for (int i = 2; i <= x / i; i++)
                    {
                        if (x % i == 0)
                        {
                            factor.push_back(i);
                            while (x % i == 0)
                                x /= i;
                        }
                    }
                    if (x > 1)
                        factor.push_back(x);
                    int res = dfs(0, 0, n);
                    return res;
                }
            }

            // 欧拉函数. 求区间 [1, x] 中与 x 互质的数的个数. 复杂度: O(logx) -> O(x^0.5).
            int euler(int x)
            {
                int res = x;
                for (int i = 2; i <= x / i; i++)
                    if (x % i == 0)
                    {
                        res = res / i * (i - 1);
                        while (x % i == 0)
                            x /= i;
                    }
                if (x > 1)
                    res = res / x * (x - 1);
                return res;
            }

            // 线性筛法欧拉函数. 求区间[1, x]中与x互质的数的个数, x 遍历 [1, n]. 复杂度: O(n).
            namespace linear
            {
                const int MAX = 1000005;

                bool vis[MAX] = {0};
                int prime[MAX];
                int euler[MAX];
                void euler_linear(int n)
                {
                    int cnt = 0;
                    euler[1] = 1;
                    vis[1] = true;
                    for (int i = 2; i <= n; i++)
                    {
                        if (not vis[i])
                        {
                            prime[cnt++] = i;
                            euler[i] = i - 1; // 质数
                        }
                        for (int j = 0; j < cnt and prime[j] * i <= n; j++)
                        {
                            vis[prime[j] * i] = true;
                            if (i % prime[j] == 0)
                            {
                                // 该语句在 prime[j] * i 访问共其 (总质因子数 - 不重复质因子数) 次.
                                euler[prime[j] * i] = euler[i] * prime[j];
                                break;
                            }
                            // 该语句在 prime[j] * i 访问共其 不重复质因子数 次.
                            euler[prime[j] * i] = euler[i] * (prime[j] - 1);
                        }
                    }
                }
            }
        }
    }

    // 排列组合
    namespace combinatorics
    {
        namespace dynamic_programming_solution
        {
            const int MAX = 1005;

            int C[MAX][MAX];
            inline void load_C(int n)
            {
                C[0][0] = 1;
                for (int i = 1; i <= n; i++)
                {
                    C[i][0] = 1;
                    for (int j = 1; j < i; j++)
                        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                    C[i][i] = 1;
                }
            }

            int A[MAX][MAX];
            inline void load_A(int n)
            {
                for (int i = 0; i <= n; i++)
                {
                    A[i][0] = 1;
                    for (int j = 1; j <= i; j++)
                        A[i][j] = A[i][j - 1] * (i + 1 - j);
                }
            }
        }

        namespace inverse_element_solution
        {
            // 一般开两倍内存
            const int MAX = 100005;
            const int MOD = 1000000007;

            int fac[MAX];
            inline void load_fac(int n)
            {
                for (int i = 0, f = 1; i <= n; i++, f *= i, f %= MOD)
                    fac[i] = f;
            }

            int inv[MAX];
            inline int quick_pow(int base, int exponent, int modulo)
            {
                int res = 1;
                while (exponent)
                {
                    if (exponent & 1)
                    {
                        res *= base;
                        res %= modulo;
                    }
                    base *= base;
                    base %= modulo;
                    exponent >>= 1;
                }
                return res;
            }
            inline int inverse_element_fermat(int primal) { return quick_pow(primal, MOD - 2, MOD); }
            inline void load_inv(int n)
            {
                for (int i = 0; i <= n; i++)
                    inv[i] = inverse_element_fermat(fac[i]);
            }

            inline int A(int m, int n) { return 0 <= n and n <= m ? fac[m] * inv[n] % MOD : 0; }
            inline int C(int m, int n) { return 0 <= n and n <= m ? fac[m] * inv[n] % MOD * inv[m - n] % MOD : 0; }
        }

        namespace lucas_solution
        {

        }
    }

    // 欧几里得
    namespace gcd_
    {
        // 欧几里得算法. 复杂度: O(lg(min(x, y))).
        int __gcd(int x, int y) { return x % y ? __gcd(y, x % y) : y; }
        inline int gcd(int x, int y) { return x > y ? __gcd(x, y) : __gcd(y, x); }

        // 扩展欧几里得算法. 求解: 一元二次方程 ax + by = c. 返回: bool-有解. 复杂度: O(lg(min(a, b))).
        int __exgcd(int a, int b, int &x, int &y)
        {
            int d = a;
            if (b != 0)
            {
                d = __exgcd(b, a % b, y, x);
                y -= (a / b) * x;
            }
            else
            {
                x = 1;
                y = 0;
            }
            return d;
        }
        inline bool exgcd(int a, int b, int c, int &x, int &y)
        {
            int _x, _y, g;
            g = __exgcd(a, b, _x, _y);
            if (c % g == 0)
            {
                x = c / g * _x;
                y = c / g * _y;
                return true;
            }
            else
                return false;
        }

        // 线性同余方程. 依赖: exgcd. 求解: 线性同余方程 ax = c (mod m). 返回: 有解: x, 无解: -1. 复杂度: O(lg(min(a, m))).
        const int MOD = 1000000007;
        inline int linear_congruence_theorem(int a, int c, int m = MOD)
        {
            int x, y;
            bool flag = exgcd(a, m, c, x, y);
            return flag ? (x % m + m) % m : -1;
        }
    }

    // 逆元和快速幂
    namespace inverse_element
    {
        const int MOD = 1000000007;

        // 快速幂. 复杂度: O(log(exponent))
        inline int quick_pow(int base, int exponent)
        {
            int res = 1;
            while (exponent)
            {
                if (exponent & 1)
                    res *= base;
                base *= base;
                exponent >>= 1;
            }
            return res;
        }
        inline int quick_pow(int base, int exponent, int modulo = MOD)
        {
            int res = 1;
            while (exponent)
            {
                if (exponent & 1)
                {
                    res *= base;
                    res %= modulo;
                }
                base *= base;
                base %= modulo;
                exponent >>= 1;
            }
            return res;
        }

        // 费马小定理求逆元. 依赖: quick_pow. 复杂度: O(log(modulo)).
        inline int inverse_element_fermat(int primal, int modulo = MOD) { return quick_pow(primal, modulo - 2, modulo); }

        // 扩展欧几里得算法求逆元. 依赖: exgcd. 复杂度: O(log(modulo))
        int __exgcd(int a, int b, int &x, int &y)
        {
            int d = a;
            if (b != 0)
            {
                d = __exgcd(b, a % b, y, x);
                y -= (a / b) * x;
            }
            else
            {
                x = 1;
                y = 0;
            }
            return d;
        }
        inline bool exgcd(int a, int b, int c, int &x, int &y)
        {
            int _x, _y, g;
            g = __exgcd(a, b, _x, _y);
            if (c % g == 0)
            {
                x = c / g * _x;
                y = c / g * _y;
                return true;
            }
            else
                return false;
        }
        inline int inverse_element_exgcd(int primal, int modulo = MOD)
        {
            int x, y;
            bool flag = exgcd(primal, modulo, 1, x, y);
            return flag ? (x % modulo + modulo) % modulo : -1;
        }

        // Useless - 欧拉定理求逆元. 依赖: euler. 复杂度: O(log(modulo)) + 预处理: O(log(modulo)) -> O(modulo^0.5)
        inline int euler(int x)
        {
            int res = x;
            for (int i = 2; i <= x / i; i++)
                if (x % i == 0)
                {
                    res = res / i * (i - 1);
                    while (x % i == 0)
                        x /= i;
                }
            if (x > 1)
                res = res / x * (x - 1);
            return res;
        }
        inline int inverse_element_euler(int primal, int modulo = MOD)
        {
            static int eu = -1, last = -1;
            if (modulo != last) // 预处理: modulo 变化的时候执行. 如果 modulo 反复变化这里会 TLE.
            {
                eu = euler(modulo) - 1;
                last = modulo;
            }
            int _eu = eu, _primal = primal, res = 1;
            while (_eu > 0)
            {
                if (_eu & 1)
                    res = res * _primal % modulo;
                _eu >>= 1;
                _primal = _primal * _primal % modulo;
            }
            return primal * res % modulo == 1 ? res : 0;
        }

        // 线性筛求逆元. 求 [1, range] 所有数的逆元. 复杂度: O(range).
        inline void inverse_element_linear(int range, int modulo, int res[])
        {
            res[1] = 1;
            for (int i = 2; i <= range; i++)
                res[i] = (modulo - modulo / i) * res[modulo % i] % modulo;
        }
    }

    // 快速傅里叶变换
    namespace fast_fast_tle
    {
        const int MAX = (1 << 17) * 2 + 5; // 注意数组开 2^(ceil(log(MAX))) * 2
        const double Pi = acos(-1.0);
        int tax[MAX];
        int limit = 1;
        struct Complex
        {
            double r;
            double i;
            Complex(double r = 0, double i = 0) { this->r = r, this->i = i; }
            Complex operator+(Complex other) { return Complex(r + other.r, i + other.i); }
            Complex operator-(Complex other) { return Complex(r - other.r, i - other.i); }
            Complex operator*(Complex other) { return Complex(r * other.r - i * other.i, r * other.i + i * other.r); }
            Complex operator/(double other) { return Complex(r / other, i / other); }
        } a[MAX], b[MAX];

        // 快速傅里叶变换. 参数: A: 操作数列, mode: 变换模式: 1: 系数->点集, 2: 点集->系数
        void fast_fast_tle(Complex A[], int mode)
        {
            for (int i = 0; i < limit; i++)
                if (i < tax[i])
                    swap(A[i], A[tax[i]]);
            for (int mid = 1; mid < limit; mid <<= 1)
            {
                Complex Wn(cos(Pi / mid), mode * sin(Pi / mid));
                for (int R = mid << 1, j = 0; j < limit; j += R)
                {
                    Complex w(1, 0);
                    for (int k = 0; k < mid; k++, w = w * Wn)
                    {
                        Complex x = A[j + k], y = w * A[j + mid + k];
                        A[j + k] = x + y;
                        A[j + mid + k] = x - y;
                    }
                }
            }
        }

        // 快速傅里叶卷积. 注意输入与结果为复数数组. 参数: a: 原始数组1 以及 结果数组, n: 原始数组1长度, b: 原始数组2, m: 原始数组2长度. 返回: 结果数组长度
        int fast_convolution(Complex a[], int n, Complex b[], int m)
        {
            // Attention: 将直接在 a, b 数组上修改, 而非拷贝
            int l = 0;
            limit = 1;
            while (limit < n + m - 1)
            {
                limit <<= 1;
                l++;
            }
            for (int i = 0; i < limit; i++)
                tax[i] = (tax[i >> 1] >> 1) | ((i & 1) << (l - 1));
            fast_fast_tle(a, 1);
            fast_fast_tle(b, 1);
            for (int i = 0; i <= limit; i++)
                a[i] = a[i] * b[i] / limit;
            fast_fast_tle(a, -1);
            return n + m - 1;
        }
    }
}

// 数据结构
namespace data_structure
{
    // ST表 - 以 区间最大值 为例. 时间: O(1) + 预处理: O(nlogn), 内存: O(nlogn)
    namespace sparse_table
    {
        // 1-index
        const int MAX = 100005;
        const int LOG = 17;

        int lg2[MAX];
        int a[MAX];
        int st[MAX][LOG];

        void load_lg2(int n)
        {
            lg2[0] = -1;
            for (int i = 1; i <= n; i++)
                lg2[i] = lg2[i >> 1] + 1;
        }

        void build(int n)
        {
            for (int i = 1; i <= n; i++)
                st[i][0] = a[i];
            for (int j = 1, v = 1; v < n; j++, v <<= 1)
                for (int i = 1; i <= n; i++)
                    st[i][j] = max(st[i][j - 1], st[min(i + v, n)][j - 1]); // Attention
        }

        int query(int l, int r)
        {
            int u = lg2[r - l + 1];
            return max(st[l][u], st[r - (1 << u) + 1][u]); // Attention
        }
    }

    // 分块 - 以 区间求和-区间修改 为例. 时间: O(n^0.5) + 预处理: O(n) + 后处理: O(n), 内存: O(n)
    namespace block
    {
        // 0-index
        const int MAX = 100005;
        const int SQR = 320;

        int a[MAX];
        int size_;
        int block[SQR][SQR];
        int sum[SQR] = {0};
        int lazy[SQR] = {0};

        void build(int n)
        {
            size_ = sqrt(n);
            for (int i = 0; i < n; i++)
            {
                block[i / size_][i % size_] = a[i];
                sum[i / size_] += a[i];
            }
        }

        void load(int n)
        {
            size_ = sqrt(n);
            for (int i = (n - 1) / size_; i >= 0; i++)
            {
                for (int j = 0; j < size_; j++)
                    block[i][j] += lazy[i];
                lazy[i] = 0;
            }
        }

        void modify(int l, int r, int val)
        {
            int ll = (l + size_ - 1) / size_;
            int dl = (l + size_ - 1) % size_ + 1;
            int rr = (r + 1) / size_ - 1;
            int dr = (r + 1) % size_ - 1;
            for (int i = dl; i < size_; i++)
                block[ll - 1][i] += val;
            sum[ll - 1] += (size_ - dl) * val;
            for (int i = ll; i <= rr; i++)
            {
                sum[i] += size_ * val;
                lazy[i] += val;
            }
            for (int i = 0; i <= dr; i++)
                block[rr + 1][i] += val;
            sum[rr + 1] += (dr + 1) * val;
        }

        int query(int l, int r)
        {
            int ll = (l + size_ - 1) / size_;
            int dl = (l + size_ - 1) % size_ + 1;
            int rr = (r + 1) / size_ - 1;
            int dr = (r + 1) % size_ - 1;
            int res = 0;
            for (int i = dl; i < size_; i++)
                res += block[ll - 1][i] + lazy[ll - 1];
            for (int i = ll; i <= rr; i++)
                res += sum[i];
            for (int i = 0; i <= dr; i++)
                res += block[rr + 1][i] + lazy[rr + 1];
            return res;
        }
    }

    // 莫队. 时间: O(n^1.5), 内存: O(n)
    namespace mos
    {
        // 基础莫队 - 以 区间互异性 为例.
        namespace static_mos
        {
            const int MAX = 100005;

            int a[MAX];
            int size_, l, r, cur;
            struct Query
            {
                int index;
                int left;
                int right;
            } qry[MAX];
            int buk[MAX];
            bool out[MAX];

            // 排序函数: 左区号升序-右界升序-左界升序
            bool cmp(const Query &x, const Query &y)
            {
                int xx = x.left / size_, yy = y.left / size_;
                if (xx != yy)
                    return xx < yy;
                if (x.right != y.right)
                    return x.right < y.right;
                return x.left < y.left;
            }

            // 添加元素  // Attention
            int add(int x)
            {
                buk[a[x]]++;
                if (buk[a[x]] == 1)
                    cur++;
            }

            // 移除元素  // Attention
            int del(int x)
            {
                buk[a[x]]--;
                if (buk[a[x]] == 0)
                    cur--;
            }

            void solve()
            {
                int n, q;
                cin >> n >> q;
                for (int i = 0; i < n; i++)
                    cin >> a[i];
                size_ = sqrt(n), l = 0, r = 0, cur = 1, buk[a[0]]++; // Attention: 别忘了设置初始值
                for (int i = 0; i < q; i++)
                {
                    cin >> qry[i].left >> qry[i].right;
                    qry[i].index = i;
                    qry[i].left--;
                    qry[i].right--;
                }
                sort(qry, qry + q, cmp);
                for (int i = 0; i < q; i++)
                {
                    while (qry[i].left < l)
                        add(--l);
                    while (qry[i].right > r)
                        add(++r);
                    while (qry[i].left > l)
                        del(l++);
                    while (qry[i].right < r)
                        del(r--);
                    if (cur == r - l + 1)
                        out[qry[i].index] = true;
                    else
                        out[qry[i].index] = false;
                }
                for (int i = 0; i < q; i++)
                    if (out[i])
                        cout << "Yes" << endl;
                    else
                        cout << "No" << endl;
            }

        }

        // 带修莫队
        namespace modifiable_mos
        {

        }

        // 回滚莫队
        namespace rollback_mos
        {

        }

        // 树上莫队
        namespace mos_on_tree
        {

        }

        // 二次离线莫队
        namespace mos_twice
        {

        }

        // 在线莫队
        namespace mos_online
        {

        }
    }

    // 树状数组
    namespace tree_array
    {

    }

    // 线段树. 时间: O(logn) + 预处理: O(n) + 后处理: O(n), 内存: O(4n)
    namespace segment_tree
    {
        // 基础线段树
        namespace non_tagged
        {

        }

        // 带lazy标记的线段树 - 以 区间求和-区间修改 为例. 局限性: 近二十倍大常数
        namespace lazy_tagged
        {
            const int MAX = 100005;

            int a[MAX]; // 1-index
            struct SegmentTree
            {
                int left;
                int right;
                int sum = 0;  // Attention: 别忘了设置初值
                int lazy = 0; // Attention: 别忘了设置初值
            } node[MAX * 4];  // 1-index

#define ls(idx) (idx * 2)     // 返回左子节点
#define rs(idx) (idx * 2 + 1) // 返回右子节点

            // 初始化 idx 索引  // Attention
            inline void init(SegmentTree &leaf, int idx)
            {
                leaf.sum = a[idx];
            }

            // load 导出, 不带 lazy 标记的线段树, 无需 output  // Attention
            inline void output(const SegmentTree &leaf, int idx)
            {
                a[idx] = leaf.sum;
            }

            // 向上维护, 状态合并方程  // Attention
            inline SegmentTree &merge_up(SegmentTree &father, const SegmentTree &left, const SegmentTree &right)
            {
                father.sum = left.sum + right.sum;
                return father;
            }

            // lazy 初始方程  // Attention
            inline void lazy_init(SegmentTree &node, int val)
            {
                node.sum += val * (node.right - node.left + 1);
                node.lazy += val;
            }

            // 向下维护, lazy 传递方程  // Attention
            inline void lazy_down(SegmentTree &father, SegmentTree &left, SegmentTree &right)
            {
                // 前两步务必在后三步前面
                left.sum += father.lazy * (left.right - left.left + 1);
                right.sum += father.lazy * (right.right - right.left + 1);
                left.lazy += father.lazy;
                right.lazy += father.lazy;
                father.lazy = 0;
            }

            // 建树
            void build(int l, int r, int idx)
            {
                if (l == r)
                {
                    node[idx].left = l;
                    node[idx].right = l;
                    init(node[idx], l);
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (l + r) / 2;
                build(l, mid, li);
                build(mid + 1, r, ri);
                node[idx].left = node[li].left;
                node[idx].right = node[ri].right;
                merge_up(node[idx], node[li], node[ri]);
            }
            inline void build(int n) { build(1, n, 1); }

            // 全载, 清空并重置 lazy, 不带 lazy 标记的线段树, 无需 load
            void load(int l, int r, int idx)
            {
                if (l == r)
                {
                    output(node[idx], l);
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (l + r) / 2;
                lazy_down(node[idx], node[li], node[ri]);
                load(l, mid, li);
                load(mid + 1, r, ri);
                merge_up(node[idx], node[li], node[ri]);
            }
            inline void load(int n) { load(1, n, 1); }

            // 区间修改, 不带 lazy 标记的线段树, 无法 modify
            void modify(int l, int r, int val, int idx)
            {
                if (l <= node[idx].left and node[idx].right <= r)
                {
                    lazy_init(node[idx], val);
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                lazy_down(node[idx], node[li], node[ri]);
                if (l <= mid)
                    modify(l, r, val, li);
                if (r > mid)
                    modify(l, r, val, ri);
                merge_up(node[idx], node[li], node[ri]);
            }
            inline void modify(int l, int r, int val) { modify(l, r, val, 1); }

            // 区间查询
            SegmentTree query(int l, int r, int idx)
            {
                if (l <= node[idx].left and node[idx].right <= r)
                    return node[idx];
                SegmentTree res;
                res.left = l;
                res.right = r;
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                lazy_down(node[idx], node[li], node[ri]);
                if (l <= mid)
                    res = query(l, r, li);
                if (r > mid)
                    res = merge_up(node[0], res, query(l, r, ri));
                return res;
            }
            inline SegmentTree query(int l, int r) { return query(l, r, 1); }
        }

        // 带权线段树 - 以 计数小于x-单点修改 为例. 局限性: 不离散数域决定内存, 离散化或将约束修改
        namespace weighted
        {
            const int MAX = 100005;

            struct SegmentTree
            {
                int left;
                int right;
                int tot = 0; // Attention: 别忘了设置初值
            } node[MAX * 4]; // 1-index

#define ls(idx) (idx * 2)
#define rs(idx) (idx * 2 + 1) // 返回右子节点

            // 向上维护, 状态合并方程  // Attention
            inline SegmentTree &merge_up(SegmentTree &father, const SegmentTree &left, const SegmentTree &right)
            {
                father.tot = left.tot + right.tot;
                return father;
            }

            // 建树
            void build(int l, int r, int idx)
            {
                if (l == r)
                {
                    node[idx].left = l;
                    node[idx].right = l;
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (l + r) / 2;
                build(l, mid, li);
                build(mid + 1, r, ri);
                node[idx].left = node[li].left;
                node[idx].right = node[ri].right;
                merge_up(node[idx], node[li], node[ri]);
            }
            inline void build(int n) { build(1, n, 1); }

            // 单点插入  // Attention
            void insert(int x, int idx)
            {
                if (x == node[idx].left and node[idx].right == x)
                {
                    node[idx].tot++;
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                if (x <= mid)
                    insert(x, li);
                else
                    insert(x, ri);
                merge_up(node[idx], node[li], node[ri]);
            }
            inline void insert(int x) { insert(x, 1); }

            // 区间查询  // Attention
            int query(int x, int idx)
            {
                if (node[idx].left == node[idx].right)
                    return node[idx].tot;
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                if (x <= mid)
                    return query(x, li);
                else
                    return node[li].tot + query(x, ri);
            }
            inline int query(int x) { return query(x, 1); }
        }

        // 可持续化线段树(主席树) - 以 计数区间第k小为例. 时间: O(logn) + 预处理: O(n), 内存: O(4n+3i+ilogn)
        namespace persistent
        {
            const int MAXI = 30005;
            const int MAXN = 30005;
            const int LOGN = 15;

            int now_id = 0;
            int len_version = 0;
            struct Version
            {
                int id;
                int left;  // 左子版本
                int right; // 右子版本
                int tot;
            } version[MAXI * (LOGN + 3)]; // 1-index
            struct SegmentTree
            {
                int left;
                int right;
                vector<int> version; // Attention: 别忘了设置初值
            } node[MAXN * 4];        // 1-index

#define ls(idx) (idx * 2)
#define rs(idx) (idx * 2 + 1) // 返回右子节点

            // 建树
            void build(int l, int r, int idx)
            {
                if (l == r)
                {
                    node[idx].left = l;
                    node[idx].right = l;
                    version[++len_version] = {0, 0, 0, 0};
                    node[idx].version.push_back(len_version);
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (l + r) / 2;
                build(l, mid, li);
                build(mid + 1, r, ri);
                node[idx].left = node[li].left;
                node[idx].right = node[ri].right;
                version[++len_version] = {0, node[li].version.back(), node[ri].version.back(), 0};
                node[idx].version.push_back(len_version);
            }
            inline void build(int n) { build(1, n, 1); }

            // 单点插入  // Attention
            void insert(int x, int idx)
            {
                if (x == node[idx].left and node[idx].right == x)
                {
                    version[++len_version] = {now_id, 0, 0, version[node[idx].version.back()].tot + 1};
                    node[idx].version.push_back(len_version);
                    return;
                }
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                if (x <= mid)
                    insert(x, li);
                else
                    insert(x, ri);
                version[++len_version] = {now_id, node[li].version.back(), node[ri].version.back(), version[node[idx].version.back()].tot + 1};
                node[idx].version.push_back(len_version);
            }
            inline void insert(int x)
            {
                now_id++;
                insert(x, 1);
            }

            // 区间查询  // Attention
            int search(SegmentTree &node, int x)
            {
                int l = 0, r = node.version.size() - 1;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (version[node.version[mid]].id <= x)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                return node.version[r];
            }
            int query(int l, int r, int k, int idx, int lv, int rv)
            {
                if (node[idx].left == node[idx].right)
                    return node[idx].left;
                int li = ls(idx), ri = rs(idx), mid = (node[idx].left + node[idx].right) / 2;
                int tot = version[version[rv].left].tot - version[version[lv].left].tot;
                if (k <= tot)
                    return query(l, r, k, li, version[lv].left, version[rv].left);
                else
                    return query(l, r, k - tot, ri, version[lv].right, version[rv].right);
            }
            inline int query(int l, int r, int k)
            {
                return query(l, r, k, 1, search(node[1], l - 1), search(node[1], r));
            }
        }
    }

    // 字典树. 时间: O(sum(n)q), 内存: O(sum(n))
    namespace trie
    {
        struct Trie
        {
            int cnt = 0;
            map<char, Trie *> next; // O(logn) 访问, 动态内存
            // Trie *next[128] = {0};  // O(1) 访问, 静态内存
        } *root = 0;

        // 重置字典树
        void clear(Trie *p)
        {
            if (p == 0)
                return;
            for (pair<char, Trie *> pp : p->next) // 对应 O(logn) 访问
                clear(pp.second);
            // for (int i = 0; i < 128; i++) // 对应 O(1) 访问
            //     clear(p->next[i]);
            delete p;
        }
        void clear() { clear(root); }

        // 插入字符串
        void insert(string s)
        {
            Trie *p = root;
            p->cnt++;
            for (int i = 0; i <= s.size(); i++)
            {
                if (p->next[s[i]])
                    p = p->next[s[i]];
                else
                    p = p->next[s[i]] = new Trie;
                p->cnt++;
            }
        }

        // 计数字符串. 返回: 该字符串的个数
        int count(string s)
        {
            Trie *p = root;
            int i = 0;
            while (p->next[s[i]])
            {
                p = p->next[s[i]];
                i++;
            }
            return i == s.size() + 1 ? p->cnt : 0;
        }

        // 删除字符串. 如果存在多个仅减一. 返回: 布尔型-删除成功  // !!!!!!
        bool erase(string s)
        {
            if (not count(s))
                return false;
            Trie *p = root;
            p->cnt--;
            int i = 0;
            while (p->next[s[i]])
            {
                p = p->next[s[i]];
                p->cnt--;
                i++;
            }
            return true;
        }

        // 计数前缀. 返回: 该前缀的个数
        int match(string s)
        {
            Trie *p = root;
            int i = 0;
            while (i < s.size() and p->next[s[i]])
            {
                p = p->next[s[i]];
                i++;
            }
            return i == s.size() ? p->cnt : 0;
        }
    }

    // 单调栈 - 以 最近左较小值 为例. 时间: O(n), 内存: O(n)
    namespace humdrum_stack
    {
        // 1-index
        const int MAX = 1000005;
        int a[MAX];

        void solve()
        {
            int n;
            cin >> n;
            for (int i = 1; i <= n; i++)
                cin >> a[i];

            stack<int> stk; // 单增
            stk.push(-1);   // print -1 if no result, should be small enough
            for (int i = 1; i <= n; i++)
            {
                while (stk.top() >= a[i])
                    stk.pop();
                cout << stk.top() << ' ';
                stk.push(a[i]);
            }
            cout << endl;
        }
    }

    // 单调队列 - 以 滑块最小值 为例. 时间: O(n), 内存: O(n)
    namespace humdrum_queue
    {
        // 1-index
        const int MAX = 1000005;
        int a[MAX];

        void solve()
        {
            int n, m;
            cin >> n >> m;
            for (int i = 1; i <= n; i++)
                cin >> a[i];

            deque<int> que; // 单增
            for (int i = 1; i < m; i++)
            {
                while (not que.empty() and que.back() > a[i])
                    que.pop_back();
                que.push_back(a[i]);
            }
            for (int i = 1; i <= n - m + 1; i++)
            {
                while (not que.empty() and que.back() > a[i + m - 1])
                    que.pop_back();
                que.push_back(a[i + m - 1]);
                cout << que.front() << endl;
                if (que.front() == a[i])
                    que.pop_front();
            }
        }
    }

    // 并查集. 时间: O(q), 内存: O(n)
    namespace union_find_set
    {
        // 1-index
        const int MAX = 1000005;

        int father[MAX];
        int edges[MAX]; // 集合边数
        int nodes[MAX]; // 集合点数

        // 初始化
        void init(int n)
        {
            for (int i = 1; i <= n; i++)
            {
                father[i] = i;
                edges[i] = 0;
                nodes[i] = 1;
            }
        }

        // 状态合并方程
        void state_merge(int x, int y)
        {
            edges[y] += edges[x];
            edges[x] = 0;
            nodes[y] += nodes[x];
            nodes[x] = 0;
        }

        // 返回根节点
        int root(int x)
        {
            if (father[x] == x)
                return x;
            state_merge(x, father[x]);
            return father[x] = root(father[x]);
        }

        // 合并集合
        void merge(int x, int y)
        {
            x = root(x);
            y = root(y);
            edges[x]++; // 新增边
            if (x != y)
            {
                state_merge(x, y);
                father[x] = y;
            }
        }

        // 布尔型: 为集合根节点
        inline bool is_father(int x) { return father[x] == x; }

        // 布尔型: 同属同集合
        inline bool is_merged(int x, int y) { return root(x) == root(y); }

        // 返回集合点数
        inline int count_nodes(int x) { return nodes[root(x)]; }

        // 返回集合边数
        inline int count_edges(int x) { return edges[root(x)]; }

        // 布尔型: 节点属于一棵树
        inline bool is_tree(int x) { return nodes[root(x)] > edges[root(x)]; }
    }

    // 模拟堆. 时间: O(qlogn), 内存: O(n)
    namespace heap
    {
        // 0-index
        const int MAX = 100005;

        int heap[MAX]; // 堆 (树状数组)
        int a2h[MAX];  // 数组索引 -> 堆索引
        int h2a[MAX];  // 堆索引 -> 数组索引
        int total = 0; // 总节点 (含已 pop 节点)
        int siz = 0;   // 堆大小

        // C 风格比较函数
        bool cmp(int x, int y) { return x > y; }

        // 维护映射的交换
        void swap_(int u, int v)
        {
            swap(a2h[h2a[u]], a2h[h2a[v]]);
            swap(h2a[u], a2h[v]);
            swap(heap[u], heap[v]);
            if (u == siz)
            {
                a2h[h2a[u]] = -1;
                h2a[u] = -1;
            }
            if (v == siz)
            {
                a2h[h2a[v]] = -1;
                h2a[v] = -1;
            }
        }

        // 向上维护
        void up(int node)
        {
            while (node and heap[node] < heap[(node - 1) / 2])
            {
                swap_(node, (node - 1) / 2);
                node /= 2;
            }
        }

        // 向下维护
        void down(int node)
        {
            int parent = node;        // 父节点下标
            int child = 2 * node + 1; // 子节点下标
            while (child < siz)
            {
                // 判断子节点哪个大, 大的与父节点比较
                if (child + 1 < siz and cmp(heap[child], heap[child + 1]))
                    child++;
                if (cmp(heap[parent], heap[child])) // 判断父节点是否小于子节点
                {
                    swap_(parent, child); // 交换父节点和子节点
                    parent = child;       // 子节点下标 赋给 父节点下标
                }
                child = child * 2 + 1; // 换行, 比较下面的父节点和子节点
            }
        }

        // 线性初始化堆
        void build(int n)
        {
            total = siz = n;
            for (int i = 0; i < siz; i++)
            {
                a2h[i] = i;
                h2a[i] = i;
            }
            for (int i = siz / 2 - 1; i >= 0; i--)
                // 必须自下而上
                down(i);
        }

        // 插入节点
        void push(int x)
        {
            heap[siz] = x;
            a2h[total] = siz;
            h2a[siz] = total;
            up(siz);
            total++;
            siz++;
        }

        // 返回顶值
        int top() { return heap[0]; }

        // 删除顶点
        int pop()
        {
            siz--;
            swap_(0, siz);
            down(0);
            return heap[siz];
        }

        // 修改第 u 个插入的节点
        void modify_by_address(int u, int x)
        {
            int v = a2h[u];
            heap[v] = x;
            down(v);
            up(v);
        }

        // 删除第 u 个插入的节点. 返回: 布尔型: 节点在堆中
        bool pop_by_address(int u)
        {
            int v = a2h[u];
            siz--;
            swap_(v, siz);
            down(v);
            up(v);
        }
    }

    // 哈希表. 时间: O(1), 内存: ?
    namespace hash
    {
        // 哈希表. 时间: O(4.8), 内存: O(3n)
        // !!!!!! 遍历存在 BUG
        // 此哈希表拒绝遍历: 1. 未知下标越界, 2. 时间急剧上升至 O(14.4)
        class HashMap
        {
        private:
            struct _pair
            {
                bool flag = false;
                int first = 0;
                int second = 0;
            } *_data = new _pair[1];
            const double _load_factor = 0.667;
            long long _size = 0;
            long long _log2_capacity = 0;
            unsigned long long _hash_xor;
            int _hash_size;
            int _hash_cut_size;
            int _hash_cut_base;
            int _key_shift;
            int _hash_cut_shift;
            unsigned long long _mark_1;
            unsigned long long _mark_2;
            unsigned long long _mark_3;
            unsigned long long _mark_4;
            unsigned long long _mark_5;

#define randull() ((unsigned long long)rand() << 60 | (unsigned long long)rand() << 45 | (unsigned long long)rand() << 30 | (unsigned long long)rand() << 15 | (unsigned long long)rand())

            void randomit(int new_log2_capacity)
            {
                _hash_size = new_log2_capacity;
                _hash_cut_size = _hash_size >> 1;
                _hash_cut_base = _hash_size + 1 >> 1;
                _hash_xor = randull();
                _hash_cut_shift = rand() % _hash_cut_size + _hash_cut_base - _hash_cut_size;
                _key_shift = _hash_size - _hash_cut_base;
                _mark_1 = (1ull << _hash_size) - (1ull << _hash_cut_base);
                _mark_2 = (1ull << _hash_cut_base) - 1ull;
                _mark_3 = (1ull << _hash_size) - (1ull << _hash_cut_size);
                _mark_4 = (1ull << _hash_cut_size) - 1ull;
                _mark_5 = (1ull << _hash_size) - 1ull;
            }

            // Test Data: 100000 randomize integer, 100 test, in average.
            // Hash collision expectation 3.27 for load factor 0.500
            // Hash collision expectation 4.06 for load factor 0.600
            // Hash collision expectation 4.80 for load factor 0.667
            // Hash collision expectation 5.28 for load factor 0.700
            // Hash collision expectation 5.76 for load factor 0.800
            // Never try to hack it, it's with no chink.
            int hash(unsigned long long key, unsigned long long cnt)
            {
                key = key ^ _hash_xor;
                unsigned long long __ = key & _mark_1 | key >> _key_shift & _mark_2;
                unsigned long long base = key << _hash_cut_size & _mark_3 | __ >> _hash_cut_shift & _mark_4;
                return base + cnt & _mark_5;
            }

            _pair *position(_pair *dst, int first)
            {
                int cnt = 0;
                _pair *it = dst + hash(first, cnt++);
                while (it->flag and it->first != first)
                    it = dst + hash(first, cnt++);
                return it;
            }

            pair<_pair *, bool> push(_pair *dst, int first, int second)
            {
                _pair *it = position(dst, first);
                if (it->flag)
                    return {it, false};
                *it = {true, first, second};
                return {it, true};
            }

            void reload(int new_log2_capacity)
            {
                randomit(new_log2_capacity);
                _pair *new_data = new _pair[1 << new_log2_capacity];
                for (_pair *it = _data; it != _data + (1 << _log2_capacity); it++)
                    if (it->flag)
                        push(new_data, it->first, it->second);
                _log2_capacity = new_log2_capacity;
                delete _data;
                _data = new_data;
            }

        public:
            HashMap(int capacity = 4)
            {
                if (capacity < 4)
                    capacity = 4;
                srand(time(0) << 10 | clock());
                reload(log2(capacity * 2 - 1));
            }

            int operator[](int key)
            {
                _pair *it = position(_data, key);
                return it->second;
            }

            _pair *begin() { return _data; }

            int capacity() { return 1 << _log2_capacity; }

            void clear()
            {
                _size = 0;
                delete _data;
                _data = new _pair[1];
            }

            int count(int key)
            {
                _pair *it = position(_data, key);
                return it->flag;
            }

            bool empty() { return _size == 0; }

            _pair *end() { return _data + (1 << _log2_capacity); }

            bool erase(_pair *address)
            {
                if (not address->flag)
                    return false;
                _size--;
                *address = {false, 0, 0};
                return true;
            }

            _pair *erase(int key)
            {
                _pair *it = position(_data, key);
                if (not it->flag)
                    return end();
                _size--;
                *it = {false, 0, 0};
                return it;
            }

            _pair *find(int key)
            {
                _pair *it = position(_data, key);
                if (it->flag)
                    return it;
                return end();
            }

            pair<_pair *, bool> insert(pair<int, int> pair_)
            {
                if (_size > _load_factor * (1 << _log2_capacity))
                    reload(_log2_capacity + 1);
                pair<_pair *, bool> tmp = push(_data, pair_.first, pair_.second);
                if (tmp.second)
                {
                    _size++;
                    return tmp;
                }
                else
                    return tmp;
            }

            void reserve(int new_capacity)
            {
                if (new_capacity < 4)
                    return;
                int new_log2_capacity = log2(new_capacity * 2 - 1);
                if ((1 << new_log2_capacity) <= _size)
                    return;
                if (_log2_capacity == new_log2_capacity)
                    return;
                reload(new_log2_capacity);
            }

            void shrink_to_fit()
            {
                int new_log2_capacity = log2(_size / _load_factor - 1) + 1;
                reserve(new_log2_capacity);
            }

            long long size() { return _size; }

            ~HashMap() { delete _data; }
        };

        // 字符串哈希
        namespace string_hash
        {
            const int MAX = 1000005;

            char s[MAX];
            const unsigned long long base = 131;
            unsigned long long mhash[MAX];
            unsigned long long mbase[MAX];

            void build(int n)
            {
                mhash[0] = s[0];
                mbase[0] = 1;
                for (int i = 1; i < n; i++)
                {
                    mhash[i] = mhash[i - 1] * base + s[i];
                    mbase[i] = mbase[i - 1] * base;
                }
            }

            unsigned long long get(int l, int r)
            {
                if (l > r)
                    swap(l, r);
                return mhash[r] - mhash[l - 1] * mbase[r - l + 1];
            }
        }
    }
}

// 动态规划
namespace dynamic_programming
{
    // 背包问题
    namespace knapsack
    {
        // 01 背包 - 原始. 背包的一些拓展问题可能要从原始 01 背包出发. 复杂度: O(nm)
        namespace _01_knapsack
        {
            const int MAXM = 10005;
            const int MAXN = 105;

            int m, n;          // 背包容量, 物品数量
            int v[MAXN];       // 体积
            int w[MAXN];       // 价值
            int f[MAXN][MAXM]; // 背包

            void _01_knapsack()
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 0; j < v[i]; j++)
                        f[i][j] = f[i - 1][j];
                    for (int j = v[i]; j <= m; j--)
                        if (f[i - 1][j - v[i]] != -1 and f[i - 1][j] < f[i - 1][j - v[i]] + w[i])
                            f[i][j] = f[i - 1][j - v[i]] + w[i];
                        else
                            f[i][j] = f[i - 1][j];
                }
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 1; i <= n; i++)
                    cin >> v[i] >> w[i];
                f[0][0] = 0;
                for (int i = 1; i <= m; i++)
                    f[0][i] = -1;

                _01_knapsack();

                int max_ = 0;
                for (int i = 1; i <= m; i++)
                    max_ = max(max_, f[n][i]);
                cout << max_ << endl;
            }
        }

        // 01 背包 - 优化 - 内存优化 & 空白优化. 复杂度: O(nm)
        namespace _01_knapsack_plus
        {
            const int MAXM = 10005;
            const int MAXN = 105;

            int m, n;    // 背包容量, 物品数量
            int v[MAXN]; // 体积
            int w[MAXN]; // 价值
            int f[MAXM]; // 背包

            void _01_knapsack()
            {
                for (int i = 0; i < n; i++)
                    for (int j = m; j >= v[i]; j--)
                        f[j] = max(f[j], f[j - v[i]] + w[i]);
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 0; i < n; i++)
                    cin >> v[i] >> w[i];
                for (int i = 0; i <= m; i++)
                    f[i] = 0;

                _01_knapsack();

                int max_ = f[m];
                cout << max_ << endl;
            }
        }

        // 无限背包. 复杂度: O(nm)
        namespace limitless_knapsack
        {
            const int MAXM = 10005;
            const int MAXN = 105;

            int m, n;    // 背包容量, 物品数量
            int v[MAXN]; // 体积
            int w[MAXN]; // 价值
            int f[MAXM]; // 背包

            void limitless_knapsack()
            {
                for (int i = 0; i < n; i++)
                    // for (int j = m; j >= v[i]; j--)  // 01 背包
                    for (int j = v[i]; j <= m; j++)
                        if (f[j - v[i]] != -1 and f[j] < f[j - v[i]] + w[i])
                            f[j] = f[j - v[i]] + w[i];
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 0; i < n; i++)
                    cin >> v[i] >> w[i];
                f[0] = 0;
                for (int i = 1; i <= m; i++)
                    f[i] = -1;

                limitless_knapsack();

                int max_ = 0;
                for (int i = 1; i <= m; i++)
                    max_ = max(max_, f[i]);
                cout << max_ << endl;
            }
        }

        // 多重背包. 复杂度: O(nmlogl)
        namespace limited_knapsack
        {
            const int MAXM = 10005;
            const int MAXN = 105;
            const int LOGC = 17;

            int m, n;            // 背包容量, 物品数量
            int v[MAXN];         // 体积
            int w[MAXN];         // 价值
            int c[MAXN];         // 数量
            int cnt = 0;         // 转换后 数量
            int vv[MAXN * LOGC]; // 转换后 体积
            int ww[MAXN * LOGC]; // 转换后 价值
            int f[MAXM];         // 背包

            void transform()
            {
                // 对数转换为 01 背包
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    int len = c[i];
                    while (len)
                    {
                        vv[cnt] = (len + 1) / 2 * v[i];
                        ww[cnt] = (len + 1) / 2 * w[i];
                        cnt++;
                        len >>= 1;
                    }
                }
            }

            void _01_knapsack()
            {
                for (int i = 0; i < cnt; i++)
                    for (int j = m; j >= vv[i]; j--)
                        if (f[j - vv[i]] != -1 and f[j] < f[j - vv[i]] + ww[i])
                            f[j] = f[j - vv[i]] + ww[i];
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 0; i < n; i++)
                    cin >> v[i] >> w[i];
                f[0] = 0;
                for (int i = 1; i <= m; i++)
                    f[i] = -1;

                transform();
                _01_knapsack();

                int max_ = 0;
                for (int i = 1; i <= m; i++)
                    max_ = max(max_, f[i]);
                cout << max_ << endl;
            }
        }

        // 分组背包. 复杂度: O(sum(n)m)
        namespace grouped_knapsack
        {
            const int MAXM = 10005;
            const int MAXN = 105;

            int m, n;                           // 背包容量, 分组数量
            vector<pair<int, int>> group[MAXN]; // {{体积, 价值}}
            int f[MAXM];                        // 背包

            void grouped_knapsack()
            {
                for (int i = 0; i < n; i++)
                    for (int j = m; j >= 0; j--)
                        for (pair<int, int> p : group[i])
                            if (j >= p.second and f[j - p.first] != -1)
                                f[j] = max(f[j], f[j - p.first] + p.second);
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 0; i < n; i++)
                {
                    int t;
                    cin >> t;
                    while (t--)
                    {
                        int v, w;
                        cin >> v >> w;
                        group[i].push_back({v, w});
                    }
                }
                f[0] = 0;
                for (int i = 1; i <= m; i++)
                    f[i] = -1;

                grouped_knapsack();

                int max_ = 0;
                for (int i = 1; i <= m; i++)
                    max_ = max(max_, f[i]);
                cout << max_ << endl;
            }
        }

        // 合并背包. 复杂度: O(m^2)
        namespace merge_knapsack
        {
            const int MAXN = 1005;
            const int MAXM = 1005;
            const int INF = 0x3f3f3f3f3f3f3f3fll;

            int n, m;
            int dp[MAXN][MAXM]; // 默认值 -INF-1

            // 将背包 y 合并到背包 x. 可以用分组背包
            void merge_knapsack(int x, int y)
            {
                for (int i = m; i >= 0; i--)
                    for (int j = i; j >= 0; j--)
                    {
                        if (dp[x][i - j] < 0 or dp[y][j] < 0)
                            continue;
                        dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[y][j]);
                    }
            }
        }

        // 前后缀背包. 复杂度: O(qm) + 预处理 O(nm)
        namespace prefix7suffix_knapsack
        {
            const int MAXM = 10005;
            const int MAXN = 105;

            int m, n, q;            // 背包容量, 物品数量, 询问次数
            int v[MAXN];            // 体积
            int w[MAXN];            // 价值
            int prebag[MAXN][MAXM]; // 前缀背包
            int sufbag[MAXN][MAXM]; // 后缀背包

            void prefix_treatment()
            {
                for (int i = 0; i <= m; i++)
                    prebag[0][i] = 0; // 空白优化
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 0; j < v[i]; j++)
                        prebag[i][j] = prebag[i - 1][j];
                    for (int j = v[i]; j <= m; j++)
                        prebag[i][j] = max(prebag[i - 1][j], prebag[i - 1][j - v[i]] + w[i]);
                }
            }

            void suffix_treatment()
            {
                for (int i = 0; i <= m; i++)
                    sufbag[n + 1][i] = 0; // 空白优化
                for (int i = n; i >= 1; i--)
                {
                    for (int j = 0; j < v[i]; j++)
                        sufbag[i][j] = sufbag[i + 1][j];
                    for (int j = v[i]; j <= m; j++)
                        sufbag[i][j] = max(sufbag[i + 1][j], sufbag[i + 1][j - v[i]] + w[i]);
                }
            }

            int query(int l, int r)
            {
                int max_ = 0;
                for (int i = 0; i <= m; i++)
                    max_ = max(max_, prebag[l - 1][i] + sufbag[r + 1][m - i]);
                return max_;
            }

            void solve()
            {
                cin >> m >> n;
                for (int i = 1; i <= n; i++)
                    cin >> v[i] >> w[i];

                prefix_treatment();
                suffix_treatment();

                cin >> q;
                while (q--)
                {
                    int l, r;
                    cin >> l >> r;
                    cout << query(l, r) << endl;
                }
            }
        }

        // 分治背包
        namespace divide7conquer_knapsack
        {

        }
    }
}

// 字符串
namespace string_
{
    // KMP字符串匹配. 复杂度: O(m+n).
    namespace KMP
    {
        // KMP字符串匹配(懒惰). s: 文本, pattern: 模式串, n: 文本长度, m: 模式串长度. 返回: 匹配首索引.
        int kmp_lazy(char *s, char *pattern, int n, int m)
        {
            s--;
            pattern--;
            vector<int> next_(m + 1, 0);
            for (int i = 2, j = 0; i <= m; i++)
            {
                while (j and pattern[i] != pattern[j + 1])
                    j = next_[j];
                if (pattern[i] == pattern[j + 1])
                    j++;
                next_[i] = j;
            }
            for (int i = 1, j = 0; i <= n; i++)
            {
                while (j and s[i] != pattern[j + 1])
                    j = next_[j];
                if (s[i] == pattern[j + 1])
                    j++;
                if (j == m)
                    return i - j;
            }
            return -1;
        }

        // KMP字符串匹配(贪婪). s: 文本, pattern: 模式串, n: 文本长度, m: 模式串长度, res: 结果数组. 返回: 结果数量.
        int kmp_greedy(char *s, char *pattern, int n, int m, int res[])
        {
            int cnt = 0;
            s--;
            pattern--;
            vector<int> next_(m + 1, 0);
            for (int i = 2, j = 0; i <= m; i++)
            {
                while (j and pattern[i] != pattern[j + 1])
                    j = next_[j];
                if (pattern[i] == pattern[j + 1])
                    j++;
                next_[i] = j;
            }
            for (int i = 1, j = 0; i <= n; i++)
            {
                while (j and s[i] != pattern[j + 1])
                    j = next_[j];
                if (s[i] == pattern[j + 1])
                    j++;
                if (j == m)
                {
                    res[cnt++] = i - j;
                    j = next_[j];
                }
            }
            return cnt;
        }
    }
}

// 图论
namespace graph
{
    // 广度优先搜索
    namespace breadth_first_search
    {
        const int MAX = 1005;

        int n;
        char map_[MAX][MAX];
        int track[MAX][MAX];
        struct XY
        {
            int x;
            int y;
            XY operator+(XY xy) { return {x + xy.x, y + xy.y}; }
            XY operator*(int v) { return {x * v, y * v}; }
            bool operator<(XY xy) const { return track[x][y] < track[xy.x][xy.y]; }
            bool operator>(XY xy) const { return track[x][y] > track[xy.x][xy.y]; }
            bool is_valid(XY xy) { return 0 <= x and x < n and 0 <= y and y < n and map_[x][y] != 'x' and (track[x][y] == -1 or track[x][y] > track[xy.x][xy.y]); }
        } st, ed;
        vector<XY> next_{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<XY> que;

        void search(XY pos)
        {
            for (XY nxt : next_)
                for (int i = 1; i < n; i++)
                {
                    XY nw = pos + nxt * i;
                    if (nw.is_valid(pos))
                    {
                        track[nw.x][nw.y] = track[pos.x][pos.y] + 1;
                        que.push(nw);
                    }
                    else
                        break;
                }
        }

        void bfs()
        {
            que.push(st);
            memset(track, -1, sizeof(track));
            track[st.x][st.y] = 0;
            while (not que.empty() and track[ed.x][ed.y] == -1)
            {
                XY pos = que.front();
                que.pop();
                search(pos);
            }
        }

        void solve()
        {
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cin >> map_[i];
                for (int j = 0; j < n; j++)
                    if (map_[i][j] == 'A')
                        st = {i, j};
                    else if (map_[i][j] == 'B')
                        ed = {i, j};
            }
            bfs();
            cout << track[ed.x][ed.y] << endl;
        }
    }

    // 拓扑排序. 复杂度: O(n)
    namespace topsort
    {
        const int MAX = 1000005;

        set<int> edge[MAX]; // 重边, 否则用 vector
        int in_degree[MAX] = {0};
        int top_order[MAX];

        // 建图
        void build(int m)
        {
            while (m--)
            {
                int u, v;
                cin >> u >> v;
                if (u == v) // 自环
                    continue;
                pair<set<int>::iterator, bool> tmp = edge[u].insert(v);
                if (tmp.second)
                    in_degree[v]++;
            }
        }

        // 拓扑
        bool topsort(int n)
        {
            int cnt = 0;
            stack<int> stk;
            for (int i = 1; i <= n; i++)
                if (in_degree[i] == 0)
                    stk.push(i);
            while (not stk.empty())
            {
                int x = stk.top();
                stk.pop();
                top_order[cnt++] = x;
                for (int y : edge[x])
                {
                    in_degree[y]--;
                    if (in_degree[y] == 0)
                        stk.push(y);
                }
            }
            return cnt == n;
        }
    }

    // 最短路径
    namespace shortest_rount
    {
        // dijkstra - 堆优化 O(mlogn)
        namespace dijkstra
        {
            // 邻接表存图
            const int MAX = 1005;
            vector<pair<int, int>> edge[MAX];
            int dis[MAX];
            bool vis[MAX];

            // dijkstra 单源多点最短路径 正边 堆优化 O((n+m)log(n))
            // 参数: st: 起点.
            void dijkstra(int st)
            {
                memset(dis, 0x3f, sizeof(dis));
                memset(vis, false, sizeof(vis));
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
                dis[st] = 0;
                heap.push({0, st});
                while (not heap.empty())
                {
                    pair<int, int> p = heap.top();
                    heap.pop();
                    int x = p.second, distance = p.first;
                    if (vis[x])
                        continue;
                    vis[x] = true;
                    for (pair<int, int> p : edge[x])
                    {
                        int y = p.first, weight = p.second;
                        if (dis[y] > distance + weight)
                        {
                            dis[y] = distance + weight;
                            heap.push({dis[y], y});
                        }
                    }
                }
            }
        }

        // bellman - 判断负环 & 跳出优化 O(mn)
        namespace bellman
        {
            // 边目录存图
            const int MAXN = 105;
            const int MAXM = 10005;
            struct EDGE
            {
                int u, v, w;
            } edge[MAXM];
            int dis[MAXN];

            // bellman 单源多点最短路径 正负边 判断负环 跳出优化
            // 参数: st: 起点, n: 点数, m: 边数. 返回: 是否不存在负环.
            bool bellman(int st, int n, int m)
            {
                for (int __ = 0; __ < n; __++)
                {
                    bool flag = true;
                    for (int i = 1; i <= m; i++)
                        if (dis[edge[i].v] > dis[edge[i].u] + edge[i].w)
                        {
                            dis[edge[i].v] = dis[edge[i].u] + edge[i].w;
                            flag = false;
                        }
                    if (flag)
                        return true;
                }
                return false;
            }
        }

        // spfa - bellman队列优化 O(m) -> O(mn)
        namespace spfa
        {
            const int MAX = 1005;

            // 邻接表存图
            vector<pair<int, int>> edge[MAX];
            int dis[MAX];
            bool vis[MAX];
            int cou[MAX];

            // spfa 单源多点最短路径 正负边 判断负环 队列优化
            // 参数: st: 起点, n: 点数. 返回: 是否不存在负环.
            bool spfa(int st, int n)
            {
                memset(dis, 0x3f, sizeof(int) * (n + 1));
                memset(vis, false, sizeof(int) * (n + 1));
                memset(cou, 0, sizeof(int) * (n + 1));
                dis[st] = 0;
                vis[st] = true;
                queue<int> que;
                que.push(st);
                while (not que.empty())
                {
                    int x = que.front();
                    que.pop();
                    vis[x] = false;
                    for (pair<int, int> p : edge[x])
                    {
                        int y = p.first, d = p.second;
                        if (dis[y] > dis[x] + d)
                        {
                            dis[y] = dis[x] + d;
                            cou[y] = cou[x] + 1;
                            if (cou[y] >= n)
                                return false;
                            if (not vis[y])
                            {
                                que.push(y);
                                vis[y] = true;
                            }
                        }
                    }
                }
                return true;
            }
        }

        // floyd O(n^3)
        namespace floyd
        {
            const int MAX = 105;

            // 邻接矩阵存图
            int edge[MAX][MAX]; // 不相连的点为INF, 自身为0

            // floyd 多源多点最短路径 正负边
            // 参数: n: 点数.
            void floyd(int n)
            {
                for (int k = 1; k <= n; k++)
                    for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= n; j++)
                            edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    // 最小生成树
    namespace minimum_spanning_tree
    {
        // prim - O(n^2)
        namespace prim
        {
            const int INF = 0x3f3f3f3f3f3f3f3fll;
            const int MAX = 3005;

            int n, m;
            vector<pair<int, int>> edge[MAX];
            bool vis[MAX] = {false};

            int prim()
            {
                int dis = 0;
                vis[1] = true;
                for (int i = 1; i < n; i++)
                {
                    int ymin = 0, min_ = INF;
                    for (int x = 1; x <= n; x++)
                        if (vis[x])
                        {
                            for (pair<int, int> p : edge[x])
                            {
                                int y = p.first, distance = p.second;
                                if (not vis[y] and min_ > distance)
                                {
                                    ymin = y;
                                    min_ = distance;
                                }
                            }
                        }
                    if (ymin == 0)
                        return -1;
                    vis[ymin] = true;
                    dis += min_;
                }
                return dis;
            }
        }

        // kruskal - O(mlogm)
        namespace kruskal
        {
            const int MAXN = 10005;
            const int MAXM = 100005;
            int n, m;
            struct Edge
            {
                int u;
                int v;
                int w;
            } edge[MAXM];
            int father[MAXN];

            int root(int x) { return father[x] == x ? x : father[x] = root(father[x]); }

            void merge(int x, int y) { father[root(x)] = root(y); }

            int kruskal()
            {
                iota(father + 1, father + n + 1, 1);
                sort(edge, edge + m, [](const Edge &x, const Edge &y)
                     { return x.w < y.w; });
                int cnt = 0, i = 0, dis = 0;
                while (cnt < n - 1 and i < m)
                {
                    if (root(edge[i].u) != root(edge[i].v))
                    {
                        merge(edge[i].u, edge[i].v);
                        cnt++;
                        dis += edge[i].w;
                    }
                    i++;
                }
                if (cnt < n - 1)
                    return -1;
                return dis;
            }
        }
    }

    // 网络流
    namespace flow_network
    {
        // 最大流最小割
        namespace max_flow_min_cut
        {
            // Useless - FF 算法. 时间复杂度: 小概率很快 -> O(fm) (f: 所求-最大流) / O(wm^2) (w: 边权)
            namespace ford_fulkerson
            {
                const int MAX = 1005;
                const int INF = 0x3f3f3f3f3f3f3f3fll;

                int n, m, st, ed;
                int flow[MAX];
                int pre[MAX]; // 前驱与标记双重作用
                int weight[MAX][MAX] = {0};
                vector<int> edge[MAX];

                // 快速路径搜索
                bool dfs(int x)
                {
                    if (x == ed)
                        return true;
                    for (int y : edge[x])
                        if (weight[x][y] > 0 and pre[y] == -1)
                        {
                            flow[y] = min(flow[x], weight[x][y]);
                            pre[y] = x;
                            if (dfs(y))
                                return true;
                            pre[y] = -1;
                        }
                    return false;
                }
                bool dfs()
                {
                    for (int i = 1; i <= n; i++)
                        pre[i] = -1;
                    flow[st] = INF;
                    pre[st] = st;
                    return dfs(st);
                }

                // 修改流
                void modify(int w)
                {
                    int y = ed;
                    while (pre[y] != y)
                    {
                        int x = pre[y];
                        weight[x][y] -= w;
                        weight[y][x] += w;
                        y = x;
                    }
                }

                // FF 主调用
                int ford_fulkerson()
                {
                    int res = 0;
                    for (int y : edge[st])
                        res -= weight[y][st];
                    while (dfs())
                        modify(flow[ed]);
                    for (int y : edge[st])
                        res += weight[y][st];
                    return res;
                }

                void solve()
                {
                    cin >> n >> m >> st >> ed;
                    for (int i = 0; i < m; i++)
                    {
                        int u, v, w;
                        cin >> u >> v >> w;
                        if (u == v or w == 0) // 自环, 空边
                            continue;
                        if (weight[u][v] or weight[v][u]) // 重边
                            weight[u][v] += w;
                        else
                        {
                            edge[u].push_back(v);
                            edge[v].push_back(u);
                            weight[u][v] = w;
                        }
                    }
                    cout << ford_fulkerson() << endl;
                }
            }

            // EK 算法. 时间复杂度: 很快 -> O(nm^2)
            namespace edmonds_karp
            {
                const int MAX = 1005;
                const int INF = 0x3f3f3f3f3f3f3f3fll;

                int n, m, st, ed;
                int flow[MAX];
                int pre[MAX]; // 前驱与标记双重作用
                int weight[MAX][MAX] = {0};
                vector<int> edge[MAX];

                // 最少步数搜索
                bool bfs()
                {
                    for (int i = 1; i <= n; i++)
                        pre[i] = -1;
                    queue<int> que;
                    que.push(st);
                    flow[st] = INF;
                    pre[st] = st;
                    while (not que.empty() and pre[ed] == -1)
                    {
                        int x = que.front();
                        que.pop();
                        for (int y : edge[x])
                            if (weight[x][y] > 0 and pre[y] == -1)
                            {
                                que.push(y);
                                flow[y] = min(flow[x], weight[x][y]);
                                pre[y] = x;
                            }
                    }
                    return pre[ed] != -1;
                }

                // 修改流
                void modify(int w)
                {
                    int y = ed;
                    while (pre[y] != y)
                    {
                        int x = pre[y];
                        weight[x][y] -= w;
                        weight[y][x] += w;
                        y = x;
                    }
                }

                // EK 主调用
                int edmonds_karp()
                {
                    int res = 0;
                    for (int y : edge[st])
                        res -= weight[y][st];
                    while (bfs())
                        modify(flow[ed]);
                    for (int y : edge[st])
                        res += weight[y][st];
                    return res;
                }

                void solve()
                {
                    cin >> n >> m >> st >> ed;
                    for (int i = 0; i < m; i++)
                    {
                        int u, v, w;
                        cin >> u >> v >> w;
                        if (u == v or w == 0) // 自环, 空边
                            continue;
                        if (weight[u][v] or weight[v][u]) // 重边
                            weight[u][v] += w;
                        else
                        {
                            edge[u].push_back(v);
                            edge[v].push_back(u);
                            weight[u][v] = w;
                        }
                    }
                    cout << edmonds_karp() << endl;
                }
            }

            // Dinic 算法. 时间复杂度: 还要快 -> O(mn^2)
            namespace dinic
            {
                const int MAX = 1005;
                const int INF = 0x3f3f3f3f3f3f3f3fll;

                int n, m, st, ed;
                int depth[MAX];
                int weight[MAX][MAX] = {0};
                vector<int> edge[MAX];

                // 搜索阻塞流
                int dfs(int x, int flow)
                {
                    if (x == ed)
                        return flow;
                    int cost = 0;
                    for (int y : edge[x])
                        if (weight[x][y] > 0 and depth[y] == depth[x] + 1)
                        {
                            int tmp = dfs(y, min(flow, weight[x][y]));
                            weight[x][y] -= tmp;
                            weight[y][x] += tmp;
                            cost += tmp;
                            flow -= tmp;
                        }
                    return cost;
                }

                // 构建分层图
                bool bfs()
                {
                    for (int i = 1; i <= n; i++)
                        depth[i] = -1;
                    queue<int> que;
                    que.push(st);
                    depth[st] = 0;
                    while (not que.empty() and depth[ed] == -1)
                    {
                        int x = que.front();
                        que.pop();
                        for (int y : edge[x])
                            if (weight[x][y] > 0 and depth[y] == -1)
                            {
                                que.push(y);
                                depth[y] = depth[x] + 1;
                            }
                    }
                    return depth[ed] != -1;
                }

                // Dinic 主调用
                int dinic()
                {
                    int res = 0;
                    for (int y : edge[st])
                        res -= weight[y][st];
                    while (bfs())
                        dfs(st, INF);
                    for (int y : edge[st])
                        res += weight[y][st];
                    return res;
                }

                void solve()
                {
                    cin >> n >> m >> st >> ed;
                    for (int i = 0; i < m; i++)
                    {
                        int u, v, w;
                        cin >> u >> v >> w;
                        if (u == v or w == 0) // 自环, 空边
                            continue;
                        if (weight[u][v] or weight[v][u]) // 重边
                            weight[u][v] += w;
                        else
                        {
                            edge[u].push_back(v);
                            edge[v].push_back(u);
                            weight[u][v] = w;
                        }
                    }
                    cout << dinic() << endl;
                }
            }
        }

        // 最小费用最大流
        namespace min_cost_max_flow
        {
            // EK + SPFA 算法. 注意: 本算法不处理反边, 重边. 时间复杂度: 很快 -> O(nm^3)
            namespace edmonds_karp
            {
                const int MAX = 1005;
                const int INF = 0x3f3f3f3f3f3f3f3fll;

                int n, m, st, ed;
                int max_flow = 0, min_cost = 0;
                int dis[MAX];
                int vis[MAX];
                int flow[MAX];
                int pre[MAX];
                int weight[MAX][MAX] = {0};
                int cost[MAX][MAX] = {0};
                vector<int> edge[MAX];

                // 最短路径搜索(存在负边, 不处理负环)
                bool spfa()
                {
                    for (int i = 1; i <= n; i++)
                    {
                        dis[i] = INF;
                        vis[i] = false;
                    }
                    dis[st] = 0;
                    queue<int> que;
                    que.push(st);
                    vis[st] = true;
                    flow[st] = INF;
                    pre[st] = st;
                    while (not que.empty())
                    {
                        int x = que.front();
                        que.pop();
                        vis[x] = false;
                        for (int y : edge[x])
                        {
                            if (weight[x][y] == 0)
                                continue;
                            if (dis[y] > dis[x] + cost[x][y])
                            {
                                dis[y] = dis[x] + cost[x][y];
                                flow[y] = min(flow[x], weight[x][y]);
                                pre[y] = x;
                                if (not vis[y])
                                {
                                    que.push(y);
                                    vis[y] = true;
                                }
                            }
                        }
                    }
                    return dis[ed] < INF;
                }

                // 修改流
                void modify(int w)
                {
                    int y = ed;
                    max_flow += w;
                    while (pre[y] != y)
                    {
                        int x = pre[y];
                        weight[x][y] -= w;
                        weight[y][x] += w;
                        min_cost += w * cost[x][y];
                        y = x;
                    }
                }

                // EK 主调用
                void edmonds_karp()
                {
                    max_flow = 0, min_cost = 0;
                    while (spfa())
                        modify(flow[ed]);
                }

                void solve()
                {
                    cin >> n >> m >> st >> ed;
                    for (int i = 0; i < m; i++)
                    {
                        int u, v, w, c;
                        cin >> u >> v >> w >> c;
                        if (u == v or w == 0) // 自环, 空边
                            continue;
                        edge[u].push_back(v);
                        edge[v].push_back(u);
                        weight[u][v] = w;
                        cost[u][v] = c;
                        cost[v][u] = -c;
                    }
                    edmonds_karp();
                    cout << max_flow << ' ' << min_cost << endl;
                }
            }

            namespace dinic
            {

            }
        }
    }

    // 二分图
    namespace bipartite_graph
    {
        // 判断二分图
        namespace is_bpg
        {
            const int MAX = 3005;
            int color[MAX] = {0}; // 0: 未染色, 1: 红色, -1: 蓝色
            vector<int> edge[MAX];

            bool dfs(int x)
            {
                for (int y : edge[x])
                    if (color[y])
                        if (color[y] + color[x])
                            return false;
                        else
                        {
                            color[y] = -color[x];
                            if (not dfs(y))
                                return false;
                        }
                return true;
            }
            bool is_bpg()
            {
                color[1] = 1;
                return dfs(1);
            }
        }

        // 二分图最大匹配(Dinic实现). 时间复杂度: O(mn^0.5)
        namespace max_marriage
        {

        }
    }

    // 最近公共祖先. 时间复杂度: O(logn) + 预处理: O(nlogn), 空间复杂度: O(nlogn)
    namespace lowest_common_ancestor
    {
        const int MAX = 100005;
        const int LOG = 17;

        int lg2[MAX];
        vector<int> edge[MAX];
        int depth[MAX];
        int st[MAX][LOG];

        void load_lg2(int n)
        {
            lg2[0] = -1;
            for (int i = 1; i <= n; i++)
                lg2[i] = lg2[i >> 1] + 1;
        }

        // 建表
        void dfs(int x, int pre, int level)
        {
            depth[x] = level;
            st[x][0] = pre;
            for (int i = 1; i <= lg2[depth[x]]; i++)
                st[x][i] = st[st[x][i - 1]][i - 1];
            for (int y : edge[x])
                if (y != pre)
                    dfs(y, x, level + 1);
        }

        // 查询
        int lca(int x, int y)
        {
            if (depth[x] < depth[y])
                swap(x, y);
            while (depth[x] > depth[y])
                x = st[x][lg2[depth[x] - depth[y]]];
            if (x == y)
                return x;
            for (int k = lg2[depth[x]]; k >= 0; --k)
                if (st[x][k] != st[y][k])
                {
                    x = st[x][k];
                    y = st[y][k];
                }
            return st[x][0];
        }
    }
}

// 排序算法
namespace sort_
{
    // 快速排序. 如果必要, 使用__quick_sort, 其l/r是包含的.
    void __quick_sort(int q[], int l, int r)
    {
        if (l >= r)
            return;

        int i = l - 1, j = r + 1, x = q[l + r >> 1];
        while (i < j)
        {
            do
                i++;
            while (q[i] < x);
            do
                j--;
            while (q[j] > x);
            if (i < j)
                swap(q[i], q[j]);
        }
        __quick_sort(q, l, j);
        __quick_sort(q, j + 1, r);
    }
    inline void quick_sort(int q[], int n) { __quick_sort(q, 0, n - 1); }

    // 归并排序. 如果必要, 使用__merge_sort, 其l/r是包含的.
    void __merge_sort(int q[], int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + r >> 1;
        __merge_sort(q, l, mid);
        __merge_sort(q, mid + 1, r);

        int tmp[r - l + 1];
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
            if (q[i] <= q[j])
                tmp[k++] = q[i++];
            else
                tmp[k++] = q[j++];

        while (i <= mid)
            tmp[k++] = q[i++];
        while (j <= r)
            tmp[k++] = q[j++];

        for (i = l, j = 0; i <= r; i++, j++)
            q[i] = tmp[j];
    }
    inline void merge_sort(int q[], int n) { __merge_sort(q, 0, n - 1); }
}

// 搜索算法
namespace binary_search
{
    // 二分查找, 返回任意索引, 否则返回-1.
    int binary_search_bool(int q[], int n, int value)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (q[m] == value)
                return m;
            else if (q[m] < value)
                i = m + 1;
            else
                j = m - 1;
        }
        return -1;
    }

    // 二分查找, 返回首个大于等于索引.
    int binary_search_lower(int q[], int n, int value)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (q[m] < value)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }

    // 二分查找, 返回首个大于索引.
    int binary_search_upper(int q[], int n, int value)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (q[m] <= value)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
}

// 快读快写
namespace fast_io
{
    // 快读. __int128_t 类型必须使用此函数读取.
    inline int read(int &x)
    {
        int ans = 0;
        bool f = false;
        char c = getchar();
        while (!isdigit(c))
        {
            if (c == '-')
                f = true;
            c = getchar();
        }
        while (isdigit(c))
        {
            ans = ans * 10 + c - '0';
            c = getchar();
        }
        return x = f ? -ans : ans;
    }

    // 快写. __int128_t 类型必须使用此函数打印.
    void __write(int x)
    {
        if (x > 9)
            __write(x / 10);
        putchar(x % 10 + '0');
    }
    inline void write(int x)
    {
        if (x < 0)
        {
            x = -x;
            putchar('-');
        }
        __write(x);
        putchar('\n');
    }

    // 超级读写
    // #define DEBUG 1  // 调试开关
    class IO
    {
    public:
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
        char buf[MAXSIZE], *p1, *p2;
        char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
        IO() : p1(buf), p2(buf), pp(pbuf)
        {
        }

        ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
        inline char gc()
        {
#if DEBUG // 调试，可显示字符
            return getchar();
#endif
            if (p1 == p2)
                p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
            return p1 == p2 ? ' ' : *p1++;
        }

        inline bool blank(char ch)
        {
            return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
        }

        template <class T>
        inline void read(T &x)
        {
            register double tmp = 1;
            register bool sign = 0;
            x = 0;
            register char ch = gc();
            for (; !isdigit(ch); ch = gc())
                if (ch == '-')
                    sign = 1;
            for (; isdigit(ch); ch = gc())
                x = x * 10 + (ch - '0');
            if (ch == '.')
                for (ch = gc(); isdigit(ch); ch = gc())
                    tmp /= 10.0, x += tmp * (ch - '0');
            if (sign)
                x = -x;
        }

        inline void read(char *s)
        {
            register char ch = gc();
            for (; blank(ch); ch = gc())
                ;
            for (; !blank(ch); ch = gc())
                *s++ = ch;
            *s = 0;
        }

        inline void read(char &c)
        {
            for (c = gc(); blank(c); c = gc())
                ;
        }

        inline void push(const char &c)
        {
#if DEBUG // 调试，可显示字符
            putchar(c);
#else
            if (pp - pbuf == MAXSIZE)
                fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
            *pp++ = c;
#endif
        }

        template <class T>
        inline void write(T x)
        {
            if (x < 0)
                x = -x, push('-'); // 负数输出
            static T sta[35];
            T top = 0;
            do
            {
                sta[top++] = x % 10, x /= 10;
            } while (x);
            while (top)
                push(sta[--top] + '0');
        }

        template <class T>
        inline void write(T x, char lastChar)
        {
            write(x), push(lastChar);
        }
    } io;
}
