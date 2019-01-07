#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
fstream fi("input.dat");
fstream fo("danhba.dat");
struct Contact{
	char name[20];
	char phone[11];
	char email[20];
	char address[50];
	char sex[5];
};
vector <Contact> DB;
// doc file DAT
void readFile(){
	Contact c;
	DB.clear();
	while(!fi.eof()) {
		fi.read(c.name, sizeof(c.name));
		fi.read(c.sex, sizeof(c.sex));
		fi.read(c.phone, sizeof(c.phone));
		fi.read(c.email,sizeof(c.email));
		fi.read(c.address, sizeof(c.address));
		DB.push_back(c);
	}
	fi.close();
	DB.pop_back();
}
// ghi file DAT
void writeFileContact() {
	for (int i = 0; i < DB.size(); i++) {
		fo.write(DB[i].name, sizeof(DB[i].name));
		fo.write(DB[i].sex, sizeof(DB[i].sex));
		fo.write(DB[i].phone, sizeof(DB[i].phone));
		fo.write(DB[i].email, sizeof(DB[i].email));
		fo.write(DB[i].address, sizeof(DB[i].address));	
	}
	fo.close(); 
}
// them 1 danh ba
void themmoi(Contact c){
	DB.push_back(c);
}
// liet ke danh ba
void lietkeDB(){
	for (int i = 0; i < DB.size(); i++) {
		cout << "Ten: " << DB[i].name << endl;
		cout << "Gioi tinh: " << DB[i].sex << endl;
		cout << "So DT: " << DB[i].phone << endl;
		cout << "Email: " << DB[i].email << endl;
		cout << "Dia chi: " << DB[i].address << endl;
		cout<<"------------------------------"<<endl;
	}
}
// chinh sua danh ba theo sdt
void chinhsua(){
	Contact moi;
	int vt,check;
	char sdt[11];
	cout<<"Nhap sdt can chinh sua: ";
	cin>>sdt;
	for(int i=0;i<DB.size();i++){
		if(strcmp(sdt,DB[i].phone)==0){
			vt=i;
			DB.erase(DB.begin()+vt);
			cout<<"Ten moi: ";
			cin>>moi.name;
			cout<<"Gioi tinh moi: ";
			cin>>moi.sex;
			cout<<"SDT moi: ";
			cin>>moi.phone;
			cout<<"Email moi: ";
			cin>>moi.email;
			cout<<"Dia chi moi: ";
			cin>>moi.address;
			DB.insert(DB.begin()+vt,moi);
		}	
	}
}
// xoa danh ba theo sdt
void xoa(){
	int vt,check;
	char sdt[11];
		cout<<"Nhap sdt can xoa: ";
		cin>>sdt;
		for(int i=0;i<DB.size();i++){
			if(strcmp(sdt,DB[i].phone)==0){
				vt=i;
				DB.erase(DB.begin()+vt);
				check=1;
			}
		
		}

}
// tim kiem danh ba theo ten
void timkiem(){
	int vt,check;
	char ten[20];
		cout<<"Nhap ten: ";
		cin>>ten;
		for(int i=0;i<DB.size();i++){
			if(strcmp(ten,DB[i].name)==0){
				vt=i;
				cout<<DB[vt].name<<endl;
				cout<<DB[vt].sex<<endl;
				cout<<DB[vt].phone<<endl;
				cout<<DB[vt].email<<endl;
				cout<<DB[vt].address<<endl;
				check=1;
			}
		
		}
}
int main(){
	vector <Contact> DB;
	
	Contact c1;
	strcpy(c1.name,"hoang");
	strcpy(c1.phone,"123456");
	strcpy(c1.email,"hoang@gmail.com");
	strcpy(c1.address,"nha trang");
	strcpy(c1.sex,"nam");
	
	Contact c2;
	strcpy(c2.name,"phuong");
	strcpy(c2.phone,"321654");
	strcpy(c2.email,"phuong@gmail.com");
	strcpy(c2.address,"khanh hoa");
	strcpy(c2.sex,"nu");
	
	
	Contact c3;
	strcpy(c3.name,"tam");
	strcpy(c3.phone,"456321");
	strcpy(c3.email,"tam@gmail.com");
	strcpy(c3.address,"khanh hoa");
	strcpy(c3.sex,"nu");
	themmoi(c1);
	themmoi(c2);
	themmoi(c3);
	writeFileContact();
	cout<<"Danh sanh danh ba: "<<endl;
	lietkeDB();
	chinhsua();
	xoa();
	timkiem();
	lietkeDB();
	writeFileContact();
}
