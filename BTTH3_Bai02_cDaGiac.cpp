#include <bits/stdc++.h>
#include "cDaGiac.h"
#include "Diem.h"
using namespace std;

int main()
{
    cDaGiac d;
    d.NhapDaGiac();
    d.TinhDoDaiCanhDaGiac();
    cout << "Chu vi da giac : ";
    cout << d.chuVi() << endl;
    cout << "Dien tich da giac : ";
    cout << d.dienTich() << endl;
    cout << endl;
    d.TinhTien();
    cout << endl;
    d.Quay();
    cout << endl;
    d.PhongToThuNho();
    return 0;
}
/*
Nhap so luong dinh cua da giac : 4
Nhap dinh thu 1
Nhap toa do x : 0
Nhap toa do y : 0
Nhap dinh thu 2
Nhap toa do x : 4
Nhap toa do y : 0
Nhap dinh thu 3
Nhap toa do x : 4
Nhap toa do y : 3
Nhap dinh thu 4
Nhap toa do x : 0
Nhap toa do y : 3
Chu vi da giac : 14
Dien tich da giac : 12

Nhap khoang cach toa do tinh tien :2 1
Doi da giac di mot doan (2,1) :
Dinh 1: (2,1)
Dinh 2: (6,1)
Dinh 3: (6,4)
Dinh 4: (2,4)

Nhap so do muon quay : 90
Nhap toa do diem muon quay quanh : 0 0
Toa do da giac diem sau khi quay
Dinh 1: (-1,2)
Dinh 2: (-1,6)
Dinh 3: (-4,6)
Dinh 4: (-4,2)

Nhap he so k (k>1:phong to, 0<k<1:thu nho) muon thay doi kich thuoc : 0.5
Ban chon thu nho
Ban muon phong to/thu nho quanh diem nao ? Tra loi: 0 0
Toa do cac dinh cua da giac sau khi phong to/thu nho
Dinh : (-0.5,1)
Dinh : (-0.5,3)
Dinh : (-2,3)
Dinh : (-2,1)
*/
