// Rabin-Karp algorithm in C++

#include <string.h>

#include <iostream>
using namespace std;

#define d 26

void rabinKarp(char pattern[], char text[], int mod)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % mod;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % mod;
        t = (d * t + text[i]) % mod;
    }

    // Find the match
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern is found at position: " << i + 1 << endl;
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % mod;

            if (t < 0)
                t = (t + mod);
        }
    }
}

int main()
{
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int mod = 13;
    rabinKarp(pattern, text, mod);
}