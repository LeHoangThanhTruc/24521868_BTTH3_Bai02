#ifndef CDAGIAC_H
#define CDAGIAC_H
#include "Diem.h"
#include <bits/stdc++.h>
using namespace std;

class cDaGiac
{
    public:
        cDaGiac();
        cDaGiac(vector<Diem>dinh, int n,vector<double> doDaiCanh);
        void NhapDaGiac();
        void TinhDoDaiCanhDaGiac();
        void Kiemtra();
        double chuVi();
        double dienTich();
        void TinhTien();
        Diem CongThucQuayQuanhDiem(Diem P,double do_radian, Diem O);
        void Quay();
        Diem ZoomInZoomOut(Diem u,double k, Diem P);
        void PhongToThuNho();
        virtual ~cDaGiac();
    private:
        vector<Diem> dinh;
        int n;
        vector<double> doDaiCanh;

};

#endif // CDAGIAC_H
