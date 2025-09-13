#include <iostream>
using namespace std;

void tukarPosisi(int *data, int panjang){
    for(int i=0; i<panjang/2; i++){
        int temp = data[i];
        data[i] = data[panjang-1-i];
        data[panjang-1-i] = temp;
    }
}

int main(){

    int prima[7] = {2,3,5,7,11,13,17};
    int panjang = sizeof(prima)/sizeof(prima[0]);

    cout<<"Array sebelum ditukar"<<endl;
    for(int i=0; i<7; i++){
        cout<<prima[i]<<" ";
    };
    cout<<endl;

    tukarPosisi(prima, panjang);

    cout<<"Array setelah ditukar"<<endl;
    for(int i=0; i<7; i++){
        cout<<prima[i]<<" ";
    };
    cout<<endl;

    return 0;
}