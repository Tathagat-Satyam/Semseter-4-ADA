#include <iostream>
#include <string>
using namespace std;
void permute(string s, int l, int r) {
    if (l == r) cout << s << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
int main() {
    string str; cin >> str;
    permute(str, 0, str.length() - 1);
    return 0;
}