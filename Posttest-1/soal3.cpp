#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    double ipk;
};


int main(){

    Mahasiswa mhs[4];

    for(int i=0; i<4; i++){
        cout<<"Mahasiswa ke-"<<i+1<<endl;
        cout<<"Nama\t: ";
        getline(cin, mhs[i].nama);
        cout<<"Nim\t: ";
        getline(cin, mhs[i].nim);
        cout<<"Ipk\t: ";
        cin>>mhs[i].ipk;
        cin.ignore();
        cout<<endl;
    }

    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            if(mhs[j].nim > mhs[j+1].nim){
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
    cout<<endl;

    cout<<"Data Mahasiswa "<<endl;
    for(int l=0; l<4; l++){
        cout<<"Mahasiswa ke-"<<l+1<<endl;
        cout<<"Nama\t: "<<mhs[l].nama<<endl;
        cout<<"Nim\t: "<<mhs[l].nim<<endl;
        cout<<"Ipk\t: "<<mhs[l].ipk<<endl;
        cout<<endl;
    }

    return 0;
}