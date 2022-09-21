#include "bits/stdc++.h"
#define NO_OF_CHARS 256
using namespace std;

void shiftTable(string str, int size, int chars[256]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++) 
        chars[i] = -1;
    for (i = 0; i < size; i++)
        chars[(int) str[i]] = 1;
}

void search(string txt, string pat) {
    int m = pat.size();
    int n = txt.size();
    int chars[NO_OF_CHARS];
    shiftTable(pat, m, chars);
    int s=0;
    while ( s <= (n-m)) {
        int j = m-1;
        while (j >= 0 && pat[j] == txt[s+j])
            j--;
        if(j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;
            s += (s+m<n) ? m-chars[txt[s+m]] : 1;
        }
        else 
            s += max(1, j-chars[txt[s+j]]);
    }
}

int main() {
    string txt = "HELLOWORLDHELLOWORD";
    string pat = "WOR";
    cout << "Text = " << txt << endl;
    cout << "Pattern = " << pat << endl;
    search(txt, pat);
    return 0;
}