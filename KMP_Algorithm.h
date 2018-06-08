#include<bits/stdc++.h>

using namespace std;

int a[100000];
 int count1 = 0 ;
string s,t;
void Bang_hau_to(string &, int );
void So_khop(string &, string &);

void print_menu();
void File();
void Search(fstream &file);
void Replace(fstream &file);
void Exit();
void KMP_Algorithm();
void Stack();
void File();
void Dothi();
void BFS(int,int ,int, int b[][100]);

void Bang_hau_to(string &s, int a[]){
     int k = 0;
    a[0] = 0;
    for(int i = 1 ;i < s.length(); i++){
        while(k > 0 && s[k] != s[i]) k = a[k];
        if(s[k] == s[i]) k = k+1;
        a[i] = k;
    }
   // for(int i = 0; i< s.length(); i++ ) cout << a[i] << "  ";
  //  cout << endl;
}

void So_khop(string &s, string &t){

    Bang_hau_to(s,a);
    int j = 0; // j la chi so cua T
  //  cout << s;
    int k = 0; // k la chi so de so khop
    int m = s.length(); int n = t.length();
    while(j+m <= n){
        while (k < m && s[k] == t[j+k]) k++; //tim vi tri s[k] != t[j+k]
        if( k == m) {

            cout << "Found in Line: " << count1 << "   ";
            cout << "Colum: " << j << endl;
        }
        if( k == 0) j++;
        else {
            j = j+k-a[k-1]; // j nhay den vi tri

            k = a[k-1];     // k so sanh tu a[k]
           // cout << a[4];
        }
     //   cout << j << "  " << k << endl;

    }

}

