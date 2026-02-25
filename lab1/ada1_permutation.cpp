#include <iostream>
#include <string>
#include<chrono>
using namespace std::chrono;
using namespace std;

void permute(string s, int start = 0) {
    if (start == s.length() - 1) {
        cout << s << endl;
        return;
    }
    
    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);  
        permute(s, start + 1);   
        swap(s[start], s[i]);   
    }
}

int main() {
    string str; 
    cout<<"enter ur string";
    cin>>str;
    cout << "Permutations of " << str << ":\n";
    permute(str);
    return 0;
}
 