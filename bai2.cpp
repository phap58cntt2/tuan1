#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
struct NGAYTHANG{
    int ngay;
    int thang;
    int nam;
};
bool ktnhuan(NGAYTHANG N);
void Nhap( NGAYTHANG &N);
void ngaytrongnam(NGAYTHANG N);
void CongThem(NGAYTHANG N);
void TruRa(NGAYTHANG N);

// kiem tra nam nhuan
bool ktnhuan(NGAYTHANG N){
    if( ( ( N.nam%100 != 0) && ( N.nam%4 == 0) ) || ( N.nam%400==0 ))
        return true;
    else
        return false;
}
// Nhap ngay thang
void Nhap( NGAYTHANG &N){
	char c;
	do{
		cout<<"Nhap ngay thang : ";
		cin>>N.ngay>>c>>N.thang>>c>>N.nam;
	}
	while((N.ngay>31 || N.thang>12)||(N.thang==2 && N.ngay>29)|| (ktnhuan(N)==false && N.ngay>28) && N.thang==2);
}
// so thu tu ngay tring nam
void ngaytrongnam(NGAYTHANG N)
{
    int n, thutu;
    n=0;
    switch (N.thang)
    {
    case 12: n=n+30;
    case 11: n=n+31;
    case 10: n=n+30;
    case 9: n=n+31;
    case 8: n=n+31;
    case 7: n=n+30;
    case 6: n=n+31;
    case 5: n=n+30;
    case 4: n=n+31;
    case 3: if(ktnhuan(N))
                n=n+29;
            else
                n=n+28;
    case 2: n=n+31;
    case 1: n=n;
    }
    thutu=n+(N.ngay);
    cout<<endl<<"Ngay thu "<<thutu<<" trong nam"<<endl;
}
// cong them ngay
void CongThem(NGAYTHANG N){
	int n;
	cout<<"Nhap so nguyen duong de cong : ";
	cin >> n;
	while(n != 0){
		if((N.ngay<31 &&(N.thang==1 || N.thang==3 || N.thang==5 || N.thang==7 || N.thang==8 || N.thang==10 || N.thang==12)) 
			|| (N.ngay < 30 && (N.thang==4 || N.thang==6||N.thang == 9))|| (N.ngay<29 && ktnhuan(N))|| (N.ngay<28 && ktnhuan(N)==false))
			N.ngay++;
		else{
			if(N.thang < 12){
				N.thang++;
				N.ngay = 1;	
			}
			else{
				N.nam++;
				N.thang = 1;
				N.ngay = 1;
			}
		}					
		n--;
	}
	cout<<"Ngay sau khi cong : "<<N.ngay<<"/"<<N.thang<<"/"<<N.nam<<endl;
}
// tru ra ngay
void TruRa(NGAYTHANG N){
	int n;
	cout<<"Nhap so nguyen duong de tru : ";
	cin >> n;
	while(n != 0){
		if( N.ngay> 1 )
			N.ngay--;
		else
		{
			if(N.thang >1){
				N.thang--;
				if(N.thang == 1 || N.thang == 3 || N.thang == 5 || N.thang == 7 || N.thang == 8 || N.thang ==10 || N.thang == 12)
					N.ngay = 31;
				else
					if(N.thang == 4 || N.thang == 6 || N.thang == 9 || N.thang == 11)
						N.ngay = 30;
					else{
						if(ktnhuan(N))
							N.ngay = 29;
						else
							N.ngay = 28;
						}
			}
			else{
				N.nam --;
				N.thang = 12;
				N.ngay = 31;
			}
		}
		n--;
	}
	cout<<"Ngay sau khi tru : "<<N.ngay<<"/"<<N.thang<<"/"<<N.nam;
}
int main(){
	NGAYTHANG N;
	string st[10];
	Nhap(N);
	if(ktnhuan(N)==1)
		cout<<"Nam nhuan!";
	else
		cout<<"Nam khong nhuan!";
	ngaytrongnam(N);
	CongThem(N);
	TruRa(N);

}
