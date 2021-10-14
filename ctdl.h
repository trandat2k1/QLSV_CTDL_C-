#pragma once
#include<iostream>
#include <string>
using namespace std;
#define MAX_MAMH 10
#define MAX_TENMH 50
#define MAX_MASV 15
#define MAX_MALOP 15
#define MAX_PHAI 4
#define MAX_SDT 11
#define MAX_HO 20
#define MAX_TEN 15
#define MAX_NIEN_KHOA 10
#define MAX_LOP_TIN_CHI 10000
//khai bao mon hoc
struct mon_hoc
{
	int ID;
	char MAMH[MAX_MAMH];
	char TENMH[MAX_TENMH];
	int STCLT;
	int STCTH;
};
typedef struct mon_hoc MON_HOC;
struct ds_mon_hoc
{
	MON_HOC data;
	struct ds_mon_hoc* pleft;
	struct ds_mon_hoc* pright;
};
typedef struct ds_mon_hoc TREE_MON_HOC;

// ket thuc khai bao mon hoc
// khai bao sinh vien
struct sinh_vien
{
	char MASV[MAX_MASV];
	char HO[MAX_HO];
	char TEN[MAX_TEN];
	char PHAI[MAX_PHAI];
	char SDT[MAX_SDT];
	char MALOP[MAX_MALOP];
};

typedef struct sinh_vien SINH_VIEN;
struct node_sinh_vien
{
	SINH_VIEN data;
	struct node_sinh_vien* pNext;
};
typedef struct node_sinh_vien NODE_SINH_VIEN;
struct ds_sinh_vien
{
	NODE_SINH_VIEN* pHead = NULL;
	NODE_SINH_VIEN* pTail = NULL;
	int tongSV = 0;
};
typedef ds_sinh_vien DS_SINH_VIEN;
//ket thuc khai bao danh sach sinh vien
//khai bao danh sach sinh vien dang ki
struct sv_dang_ky
{
	char MASV[MAX_MASV];
	float DIEM;
	struct sv_dang_ky* pNext;
};
typedef struct sv_dang_ky SV_DANG_KY;
struct ds_sv_dang_ky
{
	SV_DANG_KY* pHead = NULL;
	SV_DANG_KY* pTail = NULL;
};
typedef struct ds_sv_dang_ky DS_SV_DANG_KY;
//ket thuc danh sach dang ky
//khai bao lop tin chi
struct lop_tin_chi
{
	int MALOPTC;
	char MAMH[MAX_MAMH];
	char NIEN_KHOA[MAX_NIEN_KHOA];
	int HOC_KY;
	int NHOM;
	int SO_SV_MAX;
	int SO_SV_MIN;
	DS_SV_DANG_KY DSSV;
	bool HUY_LOP;
	int tong_sv_dk;
};
typedef struct lop_tin_chi LOP_TIN_CHI;
struct ds_lop_tin_chi
{
	LOP_TIN_CHI* data[MAX_LOP_TIN_CHI];
	int sl= 0;
};
typedef struct ds_lop_tin_chi DS_LOP_TIN_CHI;
//ket thuc khai bao lop tin chi

