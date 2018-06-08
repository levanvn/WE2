// Thuat toan KMP cho bai toan String Searching: Tim xau S trong text T
/*
https://en.wikipedia.org/wiki/String_searching_algorithm
http://vnoi.info/wiki/translate/wcipeg/kmp
http://www.comp.nus.edu.sg/~rahul/allfiles/aldrian-text-searching.pdf
Y tuong : xu ly S truoc khi so khop de bo qua nhung vi tri khong can thiet

*/

#include <bits/stdc++.h>
using namespace std;

int a[100000];
string s,t;

void Bang_hau_to(string &s, int a[]){
     int k = 0;
    a[0] = 0;
    for(int i = 1 ;i < s.length(); i++){
        while(k > 0 && s[k] != s[i]) k = a[k];
        if(s[k] == s[i]) k = k+1;
        a[i] = k;
    }
    for(int i = 0; i< s.length(); i++ ) cout << a[i] << "  ";
    cout << endl;
}

void So_khop(string &s, string &t){
    int j = 0; // j la chi so cua T

    int k = 0; // k la chi so de so khop
    int m = s.length(); int n = t.length();
    while(j+m <= n){
        while (k < m && s[k] == t[j+k]) k++; //tim vi tri s[k] != t[j+k]
        if( k == m) cout << "Tim thay tai vi tri: " << j << endl;
        if( k == 0) j++;
        else {
            j = j+k-a[k-1]; // j nhay den vi tri
            k = a[k-1];     // k so sanh tu a[k]
        }
        cout << j << "  " << k << endl;

    }

}

int main(){
    cin >> s;
    cin >> t;
    Bang_hau_to(s,a);
    So_khop(s,t);

return 0;
}
