#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;;

struct flightSchecule
{
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node
{
    flightSchecule data;
    Node* next;
};

string codeCreate(string code, int &squence){
    if (squence==0){
        squence++;
        return code;
    }else{
        return code + "-" + to_string(squence++);
    };
}

void tambahJadwal(Node *&head, string code, int &squence){
    Node *newNode = new Node;
    newNode->data.kodePenerbangan = codeCreate(code, squence);
    cout<<"Masukkan Tujuan Penerbangan : ";
    getline(cin, newNode->data.tujuan);
    cout<<"Masukan Status Penerbangan : ";
    getline(cin,newNode->data.status);

    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
    }else{
        Node *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout<<"Data Berhasil di tambahkan"<<endl;
    system("pause");
};

void sisipkanJadwal(Node *&head, string code, int &squence){
    int posisi = 2 + 1;

    Node *newNode = new Node;
    newNode->data.kodePenerbangan = codeCreate(code, squence);
    cout<<"Masukkan Tujuan Penerbangan : ";
    getline(cin, newNode->data.tujuan);
    cout<<"Masukan Status Penerbangan : ";
    getline(cin,newNode->data.status);

    if(head == nullptr || posisi <=1){
        newNode->next = head;
        head = newNode;
    }else{
        Node *temp = head;
        int start = 1;
        while(temp->next!=nullptr && start < posisi-1){
            temp = temp->next;
            start++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout<<"Jadwal berhasil di sisipkan di posisi" << posisi<<" dengan kode : "<< newNode->data.kodePenerbangan<<endl;
    system("pause");

}

void hapusAwal(Node *&head){
    if (head==nullptr){
        cout<<"Data Kosong"<<endl;
        cout<<"Tidak ada data untuk di hapus"<<endl;
    }else{
        Node* temp = head;
        head = head->next;
        cout<<"Data dengan kode penerbangan "<<temp->data.kodePenerbangan<<" Berhasil di hapus"<<endl;
        delete temp;
        cout<<"Data Berhasil di hapus"<<endl;
    }
    system("pause");
}

void UpdateStatus(Node *&head){
    if (head==nullptr){
        cout<<"Data Kosong"<<endl;
        cout<<"Tidak ada data untuk di hapus"<<endl;
    }else{
        string kode;
        cout<<"Masukkan kode penerbangan yang akan di update: ";
        cin>>kode;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Node *temp = head;
        while(temp != nullptr && temp->data.kodePenerbangan != kode){
            temp = temp->next;
        }

        if(temp == nullptr){
            cout<<"Kode penerbangan tidak ditemukan"<<endl;
        }
        else{
            cout<<"Status saat ini " << temp->data.status<<endl;
            cout<<"Masukkan status baru : ";
            getline(cin,temp->data.status);
            cout<<"Status diperbaharui"<<endl;
        }
    }
    system("pause");
    
}

void showAll(Node *&head){
    if (head==nullptr){
        cout<<"Data Kosong"<<endl;
        cout<<"Tidak ada data untuk ditampilkan"<<endl;
    }
    else{
        Node *temp = head;
        cout<<"Daftar Jadwal Penerbangan"<<endl;
        cout<<string("=",20)<<endl;
        cout<<left<<
        setw(4)<<"No"<<
        setw(9)<<"Kode"<<
        setw(15)<<"Tujuan"<<
        setw(13)<<"Status"
        <<endl;
        cout<<string(36,'=')<<endl;
        int angka = 0;
        while (temp != nullptr)
        {   
            cout<<left
            <<setw(4)<<angka+1
            <<setw(9)<<temp->data.kodePenerbangan
            <<setw(15)<<temp->data.tujuan
            <<setw(13)<<temp->data.status<<endl;
            angka ++;
            temp = temp->next;
        }
        cout<<string(36,'=')<<endl;
        
    }
    system("pause");
}

main(){

    int pilih, codeSquence=0;
    string codeUnique = "JT-052";

    Node *head = nullptr;
    Node *tail = nullptr;

    do{
        system("cls||clear");
        cout<<" "<<string(36,'=')<<endl;
        cout<<"|        FLIGHT SCHEDULE SYSTEM      |"<<endl;
        cout<<"|  SANTOSO P TOGATOROP - 2409106052  |"<<endl;
        cout<<" "<<string(36,'=')<<endl;
        cout<<"| 1. Tambah Jadwal Penerbangan       |"<<endl;
        cout<<"| 2. Sisipkan Jadwal Penerbangan     |"<<endl;
        cout<<"| 3. Hapus Jadwal Paling Awal        |"<<endl;
        cout<<"| 4. Update Status Penerbangan       |"<<endl;
        cout<<"| 5. Tampilkan Semua Jadwal          |"<<endl;
        cout<<"| 0. Keluar                          |"<<endl;
        cout<<" "<<string(36,'=')<<endl;
        cout<<"Pilihan Anda : ";
        cin>>pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls||clear");


        switch (pilih)
        {
        case 1: tambahJadwal(head, codeUnique, codeSquence); break;
        case 2: sisipkanJadwal(head, codeUnique, codeSquence);break;
        case 3: hapusAwal(head); break;
        case 4: UpdateStatus(head); break;
        case 5: showAll(head); break;
        case 0: cout<<"Keluar dari program....";break;
        default:break;
        }



    }while (pilih != 0) ;

    return 0;
}
