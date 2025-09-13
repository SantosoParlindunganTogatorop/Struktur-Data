#include <iostream>
using namespace std;

int main(){

    int jumlah[2] = {0,0};

    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i=0; i<3; i++){
        if(i%2==0){
            for(int j=0; j<3; j++){
                jumlah[i/2] += matrix[i][j];
            }
        }
    }

    for (int k=0; k<2; k++){
        cout<<"Jumlah elemen pada index "<<k<<" adalah "<<jumlah[k]<<endl;
    }

    cout<<"MATRIX ORDO 3 x 3"<<endl;

    for (int l=0; l<3; l++){
        for (int m=0; m<3; m++){
            cout<<matrix[l][m]<<" ";
        };
        cout<<endl;
    }

    return 0;
}