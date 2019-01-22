#include <stdio.h>
#include <conio.h>
#include <iostream>
#define MAX 1000000
#define max 100
#define FileIn "dothi.txt"
using namespace std;
void Doc_File(int A[max][max], int &n, int &D, int &C) {
 FILE*f = fopen(FileIn,"rb");
 fscanf(f,"%d",&n);
 cout<<"Nhap diem dau : ";
 cin>>D;
 cout<<"Nhap diem cuoi : ";
 cin>>C;
 cout<<"Ma Tran Lien Ket Tuong Ung.\n";
 for(int i =0;i<n;i++) {
  for(int j =0;j<n;j++) {
   fscanf(f,"%d",&A[i][j]);
   cout<<A[i][j]<<" ";
  }
  cout<<endl; 
 }
 fclose(f);
 D--; C--;
}
void Dijkstra(int A[max][max], int n, int D, int C) {
 char DanhDau[max];
 int Nhan[max], Truoc[max], XP, min;
 for(int i=0; i<n; i++){
  Nhan[i] = MAX;
  DanhDau[i] = 0;
  Truoc[i] = D;
 }
 Nhan[D] = 0;
 DanhDau[D] = 1;
 XP = D;
 while(XP != C){
  for(int j=0; j<n; j++)
   if(A[XP][j]>0 && Nhan[j]>A[XP][j]+Nhan[XP] && DanhDau[j]==0) {
    Nhan[j] = A[XP][j]+Nhan[XP];
    Truoc[j] = XP;
   }
   min = MAX;
  for(int j = 0; j<n; j++)
  if(min>Nhan[j]&& DanhDau[j]==0){
   min = Nhan[j];
   XP = j;
  }
  DanhDau[XP] = 1;
 }
 cout<<"Duong Di Ngan Nhat La:"<<Nhan[C]<<endl;
 cout<<C+1<<" <-"<<Truoc[C]+1;
 int i = Truoc[C];
 while(i!=D){
  i = Truoc[i];
  cout<<" <-"<<i+1;
 }
}
int  main() {
 int A[max][max],n,Dau,Cuoi;
 Doc_File(A,n,Dau,Cuoi);
 Dijkstra(A,n,Dau,Cuoi);
 getch();

} 
