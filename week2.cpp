#include<bits/stdc++.h>
#include "KMP_Algorithm.h"

using namespace std;
int main(){
    while(1){
        print_menu();
        int choose;
        cin >> choose;
        switch(choose){
            case 1:
                Stack();
                break;
            case 2:

                File();
                break;
            case 3:
               Dothi();
                break;
        }

    }
return 0;
}

void print_menu(){
	printf("Danh sach cac bai tap:\r\n");
	printf("\t1. Day ngoac dungr\n");
	printf("\t2. String Searching \r\n");
	printf("\t3. Do thi \r\n");

	printf("\r\n>> Chon (1->3) tuong ung voi bai tap: ");
}


void File(){
    string file;
    cout << "Nhap vao file: "; cin >> file;
    ifstream fstr;
    fstr.open(file,ios::in);
    if(!fstr){

        cout << "Can not open file." << endl;
        exit(1);

    }
   
    
    cout << "Chon chuc nang :" <<endl;
    cout << "   1.Search\n   2.Replace\n   3.Exit\n";
    cout << "-------------------------------------" << endl;

    int choose;

    cin >> choose;
    switch(choose){
        case 1:
            Search(fstr);
            break;
        case 2:
            Replace(fstr);
            break;
        case 3:
          //  Exit();
            break;

    }
   // fst.close();

}

void Search(fstream &fstr){

    cout << "Enter keyword: ";
    string keyword;
    cin >> keyword;
   // getline(cin,keyword);
    //cout << keyword << endl;
    string str;  // str de doc tung dong
    //int count = 0; // bien dem so hang
    while(!fstr.eof()){
        count1++;
        getline(fstr,str);
        cout << "Line " << count1 << ": " << str << endl;
        So_khop(keyword,str); // Dung thuat toan KMP cho bai toa String Searching
        //cout << "Exit" ;
    }
    fstr.close();
}

void Replace(fstream &fstr){
  // fstr.open(file,ios::in | ios::out);

    cout << "Enter keyword: ";
    string s,newword;
   cin >> s;
   cout << "Enter new word(s): ";
    cin >> newword;
    string t;  // str de doc tung dong
     count1 = 0; // bien dem so hang
    while(!fstr.eof()){
        count1++;
        getline(fstr,t);
       // cout << "Truoc: " <<  fstr.tellg() << "   " << endl;
        char c;
      //  fstr >> c;
       // cout << c << endl;

       // cout << "Line " << count1 << ": " << t.length() << endl;
        Bang_hau_to(s,a);
   int  j = 0; // j la chi so cua T
  //  cout << s;
    int k = 0; // k la chi so de so khop
    int m = s.length(); int n = t.length();
    while(j+m <= n){
        while (k < m && s[k] == t[j+k]) k++; //tim vi tri s[k] != t[j+k]
        if( k == m) {

            cout << "Found in Line: " << count1 << "   ";
            cout << "Colum: " << j << endl;
            //long cur = fstr.tellg() + j;
            fstr.seekg(sizeof(char)*(j-n-1),ios::cur); // nhay den vi tri tim thay
            //cout << "Sau : " << fstr.tellg() << endl;
            fstr << newword;
            fstr.seekg(sizeof(char)*(n-j-m+1),ios::cur);
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
    cout << "Replace successfully!" << endl;
    fstr.close();

}
void Dothi(){

    int n,m,u,v,x,y;
    int b[100][100];

    ifstream inF;

    inF.open("INPUT.TXT");
    inF  >> n >> m >> u >> v;

    memset(b,0,sizeof(b));

        while(!inF.eof()){
            inF  >> x >> y;
            b[x][y] = 1;

        }

    BFS(u,v,n,b);
}

#include<queue>

void BFS(int dau, int cuoi, int n,int b[][100]){
    queue <int> qu;
    bool chuaxet[100];
    int truoc[100];
    memset(chuaxet,true,sizeof(chuaxet));
    chuaxet[dau] = false;
    qu.push(dau);
    int depth[100];depth[dau]=0;
    while(!qu.empty() ){
        int temp = qu.front();//cout  << qu.front() << endl;
        qu.pop();
        for(int i = 1 ; i <= n ;i++){
            if(b[temp][i] == 1 && chuaxet[i]){
                depth[i] = depth[temp] +1;
                qu.push(i);chuaxet[i] = false;
                truoc[i] = temp;
            }
        }
        if(chuaxet[cuoi] == false) break;
    }
   // for(int i = 1 ; i <= n ;i++) cout << depth[ i] << " ";
    int xuoi[100]; int k = depth[cuoi];int dem = k; xuoi[k] = cuoi;
    while(truoc[cuoi] != dau) {  cuoi = truoc[cuoi]; xuoi[k-1] = cuoi; k--;}
    xuoi[0] = dau;
    for(int i = 0; i <= dem ; i++) cout <<xuoi[i] << "  ";
    cout << endl;
}


void Stack(){
    int n = 0;
    stack <char> st;
    string s;
    //string *x;
    cout << "Nhap vao day ngoac: ";
    cin >> s;
    //x = &s;
    //cout << *x;
    for(int i = 0; i < s.length() ;i++){
        if(s[i] == '(' ) st.push(s[i]);

        else {
            if(!st.empty())	st.pop();
            else { n++;}
        }
    }
    int  k = n;
    while (!st.empty())
    {
        n++;
        st.pop();
    }
    cout << n  << endl;
    if (n!=0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i <= k) cout << "(" << i-1 << endl;
            else cout << ")" << s.length() +i-k-1 << endl;

        }
    }

}
