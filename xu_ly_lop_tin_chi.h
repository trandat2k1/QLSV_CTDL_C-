#pragma once
#include "myEdit.h"
#include "ctdl.h"
#include "mylib.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include "xu_ly_diem.h"
using namespace std;
/*Khai bao nguyen mau ham*/
bool CheckNienKhoa(string);
void them_vao_ds_lop_tin_chi(DS_LOP_TIN_CHI&, LOP_TIN_CHI*);
int chuyen_char_sang_int(char*);
void xoa_thong_bao(int , int , int);
void Draw_them_lop_tin_chi(DS_LOP_TIN_CHI&, TREE_MON_HOC*);
void In_lop_tin_chi(DS_LOP_TIN_CHI);
void Xoa_sua_lop_tin_chi(DS_LOP_TIN_CHI&, TREE_MON_HOC*,int);
void Xoa_lop_tin_chi(DS_LOP_TIN_CHI&, int);
void Sua_lop_tin_chi(DS_LOP_TIN_CHI&,TREE_MON_HOC *,int);
int dem_so_chu_so(int);
void In_lop_tin_chi(DS_LOP_TIN_CHI);
void In_danh_sach_sv_dang_ki(DS_LOP_TIN_CHI, DS_SINH_VIEN);

int Search_danh_sach_sv_dang_ki(DS_LOP_TIN_CHI);
void  In_danh_sach_sv_dk(DS_LOP_TIN_CHI,DS_SINH_VIEN);
void cap_vung_nho_in_ds_mon(int*&, int, int);
NODE_SINH_VIEN* tim_ma_sv(DS_SINH_VIEN);
bool Check_mo_lop_tin_chi(DS_LOP_TIN_CHI , char* , int);
char* search_mon_hoc(TREE_MON_HOC* , char* );
bool checkInputTrong(char*);
void Huy_lop_tin_chi(DS_LOP_TIN_CHI &,DS_LOP_TIN_CHI &,int,char*);
struct timeDK;
void time_dk(timeDK&);
void in_tg_ket_thuc(int,timeDK);
int check_tg_dang_ki(int , timeDK);
void Dang_Ki_Lop_Tin_Chi(DS_LOP_TIN_CHI &,DS_LOP_TIN_CHI &,DS_SINH_VIEN,TREE_MON_HOC *,int);
void ds_mon_sv_da_dki(DS_LOP_TIN_CHI &,DS_LOP_TIN_CHI &,TREE_MON_HOC *,char*,int tgbd);
void menu_ltc();
/*CODE*/
void menu_ltc()
{
	DS_LOP_TIN_CHI ds_ltc;
	ds_ltc.sl=0;
	DS_LOP_TIN_CHI ds_lop_sv_dk;
	DS_SINH_VIEN ds_sv;
	TREE_MON_HOC *T=NULL;
	int nLTC;
	Doc_file_mon_hoc(T);
	time_t now = time(0);
	tm* ltm=localtime(&now);
	int tgbd=ltm->tm_hour*3600+ltm->tm_min*60+ltm->tm_sec;
	Doc_file_sinh_vien(ds_sv);
	doc_file_ltc(ds_ltc,nLTC);
	char c;
	
	while (1)
	{
		system("cls");
		int chonltc = VeLopTinChi(itemloptinchi);
		if (chonltc == 1)
		{
			Draw_them_lop_tin_chi(ds_ltc,T);

		}
		else if (chonltc == 2)
		{
			Xoa_sua_lop_tin_chi(ds_ltc,T,tgbd);

		}
		else if (chonltc == 3)
		{
			In_lop_tin_chi(ds_ltc);

		}
		else if (chonltc == 4)
		{
			In_danh_sach_sv_dk(ds_ltc, ds_sv);

		}
		else if (chonltc == 5)
		{
				Dang_Ki_Lop_Tin_Chi(ds_ltc,ds_lop_sv_dk , ds_sv, T,tgbd);	
		}
		else if (chonltc == 0)
		{
			break;
		}	
	}
} 

bool CheckNienKhoa(string nienkhoa) {
	string delimiter = "_";
	string firstYear = nienkhoa.substr(0, nienkhoa.find(delimiter));
	string lastYear = nienkhoa.substr(nienkhoa.find(delimiter) + 1, nienkhoa.length() - 1);
	int first = atoi(firstYear.c_str());
	int last = atoi(lastYear.c_str());
	if (first < 2000 || last > 2050 || first >= last)
	{
		return false;
	}
	return true;
}

bool checkInputTrong(char* c)
{
	if (strlen(c) == 0) return false;
	return true;
}
void xoa_thong_bao(int x, int y, int length)
{
	gotoxy(x, y);
	for (int i = 0; i < length; i++) cout << " ";
}
int dem_so_chu_so(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	if (count == 0) return 1;
	return count;
}
int chuyen_char_sang_int(char* c)
{
	int so = 0;
	for (int i = 0; i < strlen(c); i++)
	{
		so = so * 10 + int(c[i] - 48);
	}
	return so;
}
struct timeDK
{
	int ngaydk;
	int hdk;
	int pdk;
};
void Draw_them_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc,TREE_MON_HOC *T)
{
	BD:
	int x = 40, y = 4;
	Normal();
	rectagle(x, y, 80, 26);
	gotoxy(x + 3, y + 2);
	cout << "Ma Mon Hoc";
	gotoxy(x + 3, y + 6);
	cout << "Nien Khoa";
	gotoxy(x + 3, y + 10);
	cout << "Hoc Ky";
	gotoxy(x + 3, y + 14);
	cout << "Nhom";
	gotoxy(x + 3, y + 18);
	cout << "Sinh Vien Min";
	gotoxy(x + 3, y + 22);
	cout << "Sinh Vien Max";
	rectagle(x + 20, y + 1, 40, 2);
	rectagle(x + 20, y + 5, 40, 2);
	rectagle(x + 20, y + 9, 40, 2);
	rectagle(x + 20, y + 13, 40, 2);
	rectagle(x + 20, y + 17, 40, 2);
	rectagle(x + 20, y + 21, 40, 2);
	bang_vao_ra(50,32);
	int vt = 0;
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	p->MALOPTC = (ds_ltc.sl == 0) ? 100 : ds_ltc.data[ds_ltc.sl - 1]->MALOPTC + 1;
	p->DSSV.pHead = NULL;
	p->DSSV.pTail = NULL;
	p->MAMH[0] = '\0';
	p->NIEN_KHOA[0] = '\0';
	p->tong_sv_dk = 0;
	p->HUY_LOP=true;
	char tamhk[4];
	tamhk[0] = '\0';
	char tamnhom[4];
	tamnhom[0] = '\0';

	char tamminsv[4];
	tamminsv[0] = '\0';

	char tammaxsv[4];
	tammaxsv[0] = '\0';
MAMH:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 2);
			char c = GetKey();
			if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) && (vt < MAX_MAMH))
			{
				p->MAMH[vt] = toupper(c);
				cout << p->MAMH[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				p->MAMH[vt] = '\0';
				gotoxy(x + 23 + vt, y + 2);
				cout << " ";
			}
			if (c == key_Down || c == key_tab ||c==key_Enter)
			{
				p->MAMH[vt] = '\0';
				if (search_mon_hoc(T, p->MAMH) == 0)
				{
					char s[100] = "MON HOC KHONG TON TAI !";
					Thong_bao(x+4,y+25,s);
					vt = strlen(p->MAMH);
					Sleep(1500);
					gotoxy(x + 4, y + 25);
					cout << "                                   ";
					goto MAMH;
				}
				else
				{
					vt = strlen(p->NIEN_KHOA);
					goto NIENKHOA;
				}
			}
			if (c == key_esc)
			{
				goto ESC;
			}
		}
	}
NIENKHOA:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 6);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < MAX_NIEN_KHOA)
			{
				if (vt == 3)
				{
					p->NIEN_KHOA[vt] = c;
					cout << p->NIEN_KHOA[vt];
					p->NIEN_KHOA[vt + 1] = '_';
					cout << p->NIEN_KHOA[vt + 1];
					vt++;
				}
				else
				{
					p->NIEN_KHOA[vt] = c;
					cout << p->NIEN_KHOA[vt];
				}
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				p->NIEN_KHOA[vt] = '\0';
				gotoxy(x + 23 + vt, y + 6);
				cout << " ";
			}
			if (c == key_Up)
			{
				p->NIEN_KHOA[vt] = '\0';
				vt = strlen(p->MAMH);
				goto MAMH;
			}
			if (c == key_esc)
			{
				goto ESC;
			}
			if (c == key_Down || c == key_tab || c==key_Enter)
			{
				p->NIEN_KHOA[vt] = '\0';
				vt = strlen(tamhk);
				if (CheckNienKhoa(p->NIEN_KHOA) == false)
				{
					char k[100] = "NIEN KHOA > 2000 && <2050";
					Thong_bao(x + 4, y + 25,k);
					Sleep(1500);
					gotoxy(x + 4, y + 25);
					cout << "                                    ";
					vt = strlen(p->NIEN_KHOA);
				}
				else
				{
					goto HK;
				}
			}

		}
	}
HK:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 10);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamhk[vt] = c;
				cout << tamhk[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamhk[vt] = '\0';
				gotoxy(x + 23 + vt, y + 10);
				cout << " ";
			}
			if (c == key_Up)
			{
				tamhk[vt] = '\0';
				vt = strlen(p->NIEN_KHOA);
				p->HOC_KY = chuyen_char_sang_int(tamhk);
				goto NIENKHOA;
			}
			if (c == key_esc)
			{
				goto ESC;
			}
			if (c == key_Down || c == key_tab || c==key_Enter)
			{
				tamhk[vt] = '\0';
				if (!checkInputTrong(tamhk))
				{
					char k[100] = "Khong duoc de trong !";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1000);
					xoa_thong_bao(x + 4, y + 25, 50);
					goto HK;
				}
				else
				{
					vt = strlen(tamnhom);
					p->HOC_KY = chuyen_char_sang_int(tamhk);
					goto NHOM;
				}
			}
		}
	}
NHOM:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 14);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamnhom[vt] = c;
				cout << tamnhom[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamnhom[vt] = '\0';
				gotoxy(x + 23 + vt, y + 14);
				cout << " ";
			}
			if (c == key_Up)
			{
				tamnhom[vt] = '\0';
				vt = strlen(tamhk);
				goto HK;
			}
			if (c == key_esc)
			{
				goto ESC;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				tamnhom[vt] = '\0';
				if (!checkInputTrong(tamnhom))
				{
					char k[100] = "Khong duoc de trong !";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1000);
					xoa_thong_bao(x + 4, y + 25, 50);
					goto NHOM;
				}
				else
				{
					vt = strlen(tamminsv);
					p->NHOM = chuyen_char_sang_int(tamnhom);
					goto MINSV;
				}		
			}
		}
	}
MINSV:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 18);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamminsv[vt] = c;
				cout << tamminsv[vt];
				vt++;
			}
			if (c == key_esc)
			{
				goto ESC;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamminsv[vt] = '\0';
				gotoxy(x + 23 + vt, y + 18);
				cout << " ";
			}
			if (c == key_Up)
			{
				tamminsv[vt] = '\0';
				vt = strlen(tamnhom);
				p->SO_SV_MIN = chuyen_char_sang_int(tamminsv);
				goto NHOM;
			}
			if (c == key_Down || c == key_tab ||c==key_Enter)
			{
				tamminsv[vt] = '\0';
				if (!checkInputTrong(tamminsv))
				{
					char k[100] = "Khong duoc de trong !";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1000);
					xoa_thong_bao(x + 4, y + 25, 50);
				}
				else
				{
					vt = strlen(tammaxsv);
					p->SO_SV_MIN = chuyen_char_sang_int(tamminsv);
					goto MAXSV;
				}		
			}
		}
	}
MAXSV:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 22);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tammaxsv[vt] = c;
				cout << tammaxsv[vt];
				vt++;
			}

			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tammaxsv[vt] = '\0';
				gotoxy(x + 23 + vt, y + 22);
				cout << " ";
			}
			if (c == key_Up)
			{
				tammaxsv[vt] = '\0';
				vt = strlen(tamminsv);
				p->SO_SV_MAX = chuyen_char_sang_int(tammaxsv);
				goto MINSV;
			}
			if (c == key_esc)
			{
				goto ESC;
			}
			if (c == key_Enter)
			{
				tammaxsv[vt] = '\0';
				p->SO_SV_MAX = chuyen_char_sang_int(tammaxsv);
				if (p->SO_SV_MAX <= p->SO_SV_MIN)
				{
					char c[100] = "So luong SV max phai lon hon SV min";
					Thong_bao(x + 4, y + 25, c);
					Sleep(2000);
					gotoxy(x + 4, y + 25);
					cout << "                                                 ";
				}
				else
				{
					int k;
					k = bang_thong_bao("Ban chac chan muon them ?");
					if (k == 1)
					{
						int vtri=0;
						for (int i = 0; i < ds_ltc.sl; i++)
						{
							if (strcmp(ds_ltc.data[i]->NIEN_KHOA , p->NIEN_KHOA )==0 &&
								ds_ltc.data[i]->NHOM == p->NHOM && ds_ltc.data[i]->HOC_KY == p->HOC_KY
								&& strcmp(ds_ltc.data[i]->MAMH, p->MAMH) == 0
								)
							{
								vtri++;
							}
						}
						if(vtri==1)
						{
							xoa_ben_phai();
							char s[50] = "       LOP DA TON TAI !  ";
							khung_thong_bao(60, 15,58, 4,s);
							Sleep(1000);
						}else
						{
							xoa_ben_phai();
							char s[50] = "       THEM THANH CONG !";
							khung_thong_bao(60, 15,58, 4,s);
							Sleep(1000);
							them_vao_ds_lop_tin_chi(ds_ltc, p);
							Ghi_file_lop_tin_chi(ds_ltc);
						}
						goto BD;
					}
					else
					{
						goto BD;
					}
					delete p;
				}
			}
		}
	}
	return;
ESC:
	{
		char c[50] = "Ban co chac chan muon thoat ?";
		int lc = bang_thong_bao(c);
		if (lc == 1)
		{
			delete p;
			return;
		}
		else
		{
			xoa_ben_phai();
			delete p;
			goto BD;
		}
	};
}

void In_lop_tin_chi(DS_LOP_TIN_CHI ds_ltc)
{
	INRA:
	int x = 40, y = 4, row = 0, trang = 0, tongTrang = 0;
	char c;
	while (1)
	{
		if (ds_ltc.sl == 0)
		{
			rectagle(x + 15, y + 8, 40, 6);
			gotoxy(x + 18, y + 11);
			cout << "DANH SACH TIN CHI TRONG !";
			c = GetKey();
			if (c == key_esc || c == key_Enter)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==1) return;
				goto INRA;
			}
		}
		else
		{
			if (ds_ltc.sl < 22)
			{
				trang = 0;
				tongTrang = 1;
			}
			else
			{
				tongTrang = (ds_ltc.sl - 1) / 22 + 1;
			}
		}
		Hien_thi_trang(trang + 1, tongTrang, x + 80, y + 28);
		int stt = 0;
		Xoa_khung_lop_tin_chi();
		Khung_lop_tin_chi();
		for (int i = trang * 22; i < 22 + trang * 22 && i < ds_ltc.sl; i++)
		{
			stt = i + 1;
			gotoxy(x + 2, y + 3 + row); cout << stt;
			gotoxy(x + 8, y + 3 + row); cout << ds_ltc.data[i]->MALOPTC;
			gotoxy(x + 17, y + 3 + row); cout << ds_ltc.data[i]->MAMH;
			gotoxy(x + 32, y + 3 + row); cout << ds_ltc.data[i]->NIEN_KHOA;
			gotoxy(x + 47, y + 3 + row); cout << ds_ltc.data[i]->NHOM;
			gotoxy(x + 57, y + 3 + row); cout << ds_ltc.data[i]->HOC_KY;
			gotoxy(x + 65, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX;
			gotoxy(x + 74, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MIN;
			gotoxy(x + 82, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX - ds_ltc.data[i]->tong_sv_dk;
			row++;
		}
		c = GetKey();
		if (c == key_esc || c == key_Enter)
		{
			if(bang_thong_bao("Ban co chac chan thoat ?")==1) return;
			goto INRA;
		}
		else if ((c == key_Down || c == key_Right) && trang < tongTrang - 1)
		{
			trang++;
		}
		else if ((c == key_Up || c == key_Left) && trang > 0)
		{
			trang--;
		}
		row = 0;
	}
}
void Xoa_sua_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc,TREE_MON_HOC *T,int tgbd)
{
INRA:
	{
		int x = 40, y = 4, row = 0, trang = 0, tongTrang = 0;
		timeDK tgdk;
		in_tg_ket_thuc(tgbd,tgdk);
		char c;
		while (1)
		{
			bang_xoa_sua(x, y + 29);
			if (ds_ltc.sl == 0)
			{
				rectagle(x + 15, y + 8, 40, 6);
				gotoxy(x + 18, y + 11);
				cout << "DANH SACH TIN CHI TRONG !";
				c = GetKey();
				if (c == key_esc || c == key_Enter)
				{
					break;
				}
			}
			else
			{
				if (ds_ltc.sl < 22)
				{
					trang = 0;
					tongTrang = 1;
				}
				else
				{
					tongTrang = (ds_ltc.sl - 1) / 22 + 1;
				}
			}

			int stt = 0;
			Xoa_khung_lop_tin_chi();
			Khung_lop_tin_chi();
			for (int i = trang * 22; i < 22 + trang * 22 && i < ds_ltc.sl; i++)
			{
				stt = i + 1;
				gotoxy(x + 2, y + 3 + row); cout << stt;
				gotoxy(x + 8, y + 3 + row); cout << ds_ltc.data[i]->MALOPTC;
				gotoxy(x + 17, y + 3 + row); cout << ds_ltc.data[i]->MAMH;
				gotoxy(x + 32, y + 3 + row); cout << ds_ltc.data[i]->NIEN_KHOA;
				gotoxy(x + 47, y + 3 + row); cout << ds_ltc.data[i]->NHOM;
				gotoxy(x + 57, y + 3 + row); cout << ds_ltc.data[i]->HOC_KY;
				gotoxy(x + 65, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX;
				gotoxy(x + 74, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MIN;
				gotoxy(x + 82, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX - ds_ltc.data[i]->tong_sv_dk;
				row++;
			}
			int chon = 0;
			//dau nhay chon 
			stt = 1;
			while (1)
			{
				Hien_thi_trang(trang + 1, tongTrang, x + 80, y + 28);
				if (chon == trang * 22)
				{
					HighLight();
					gotoxy(x + 2, y + 3 + chon - 22 * trang); cout << stt;
					gotoxy(x + 8, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MALOPTC;
					gotoxy(x + 17, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MAMH;
					gotoxy(x + 32, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NIEN_KHOA;
					gotoxy(x + 47, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NHOM;
					gotoxy(x + 57, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->HOC_KY;
					gotoxy(x + 65, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX;
					gotoxy(x + 74, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MIN;
					gotoxy(x + 82, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
					Normal();
				}
				c = GetKey();
				if (c == key_esc)
				{
					if(bang_thong_bao("Ban co chac chan thoat ?")==1) return;
					goto INRA;
				}
				else if ((c == key_Down) && trang < tongTrang && chon < ds_ltc.sl - 1)
				{
					Normal();
					gotoxy(x + 2, y + 3 + chon - 22 * trang); cout << stt;
					gotoxy(x + 8, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MALOPTC;
					gotoxy(x + 17, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MAMH;
					gotoxy(x + 32, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NIEN_KHOA;
					gotoxy(x + 47, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NHOM;
					gotoxy(x + 57, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->HOC_KY;
					gotoxy(x + 65, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX;
					gotoxy(x + 74, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MIN;
					gotoxy(x + 82, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
					chon++;
					stt++;
					HighLight();
					gotoxy(x + 2, y + 3 + chon - 22 * trang); cout << stt;
					gotoxy(x + 8, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MALOPTC;
					gotoxy(x + 17, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MAMH;
					gotoxy(x + 32, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NIEN_KHOA;
					gotoxy(x + 47, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NHOM;
					gotoxy(x + 57, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->HOC_KY;
					gotoxy(x + 65, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX;
					gotoxy(x + 74, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MIN;
					gotoxy(x + 82, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
					if (chon == 22 * (trang + 1))
					{
						trang++;
						Xoa_khung_lop_tin_chi();
						Khung_lop_tin_chi();
						row = 0;
						for (int i = trang * 22; i < 22 + trang * 22 && i < ds_ltc.sl; i++)
						{
							stt = i;
							gotoxy(x + 2, y + 3 + row); cout << ++stt;
							gotoxy(x + 8, y + 3 + row); cout << ds_ltc.data[i]->MALOPTC;
							gotoxy(x + 17, y + 3 + row); cout << ds_ltc.data[i]->MAMH;
							gotoxy(x + 32, y + 3 + row); cout << ds_ltc.data[i]->NIEN_KHOA;
							gotoxy(x + 47, y + 3 + row); cout << ds_ltc.data[i]->NHOM;
							gotoxy(x + 57, y + 3 + row); cout << ds_ltc.data[i]->HOC_KY;
							gotoxy(x + 65, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX;
							gotoxy(x + 74, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MIN;
							gotoxy(x + 82, y + 3 + row); cout << ds_ltc.data[i]->SO_SV_MAX - ds_ltc.data[i]->tong_sv_dk;
							row++;
						}
						stt = stt - (ds_ltc.sl - 23);
					}
				}
				else if (c == key_Up && chon > 0 && trang >= 0)
				{
					Normal();
					gotoxy(x + 2, y + 3 + chon - 22 * trang); cout << stt;
					gotoxy(x + 8, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MALOPTC;
					gotoxy(x + 17, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MAMH;
					gotoxy(x + 32, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NIEN_KHOA;
					gotoxy(x + 47, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NHOM;
					gotoxy(x + 57, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->HOC_KY;
					gotoxy(x + 65, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX;
					gotoxy(x + 74, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MIN;
					gotoxy(x + 82, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
					chon--;
					stt--;
					HighLight();
					gotoxy(x + 2, y + 3 + chon - 22 * trang); cout << stt;
					gotoxy(x + 8, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MALOPTC;
					gotoxy(x + 17, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->MAMH;
					gotoxy(x + 32, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NIEN_KHOA;
					gotoxy(x + 47, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->NHOM;
					gotoxy(x + 57, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->HOC_KY;
					gotoxy(x + 65, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX;
					gotoxy(x + 74, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MIN;
					gotoxy(x + 82, y + 3 + chon - 22 * trang); cout << ds_ltc.data[chon]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
					if (chon == 21 * trang && chon != 0)
					{
						trang--;
						Xoa_khung_lop_tin_chi();
						Khung_lop_tin_chi();
						row = 0;
						for (int i = trang * 22; i < 22 + trang * 22 && i < ds_ltc.sl; i++)
						{
							stt = i;
							gotoxy(x + 2, y + 3 + row - 22 * trang); cout << ++stt;
							gotoxy(x + 8, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->MALOPTC;
							gotoxy(x + 17, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->MAMH;
							gotoxy(x + 32, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->NIEN_KHOA;
							gotoxy(x + 47, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->NHOM;
							gotoxy(x + 57, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->HOC_KY;
							gotoxy(x + 65, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->SO_SV_MAX;
							gotoxy(x + 74, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->SO_SV_MIN;
							gotoxy(x + 82, y + 3 + row - 22 * trang); cout << ds_ltc.data[i]->SO_SV_MAX - ds_ltc.data[i]->tong_sv_dk;
							row++;
						}

						HighLight();
						gotoxy(x + 2, y + 3 + chon - 21 * trang);
						cout << 22 * (trang + 1);
						gotoxy(x + 8, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->MALOPTC;
						gotoxy(x + 17, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->MAMH;
						gotoxy(x + 32, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->NIEN_KHOA;
						gotoxy(x + 47, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->NHOM;
						gotoxy(x + 57, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->HOC_KY;
						gotoxy(x + 65, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->SO_SV_MAX;
						gotoxy(x + 74, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->SO_SV_MIN;
						gotoxy(x + 82, y + 3 + chon - 21 * trang); cout << ds_ltc.data[chon - 21 * trang]->SO_SV_MAX - ds_ltc.data[chon - 21 * trang]->tong_sv_dk;
						Normal();

					}
				}
				else if (c == key_F1)
				{
					if(check_tg_dang_ki(tgbd,tgdk))
					{
						HideCursor(true);
						Sua_lop_tin_chi(ds_ltc, T ,chon);
						system("cls");
						Ve_lai_sau_khi_sua_ltc(itemloptinchi,1);
						Xoa_khung_lop_tin_chi();
						Khung_lop_tin_chi();
						goto INRA;
					}else
					{
						char c[30]="DA HET THOI DE SUA !";
						khung_thong_bao(65,12,50,4,c);
						Sleep(1000);
						goto INRA;
					}
					
				}
				else if (c == key_F2)
				{
					if(check_tg_dang_ki(tgbd,tgdk))
					{
						int k = bang_thong_bao("Ban co chac chan muon xoa ?");
						if (k == 1)
						{
							Xoa_lop_tin_chi(ds_ltc, chon);
							goto INRA;	
						}
						else
						{
							goto INRA;
						}
					}else
					{
						char c[30]="DA HET THOI DE XOA !";
						khung_thong_bao(65,12,50,4,c);
						Sleep(1000);
						goto INRA;
					}
				}
			}
			row = 0;
			break;
		}
	}
}
void Xoa_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc, int vt)
{
	if(ds_ltc.sl==0 || vt>ds_ltc.sl || vt<0) return;
	if(ds_ltc.data[vt]->HUY_LOP==1)
	{
		for (int i = vt; i < ds_ltc.sl - 1; i++)
		{
			ds_ltc.data[i]->DSSV = ds_ltc.data[i + 1]->DSSV;
			ds_ltc.data[i]->HOC_KY = ds_ltc.data[i + 1]->HOC_KY;
			ds_ltc.data[i]->HUY_LOP = ds_ltc.data[i + 1]->HUY_LOP;
			ds_ltc.data[i]->MALOPTC = ds_ltc.data[i + 1]->MALOPTC;
			strcpy(ds_ltc.data[i]->MAMH, ds_ltc.data[i + 1]->MAMH);
			ds_ltc.data[i]->NHOM = ds_ltc.data[i + 1]->NHOM;
			strcpy(ds_ltc.data[i]->NIEN_KHOA, ds_ltc.data[i + 1]->NIEN_KHOA);
			ds_ltc.data[i]->SO_SV_MAX = ds_ltc.data[i + 1]->SO_SV_MAX;
			ds_ltc.data[i]->SO_SV_MIN = ds_ltc.data[i + 1]->SO_SV_MIN;
			ds_ltc.data[i]->tong_sv_dk = ds_ltc.data[i + 1]->tong_sv_dk;
		}
		delete(ds_ltc.data[ds_ltc.sl - 1]);			
		ds_ltc.sl--;	
		Ghi_file_lop_tin_chi(ds_ltc);			
		char ch[30] = "     Da Xoa Thanh Cong !!!";
		xoa_ben_phai();
		khung_thong_bao(60, 15, 58, 4, ch);
		Sleep(1000);
		xoa_ben_phai();
	}else
	{
		char ch[60] = "   Lop da dang ki du khong duoc xoa !!!";
		xoa_ben_phai();
		khung_thong_bao(60, 15, 55, 4, ch);
		Sleep(1000);
		xoa_ben_phai();
	}
	
}


void Sua_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc,TREE_MON_HOC *T,int vitrichon)
{
	SUALTC:
	int x = 40, y = 4;
	Normal();
	rectagle(x, y, 80, 26);
	gotoxy(x + 3, y + 2);
	cout << "Ma Mon Hoc";
	gotoxy(x + 3, y + 6);
	cout << "Nien Khoa";
	gotoxy(x + 3, y + 10);
	cout << "Hoc Ky";
	gotoxy(x + 3, y + 14);
	cout << "Nhom";
	gotoxy(x + 3, y + 18);
	cout << "Sinh Vien Min";
	gotoxy(x + 3, y + 22);
	cout << "Sinh Vien Max";
	rectagle(x + 20, y + 1, 40, 2);
	rectagle(x + 20, y + 5, 40, 2);
	rectagle(x + 20, y + 9, 40, 2);
	rectagle(x + 20, y + 13, 40, 2);
	rectagle(x + 20, y + 17, 40, 2);
	rectagle(x + 20, y + 21, 40, 2);
	int vt = 0;
	char tamhk[4];
	_itoa(ds_ltc.data[vitrichon]->HOC_KY, tamhk, 10);
	char tamnhom[4];
	_itoa(ds_ltc.data[vitrichon]->NHOM, tamnhom, 10);
	char tamminsv[4];
	_itoa(ds_ltc.data[vitrichon]->SO_SV_MIN, tamminsv, 10);
	char tammaxsv[4];
	_itoa(ds_ltc.data[vitrichon]->SO_SV_MAX, tammaxsv, 10);
	char mamh[MAX_MAMH];
	char nienkhoa[MAX_NIEN_KHOA];
	strcpy(nienkhoa,ds_ltc.data[vitrichon]->NIEN_KHOA);
	strcpy(mamh,ds_ltc.data[vitrichon]->MAMH);
	int hocki=ds_ltc.data[vitrichon]->HOC_KY,nhom=ds_ltc.data[vitrichon]->NHOM,svmax=ds_ltc.data[vitrichon]->SO_SV_MAX,svmin=ds_ltc.data[vitrichon]->SO_SV_MIN;
	gotoxy(x + 23, y + 2);
	cout << mamh;
	gotoxy(x + 23, y + 6);
	cout << nienkhoa;
	gotoxy(x + 23 , y + 10);
	cout << hocki;
	gotoxy(x + 23 , y + 14);
	cout << nhom;
	gotoxy(x + 23, y + 18);
	cout << svmin;
	gotoxy(x + 23, y + 22);
	cout << svmax;
	vt = strlen(mamh);
MAMH:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 2);
			char c = GetKey();
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') && vt < MAX_MAMH)
			{
				mamh[vt] = toupper(c);
				cout << mamh[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				mamh[vt] = '\0';
				gotoxy(x + 23 + vt, y + 2);
				cout << " ";
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				mamh[vt] = '\0';
				if (search_mon_hoc(T, mamh) == 0)
				{
					char s[100] = "Mon hoc khong ton tai !";
					Thong_bao(x + 4, y + 28, s);
					vt = strlen(mamh);
					Sleep(1500);
					gotoxy(x + 4, y + 28);
					cout << "                                   ";
					goto MAMH;
				}
				else
				{
					vt = strlen(nienkhoa);
					goto NIENKHOA;
				}
			}
		}
	}
NIENKHOA:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 6);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < MAX_NIEN_KHOA)
			{
				if (vt == 3)
				{
					nienkhoa[vt] = c;
					cout << nienkhoa[vt];
					nienkhoa[vt + 1] = '_';
					cout << nienkhoa[vt + 1];
					vt++;
				}
				else
				{
					nienkhoa[vt] = c;
					cout << nienkhoa[vt];
				}
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				nienkhoa[vt] = '\0';
				gotoxy(x + 23 + vt, y + 6);
				cout << " ";
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_Up)
			{
				nienkhoa[vt] = '\0';
				vt = strlen(mamh);
				goto MAMH;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				nienkhoa[vt] = '\0';
				if (CheckNienKhoa(nienkhoa) == false)
				{
					char k[100] = "Nien khoa > 2000 && <2050";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1500);
					gotoxy(x + 4, y + 25);
					cout << "                                    ";
					vt = strlen(nienkhoa);
				}
				else
				{
					vt = strlen(tamhk);
					goto HK;
				}
			}

		}
	}
HK:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 10);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamhk[vt] = c;
				cout << tamhk[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamhk[vt] = '\0';
				gotoxy(x + 23 + vt, y + 10);
				cout << " ";
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_Up)
			{
				tamhk[vt] = '\0';
				vt = strlen(nienkhoa);
				hocki = chuyen_char_sang_int(tamhk);
				goto NIENKHOA;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				tamhk[vt] = '\0';
				vt = strlen(tamnhom);
				hocki = chuyen_char_sang_int(tamhk);
				goto NHOM;
			}
		}
	}
NHOM:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 14);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamnhom[vt] = c;
				cout << tamnhom[vt];
				vt++;
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamnhom[vt] = '\0';
				gotoxy(x + 23 + vt, y + 14);
				cout << " ";
			}
			if (c == key_Up)
			{
				tamnhom[vt] = '\0';
				vt = strlen(tamhk);
				goto HK;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				tamnhom[vt] = '\0';
				vt = strlen(tamminsv);
				nhom = chuyen_char_sang_int(tamnhom);
				goto MINSV;
			}
		}
	}
MINSV:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 18);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamminsv[vt] = c;
				cout << tamminsv[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamminsv[vt] = '\0';
				gotoxy(x + 23 + vt, y + 18);
				cout << " ";
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_Up)
			{
				tamminsv[vt] = '\0';
				vt = strlen(tamnhom);
				svmin = chuyen_char_sang_int(tamminsv);
				goto NHOM;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				tamminsv[vt] = '\0';
				vt = strlen(tammaxsv);
				svmin = chuyen_char_sang_int(tamminsv);
				goto MAXSV;
			}
		}
	}
MAXSV:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 22);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tammaxsv[vt] = c;
				cout << tammaxsv[vt];
				vt++;
			}
			if(c==key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==0)
				{	
					goto SUALTC;
				}else
				{
					return;	
				}	
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tammaxsv[vt] = '\0';
				gotoxy(x + 23 + vt, y + 22);
				cout << " ";
			}
			if (c == key_Up)
			{
				tammaxsv[vt] = '\0';
				vt = strlen(tamminsv);
				svmax = chuyen_char_sang_int(tammaxsv);
				goto MINSV;
			}
			if (c == key_Enter)
			{
				svmax = chuyen_char_sang_int(tammaxsv);
				if (svmax <= svmin)
				{
					char c[100] = "So luong sv max phai lon hon SV min";
					Thong_bao(x + 4, y + 25, c);
					Sleep(2000);
					gotoxy(x + 4, y + 25);
					vt=0;
					tammaxsv[vt] = '\0';
					cout << "                                                 ";
					svmax=0;
					gotoxy(x+23,y+22);cout<<"      ";
					goto MAXSV;
				}
				else
				{
					int k = bang_thong_bao("Ban chac chac sua ? ");
					if (k == 1)
					{
						
						int vtri=0;
						for (int i = 0; i < ds_ltc.sl; i++)
						{
							if(i==vitrichon)  continue;
							if (strcmp(ds_ltc.data[i]->NIEN_KHOA , nienkhoa )==0 &&
								ds_ltc.data[i]->NHOM == nhom && ds_ltc.data[i]->HOC_KY == hocki
								&& strcmp(ds_ltc.data[i]->MAMH, mamh) == 0
								)
							{
								vtri++;
							}
						}
						
						if(vtri==1)
						{
							xoa_ben_phai();
							char s[50] = "       Lop da ton tai !  ";
							khung_thong_bao(60, 15,58, 4,s);
							Sleep(1000);
							xoa_ben_phai();
							goto SUALTC;
						}else
						{
							
							tammaxsv[vt] = '\0';
							svmax = chuyen_char_sang_int(tammaxsv);
							ds_ltc.data[vitrichon]->HOC_KY = hocki;
							strcpy(ds_ltc.data[vitrichon]->MAMH, mamh);
							ds_ltc.data[vitrichon]->NHOM = nhom;
							strcpy(ds_ltc.data[vitrichon]->NIEN_KHOA, nienkhoa);
							ds_ltc.data[vitrichon]->SO_SV_MAX = svmax;
							ds_ltc.data[vitrichon]->SO_SV_MIN = svmin;
								
							xoa_ben_phai();
							char s[50] = "    Sua lop thanh cong !";
							khung_thong_bao(60, 15,58, 4,s);
							Sleep(1000);
							break;
						}
					}
					else
					{
						goto SUALTC;
					}
				}
			}
		}
	}
	Ghi_file_lop_tin_chi(ds_ltc);
}


int Search_danh_sach_sv_dang_ki(DS_LOP_TIN_CHI ds_ltc)
{
	BD:
	int x = 40, y = 4;
	bang_vao_ra(50,32);
	Normal();
	rectagle(x, y, 80, 26);
	gotoxy(x + 3, y + 6);
	cout << "Nien Khoa";
	gotoxy(x + 3, y + 10);
	cout << "Hoc Ky";
	gotoxy(x + 3, y + 14);
	cout << "Nhom";
	gotoxy(x + 3, y + 18);
	cout << "Ma Mon Hoc";	
	rectagle(x + 20, y + 5, 40, 2);
	rectagle(x + 20, y + 9, 40, 2);
	rectagle(x + 20, y + 13, 40, 2);
	rectagle(x + 20, y + 17, 40, 2);
	
	int vt = 0;
	char mamh[MAX_MAMH];
	char nienkhoa[MAX_NIEN_KHOA];
	int hocki,nhom;
	mamh[0] = '\0';
	nienkhoa[0] = '\0';
	char tamhk[4];
	tamhk[0] = '\0';
	char tamnhom[4];
	tamnhom[0] = '\0';

	vt = strlen(nienkhoa);
NIENKHOA:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 6);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < MAX_NIEN_KHOA)
			{
				if (vt == 3)
				{
					nienkhoa[vt] = c;
					cout << nienkhoa[vt];
					nienkhoa[vt + 1] = '_';
					cout << nienkhoa[vt + 1];
					vt++;
				}
				else
				{
					nienkhoa[vt] = c;
					cout << nienkhoa[vt];
				}
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				nienkhoa[vt] = '\0';
				gotoxy(x + 23 + vt, y + 6);
				cout << " ";
			}
			if(c== key_esc)
			{
				if(bang_thong_bao("Ban co chac chan muon thoat")==1) 
				{
					return -2;	
				}else{
					xoa_ben_phai();
					goto BD;
				}
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				nienkhoa[vt] = '\0';
				vt = strlen(tamhk);
				if (CheckNienKhoa(nienkhoa) == false)
				{
					char k[100] = "Nien khoa > 2000 && <2050";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1500);
					gotoxy(x + 4, y + 25);
					cout << "                                    ";
					vt = strlen(nienkhoa);
				}
				else
				{
					goto HK;
				}
			}
			if (c == key_esc)
			{
				return -2;
			}
		}
	}
HK:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 10);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamhk[vt] = c;
				cout << tamhk[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamhk[vt] = '\0';
				gotoxy(x + 23 + vt, y + 10);
				cout << " ";
			}
			if (c == key_Up)
			{
				tamhk[vt] = '\0';
				vt = strlen(nienkhoa);
				hocki = chuyen_char_sang_int(tamhk);
				goto NIENKHOA;
			}
			if(c== key_esc)
			{
				if(bang_thong_bao("Ban co chac chan muon thoat")==1) 
				{
					return -2;	
				}else{
					xoa_ben_phai();
					goto BD;
				}
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				
				tamhk[vt] = '\0';
				if (!checkInputTrong(tamhk))
				{
					char k[100] = "Khong duoc de trong !";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1000);
					xoa_thong_bao(x + 4, y + 25, 50);
					goto HK;
				}
				else
				{
					vt = strlen(tamnhom);
					hocki = chuyen_char_sang_int(tamhk);
					goto NHOM;
				}
			}
		}
	}
NHOM:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 14);
			char c = GetKey();
			if ((c >= '0' && c <= '9') && vt < 3)
			{
				tamnhom[vt] = c;
				cout << tamnhom[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				tamnhom[vt] = '\0';
				gotoxy(x + 23 + vt, y + 14);
				cout << " ";
			}
			if(c== key_esc)
			{
				if(bang_thong_bao("Ban co chac chan muon thoat")==1) 
				{
					return -2;	
				}else{
					xoa_ben_phai();
					goto BD;
				}
			}
			if (c == key_Up)
			{
				tamnhom[vt] = '\0';
				vt = strlen(tamhk);
				goto HK;
			}
			if (c == key_Down || c == key_tab || c == key_Enter)
			{
				tamnhom[vt] = '\0';
				if (!checkInputTrong(tamnhom))
				{
					char k[100] = "Khong duoc de trong !";
					Thong_bao(x + 4, y + 25, k);
					Sleep(1000);
					xoa_thong_bao(x + 4, y + 25, 50);
					goto NHOM;
				}
				else
				{
					vt = strlen(mamh);
					nhom = chuyen_char_sang_int(tamnhom);
					goto MAMH;
				}	
			}
		}
	}

MAMH:
	{
		HideCursor(false);
		while (1)
		{
			gotoxy(x + 23 + vt, y + 18);
			char c = GetKey();
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') && vt < MAX_MAMH)
			{
				mamh[vt] = toupper(c);
				cout << mamh[vt];
				vt++;
			}
			if (c == key_bkspace && vt > 0)
			{
				vt--;
				mamh[vt] = '\0';
				gotoxy(x + 23 + vt, y + 18);
				cout << " ";
			}
			if(c== key_esc)
			{
				if(bang_thong_bao("Ban co chac chan muon thoat")==1) 
				{
					return -2;	
				}else{
					xoa_ben_phai();
					goto BD;
				}
			}
			if (c == key_Enter)
			{
				mamh[vt] = '\0';
				int i;
				for (i = 0; i < ds_ltc.sl; i++)
				{
					if (strcmp(ds_ltc.data[i]->NIEN_KHOA , nienkhoa )==0 &&
						ds_ltc.data[i]->NHOM == nhom && ds_ltc.data[i]->HOC_KY == hocki
						&& strcmp(ds_ltc.data[i]->MAMH, mamh) == 0
						)
					{
						return i;
					}
				}
				if (i == ds_ltc.sl)
				{
					return -1;
				}
			}
			if (c == key_Up)
			{
				mamh[vt] = '\0';
				vt = strlen(tamnhom);
				goto NHOM;
			}
		}
	}
}


void In_danh_sach_sv_dk(DS_LOP_TIN_CHI ds_ltc,DS_SINH_VIEN ds_sv)
{
	system("cls");
	Normal();
	Ve_lai_sau_khi_sua_ltc(itemloptinchi,3);
	BDINSVDK:
	int vitri = Search_danh_sach_sv_dang_ki(ds_ltc);
	int x = 45, y = 5;
	char c;
	if (vitri == -1)
	{
		char c[100] = "KHONG TIM THAY LOP TIN CHI NAY !";
		Thong_bao(x + 4, y + 23, c);
		Sleep(1000);
		goto BDINSVDK;
	}
	else if (vitri == -2)
	{
		return;	
	}
	else if (vitri != -1 && ds_ltc.data[vitri]->tong_sv_dk == 0)
	{
		char c[100] = "KHONG CO SINH VIEN DANG KI LOP NAY !";
		Thong_bao(x + 4, y + 23, c);
		Sleep(1000);
		goto BDINSVDK;
	}
	xoa_ben_phai();
	NODE_SINH_VIEN* sv;
	SV_DANG_KY* sv_dk;
	int stt = 0;
	int trang = 1;
	int tongTrang = so_trang(1.0 * ds_ltc.data[vitri]->tong_sv_dk / 20);
BDIN:
	Hien_thi_trang(trang, tongTrang, x + 70, y + 28);
	int count = 0, row = 0;
	xoa_khung_ds_sv_dk();
	khung_danh_sach_sv_dk();
	Ve_lai_sau_khi_sua_ltc(itemloptinchi, 3);
	get_SV_DK(ds_ltc.data[vitri]->DSSV,ds_sv,sv_dk,sv,stt);
	for (SV_DANG_KY* h = sv_dk; h != NULL && count < 20; h = h->pNext)
	{
		for (NODE_SINH_VIEN* k = ds_sv.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(h->MASV , k->data.MASV)==0)
			{
				count++;
				++stt;
				++row;
				gotoxy(x + 2, y + row);cout << k->data.MASV;
				gotoxy(x + 2 + 12, y + row);cout << char(179);
				gotoxy(x + 2 + 15, y + row);
				cout << k->data.HO;
				gotoxy(x + 17 + 18, y + row);cout << char(179);
				gotoxy(x + 17 + 20, y + row);
				cout << k->data.TEN;
				gotoxy(x + 37 + 10, y + row);cout << char(179);
				gotoxy(x + 37 + 15, y + row);
				cout << k->data.PHAI;
				gotoxy(x + 52 + 4, y + row);cout << char(179);
				gotoxy(x + 52 + 5, y + row);
				cout << k->data.SDT;
				gotoxy(x + 52 + 18, y + row);cout << char(179);
				gotoxy(x + 52 + 20, y + row);
				cout << k->data.MALOP;
				break;
			}
		}
	}
	while(1)
	{
		char c=GetKey();
		if(c==key_esc)
		{
			int k;
			k=bang_thong_bao("Ban co chac chan muon thoat ?");
			if(k==1)
			{
				xoa_ben_phai();
				goto BDINSVDK;
			}else
			{
				xoa_ben_phai();
				stt-=count;
				goto BDIN;
			}
		}
		else if(c==key_Down)
		{
			trang+=1;
			if(trang > tongTrang) trang = tongTrang;
			else
			{
				xoa_ben_phai();
				goto BDIN;
			}
		}
		else if(c == key_Up)
		{
			trang-=1;
			if(trang <= 0) trang = 1;
			else
			{
				stt -= (count + 20);
				goto BDIN;
			}
		}
	}
	_getch();
} 
// chon dang ki hay la huy 
int Dang_ki_or_huy_lop()
{
	HideCursor(true);
	Normal();
	int x=60,y=20;
	rectagle(x,y,30,4);
	gotoxy(x+8,y+2);
	cout<<"DANG KI LOP";
	rectagle(x,y+6,30,4);
	gotoxy(x+4,y+6+2);
	cout<<"HUY or XEM LOP DA DKI";
	HighLight();
	rectagle(x,y,30,4);
	gotoxy(x+8,y+2);
	cout<<"DANG KI LOP";
	char c;
	int chon=0;
	while(1)
	{
		c=GetKey();
		if(c==key_Down && chon == 0)
		{
			Normal();
			rectagle(x,y,30,4);
			gotoxy(x+8,y+2);
			cout<<"DANG KI LOP";
			HighLight();
			rectagle(x,y+6,30,4);
			gotoxy(x+4,y+6+2);
			cout<<"HUY or XEM LOP DA DKI";
			chon++;
		}
		if(c==key_Up && chon ==1)
		{
			HighLight();
			rectagle(x,y,30,4);
			gotoxy(x+8,y+2);
			cout<<"DANG KI LOP";
			Normal();
			rectagle(x,y+6,30,4);
			gotoxy(x+4,y+6+2);
			cout<<"HUY or XEM LOP DA DKI";
			--chon;
		}
		if(c==key_Enter)
		{
			return chon;
		}
		if (c==key_esc)
		{
			return -1;
		}
	}
	return -1;
}
//BAT DAU DANG KI LOP TIN CHI
NODE_SINH_VIEN* tim_ma_sv(DS_SINH_VIEN ds_sv)
{
	BDNHAP:
	Normal();
	char MSV[15];
	int x = 50, y = 10,vt=0;
	rectagle(x, y, 60, 8);
	gotoxy(x + 4, y + 2);
	cout << "Nhap MSSV cua ban : ";
	rectagle(x + 4, y + 4, 45, 2);
	char c;
	bang_vao_ra(50,33);
	HideCursor(false);
	while (1)
	{
		gotoxy(x + 6 + vt, y + 5);
		c = GetKey();
		if ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') && (vt < MAX_MASV))
		{
			MSV[vt] = toupper(c);
			gotoxy(x + 6 + vt, y + 5);
			cout << MSV[vt];
			vt++;	
		}
		if (c == key_Enter)
		{
			MSV[vt] = '\0';
			for (NODE_SINH_VIEN* k = ds_sv.pHead; k != NULL; k=k->pNext)
			{
				if (_stricmp(k->data.MASV, MSV) == 0)
				{
					return k;
				}
				else if (_stricmp(k->data.MASV, MSV) != 0 && k == ds_sv.pTail)
				{
					char c;
					xoa_ben_phai();
					char s[100] = "Khong tim thay sinh vien !!!";
					khung_thong_bao(60, 15, 58, 4, s);
					Sleep(1000);
					xoa_ben_phai();
					goto BDNHAP;	
				}
			}
		}
		if (c == key_bkspace && vt>0)
		{	
			vt--;
			MSV[vt] = '\0';
			gotoxy(x + 6 + vt, y + 5);
			cout << ' ';
		}
		if(c == key_esc)
		{
			return NULL;
		}
	}
}
bool Check_mo_lop_tin_chi(DS_LOP_TIN_CHI ds_ltc,char *cNienkhoa , int cHK)
{
	for (int i = 0; i < ds_ltc.sl; i++)
	{
		if (_stricmp(ds_ltc.data[i]->NIEN_KHOA, cNienkhoa) == 0 && ds_ltc.data[i]->HOC_KY==cHK)
		{
			return true;
		}
	}
	return false;
}
void cap_vung_nho_in_ds_mon(int* &a ,int vung_nho_cu,int vung_nho_moi)// cap vung nho de hien thi ra danh sach mon  do ton bo nho
{
	int* temp = new int[vung_nho_cu];
	for (int i = 0; i < vung_nho_cu; i++)
	{
		temp[i] = a[i];
	}
	delete[]a;
	a = new int[vung_nho_moi];
	for (int i = 0; i < vung_nho_moi; i++)
	{
		a[i]= temp[i];
	}
	delete[]temp;
}
bool check_sv_da_dk(DS_SV_DANG_KY ds_svdk, char masvdk[MAX_MAMH])
{
	for (SV_DANG_KY* k = ds_svdk.pHead; k != NULL; k = k->pNext)
	{
		if (strcmp(k->MASV, masvdk) == 0)
		{
			return false;
		}
	}
	return true;
}
//Ba lam

char* search_mon_hoc(TREE_MON_HOC* T, char *mamh)
{
	TREE_MON_HOC* p = T;
	int sp = -1;
	TREE_MON_HOC* STACK[100];
	while (p != NULL)
	{
		if (strcmp(p->data.MAMH, mamh) == 0)
		{
			return p->data.TENMH;
		}
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
	return 0;
}
//kt Ba lam

void time_dk(timeDK &tgdk)
{
	tgdk.ngaydk=0;
	tgdk.hdk=0;
	tgdk.pdk=5;
}
void in_tg_ket_thuc(int tgbd ,timeDK tgdk)
{
	time_dk(tgdk);
	time_t now = time(0);
	tm* ltm=localtime(&now);
	int tong_tg=tgdk.ngaydk*86400+tgdk.hdk*3600+tgdk.pdk*60+tgbd;
	int ngay,h,m,s;
	if(tong_tg > 86400)
	{
		ngay=ltm->tm_mday + (tong_tg / 86400) + 1;
		h = (tong_tg- (tong_tg / 86400) *86400)/3600;
		m = ( tong_tg - (tong_tg / 86400) *86400 - h * 3600 ) / 60;
		s = tong_tg - (tong_tg / 86400) *86400 - (h * 3600 ) - m *60;
	}else
	{
		ngay=ltm->tm_mday;
		h = tong_tg/3600;
		m = ( tong_tg - h * 3600 ) / 60;
		s = tong_tg - h *3600 - m * 60;
	}
	gotoxy(2,2);
	SetBGColor(15);
	SetColor(12);
	cout<<"Dang ki ket thuc vao "<<ngay<<"/"<<ltm->tm_mon+1<<" luc "<<h<<":"<<m<<":"<<s<<"s";
}
int check_tg_dang_ki(int tgbd , timeDK tgdk)
{
	time_t now=time(0);
	tm* ltm=localtime(&now);
	time_dk(tgdk);
	if(ltm->tm_hour*3600+ltm->tm_min*60+ltm->tm_sec < tgdk.ngaydk*86400+tgdk.hdk*3600+tgdk.pdk*60+tgbd) return 1;
	return 0;
}
void Dang_Ki_Lop_Tin_Chi(DS_LOP_TIN_CHI &ds_ltc,DS_LOP_TIN_CHI &ds_lop_sv_dk,DS_SINH_VIEN ds_sv,TREE_MON_HOC *T,int tgbd)
{
	BD:
	SetBGColor(15);
	SetColor(12);
	timeDK tgdk;
	in_tg_ket_thuc(tgbd,tgdk);
	Normal();
	NODE_SINH_VIEN* k = tim_ma_sv(ds_sv);
	if (k == NULL)
	{
		char c;
		xoa_ben_phai();
		char s[100] = "Ban co chac chan muon thoat ?";
		if(bang_thong_bao(s)==1)
		{
			return;
		}else
		{
			xoa_ben_phai();
			goto BD;
		}
	}
	else
	{
		int luachon =Dang_ki_or_huy_lop(); 
		if(luachon==0)
		{
			BDNHAP:
			Normal();
			bang_vao_ra(50,36);
			int x = 50, y = 6;
			gotoxy(x + 25, y - 2);
			cout << "THONG TIN SINH VIEN";
			rectagle(x, y, 70, 28);
			gotoxy(x + 4, y + 3);
			cout << "MSSV";
			rectagle(x + 15, y + 2, 50, 2);
			gotoxy(x + 18, y + 3); cout << k->data.MASV;
	
			gotoxy(x + 4, y + 6);
			cout << "Ho Ten";
			rectagle(x + 15, y + 5, 50, 2);
			gotoxy(x + 18, y + 6); cout << k->data.HO << " " << k->data.TEN;
	
			gotoxy(x + 4, y + 9);
			cout << "Phai";
			rectagle(x + 15, y + 8, 50, 2);
			gotoxy(x + 18, y + 9); cout << k->data.PHAI;
	
			gotoxy(x + 4, y + 12);
			cout << "SDT";
			rectagle(x + 15, y + 11, 50, 2);
			gotoxy(x + 18, y + 12); cout << k->data.SDT;
	
			gotoxy(x + 4, y + 15);
			cout << "Ma Lop";
			rectagle(x + 15, y + 14, 50, 2);
			gotoxy(x + 18, y + 15); cout << k->data.MALOP;
	
			rectagle(x + 2, y + 17, 66, 8);
			gotoxy(x + 4, y + 19);
			cout << "Nien Khoa  ";
			rectagle(x + 15, y + 18, 50, 2);
	
	
			gotoxy(x + 4, y + 22);
			cout << "Hoc Ky ";
			rectagle(x + 15, y + 21, 50, 2);
			
			
			char nienkhoa[MAX_NIEN_KHOA];
			int hocky=0;
			nienkhoa[0] = '\0';
			int vt = strlen(nienkhoa);
			char tamhk[4];
			tamhk[0] = '\0';
		NIENKHOA:
			{
				HideCursor(false);
				while (1)
				{
					gotoxy(x + 18 + vt, y + 19);
					char c = GetKey();
					if ((c >= '0' && c <= '9') && vt < MAX_NIEN_KHOA)
					{
						if (vt == 3)
						{
							nienkhoa[vt] = c;
							cout << nienkhoa[vt];
							nienkhoa[vt + 1] = '_';
							cout << nienkhoa[vt + 1];
							vt++;
						}
						else
						{
							nienkhoa[vt] = c;
							cout << nienkhoa[vt];
						}
						vt++;
					}
					if (c == key_bkspace && vt > 0)
					{
						vt--;
						nienkhoa[vt] = '\0';
						gotoxy(x + 18 + vt, y + 19);
						cout << " ";
					}
					if (c == key_Down || c == key_tab || c == key_Enter)
					{
						nienkhoa[vt] = '\0';
						vt = strlen(tamhk);
						if (CheckNienKhoa(nienkhoa) == false)
						{
							char k[100] = "Nien khoa > 2000 && <2050";
							Thong_bao(x + 4, y + 26, k);
							Sleep(500);
							gotoxy(x + 4, y + 26);
							cout << "                                    ";
							vt = strlen(nienkhoa);
						}
						else
						{
							goto HK;
						}
					}
					if(c==key_esc)
					{
						if(bang_thong_bao("Ban co chac chan thoat ?")==0)
						{
							xoa_khung_nhap();
							goto BDNHAP;	
						}				
						else{
						xoa_khung_nhap();
						goto BD;
						}
					}
				}
			}
		HK:
			{
				HideCursor(false);
				while (1)
				{
					gotoxy(x + 18 + vt, y + 22);
					char c = GetKey();
					if ((c >= '0' && c <= '9') && vt < 3)
					{
						tamhk[vt] = c;
						cout << tamhk[vt];
						vt++;
					}
					if (c == key_bkspace && vt > 0)
					{
						vt--;
						tamhk[vt] = '\0';
						gotoxy(x + 18 + vt, y + 22);
						cout << " ";
					}
					if (c == key_Up)
					{
						tamhk[vt] = '\0';
						vt = strlen(nienkhoa);
						hocky = chuyen_char_sang_int(tamhk);
						goto NIENKHOA;
					}
					if(c==key_esc)
					{
						if(bang_thong_bao("Ban co chac chan thoat ?")==0)
						{
							xoa_khung_nhap();
							goto BDNHAP;	
						}				
						else{
						xoa_khung_nhap();
						goto BD;
						}
					}
					if (c == key_Enter)
					{
						tamhk[vt] = '\0';
						if (!checkInputTrong(tamhk))
						{
							char k[100] = "Khong duoc de trong !";
							Thong_bao(x + 4, y + 26, k);
							Sleep(1000);
							xoa_thong_bao(x + 4, y + 26, 50);
							goto HK;
						}
						else
						{
							hocky = chuyen_char_sang_int(tamhk);
							xoa_ben_phai();
							goto DANGKI;
						}
					}
				}
			}
		DANGKI:
			{
				while(1)
				{
					char c;
					if (Check_mo_lop_tin_chi(ds_ltc, nienkhoa, hocky)==0)
					{
						char tb[100] = "Khong co lop tin chi phu hop !";
						khung_thong_bao(50,12,60,5,tb);
						Sleep(1000);
						goto BDNHAP;
					}
					else
					{
						xoa_khung_mon_dki();
						khung_mon_dki();
						x = 45, y = 5;
						int row = 0, trang = 0, tongTrang = 0;
						int* a=NULL, n = 0;
						gotoxy(x,y-2);
						cout << "USER: "<< k->data.MASV;
						SetBGColor(12);
						SetColor(15);
						gotoxy(x,y+26);cout<<"Enter : Dang ki ";
						gotoxy(x+30,y+26);cout<<"Tab : Xem cac mon da dang ki ";
						gotoxy(x+65,y+26);cout<<"ESC : Thoat";
						Normal();
						for (int i = 0; i < ds_ltc.sl; i++)//luu cac vi tri thoa man vao mang dong a[n]
						{
							if (_stricmp(ds_ltc.data[i]->NIEN_KHOA, nienkhoa) == 0 && ds_ltc.data[i]->HOC_KY == hocky)
							{
								if (n == 0)
								{
									a = new int;
								}
								else
								{
									cap_vung_nho_in_ds_mon(a, n, n + 1);
								}
								a[n] = i;
								n++;
							}
						}
						
						for (int i = trang * 12; i < 12 + trang * 12 && i < n; i++)
						{
							gotoxy(x + 1, y + row + 1);
							cout << ds_ltc.data[a[i]]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
							gotoxy(x + 13, y + row + 1);
							cout << search_mon_hoc(T, ds_ltc.data[a[i]]->MAMH);
							gotoxy(x + 41, y + row + 1); cout << char(179);
							gotoxy(x + 48, y + row + 1); cout << ds_ltc.data[a[i]]->NHOM;
							gotoxy(x + 56, y + row + 1); cout << char(179);
							gotoxy(x + 63, y + row + 1); cout << ds_ltc.data[a[i]]->tong_sv_dk;
							gotoxy(x + 69, y + row + 1); cout << char(179);
							gotoxy(x + 73, y + row + 1); cout << ds_ltc.data[a[i]]->SO_SV_MAX - ds_ltc.data[a[i]]->tong_sv_dk;
							row++;
						}

						if (ds_ltc.sl < 12)
						{
							trang = 0;
							tongTrang = 1;
						}
						else
						{
							tongTrang = (ds_ltc.sl - 1) / 12 + 1;
						}
						Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);
						int chon = 0;
						while (1)
						{
							if (chon == trang * 12)
							{
								HighLight();
								gotoxy(x + 1, y + 1 + chon - 12 * trang);
								cout << ds_ltc.data[a[chon]]->MAMH;
								gotoxy(x + 13, y + 1 + chon - 12 * trang);
								cout << search_mon_hoc(T, ds_ltc.data[a[chon]]->MAMH);
								gotoxy(x + 48, y + 1+ chon - 12 * trang); cout << ds_ltc.data[a[chon]]->NHOM;
						
								gotoxy(x + 63, y + 1 + chon - 12 * trang); cout << ds_ltc.data[a[chon]]->tong_sv_dk;
						
								gotoxy(x + 73, y + 1+chon - 12 * trang); cout << ds_ltc.data[a[chon]]->SO_SV_MAX - ds_ltc.data[a[chon]]->tong_sv_dk;
								Normal();
							}


							c = GetKey();
							if (c == key_Down && trang < tongTrang && chon < n - 1)
							{
								Normal();
								gotoxy(x + 1, y + chon - 12 * trang + 1);
								cout << ds_ltc.data[a[chon]]->MAMH;
								gotoxy(x + 13, y + chon - 12 * trang + 1);
								cout << search_mon_hoc(T, ds_ltc.data[a[chon]]->MAMH);
								gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->NHOM;

								gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->tong_sv_dk;

								gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->SO_SV_MAX - ds_ltc.data[a[chon]]->tong_sv_dk;
								HighLight();
								chon++;
								gotoxy(x + 1, y + chon - 12 * trang + 1);
								cout << ds_ltc.data[a[chon]]->MAMH;
								gotoxy(x + 13, y + chon - 12 * trang + 1);
								cout << search_mon_hoc(T, ds_ltc.data[a[chon]]->MAMH);
								gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->NHOM;

								gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->tong_sv_dk;

								gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->SO_SV_MAX - ds_ltc.data[a[chon]]->tong_sv_dk;
						  		if (chon == 12 * (trang + 1))
								{
									trang++;
									Normal();
									xoa_khung_mon_dki();
									khung_mon_dki();
									Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);
									row = 0;
									for (int i = trang * 12; i < 12 + trang * 12 && i < n; i++)
									{
										
										gotoxy(x + 1, y + row + 1);
										cout << ds_ltc.data[a[i]]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
										gotoxy(x + 13, y + row + 1);
										cout << search_mon_hoc(T, ds_ltc.data[a[i]]->MAMH);
										gotoxy(x + 41, y + row + 1); cout << char(179);
										gotoxy(x + 48, y + row + 1); cout << ds_ltc.data[a[i]]->NHOM;
										gotoxy(x + 56, y + row + 1); cout << char(179);
										gotoxy(x + 63, y + row + 1); cout << ds_ltc.data[a[i]]->tong_sv_dk;
										gotoxy(x + 69, y + row + 1); cout << char(179);
										gotoxy(x + 73, y + row + 1); cout << ds_ltc.data[a[i]]->SO_SV_MAX - ds_ltc.data[a[i]]->tong_sv_dk;
										row++;
									}
								}
							}
							if (c == key_Up && chon > 0 && trang >= 0)
							{
								Normal();
								gotoxy(x + 1, y + chon - 12 * trang + 1);
								cout << ds_ltc.data[a[chon]]->MAMH;
								gotoxy(x + 13, y + chon - 12 * trang + 1);
								cout << search_mon_hoc(T, ds_ltc.data[a[chon]]->MAMH);
								gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->NHOM;

								gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->tong_sv_dk;

								gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->SO_SV_MAX - ds_ltc.data[a[chon]]->tong_sv_dk;
								HighLight();
								chon--;
								gotoxy(x + 1, y + chon - 12 * trang+ 1);
								cout << ds_ltc.data[a[chon]]->MAMH;
								gotoxy(x + 13, y + chon - 12 * trang + 1);
								cout << search_mon_hoc(T, ds_ltc.data[a[chon]]->MAMH);
								gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->NHOM;

								gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->tong_sv_dk;
								gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_ltc.data[a[chon]]->SO_SV_MAX - ds_ltc.data[a[chon]]->tong_sv_dk;
								if (chon == 11 * trang && chon != 0)
								{
									trang--;
									Normal();
									xoa_khung_mon_dki();
									khung_mon_dki();
									Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);
									row = 0;
									for (int i = trang * 12; i < 12 + trang * 12 && i < n; i++)
									{
										gotoxy(x + 1, y + row + 1 - 12 * trang );
										cout << ds_ltc.data[a[i]]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
										gotoxy(x + 13, y + row + 1 - 12 * trang);
										cout << search_mon_hoc(T, ds_ltc.data[a[i]]->MAMH);
										gotoxy(x + 41, y + row + 1 - 12 * trang); cout << char(179);
										gotoxy(x + 48, y + row + 1 - 12 * trang); cout << ds_ltc.data[a[i]]->NHOM;
										gotoxy(x + 56, y + row + 1 - 12 * trang); cout << char(179);
										gotoxy(x + 63, y + row + 1 - 12 * trang); cout << ds_ltc.data[a[i]]->tong_sv_dk;
										gotoxy(x + 69, y + row + 1 - 12 * trang); cout << char(179);
										gotoxy(x + 73, y + row + 1 - 12 * trang); cout << ds_ltc.data[a[i]]->SO_SV_MAX - ds_ltc.data[a[i]]->tong_sv_dk;
										row++;
									}
									HighLight();
									gotoxy(x + 1, y + chon - 11 * trang + 1);
									cout << ds_ltc.data[a[chon - 11 * trang]]->MAMH;
									gotoxy(x + 13, y + chon - 11 * trang + 1);
									cout << search_mon_hoc(T, ds_ltc.data[a[chon - 11 * trang]]->MAMH);
									gotoxy(x + 48, y + chon - 11 * trang + 1); cout << ds_ltc.data[a[chon - 11 * trang]]->NHOM;
					
									gotoxy(x + 63, y + chon - 11 * trang + 1); cout << ds_ltc.data[a[chon - 11 * trang]]->tong_sv_dk;
					
									gotoxy(x + 73, y + chon - 11 * trang + 1); cout << ds_ltc.data[a[chon - 11 * trang]]->SO_SV_MAX - ds_ltc.data[chon]->tong_sv_dk;
									Normal();
								}
							}
							if (c == key_Enter)
							{
								if(check_tg_dang_ki(tgbd,tgdk)==0)
								{
									char c[30]="DA HET THOI GIAN DANG KI !";
									khung_thong_bao(65,12,50,4,c);
									Sleep(1000);
									goto DANGKI;
								}
								else
								{
									string s = "Ban co chac chan muon dang ki lop ?";
									int luachon=bang_thong_bao(s);
									if (luachon == 0)
									{
										goto DANGKI;
									}
									else
									{
										if (check_sv_da_dk(ds_ltc.data[a[chon]]->DSSV, k->data.MASV) == true)
										{
											ds_ltc.data[a[chon]]->tong_sv_dk++;
											SV_DANG_KY* x = new SV_DANG_KY;
											strcpy(x->MASV, k->data.MASV);
											x->DIEM = -1;
											x->pNext = NULL;
		
											them_sau_ds_sv_dk(ds_ltc.data[a[chon]]->DSSV, x);
											char s[100] = "Ban da dang ki thanh cong !";
											khung_thong_bao(60, 15, 58, 4, s);
											Sleep(500);
											if(ds_ltc.data[a[chon]]->tong_sv_dk>=ds_ltc.data[a[chon]]->SO_SV_MIN) ds_ltc.data[a[chon]]->HUY_LOP=false;
											Ghi_file_lop_tin_chi(ds_ltc);
										}
										else
										{
											char s[100] = "SV da dang ki lop nay roi!";
											khung_thong_bao(60, 15,58, 4,s);
											Sleep(500);
										}	
										goto DANGKI;
									}	
								}
							}
							if (c == key_esc)
							{
								if(bang_thong_bao("Ban co chac chan thoat ?")==1)
								{
									xoa_ben_phai();
									goto BDNHAP;
								}
								else
								{
									break;	
								}
								
							}
							if(c==key_tab)
							{
								ds_mon_sv_da_dki(ds_ltc,ds_lop_sv_dk,T,k->data.MASV,tgbd);	
							}
							goto DANGKI;
							}
						}				
					}
				}
			}	
			delete k;
		}
		else if(luachon==1)
		{
			ds_mon_sv_da_dki(ds_ltc,ds_lop_sv_dk,T,k->data.MASV,tgbd);	
			xoa_ben_phai();
			goto BD;
		}else if(luachon==-1)
		{
			xoa_ben_phai();
			goto BD;
		}
	}
	
//	_getch();
}
//Ket thuc dang ki lop tin chi
//Huy lop tin chi
void Huy_lop_tin_chi(DS_LOP_TIN_CHI& ds_ltc, DS_LOP_TIN_CHI& ds_lop_sv_dk, int vitri, char* masv)
{
	if (ds_lop_sv_dk.sl == 0) return;
	SV_DANG_KY* g = new SV_DANG_KY;
	int vtxoa = 0;
	for (int i = 0;i < ds_ltc.sl;i++)
	{
		if (ds_lop_sv_dk.data[vitri]->MALOPTC == ds_ltc.data[i]->MALOPTC)
		{
			vtxoa = i;
			break;
		}
	}

	for (SV_DANG_KY* k = ds_ltc.data[vtxoa]->DSSV.pHead;k != NULL;k = k->pNext)
	{
		if (strcmp(masv, k->MASV) == 0)
		{
			if (k == ds_ltc.data[vtxoa]->DSSV.pHead)
			{
				g = ds_ltc.data[vtxoa]->DSSV.pHead;
				ds_ltc.data[vtxoa]->DSSV.pHead = ds_ltc.data[vtxoa]->DSSV.pHead->pNext;
				ds_ltc.data[vtxoa]->tong_sv_dk--;
				delete g;
				break;
			}
			else if (k == ds_ltc.data[vtxoa]->DSSV.pTail)
			{
				g->pNext = NULL;
				delete ds_ltc.data[vtxoa]->DSSV.pTail;
				ds_ltc.data[vtxoa]->DSSV.pTail = g;
				ds_ltc.data[vtxoa]->tong_sv_dk--;
				break;
			}
			else
			{
				g->pNext = k->pNext;
				delete k;
				k = g->pNext;
				ds_ltc.data[vtxoa]->tong_sv_dk--;
				break;
			}
		}
		g = k;
	}
	if(ds_ltc.data[vtxoa]->tong_sv_dk < ds_ltc.data[vtxoa]->SO_SV_MIN) ds_ltc.data[vtxoa]->HUY_LOP=true;
	Ghi_file_lop_tin_chi(ds_ltc);
	//	Xoa_lop_tin_chi(ds_lop_sv_dk,vitri);
	for (int i = vitri; i < ds_lop_sv_dk.sl - 1; i++)
	{
		ds_lop_sv_dk.data[i]->DSSV = ds_lop_sv_dk.data[i + 1]->DSSV;
		ds_lop_sv_dk.data[i]->HOC_KY = ds_lop_sv_dk.data[i + 1]->HOC_KY;
		ds_lop_sv_dk.data[i]->HUY_LOP = ds_lop_sv_dk.data[i + 1]->HUY_LOP;
		ds_lop_sv_dk.data[i]->MALOPTC = ds_lop_sv_dk.data[i + 1]->MALOPTC;
		strcpy(ds_lop_sv_dk.data[i]->MAMH, ds_lop_sv_dk.data[i + 1]->MAMH);         
		ds_lop_sv_dk.data[i]->NHOM = ds_lop_sv_dk.data[i + 1]->NHOM;
		strcpy(ds_lop_sv_dk.data[i]->NIEN_KHOA, ds_lop_sv_dk.data[i + 1]->NIEN_KHOA);
		ds_lop_sv_dk.data[i]->SO_SV_MAX = ds_lop_sv_dk.data[i + 1]->SO_SV_MAX;
		ds_lop_sv_dk.data[i]->SO_SV_MIN = ds_lop_sv_dk.data[i + 1]->SO_SV_MIN;
		ds_lop_sv_dk.data[i]->tong_sv_dk = ds_lop_sv_dk.data[i + 1]->tong_sv_dk;
	}
	delete(ds_lop_sv_dk.data[ds_lop_sv_dk.sl - 1]);
	ds_lop_sv_dk.sl--;
	
}

void ds_mon_sv_da_dki(DS_LOP_TIN_CHI& ds_ltc, DS_LOP_TIN_CHI& ds_lop_sv_dk, TREE_MON_HOC* T, char* masv,int tgbd,bool mode,int nienkhoa,int hocki)
{
	system("cls");
	timeDK tgdk;
	in_tg_ket_thuc(tgbd,tgdk);
	Normal();
	ds_lop_sv_dk.sl = 0;
	for (int i = 0;i < ds_ltc.sl;i++)
	{
		for (SV_DANG_KY* k = ds_ltc.data[i]->DSSV.pHead;k != NULL;k = k->pNext)
		{
			if ((strcmp(masv, k->MASV) == 0)
				LOP_TIN_CHI *ltc = new LOP_TIN_CHI;
				ltc->DSSV = ds_ltc.data[i]->DSSV;
				ltc->HOC_KY = ds_ltc.data[i]->HOC_KY;
				ltc->HUY_LOP = ds_ltc.data[i]->HUY_LOP;
				ltc->MALOPTC = ds_ltc.data[i]->MALOPTC;
				strcpy(ltc->MAMH, ds_ltc.data[i]->MAMH);
				strcpy(ltc->NIEN_KHOA, ds_ltc.data[i]->NIEN_KHOA);
				ltc->NHOM = ds_ltc.data[i]->NHOM;
				ltc->SO_SV_MAX = ds_ltc.data[i]->SO_SV_MAX;
				ltc->SO_SV_MIN = ds_ltc.data[i]->SO_SV_MIN;
				ltc->tong_sv_dk = ds_ltc.data[i]->tong_sv_dk;
				them_vao_ds_lop_tin_chi(ds_lop_sv_dk, ltc);
				break;
			}
		}
	}
	Ve_lai_sau_khi_sua_ltc(itemloptinchi, 4);
	while (1)
	{
		
		int x = 45, y = 5,row = 0, trang = 0, tongTrang = 0;
		SetBGColor(12);
		SetColor(15);
		gotoxy(x,y+26);cout<<"Enter : Huy Lop ";
		
		gotoxy(x+65,y+26);cout<<"ESC : Thoat";
		Normal();
		khung_mon_dki();
		gotoxy(x, y - 2);
		cout << "USER: " << masv;
		if (ds_lop_sv_dk.sl == 0)
		{
			gotoxy(75, 31);
			cout << "DANH SACH TRONG !!!";
			Sleep(1000);
			break;
		}
		char c;
		for (int i = trang * 12; i < 12 + trang * 12 && i < ds_lop_sv_dk.sl; i++)
		{
			gotoxy(x + 1, y + row + 1);
			cout << ds_lop_sv_dk.data[i]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
			gotoxy(x + 13, y + row + 1);
			cout << search_mon_hoc(T, ds_lop_sv_dk.data[i]->MAMH);
			gotoxy(x + 41, y + row + 1); cout << char(179);
			gotoxy(x + 48, y + row + 1); cout << ds_lop_sv_dk.data[i]->NHOM;
			gotoxy(x + 56, y + row + 1); cout << char(179);
			gotoxy(x + 63, y + row + 1); cout << ds_lop_sv_dk.data[i]->tong_sv_dk;
			gotoxy(x + 69, y + row + 1); cout << char(179);
			gotoxy(x + 73, y + row + 1); cout << ds_lop_sv_dk.data[i]->SO_SV_MAX - ds_lop_sv_dk.data[i]->tong_sv_dk;
			row++;
		}
		
		if (ds_lop_sv_dk.sl < 12)
		{
			trang = 0;
			tongTrang = 1;
		}
		else
		{
			tongTrang = (ds_lop_sv_dk.sl - 1) / 12 + 1;
		}
		Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);

		int chon = 0;
		while (1)
		{
			
			if (chon == trang * 12)
			{
				HighLight();
				gotoxy(x + 1, y + 1 + chon - 12 * trang);
				cout << ds_lop_sv_dk.data[chon]->MAMH;
				gotoxy(x + 13, y + 1 + chon - 12 * trang);
				cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon]->MAMH);
				gotoxy(x + 48, y + 1+ chon - 12 * trang); cout << ds_lop_sv_dk.data[chon]->NHOM;
		
				gotoxy(x + 63, y + 1 + chon - 12 * trang); cout << ds_lop_sv_dk.data[chon]->tong_sv_dk;
		
				gotoxy(x + 73, y + 1+chon - 12 * trang); cout << ds_lop_sv_dk.data[chon]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
				Normal();
			}
			c = GetKey();
			if (c == key_Down && trang < tongTrang && chon < ds_lop_sv_dk.sl - 1)
			{
				Normal();
				gotoxy(x + 1, y + chon - 12 * trang + 1);
				cout << ds_lop_sv_dk.data[chon]->MAMH;
				gotoxy(x + 13, y + chon - 12 * trang + 1);
				cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon]->MAMH);
				gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->NHOM;

				gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->tong_sv_dk;

				gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
				HighLight();
				chon++;
				gotoxy(x + 1, y + chon - 12 * trang + 1);
				cout << ds_lop_sv_dk.data[chon]->MAMH;
				gotoxy(x + 13, y + chon - 12 * trang + 1);
				cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon]->MAMH);
				gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->NHOM;

				gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->tong_sv_dk;

				gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
		  		if (chon == 12 * (trang + 1))
				{
					trang++;
					Normal();
					xoa_khung_mon_dki();
					khung_mon_dki();
					Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);
					row = 0;
					for (int i = trang * 12; i < 12 + trang * 12 && i < ds_lop_sv_dk.sl; i++)
					{
						
						gotoxy(x + 1, y + row + 1);
						cout << ds_lop_sv_dk.data[i]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
						gotoxy(x + 13, y + row + 1);
						cout << search_mon_hoc(T, ds_lop_sv_dk.data[i]->MAMH);
						gotoxy(x + 41, y + row + 1); cout << char(179);
						gotoxy(x + 48, y + row + 1); cout << ds_lop_sv_dk.data[i]->NHOM;
						gotoxy(x + 56, y + row + 1); cout << char(179);
						gotoxy(x + 63, y + row + 1); cout << ds_lop_sv_dk.data[i]->tong_sv_dk;
						gotoxy(x + 69, y + row + 1); cout << char(179);
						gotoxy(x + 73, y + row + 1); cout << ds_lop_sv_dk.data[i]->SO_SV_MAX - ds_lop_sv_dk.data[i]->tong_sv_dk;
						row++;
					}
				}
			}
			if (c == key_Up && chon > 0 && trang >= 0)
			{
				Normal();
				gotoxy(x + 1, y + chon - 12 * trang + 1);
				cout << ds_lop_sv_dk.data[chon]->MAMH;
				gotoxy(x + 13, y + chon - 12 * trang + 1);
				cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon]->MAMH);
				gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->NHOM;

				gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->tong_sv_dk;

				gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
				HighLight();
				chon--;
				gotoxy(x + 1, y + chon - 12 * trang+ 1);
				cout << ds_lop_sv_dk.data[chon]->MAMH;
				gotoxy(x + 13, y + chon - 12 * trang + 1);
				cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon]->MAMH);
				gotoxy(x + 48, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->NHOM;

				gotoxy(x + 63, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->tong_sv_dk;
				gotoxy(x + 73, y + chon - 12 * trang + 1); cout << ds_lop_sv_dk.data[chon]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
				if (chon == 11 * trang && chon != 0)
				{
					trang--;
					Normal();
					xoa_khung_mon_dki();
					khung_mon_dki();
					Hien_thi_trang(trang + 1, tongTrang, x + 70, y + 28);
					row = 0;
					for (int i = trang * 12; i < 12 + trang * 12 && i < ds_lop_sv_dk.sl; i++)
					{
						gotoxy(x + 1, y + row + 1 - 12 * trang );
						cout << ds_lop_sv_dk.data[i]->MAMH; gotoxy(x + 11, y + row + 1); cout << char(179);
						gotoxy(x + 13, y + row + 1 - 12 * trang);
						cout << search_mon_hoc(T, ds_lop_sv_dk.data[i]->MAMH);
						gotoxy(x + 41, y + row + 1 - 12 * trang); cout << char(179);
						gotoxy(x + 48, y + row + 1 - 12 * trang); cout << ds_lop_sv_dk.data[i]->NHOM;
						gotoxy(x + 56, y + row + 1 - 12 * trang); cout << char(179);
						gotoxy(x + 63, y + row + 1 - 12 * trang); cout << ds_lop_sv_dk.data[i]->tong_sv_dk;
						gotoxy(x + 69, y + row + 1 - 12 * trang); cout << char(179);
						gotoxy(x + 73, y + row + 1 - 12 * trang); cout << ds_lop_sv_dk.data[i]->SO_SV_MAX - ds_lop_sv_dk.data[i]->tong_sv_dk;
						row++;
					}
					HighLight();
					gotoxy(x + 1, y + chon - 11 * trang + 1);
					cout << ds_lop_sv_dk.data[chon - 11 * trang]->MAMH;
					gotoxy(x + 13, y + chon - 11 * trang + 1);
					cout << search_mon_hoc(T, ds_lop_sv_dk.data[chon - 11 * trang]->MAMH);
					gotoxy(x + 48, y + chon - 11 * trang + 1); cout << ds_lop_sv_dk.data[chon - 11 * trang]->NHOM;
	
					gotoxy(x + 63, y + chon - 11 * trang + 1); cout << ds_lop_sv_dk.data[chon - 11 * trang]->tong_sv_dk;
	
					gotoxy(x + 73, y + chon - 11 * trang + 1); cout << ds_lop_sv_dk.data[chon - 11 * trang]->SO_SV_MAX - ds_lop_sv_dk.data[chon]->tong_sv_dk;
					Normal();
				}
			}
			if (c == key_Enter && ds_lop_sv_dk.sl > 0 )
			{
				if(check_tg_dang_ki(tgbd,tgdk)==1)
				{
					if(bang_thong_bao("Ban co chac chan muon huy lop ?")==1) 
					{
						Huy_lop_tin_chi(ds_ltc, ds_lop_sv_dk, chon, masv);	
					}
					break;	
				}
				else
				{
					char c[30]="DA HET THOI GIAN HUY LOP !";
					khung_thong_bao(65,12,50,4,c);
					Sleep(1000);
					break;
				}
			}
			if (c == key_esc)
			{
				if(bang_thong_bao("Ban co chac chan thoat ?")==1) return;
				break;
			}
		}
		row=0;
	}
}
