#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Nguoichoi{
	char ten;
	int diem;
};
struct De{
	string cauhoi;
	string dapan[4];
	char dapandung;
	
};
fstream fi;
vector <De> D;
vector <Nguoichoi> N;
void nhapTen(){
	Nguoichoi a;
	cout<<"Nhap ten nguoi choi: ";
	cin>>a.ten;	
}
void chonDe(){
	int bode;
	cout<<"Nhap bo de: ";
	cin>>bode;
	switch (bode){
	case 1:fi.open("de1.txt", ios::in); break;
	case 2:fi.open("de2.txt", ios::in); break;
	case 3:fi.open("de3.txt", ios::in); break;
	}
}
void hiende(De d){
	
	cout<<d.cauhoi<<endl;
	for(int j=0;j<4;j++){
		char label='A'+j;
		cout<<label<<":"<<d.dapan[j]<<endl;
	}		
}
void docFileDe(){
	int n;
	fi>>n;
	D.resize(n);
	for(int i=0;i<n;i++){
		// sai tu vi tri nay
		getline(fi,D[i].cauhoi);
		for(int j=0;j<4;j++)
			getline(fi,D[i].dapan[j]);
		fi>>D[i].dapandung;
	}
}
void traloi(){
	char cautraloi;
	int diem=0;
	for(int i=0;i<D.size();i++){
		hiende(D[i]);
		cout<<D[i].cauhoi;
		cout<<"Nhap dap an: ";
		cin>>cautraloi;
		if(cautraloi==D[i].dapandung)
		{
			cout<<"Tra loi dung!";
			diem++;
		}
		else 
			cout<<"Tra loi sai!";
	}
		
}
int main(){
	int diem;
	nhapTen();
	
	chonDe();
	docFileDe();
	for(int i=0;i<D.size();i++){
		cout<<D[i].cauhoi;
	}
	traloi();
	//diem=traloi();
//	cout<<"Diem:"<<diem;
}
