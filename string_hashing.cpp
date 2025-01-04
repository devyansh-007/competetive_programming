
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




// CONTINUED 
