#include<bits/stdc++.h>
using namespace std;
	struct HangHoa{
		char ma[10];
		char ten[20];
		char dvtinh[15];
		int dg;
		int sl;
		int tt;
		
	};
	struct Node{
		HangHoa infor;
		Node *next;
	};
	typedef Node *tro;
	void nhaphh(HangHoa&hh){
		cout<<"nhap ma hang ";fflush(stdin);gets(hh.ma);
		cout<<"nhap ten hang ";fflush(stdin);gets(hh.ten);
		cout<<"nhap don vi tinh ";fflush(stdin);gets(hh.dvtinh);
		cout<<"nhap don gia";cin>>hh.dg;
		cout<<"nhap so luong ";cin>>hh.sl;
		hh.tt=hh.sl*hh.dg;
	}
	void nhap(tro&L,int soLuong){
		tro P,Q;
		HangHoa X;
		L=NULL;
		 for (int i = 0; i < soLuong; i++) {
        cout << "Nhap hang hoa thu " << i + 1 << endl;
        nhaphh(X);
        P = new Node;
        P->infor = X;
        P->next = NULL;
        if (L == NULL) {
		L = P;
		}
        else {
		Q->next = P;
		}
        Q = P;
    }
	}
	void hienthi(tro&L){
		cout<<"stt";
		cout<<setw(10)<<"ma hang";
		cout<<setw(20)<<"ten hang";
		cout<<setw(15)<<"dv tinh";
		cout<<setw(20)<<"don gia";
		cout<<setw(20)<<"so luong";
		cout<<setw(20)<<"thanh tien"<<endl;
		if(L==NULL){
			cout<<"danh sach rong";
			
		}
		tro Q=L;
		int i=0;
		while(Q!=NULL){
			HangHoa X=Q->infor;
			cout<<setw(5)<<i+1;
			cout<<setw(10)<<X.ma;
			cout<<setw(20)<<X.ten;
			cout<<setw(15)<<X.dvtinh;
			cout<<setw(20)<<X.dg;
			cout<<setw(20)<<X.sl;
			cout<<setw(20)<<X.tt<<endl;
			Q=Q->next;i++;
		}
		
	}
	void hien(tro&L){
		cout<<"stt";
		cout<<setw(10)<<"ma hang";
		cout<<setw(20)<<"ten hang";
		cout<<setw(15)<<"dv tinh";
		cout<<setw(20)<<"don gia";
		cout<<setw(20)<<"so luong";
		cout<<setw(20)<<"thanh tien"<<endl;
		if(L==NULL){
			cout<<"danh sach rong";
			
		}
		tro Q=L;
		int i=0;
		while(Q!=NULL){
			HangHoa X=Q->infor;
			cout<<setw(5)<<i+1;
			cout<<setw(10)<<X.ma;
			cout<<setw(20)<<X.ten;
			cout<<setw(15)<<X.dvtinh;
			cout<<setw(20)<<X.dg;
			cout<<setw(20)<<X.sl;
			cout<<setw(20)<<X.tt<<endl;
			Q=Q->next;i++;
		}
		
	}
	//xoa bat ky
	void xoa(int n,tro &L){
		int i=1;
		tro Q=L;
		while(i<n-1){
			Q= Q->next;
			i++;
		}
		tro P=Q->next;
		Q->next=P->next;
		delete (P);
	}
	//chen dau
	void chendau(tro &L){
		HangHoa X;
		tro P;
		P=new Node;
		nhaphh(X);
		P->infor=X;
		P->next =L;
		L=P;
	}
	//chen bat ky
	void chen(tro& L,int x){
		HangHoa X;
		tro P=L;
		tro Q;
		Q=new Node;
		nhaphh(X);
		Q->infor=X;
		int d=1;
		while(d<x){
			P=P->next;
			d++;
		}
		Q->next=P->next;
		P->next=Q;
		
	}
	// tim max
	tro Max(tro &L){
		tro maxnode=L;
		for(tro Q=L->next;Q!=NULL;Q=Q->next){
			if(Q->infor.tt>maxnode->infor.tt){
				maxnode=Q;
			}
		}
		return maxnode;
	}
	//xoa max
	void xoamax(tro &L){
		tro Q=L;
		tro P=Max(L);
		while(Q->next!=P){
			Q=Q->next;
		}
		Q->next=P->next;
		delete (P);
	}
	//sap xep
	void sapxep(tro&L){
		tro Q,P,R;
		P=L;
		while(Q!=NULL){
			R=P;
			Q=P->next;
			while(Q!=NULL){
				if(Q->infor.tt>R->infor.tt){
					R=Q;
				}
				Q=Q->next;
			}
			HangHoa tg=P->infor;
			P->infor=R->infor;
			R->infor=tg;
			P=P->next;
		}
	}
	
	

	int main(){
		tro L;int x;
		cout<<"nhap so hang hoa ban muon nhap"<<endl;
		cin>>x;
		//nhap
		nhap(L,x);
		//hien thi
		hienthi(L);
		//chen dau
		cout<<"chen vao dau danh sach "<<endl;
		chendau(L);
		hienthi(L);
		//chen vao vi tri bat ky
		cout<<"moi ban nhap vao vi tri muon chen  "<<endl;
		int y;cin>>y;
		chen(L,y);
		hienthi(L);
		//xoa vi tri bat ky
		cout<<"moi nhap vi tri ban muon xoa "<<endl;
		int z;cin>>z;
		xoa(z,L);
		hienthi(L);
		//tim max
		cout<<"hien hang hoa co thanh tien lon nhat "<<endl;
		tro m= Max(L);
		hienthi(m);
		//xoa max
		cout<<"xoa max"<<endl;
		xoamax(L);
		hienthi(L);
		//sap xep
		cout<<"sau sap xep"<<endl;
		sapxep(L);
		hienthi(L);
	
		
		
	}
