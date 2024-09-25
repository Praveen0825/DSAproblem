// pattern matching algorithm
void kmp(string &s, string &pat)
{
    string t = pat + '#' + s;
    int n = t.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && t[j] != t[i])
        {
            j = lps[j - 1];
        }
        lps[i] = t[j] == t[i] ? j + 1 : 0;
    }
}