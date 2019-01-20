#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
struct DE{
	string cauhoi;
	string A, B, C;
	string DA;
};
struct Nguoichoi{
	string ten;
	int diem;
};
vector <DE> bd;
vector <Nguoichoi> NC;
// Xuat 1 cau va tra loi
int Xuat(DE bd){	
	int diem=0;
	string DapAn;
	cout<<bd.cauhoi<<endl;
	cout<<bd.A<<endl;
	cout<<bd.B<<endl;
	cout<<bd.C<<endl;
	cout<<"Nhap dap an tra loi: "; cin>>DapAn;
	if(DapAn==bd.DA){
		cout<<"Tra loi dung"<<endl;
		diem=1;
	}
	else{
		cout<<"Tra loi sai"<<endl;
		diem=0;
	}
	cout<<"-------------------"<<endl;
	return diem;	
}
// nhap thong tin nguoi choi
void NhapTT(int d){
	Nguoichoi nc;
	cout<<"Nhap ten nguoi choi:";
	cin>>nc.ten;
	nc.diem=d;
	NC.push_back(nc);
}
// doc de tu file
void DocDe(){	
	int de;
	cout<<"Chon de: ";
	cin>>de;
	cout<<"-------------------"<<endl;
	switch (de){
		case 1:{
			ifstream f("de1.txt");
			string s;
			DE de1; 
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());
			for (int i=0;i<SL;i++){
				getline(f,s);  de1.cauhoi=s;
				getline(f,s);  de1.A=s;
				getline(f,s);  de1.B=s;
				getline(f,s);  de1.C=s;
				getline(f,s);	de1.DA =s;
				bd.push_back(de1);
			}
			break;
		}
		case 2:{
			ifstream f("de2.txt");
			string s; DE de2; 
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());
			for (int i=0;i<SL;i++)	{
				getline(f,s);
				de2.cauhoi =s;
				getline(f,s);
				de2.A=s;
				getline(f,s);
				de2.B=s;	
				getline(f,s);
				de2.C=s;
				getline(f,s);
				de2.DA =s;
				bd.push_back(de2);
			}
			break;	
		}
	}
}
// xuat diem tat ca nguoi choi
void Xuatdiemten(){
	string ck,ten;
	int check;
	do{
		check=0;
		cout<<"Nhap ten nguoi choi muon biet diem: ";
		cin>>ten;
		system("cls");
		for(int i=0;i<NC.size();i++){
			if(NC[i].ten==ten){
				cout<<"Ten:";
				cout<<NC[i].ten<<endl;
				cout<<"Diem:";
				cout<<NC[i].diem<<endl;
				cout<<"-------------------"<<endl;
				check=1;
				break;
			}	
		}
		if(check!=1){
			cout<<"Khong co nguoi choi nay!!"<<endl;
			cout<<"-------------------"<<endl;
		}
		cout<<"Ban co muon xem diem nguoi khac khong?"<<endl;
		cout<<"Y: Xem tiep"<<endl;
		cout<<"N: Khong muon xem tiep!"<<endl;
		cin>>ck;
	} while (ck!="N" && ck!="n");
}
void Lambai(){
	string check;
	do{
		DocDe();
		int d=0;
		for(int i=0;i<bd.size();i++)
			d+=Xuat(bd[i]);
		cout<<"So diem dat duoc: "<<d<<endl;
		NhapTT(d);
		system("cls");
		cout<<"Ban co muon choi tiep khong?"<<endl;
		cout<<"Y: Choi tiep"<<endl;
		cout<<"N: Ngung choi"<<endl;
		cin>>check;
		bd.clear();
	} while (check=="Y" || check=="y");
}
int main(){	
	int n;
	do{
		cout<<"Ban muon lam gi?"<<endl;
		cout<<"1: Choi"<<endl<<"2: Xem diem"<<endl<<"0: Dung chuong trinh"<<endl;
		cin>>n;
		system("cls");
		switch (n)
		{
			case 1:
				Lambai();
				system("cls");
				break;	
			case 2:
				Xuatdiemten();
				system("cls");
				break;
		}
	} while(n!=0);
}
