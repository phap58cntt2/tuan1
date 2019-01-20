#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
// khai bao file vao, ra
fstream fi("input.dat", ios::in | ios::binary);
fstream fo("danhba.dat", ios::out | ios::binary );
//
struct CONTACT {
	char name[30]; 
	char phone[11]; 
	char email[30]; 
	char address[50]; 
	char sex[5];
};
vector <CONTACT> db;// Vector db kieu danh ba
void readFileContact(); // Ham doc du lieu tu file
void writeFileContact();    // Ham ghi du lieu vào file
void showContact(); // Ham hien thi danh ba ra man hinh
void addContact();  // Ham them danh ba tu ban phim
void addContactDemo(); // Ham them danh ba demo
void editByPhone(); // Ham chinh sua danh ba theo so dien thoai
void deleteByPhone(); // Ham xoa danh ba theo so dien thoai
void searchByName();  // Ham tim kiem danh ba theo ten
bool returnToMenu(); // Ham kiem tra quay lai
void showMenu(); // Ham hien thi menu
void menuOption();  // Ham menu tuy chon


//Doc tu file
void readFileContact(){
	CONTACT c;
	
	while(!fi.eof()) {
		fi.read(c.name, 30);
		fi.read(c.sex, 5);
		fi.read(c.phone, 10);
		fi.read(c.email, 30);
		fi.read(c.address, 50);
		
		db.push_back(c);
	}
	fi.close();
	db.pop_back();
}

//Ghi file .dat
void writeFileContact() {
	for (int i = 0; i < db.size(); i++) {
		fo.write(db[i].name, sizeof(db[i].name));
		fo.write(db[i].sex, sizeof(db[i].sex));
		fo.write(db[i].phone, sizeof(db[i].phone));
		fo.write(db[i].email, sizeof(db[i].email));
		fo.write(db[i].address, sizeof(db[i].address));	
	}
	fo.close(); 
}

// Hien thi danh ba
void showFileContact() {
	for (int i = 0; i < db.size(); i++) {
		cout << "----------------" << endl;
		cout << "Name : " << db[i].name << endl;
		cout << "Sex: " << db[i].sex << endl;
		cout << "Phone number : " << db[i].phone << endl;
		cout << "Email : " << db[i].email << endl;
		cout << "Address : " << db[i].address << endl;
	}
}

// them danh ba tu ban phim
void addContact() {
	CONTACT addNew;
	cout << "Name : ";
	cin >> addNew.name;
	cout << "Sex: ";
	cin >> addNew.sex;
	cout << "Phone number : ";
	cin >> addNew.phone;
	cout << "Email : ";
	cin >> addNew.email;
	cout << "Address : ";
	cin >> addNew.address;
	
	db.push_back(addNew);
}
// them danh ba demo
void addContactDemo() { 
	CONTACT c1;
	strcpy(c1.name, "Son");
	strcpy(c1.sex, "Nam");
	strcpy(c1.phone, "0985407705");
	strcpy(c1.email, "nhuson2306@gmail.com");
	strcpy(c1.address, "QuangTri");
	db.push_back(c1);
	
	CONTACT c2;
	strcpy(c2.name, "Suong");
	strcpy(c2.sex, "Nu");
	strcpy(c2.phone, "0336692745");
	strcpy(c2.email, "xuansuonga3@gmail.com");
	strcpy(c2.address, "CamLam");
	db.push_back(c2);
	
	CONTACT c3;
	strcpy(c3.name, "Vy");
	strcpy(c3.sex, "Nam");
	strcpy(c3.phone, "0384722549");
	strcpy(c3.email, "nguyentrieuvy@gmail.com");
	strcpy(c3.address, "CamRanh");
	db.push_back(c3);
}
// chinh sua danh ba theo sdt
void editByPhone() {
	CONTACT cEdit;
	
	int vt;
	char ePhone[11];
	
	cout << "Enter the phone number to fix: ";
	cin >> ePhone;
	
	for (int i = 0; i < db.size(); i++) {
		if (strcmp(ePhone, db[i].phone) == 0) {
			vt = i;
			db.erase(db.begin() + vt);
			cout << "New name: ";
			cin >> cEdit.name;
			cout << "New sex: ";
			cin >> cEdit.sex;
			cout << "New phone: ";
			cin >> cEdit.phone;
			cout << "New email: ";
			cin >> cEdit.email;
			cout << "New address: ";
			cin >> cEdit.address;
			db.insert(db.begin() + vt , cEdit);
		}
	}
}
// xoa danh ba theo sdt
void deleteByPhone(){
	int vt;
	char delPhone[11];
	
	cout << "Enter the phone to delete: ";
	cin >> delPhone;
	
	for (int i = 0; i < db.size(); i++) {
		if (strcmp(delPhone, db[i].phone) == 0) {
			vt = i;
			db.erase(db.begin() + vt);		
		}
	}
}
// tim kiem danh ba theo ten
void searchByName() {
	int vt;
	char sName[30];	
	cout << "Enter name: ";
	cin >> sName;
	
	for (int i = 0; i < db.size(); i++) {
		if(strcmp(sName, db[i].name) == 0){
			vt = i;
			cout << "----------------" << endl;
			cout << "Name : " << db[vt].name << endl;
			cout << "Sex: " << db[vt].sex << endl;
			cout << "Phone number : " << db[vt].phone << endl;
			cout << "Email : " << db[vt].email << endl;
			cout << "Address : " << db[vt].address << endl;
		}
		
	}
}
// quay lai menu
bool returnToMenu() {
	char rtnMenu;
	cout << "-----------------------------" << endl;
    cout << "Enter z to return to the menu:> "; 
	cin >> rtnMenu;

    if(rtnMenu == 'z' || rtnMenu == 'Z') {
        return true;
    } return false;
}
// hien menu chon
void showMenu() {
	cout << "1. Add contact" << endl;
	cout << "2. Show contact" << endl;
	cout << "3. Edit contact" << endl;
	cout << "4. Delete contact" << endl;
	cout << "5. Find contact" << endl;
	cout << "6. Exit" << endl;
}
// menu tuy chon
void menuOption() {
	int mo;
	cout << "Enter your choice:> ";
	cin >> mo;
	
	switch(mo) {
		case 1:
			system("cls");
			addContact();
			cout << "Add contact successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 2: 
			system("cls");
			showFileContact();
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 3: 
			system("cls");
			cout << "------ Edit ------" << endl;
			editByPhone();
			cout << "Edit successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 4: 
			system("cls");
			cout << "------ Delete ------" << endl;
			deleteByPhone();
			cout << "Delete successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 5: 
			system("cls");
			cout << "------ Search ------" << endl;
			searchByName();	
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 6: 
			cout << "Exited!" << endl;
            break;
		default:
            system("cls");
            showMenu();
            cout << "Wrong option!" << endl;
            menuOption();
            break;
	}
}

int main() {
	//readFileContact();
	addContactDemo();
	showMenu();
	menuOption();
	writeFileContact();
}
