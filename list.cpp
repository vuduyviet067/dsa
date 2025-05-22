#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Hang {
    char mah[30];
    char tenh[50];
    char donvi[30];
    int dongia;
    int soluong;
    int thanhtien;
};

struct List {
    Hang A[MAX];
    int count;
};

void creat(List &L) {
    L.count = -1;
}

int empty(List L) {
    return L.count == -1;
}

int full(List L) {
    return L.count == MAX - 1;
}

int add_fist(List &L, Hang H) {
    if (full(L)) return 0;
    for (int i = L.count; i >= 0; i--) {
        L.A[i + 1] = L.A[i];
    }
    L.A[0] = H;
    L.count++;
    return 1;
}

int add_end(List &L, Hang H) {
    if (full(L)) return 0;
    L.count++;
    L.A[L.count] = H;
    return 1;
}

int remove(int k, List &L) {
    if (empty(L) || k < 1 || k > L.count) return 0;
    for (int i = k - 1; i < L.count; i++) {
        L.A[i] = L.A[i + 1];
    }
    L.count--;
    return 1;
}

int insert(List &L, int k, Hang H) {
    if (full(L) || k < 1 || k > L.count + 1) return 0;
    for (int i = L.count; i >= k - 1; i--) {
        L.A[i + 1] = L.A[i];
    }
    L.A[k - 1] = H;
    L.count++;
    return 1;
}

Hang lsmax(List L) {
    Hang max = L.A[0];
    for (int i = 1; i <= L.count; i++) {
        if (L.A[i].soluong > max.soluong) {
            max = L.A[i];
        }
    }
    return max;
}

Hang slmin(List L) {
    Hang min = L.A[0];
    for (int i = 1; i <= L.count; i++) {
        if (L.A[i].soluong < min.soluong) {
            min = L.A[i];
        }
    }
    return min;
}

int thay_the(List &L, const char Tenthay[], Hang H) {
    int found = 0;
    for (int i = 0; i <= L.count; i++) {
        if (strcmp(L.A[i].tenh, Tenthay) == 0) {
            L.A[i] = H;
            found = 1;
        }
    }
    return found;
}

void sapxep_tang(List &L) {
    for (int i = 0; i < L.count; i++) {
        for (int j = L.count; j > i; j--) {
            if (L.A[j].thanhtien < L.A[j - 1].thanhtien) {
                Hang temp = L.A[j];
                L.A[j] = L.A[j - 1];
                L.A[j - 1] = temp;
            }
        }
    }
}

void sapxep_giam(List &L) {
    for (int i = 0; i < L.count; i++) {
        for (int j = L.count; j > i; j--) {
            if (L.A[j].thanhtien > L.A[j - 1].thanhtien) {
                Hang temp = L.A[j];
                L.A[j] = L.A[j - 1];
                L.A[j - 1] = temp;
            }
        }
    }
}

void nhap(Hang &H) {
    cout << "Nhap ma hang: ";
    cin.getline(H.mah, 30);
    if (strcmp(H.mah, "e") == 0) return;
    cout << "Nhap ten hang: ";
    cin.getline(H.tenh, 50);
    cout << "Nhap don vi tinh: ";
    cin.getline(H.donvi, 30);
    cout << "Nhap so luong: ";
    cin >> H.soluong;
    cout << "Nhap don gia: ";
    cin >> H.dongia;
    H.thanhtien = H.soluong * H.dongia;
    cin.ignore();
}

void nhapds(List &L) {
    creat(L);
    Hang H;
    int i = 1;
    while (true) {
        cout << "Nhap hang thu " << i << ":\n";
        nhap(H);
        if (strcmp(H.mah, "e") == 0) break;
        add_fist(L, H);
        i++;
    }
}

void hienthi(List L) {
    cout << left << setw(5) << "STT" << setw(20) << "Ma hang" << setw(20) << "Ten hang" 
         << setw(20) << "Don vi" << setw(20) << "Don gia" << setw(20) << "So luong" 
         << setw(20) << "Thanh tien" << endl;
    for (int i = 0; i <= L.count; i++) {
        cout << left << setw(5) << i + 1 << setw(20) << L.A[i].mah << setw(20) << L.A[i].tenh 
             << setw(20) << L.A[i].donvi << setw(20) << L.A[i].dongia << setw(20) << L.A[i].soluong 
             << setw(20) << L.A[i].thanhtien << endl;
    }
}

int main() {
    List L;
    Hang H, maxHang, minHang;

    // 1. Nh?p danh sách hàng hóa
    cout << "\n=== NHAP DANH SACH HANG HOA ===\n";
    nhapds(L);

    // 2. Hi?n th? danh sách
    cout << "\n=== DANH SACH HANG HOA ===\n";
    if (!empty(L)) {
        hienthi(L);
    } else {
        cout << "Danh sach rong!\n";
    }

    // 3. T?m hàng có s? lý?ng l?n nh?t và nh? nh?t
    if (!empty(L)) {
        maxHang = lsmax(L);
        minHang = slmin(L);
        cout << "\n=== TIM KIEM ===\n";
        cout << "Hang co so luong lon nhat: " << maxHang.tenh << ", SL = " << maxHang.soluong << endl;
        cout << "Hang co so luong nho nhat: " << minHang.tenh << ", SL = " << minHang.soluong << endl;
    } else {
        cout << "\nKhong tim duoc vi danh sach rong!\n";
    }

    // 4. S?p x?p theo thành ti?n tãng d?n
    if (!empty(L)) {
        cout << "\n=== DANH SACH SAP XEP TANG THEO THANH TIEN ===\n";
        sapxep_tang(L);
        hienthi(L);
    }

    // 5. S?p x?p theo thành ti?n gi?m d?n
    if (!empty(L)) {
        cout << "\n=== DANH SACH SAP XEP GIAM THEO THANH TIEN ===\n";
        sapxep_giam(L);
        hienthi(L);
    }

    // 6. Thêm hàng hóa vào ð?u danh sách
    cout << "\n=== THEM HANG HOA VAO DAU DANH SACH ===\n";
    nhap(H);
        add_fist(L, H);
            hienthi(L);
      

    // 7. Thêm hàng hóa vào cu?i danh sách
    cout << "\n=== THEM HANG HOA VAO CUOI DANH SACH ===\n";
    nhap(H);

      add_end(L, H);
            hienthi(L);
     
    // 8. Xóa hàng hóa t?i v? trí k
    cout << "\n=== XOA HANG HOA ===\n";
    int k;
    cout << "Nhap vi tri k de xoa (1-based): ";
    cin >> k;
    cin.ignore();
   remove(k, L);
    hienthi(L);
    

    // 9. Chèn hàng hóa t?i v? trí k
    cout << "\n=== CHEN HANG HOA ===\n";
    cout << "Nhap vi tri k de chen (1-based): ";
    cin >> k;
    cin.ignore();
	nhap(H);
 	insert(L, k, H);
            hienthi(L);
       

    // 10. Thay th? hàng hóa theo tên
    cout << "\n=== THAY THE HANG HOA ===\n";
    char tenh_thay[50];
    cout << "Nhap ten hang hoa can thay the: ";
    cin.getline(tenh_thay, 50);
    cout << "Nhap thong tin hang hoa moi:\n";
    nhap(H);
    return 0;
}

