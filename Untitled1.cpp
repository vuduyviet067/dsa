#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Hang {
    char MaH[20];
    char TenH[50];
    char DvTinh[30];
    int SL;
    float DonGia;
};

struct node {
    Hang data;
    node* next;
};

// T?o node m?i ch?a H
node* taonode(const Hang& H) {
    node* p = new node;
    p->data = H;
    p->next = NULL;
    return p;
}

// Th�m v�o �?u danh s�ch
void themdau(node*& head, const Hang& H) {
    node* p = taonode(H);
    p->next = head;
    head = p;
}

// Ch�n sau node q
void chen_sau(node* q, const Hang& H) {
    if (!q) return;
    node* p = taonode(H);
    p->next = q->next;
    q->next = p;
}

// X�a �?u
void xoa_dau(node*& head) {
    if (!head) return;
    node* p = head;
    head = head->next;
    delete p;
}

// Nh?p m?t Hang
void nhap(Hang &H) {
    cout << "Nhap ma hang: ";    fflush(stdin);    gets(H.MaH);
    cout << "Nhap ten hang: ";   fflush(stdin);    gets(H.TenH);
    cout << "Nhap don vi tinh: ";fflush(stdin);    gets(H.DvTinh);
    cout << "Nhap don gia: ";    cin >> H.DonGia;
    cout << "Nhap so luong: ";   cin >> H.SL;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Nh?p danh s�ch �?n khi m?=e
void nhapds(node*& head) {
    head = NULL;
    Hang H;
    int i = 1;
    while (true) {
        cout << "\n--- Nhap hang thu " << i << " (ma=e de dung) ---\n";
        nhap(H);
        if (strcmp(H.MaH, "e") == 0) break;
        themdau(head, H);
        i++;
    }
}

// Hi?n th? danh s�ch v?t t� v� th�nh ti?n
void hienthi(node* head) {
    cout << left
         << setw(10) << "MaH"
         << setw(20) << "TenH"
         << setw(15) << "DVT"
         << setw(10) << "DonGia"
         << setw(10) << "SL"
         << setw(12) << "ThanhTien"
         << "\n";
    cout << string(77, '-') << "\n";

    node* temp = head;
    while (temp) {
        Hang& H = temp->data;
        float thanhTien = H.DonGia * H.SL;
        cout << left
             << setw(10) << H.MaH
             << setw(20) << H.TenH
             << setw(15) << H.DvTinh
             << setw(10) << H.DonGia
             << setw(10) << H.SL
             << setw(12) << thanhTien
             << "\n";
        temp = temp->next;
    }
}

int main() {
    node* head = NULL;

    // 1. Nh?p danh s�ch h�ng h�a
    cout << "Nhap danh sach hang hoa:\n";
    nhapds(head);

    // 2. Hi?n th? danh s�ch v?a nh?p
    cout << "\nDanh sach hang hoa vua nhap:\n";
    hienthi(head);

    // 3. Th�m m?t h�ng h�a m?i sau node c� m? h�ng c? th?
    Hang newHang;
    char maHangCanChen[20];
    cout << "\nNhap ma hang de chen sau: ";
    fflush(stdin);
    gets(maHangCanChen);
    cout << "Nhap thong tin hang hoa moi de chen:\n";
    nhap(newHang);

    // T?m node c� m? h�ng c?n ch�n sau
    node* temp = head;
    bool found = false;
    while (temp) {
        if (strcmp(temp->data.MaH, maHangCanChen) == 0) {
            chen_sau(temp, newHang);
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        cout << "\nDanh sach sau khi chen:\n";
        hienthi(head);
    } else {
        cout << "\nKhong tim thay ma hang " << maHangCanChen << " de chen sau!\n";
    }

    // 4. X�a node �?u ti�n
    cout << "\nXoa node dau tien...\n";
    xoa_dau(head);
    cout << "Danh sach sau khi xoa node dau:\n";
    hienthi(head);

    // 5. Gi?i ph�ng b? nh?
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
