#pragma once
#include "mylib.h"
#include "myEdit.h"
#include "ctdl.h"
#include <fstream>
#include <string>
#include "handleMain.h"
#include <ctime>
#define MAX_ID 1000
//cac dieu kien nhap

void Ghi_file_mon_hoc(TREE_MON_HOC*&);
void xoa_mon_hoc(TREE_MON_HOC*&, TREE_MON_HOC*);
void cay_con_trai_nhat(TREE_MON_HOC*&, TREE_MON_HOC*&);
bool check_mamh(char*);
void them_mon_hoc(TREE_MON_HOC*&, TREE_MON_HOC*);
void random_id(int*);
void Ghi_file(TREE_MON_HOC*&, ofstream&);
void Doc_file_mon_hoc(TREE_MON_HOC*&);
void xoa_man_hinh();
bool dieukien(char&);
void chuan_hoa_chu(char*);
void xoa_kitu(char*, int);
bool so(char&);
bool chu_so(char&);
bool chu(char&);
void chuoi_in_hoa(char*);
char chu_in_hoa(char);
void chuoi_in_hoa(char*);
int bang_thong_baoo(string, int, int, int, int, int, int);
char chu_in_thuong(char);


int ID_MONHOC[MAX_ID];

void xoa_man_hinh()
{
	Normal();
	for (int i = 0; i <= 26; i++)
	{
		gotoxy(43, 6 + i);
		cout << "                                                                                                       ";
	}
}

bool dieukien(char& c)
{
	if (c == key_Down || c == key_Up || c == key_Left || c == key_Right)
			return true;
	else if (c == key_Enter || c == key_bkspace)
		return true;
	return false;
}
bool chu(char& a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'z'))
		return true;
	return false;
}

bool so(char& a)
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}

bool chu_so(char& a)
{
	if (chu(a) || so(a))
		return true;
	return false;
}

void xoa_kitu(char* a, int vt)
{
	for (int i = vt; i < strlen(a); i++)
		a[i] = a[i + 1];
}
void chuan_hoa_chu(char* a)
{
	//bo dau space

	while (a[0] == ' ')
	{
		xoa_kitu(a, 0);
	}
	while (a[strlen(a) - 1] == ' ')
	{
		xoa_kitu(a, strlen(a) - 1);
	}
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ') {
			xoa_kitu(a, i + 1);
			i--;
		}
	}
	//chu dau in hoa
	if (a[0] >= 97 && a[0] <= 122)
		a[0] -= 32;
	for (int i = 1; i < strlen(a); i++)
	{
		if (a[i] == ' ' && a[i + 1] >= 97 && a[i + 1] <= 122)
			a[++i] -= 32;
		else if (a[i] >= 65 && a[i] <= 90 && a[i-1] != ' ')
			a[i] += 32;
	}
}
char chu_in_hoa(char a)
{
	char temp = a;
	if (temp >= 'a' && temp <= 'z')
		temp -= 32;
	return temp;
}

char chu_in_thuong(char a)
{
	char temp = a;
	if (temp >= 'A' && temp <= 'Z')
		temp += 32;
	return temp;
}
void chuoi_in_hoa(char* a)
{
	for (int i = 0; i < strlen(a); i++)
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
}

int bang_thong_baoo(string a, int x, int y, int width, int height, int d, int thut_dong)
{
	HideCursor(true);
	BGHightLight();
	rectagle(x, y, width, height);
	gotoxy(x + 4, y + 1); cout << a;
	gotoxy(x + 4 + thut_dong, y + 3); cout << "Co";
	HighLight();
	gotoxy(x + 4 + thut_dong + d, y + 3); cout << "Khong";
	char kitu;
	int luachon1 = 1;
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_Right)
		{
			luachon1++;
			if (luachon1 >= 2)
				luachon1 = 1;
			else
			{
				BGHightLight();
				gotoxy(x + 4 + thut_dong, y + 3);
				cout << "Co";
				HighLight();
				gotoxy(x + 4 + thut_dong + d, y + 3);
				cout << "Khong";
			}
		}
		else if (kitu == key_Left)
		{
			luachon1--;
			if (luachon1 < 0)
				luachon1 = 0;
			else
			{
				BGHightLight();
				gotoxy(x + 4 + thut_dong + d, y + 3);
				cout << "Khong";
				HighLight();
				gotoxy(x + 4 + thut_dong, y + 3);
				cout << "Co";
			}
		}
		else if (kitu == key_Enter)
		{
			if (luachon1 == 0)
			{
				Normal();
				xoa_man_hinh();
				return 0;
			}
			else if (luachon1 == 1)
			{
				Normal();
				xoa_man_hinh();
				return 1;
			}
		}
	}
}
// DS SINH VIEN

void them_sinhvien(ds_sinh_vien& ds, NODE_SINH_VIEN* p)
{
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = p;
	}
	else
	{
		ds.pTail->pNext = p;
		ds.pTail = p;
	}
	ds.tongSV++;
}

void xoa_sinhvien(ds_sinh_vien& ds, NODE_SINH_VIEN* p)
{
	NODE_SINH_VIEN* i;
	if (p == ds.pHead)
	{
		i = ds.pHead;
		ds.pHead = ds.pHead->pNext;
		delete i;
	}
	else
	{
		for (i = ds.pHead; strcmp(i->pNext->data.MASV, p->data.MASV) != 0; i = i->pNext);
		NODE_SINH_VIEN* temp = i->pNext;
		if (temp == ds.pTail)
		{
			i->pNext = NULL;
			ds.pTail = i;
		}
		else i->pNext = temp->pNext;
		delete temp;
	}
	ds.tongSV--;
}

void Doc_file_sinh_vien(ds_sinh_vien& ds)
{
	ifstream file_SV;
	NODE_SINH_VIEN* p;
	string a;
	file_SV.open("ds_sinhvien.txt");
	while (!file_SV.eof())
	{
		p = new NODE_SINH_VIEN;
		p->pNext = NULL;
		file_SV.getline(p->data.MALOP, MAX_MALOP, ',');
		file_SV.getline(p->data.MASV, MAX_MASV, ',');
		file_SV.getline(p->data.HO,MAX_HO, ',');
		file_SV.getline(p->data.TEN,MAX_TEN, ',');
		file_SV.getline(p->data.PHAI,MAX_PHAI, ',');
		file_SV.getline(p->data.SDT,MAX_SDT);
		chuoi_in_hoa(p->data.MASV);
		chuoi_in_hoa(p->data.MALOP);
		chuan_hoa_chu(p->data.HO);
		chuan_hoa_chu(p->data.TEN);
		chuan_hoa_chu(p->data.PHAI);
		them_sinhvien(ds, p);
	}
	file_SV.close();
}

void Ghi_file(ds_sinh_vien ds)
{
	ofstream file_SV;
	file_SV.open("ds_sinhvien.txt", ios_base::out);
	if (ds.tongSV == 0)
	{
		file_SV.close();
		return;
	}
	for (NODE_SINH_VIEN* p = ds.pHead;p->pNext != NULL; p = p->pNext)
	{
		file_SV << p->data.MALOP << ',';
		file_SV << p->data.MASV << ',';
		file_SV << p->data.HO << ',';
		file_SV << p->data.TEN << ',';
		file_SV << p->data.PHAI << ',';
		file_SV << p->data.SDT << '\n';
	}
	file_SV << ds.pTail->data.MALOP << ',';
	file_SV << ds.pTail->data.MASV << ',';
	file_SV << ds.pTail->data.HO << ',';
	file_SV << ds.pTail->data.TEN << ',';
	file_SV << ds.pTail->data.PHAI << ',';
	file_SV << ds.pTail->data.SDT;
	file_SV.close();
}


// LOP TIN CHI

void Init_ds_dang_ki(DS_SV_DANG_KY& dsdk)
{
	dsdk.pHead = NULL;
	dsdk.pTail = NULL;
}

void them_sau_ds_sv_dk(DS_SV_DANG_KY& dsdk, SV_DANG_KY* x)
{
	if (dsdk.pHead == NULL)
	{
		dsdk.pHead = dsdk.pTail = x;
	}
	else
	{
		dsdk.pTail->pNext = x;
		dsdk.pTail = x;
	}
}

void them_vao_ds_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc, LOP_TIN_CHI* x)
{
	if (ds_ltc.sl == MAX_LOP_TIN_CHI - 1 )
	{
		cout << "Danh sach lop tin chi da day . Khong them duoc nua !!!";
	}
	else if (ds_ltc.sl < x->SO_SV_MAX)
	{
		ds_ltc.data[ds_ltc.sl] = x;
		++ds_ltc.sl;
	}
}

void doc_file_ltc(DS_LOP_TIN_CHI& ds_ltc, int& nLTC)
{
	ifstream filein;
	filein.open("DS_Lop_tin_chi.txt", ios_base::in);
	if (filein.fail())
	{
		cout << "Mo file (DS_Lop_tin_chi.txt) khong thanh cong. Vui long kiem tra lai !!" << endl;
		return;
	};
	string c;
	filein >> nLTC;
	getline(filein, c);
	for (int i = 0;i < nLTC;i++)
	{
		LOP_TIN_CHI* data = new LOP_TIN_CHI;
		filein >> data->MALOPTC;
		filein.ignore(1);
		filein.getline(data->MAMH, MAX_MAMH, ',');
		filein.getline(data->NIEN_KHOA, MAX_NIEN_KHOA, ',');
		filein >> data->HOC_KY;
		filein.ignore(1);
		filein >> data->NHOM;
		filein.ignore(1);
		filein >> data->SO_SV_MIN;
		filein.ignore(1);
		filein >> data->SO_SV_MAX;
		filein.ignore(1);
		filein >> data->HUY_LOP;
		getline(filein, c);
		Init_ds_dang_ki(data->DSSV);
		filein >> data->tong_sv_dk;
		filein.ignore();
		if (data->tong_sv_dk > 0)
		{
			for (int i = 0; i < data->tong_sv_dk; i++)
			{
				SV_DANG_KY* sv_dk = new SV_DANG_KY;
				filein.getline(sv_dk->MASV, MAX_MASV, ',');
				filein >> sv_dk->DIEM;
				getline(filein, c);
				sv_dk->pNext = NULL;
				them_sau_ds_sv_dk(data->DSSV, sv_dk);
			}
		}
		them_vao_ds_lop_tin_chi(ds_ltc, data);
	}
	filein.close();
}

bool check_huy_lop(LOP_TIN_CHI* x)
{
	if (x->tong_sv_dk > 0)
	{
		return false;
	}
	else return true;
}

void Ghi_file_lop_tin_chi(DS_LOP_TIN_CHI ds_ltc)
{
	ofstream fileOut;
	fileOut.open("./DS_Lop_tin_chi.txt", ios_base::out);
	fileOut << ds_ltc.sl << "\n";
	for (int i = 0; i < ds_ltc.sl; i++)
	{
		fileOut << ds_ltc.data[i]->MALOPTC << "," << ds_ltc.data[i]->MAMH << ","
			<< ds_ltc.data[i]->NIEN_KHOA << "," << ds_ltc.data[i]->HOC_KY << ","
			<< ds_ltc.data[i]->NHOM << "," << ds_ltc.data[i]->SO_SV_MIN << ","
			<< ds_ltc.data[i]->SO_SV_MAX << ",";
		if (check_huy_lop(ds_ltc.data[i]))
		{
			fileOut << 1 << "\n";
		}
		else
		{
			fileOut << 0 << "\n";
		}
		fileOut << ds_ltc.data[i]->tong_sv_dk << "\n";
		if (ds_ltc.data[i]->tong_sv_dk > 0)
		{
			SV_DANG_KY* k = NULL;
			for (k = ds_ltc.data[i]->DSSV.pHead; k != NULL; k = k->pNext)
			{
				fileOut << k->MASV << "," << k->DIEM << "\n";
			}
		}
	}
	fileOut.close();
}

void xoa_sv_ltc(char* masv)
{
	DS_LOP_TIN_CHI ds_ltc;
	int n_ltc;
	doc_file_ltc(ds_ltc, n_ltc);
	SV_DANG_KY* t = new SV_DANG_KY;
	for (int i = 0; i < n_ltc;i++)
	{
		for (SV_DANG_KY* p = ds_ltc.data[i]->DSSV.pHead; p != NULL;t = p,p = p->pNext)
		{
			if(strcmp(masv,p->MASV) == 0)
			{
				if (p == ds_ltc.data[i]->DSSV.pHead)
				{
					ds_ltc.data[i]->DSSV.pHead = ds_ltc.data[i]->DSSV.pHead->pNext;
					delete p;
					ds_ltc.data[i]->tong_sv_dk--;
					break;
				}
				else if (p == ds_ltc.data[i]->DSSV.pTail)
				{
					t->pNext = NULL;
					ds_ltc.data[i]->DSSV.pTail = t;
					delete p;
					ds_ltc.data[i]->tong_sv_dk--;
					break;
				}
				else
				{
					t->pNext = p->pNext;
					delete p;
					ds_ltc.data[i]->tong_sv_dk--;
					break;
				}
				
			}
		}
	}
	Ghi_file_lop_tin_chi(ds_ltc);
	delete t;
}

bool check_mh_dk(char* mamh)
{
	DS_LOP_TIN_CHI ds_ltc;
	int n_ltc;
	doc_file_ltc(ds_ltc, n_ltc);
	for (int i = 0; i < n_ltc;i++)
		if (strcmp(ds_ltc.data[i]->MAMH, mamh) == 0)
			return true;
	return false;
}

bool check_sv_dk(char* masv)
{
	DS_LOP_TIN_CHI ds_ltc;
	int n_ltc;
	doc_file_ltc(ds_ltc, n_ltc);
	for (int i = 0; i < n_ltc;i++)
		for (SV_DANG_KY* p = ds_ltc.data[i]->DSSV.pHead; p != NULL; p = p->pNext)
			if (strcmp(p->MASV, masv) == 0)
				return true;
	return false;
}

// MON HOC
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Doc_file_mon_hoc(TREE_MON_HOC*& T)
{
	ifstream file_mon_hoc;
	int so_monhoc = 0;
	file_mon_hoc.open("ds_monhoc.txt");
	TREE_MON_HOC* p;
	while (!file_mon_hoc.eof())
	{
		p = new TREE_MON_HOC;
		file_mon_hoc.getline(p->data.MAMH, MAX_MAMH, ',');
		if(strcmp(p->data.MAMH,"\0") == 0)
		{
			delete p;
			file_mon_hoc.close();
			return;
		}
		file_mon_hoc.getline(p->data.TENMH, MAX_TENMH, ',');
		file_mon_hoc >> p->data.STCLT;
		file_mon_hoc >> p->data.STCTH;
		file_mon_hoc.ignore();
		chuoi_in_hoa(p->data.MAMH);
		chuoi_in_hoa(p->data.TENMH);
		p->data.ID = ID_MONHOC[so_monhoc++];
		them_mon_hoc(T, p);
	}
	file_mon_hoc.close();
}

void Ghi_file(TREE_MON_HOC*& T, ofstream& file)
{
	if (T != NULL)
	{
		file << T->data.MAMH << ',';
		file << T->data.TENMH << ',';
		file << T->data.STCLT << ' ';
		file << T->data.STCTH << '\n';
		Ghi_file(T->pleft, file);
		Ghi_file(T->pright, file);
	}
}

void Ghi_file_mon_hoc(TREE_MON_HOC*& T)
{
	ofstream file_mon_hoc;
	file_mon_hoc.open("ds_monhoc.txt");
	Ghi_file(T, file_mon_hoc);
	file_mon_hoc.close();
}

void random_id(int* ID_MONHOC)
{
	for (int i = 0; i < 1000; i++)
		ID_MONHOC[i] = i;
	srand(time(NULL));
	int S;
	for (int i = 0; i < 300;i++)
	{
		S = rand() % (1000 - i + 1) + i;
		swap(ID_MONHOC[i], ID_MONHOC[S]);
	}
}

bool check_mamh(char* mamh)
{
	TREE_MON_HOC* T = NULL;
	Doc_file_mon_hoc(T);
	TREE_MON_HOC* p = T;
	TREE_MON_HOC* STACK[100];
	int sp = -1;
	while(p != NULL)
	{
		if(strcmp(p->data.MAMH,mamh) == 0)
			return true;
		
		if (p->pright != NULL)
			STACK[++sp] = p->pright;
		if (p->pleft != NULL)
			p = p->pleft;
		else
		{
			if (sp == -1)
				break;
			else
				p = STACK[sp--];
		}
	}
	return false;
}

void them_mon_hoc(TREE_MON_HOC*& T, TREE_MON_HOC* p)
{
	if (T == NULL)
	{
		p->pleft = NULL;
		p->pright = NULL;
		T = p;
	}
	else
	{
		if (p->data.ID < T->data.ID)
			them_mon_hoc(T->pleft, p);
		else
			them_mon_hoc(T->pright, p);
	}
}

void cay_con_trai_nhat(TREE_MON_HOC*& temp, TREE_MON_HOC*& temp1)
{
	if (temp1->pleft != NULL) cay_con_trai_nhat(temp, temp1->pleft);
	else
	{
		temp->data = temp1->data;
		temp = temp1;
		temp1 = temp1->pright;
	}
}

void xoa_mon_hoc(TREE_MON_HOC*& T, TREE_MON_HOC* p)
{
	if (T == NULL)
		return;
	if (p->data.ID < T->data.ID) xoa_mon_hoc(T->pleft, p);
	else if (p->data.ID > T->data.ID) xoa_mon_hoc(T->pright, p);
	else
	{
		TREE_MON_HOC* temp = T;
		if (T->pleft == NULL) T = T->pright;
		else if (T->pright == NULL) T = T->pleft;
		else
		{
			cay_con_trai_nhat(temp, T->pright);
		}
		delete temp;
	}
}
