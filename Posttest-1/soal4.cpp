#include <iostream>
using namespace std;

void tukarAngka(int &bilangan1, int &bilangan2){
    int temp = bilangan1;
    bilangan1 = bilangan2;
    bilangan2 = temp;
}

int main(){

    int angka1, angka2;

    cout<<"Masukkan bilangan pertama : ";
    cin>>angka1;
    cout<<"Masukkan bilangan kedua   : ";
    cin>>angka2;
    cout<<endl;

    cout<<"Bilangan sebelum ditukar"<<endl;
    cout<<"Bilangan pertama : "<<angka1<<endl;
    cout<<"Bilangan kedua   : "<<angka2<<endl;
    cout<<endl;

    tukarAngka(angka1, angka2);

    cout<<"Bilangan setelah ditukar"<<endl;
    cout<<"Bilangan pertama : "<<angka1<<endl;
    cout<<"Bilangan kedua   : "<<angka2<<endl;

    return 0;
}