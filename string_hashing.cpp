
// TO COMPUTE NORMAL HASH OF ANY STRING 

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


// TO COMPUTE HASH FOR SUBSTRING FROM I - J


const int mod = 1e9 + 9;
const int p = 31;

vector<long long> compute_prefix_hash(const string& s) {
    int n = s.size();
    vector<long long> prefix_hash(n);
    long long hash_value = 0, pow = 1;

    for (int i = 0; i < n; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * pow) % mod;
        prefix_hash[i] = hash_value;
        pow = (pow * p) % mod;
    }

    return prefix_hash;
}

vector<long long> compute_powers(int n) {
    vector<long long> powers(n);
    powers[0] = 1;
    for (int i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * p) % mod;
    }
    return powers;
}

long long get_substring_hash(const vector<long long>& prefix_hash, const vector<long long>& powers, int i, int j) {
    long long hash_value = prefix_hash[j];
    if (i > 0) {
        hash_value = (hash_value - prefix_hash[i - 1] + mod) % mod;
    }
    hash_value = (hash_value * powers[prefix_hash.size() - i]) % mod; // Normalize hash
    return hash_value;
}



int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}



// RABIN KARP

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}






// CONTINUED 


#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long mod_pow(long long base, long long exp, long long m) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}

int computeHash(const string& s) {
    int n = s.size();
    int mul = 117;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long val = (s[i] - 'a' + 1);
        long long power = mod_pow(mul, n - i - 1, mod);
        ans = (ans + (val * power) % mod) % mod;
    }
    return ans;
}
