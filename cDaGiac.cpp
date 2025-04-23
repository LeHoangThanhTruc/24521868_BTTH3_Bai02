#include "cDaGiac.h"
#include "Diem.h"
#include <bits/stdc++.h>
using namespace std;
cDaGiac::cDaGiac(){}
cDaGiac::cDaGiac(vector<Diem> dinh, int n,vector<double> doDaiCanh):dinh(dinh),doDaiCanh(doDaiCanh){
    this->n = dinh.size();
}
//Nhap da giac va kiem tra
void cDaGiac::NhapDaGiac(){
    cout << "Nhap so luong dinh cua da giac : ";
    cin >> n;
    if (n<3){
        cout << "Da giac khong ton tai! Da giac phai co tu 3 dinh tro len! Thoat chuong trinh"<< endl;
        exit(0);
    }
    dinh.resize(n);
    for(int i =0;i < n; i++){
        cout << "Nhap dinh thu "<< i+1 <<endl;
        dinh[i].Nhap();
    }
}
void cDaGiac::TinhDoDaiCanhDaGiac(){
    doDaiCanh.resize(n);
    for (int i = 0; i < n; i++){
        //Toàn tử % cho phép quay vòng khi chỉ số đến cuối danh sách (mảng, vector các đa giác)
        int j = (i+1)%n;
        doDaiCanh[i]=dinh[i].kc(dinh[j]);
    }
}
double cDaGiac::chuVi(){
    double tong= 0;
    for(int i = 0; i < n ; i++){
        tong += doDaiCanh[i];
    }
    return tong;
}
// Dùng công thức Shoelace (hình học tọa độ) để tính diện tích đa giác bất kỳ
double cDaGiac::dienTich(){
    double tong = 0;
    for(int i = 0; i< n;i++){
        int j = (i+1)%n;
        tong+=(dinh[i].getX() * dinh[j].getY()) - (dinh[j].getX() * dinh[i].getY());
    }
    return abs(tong)/2.0;
}
void cDaGiac::TinhTien(){
    double dx, dy;
    cout << "Nhap khoang cach toa do tinh tien :";
    cin >> dx>>dy;
    for(int i = 0; i < n; i++){
        dinh[i].TinhTien(dx,dy);
    }
    cout << "Doi da giac di mot doan (" <<dx<<","<<dy<<") : " << endl;
    for(int i = 0; i < n; i++){
        cout <<"Dinh " << i+1 << ": "; dinh[i].Xuat();
    }
}
Diem cDaGiac::CongThucQuayQuanhDiem(Diem P,double do_radian, Diem O){
    //Dời điểm quay về gốc tọa độ
    double x = P.getX() - O.getX();
    double y = P.getY() - O.getY();

    double xResult = x*cos(do_radian) - y*sin(do_radian);
    double yResult = x*sin(do_radian) + y*cos(do_radian);

    return Diem(xResult+O.getX(),yResult+O.getY());
}
void cDaGiac::Quay(){
    double do_radian;
    cout<< "Nhap so do muon quay : ";
    cin >> do_radian;
    do_radian = do_radian*M_PI/180.0;
    double x0, y0;
    cout << "Nhap toa do diem muon quay quanh : ";
    cin >> x0 >> y0;
    Diem tam(x0,y0);
    for(int i =0; i <n; i++){
        dinh[i] = CongThucQuayQuanhDiem(dinh[i],do_radian,tam);
    }
    cout << "Toa do da giac diem sau khi quay" <<endl;
    for(int i = 0; i < n; i++){
        cout <<"Dinh " << i+1 << ": "; dinh[i].Xuat();
    }
}
Diem cDaGiac::ZoomInZoomOut(Diem u,double k, Diem P){
    return Diem((u.getX()-P.getX())*k+P.getX(),(u.getY()-P.getY())*k+P.getY());
}
void cDaGiac::PhongToThuNho(){
    //Nhập tỷ lệ k
    double k;
    cout << "Nhap he so k (k>1:phong to, 0<k<1:thu nho) muon thay doi kich thuoc : ";
    while(true){
        cin >> k;
        if(k>1) {
          cout <<"Ban chon phong to"  <<endl;
          break;
        }
        else if(k > 0 && k < 1) {
          cout << "Ban chon thu nho" << endl;
          break;
        }
        else if(k == 1) {
          cout << "Khong co thay doi kich thuoc (k = 1)" << endl;
          break;
        }
        else {
          cout << "He so k khong hop le! Nhap lai: ";
        }
    }
    //Nhập điểm tùy ý P(px,py)
    double px, py;
    cout << "Ban muon phong to/thu nho quanh diem nao ? Tra loi: ";
    cin >> px>>py;
    Diem P(px,py);
    for(int i = 0; i<n; i++){
        dinh[i] = ZoomInZoomOut(dinh[i], k, P);
    }
   //Thực hiện phóng to/thu nhỏ với hệ số tỷ lệ k quanh điểm P(px,py)
    cout << "Toa do cac dinh cua da giac sau khi phong to/thu nho"<<endl;
    for(int i = 0; i<n;i++){
        cout << "Dinh : ";dinh[i].Xuat();
    }
}
cDaGiac::~cDaGiac(){}
