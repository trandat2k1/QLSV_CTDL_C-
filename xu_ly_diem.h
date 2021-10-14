#pragma once
#include "xu_ly_sinh_vien.h"
#include "handleFile.h"
using namespace std;

int khung_check_diem(DS_LOP_TIN_CHI);
void get_SV_DK(DS_SV_DANG_KY, DS_SINH_VIEN, SV_DANG_KY*&, NODE_SINH_VIEN*&, int);
void HighLight_SV_DK(SV_DANG_KY*, NODE_SINH_VIEN*, int, int, int);
void Normal_SV_DK(SV_DANG_KY*, NODE_SINH_VIEN*, int, int, int);
int tong_so_sv_dk(DS_SV_DANG_KY);
void In_Diem(DS_LOP_TIN_CHI&, DS_SV_DANG_KY&, DS_SINH_VIEN, bool);
int dem_so_chu_so(int);


void menu_diem()
{
	DS_LOP_TIN_CHI ds_ltc;
	int n;
	doc_file_ltc(ds_ltc, n);
	DS_SINH_VIEN ds_sv;
	Doc_file_sinh_vien(ds_sv);
	int i = khung_check_diem(ds_ltc);
	if(i != -1)
	{
		In_Diem(ds_ltc, ds_ltc.data[i]->DSSV, ds_sv, true);
	}
	HideCursor(true);
}

int khung_check_diem(DS_LOP_TIN_CHI ds_ltc)
{
	HideCursor(false);
	int x = 70, y = 12, width = 30, heigh = 2;
	int luachon = 0;
	int a, b, c, d;
	char kitu;
	char mamh[MAX_MAMH];
	char nien_khoa[MAX_NIEN_KHOA];
	int hoc_ki = 0;
	int nhom = 0;
reset:
	xoa_man_hinh();
	a = 0; b = 0; c = 0; d = 0;
	SetBGColor(color_darkyellow);
	SetColor(color_darkyellow);
	rectagle(x - 5, y - 3, 60, 16);
	char menu[item_mh][30] = {
		"Ma mon hoc",
		"Nien khoa",
		"Hoc ki",
		"Nhom"
	};
	for (int i = 0, j = 0; i < item_mh; i++, j += 3) {
		gotoxy(x, y + j);
		SetColor(color_black);
		SetBGColor(color_darkyellow);
		cout << menu[i];
		SetBGColor(color_black);
		SetColor(color_white);
		rectagle(x + 20, y + j - 1, width, heigh);
	}
	Normal();
Mamh:
	gotoxy(x + 22 + a, y);
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_esc) return -1;
		else if (!dieukien(kitu) && a < MAX_MAMH)
		{
			if (chu_so(kitu)) {
				mamh[a] = chu_in_hoa(kitu);
				cout << mamh[a++];
			}
			else if (kitu == key_Space && mamh[a - 1] != key_Space && a != 0) {
				mamh[a++] = kitu;
				cout << kitu;
			}
		}
		else if (kitu == key_bkspace && a > 0)
		{
			mamh[--a] = ' ';
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Nien_khoa;
		else if (kitu == key_Up) goto Nhom;
		else if (kitu == key_Enter) goto Duyet;
	}
Nien_khoa:
	gotoxy(x + 22 + b, y + 3);
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_esc) return -1;
		else if (!dieukien(kitu) && b < MAX_NIEN_KHOA)
		{
			if (so(kitu)) {
				if (b == 4)
				{
					nien_khoa[b] = char(95);
					cout << nien_khoa[b++];
				}
				nien_khoa[b] = kitu;
				cout << nien_khoa[b++];
			}
			else if (kitu == key_Space && nien_khoa[b - 1] != key_Space && b != 0) {
				nien_khoa[b++] = kitu;
				cout << kitu;
			}
		}
		else if (kitu == key_bkspace && b > 0)
		{
			nien_khoa[--b] = ' ';
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Hoc_ki;
		else if (kitu == key_Up) goto Mamh;
		else if (kitu == key_Enter) goto Duyet;
	}
Hoc_ki:
	gotoxy(x + 22 + c, y + 6);
	while (true)
	{
		kitu = GetKey();
		if (!dieukien(kitu) && so(kitu) && c < 1)
		{
			c++;
			hoc_ki = int(kitu - 48);
			cout << hoc_ki;
		}
		else if (kitu == key_bkspace && c > 0)
		{
			c--;
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Nhom;
		else if (kitu == key_Up) goto Nien_khoa;
		else if (kitu == key_esc) return -1;
		else if (kitu == key_Enter) goto Duyet;
	}

Nhom:
	gotoxy(x + 22 + d, y + 9);
	while (true)
	{
		kitu = GetKey();
		if (!dieukien(kitu) && so(kitu) && d < 1)
		{
			d++;
			nhom = int(kitu - 48);
			cout << nhom;
		}
		else if (kitu == key_bkspace && d > 0)
		{
			d--;
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Mamh;
		else if (kitu == key_Up) goto Hoc_ki;
		else if (kitu == key_esc) return -1;
		else if (kitu == key_Enter) goto Duyet;
	}
Duyet:
	if (a == 0 || b == 0 || c == 0 || d == 0)
	{
		gotoxy(60, 30);
		HideCursor(true);
		cout << "Khong thanh cong!!! Ban can dien du thong tin.";
		Sleep(1000);
		gotoxy(60, 30);
		cout << "                                                  ";
		HideCursor(false);
		if (a == 0) goto Mamh;
		else if (b == 0) goto Nien_khoa;
		else if (c == 0) goto Hoc_ki;
		else if (d == 0) goto Nhom;
	}
	else
	{
		if (a < MAX_MAMH)
		{
			mamh[a] = '\0';
			nien_khoa[b] = '\0';
		}
		else
		{
			mamh[MAX_MAMH - 1] = '\0';
			nien_khoa[MAX_NIEN_KHOA - 1] = '\0';
		}
		for (int i = 0; i < ds_ltc.sl;i++)
		{
			if (strcmp(ds_ltc.data[i]->MAMH, mamh) == 0 && strcmp(ds_ltc.data[i]->NIEN_KHOA, nien_khoa) == 0 && ds_ltc.data[i]->HOC_KY == hoc_ki && ds_ltc.data[i]->NHOM == nhom)
			{
				return i;
			}
		}
		Normal();
		gotoxy(80, 28);
		cout << "Thong tin khong ton tai !!!";
		Sleep(1000);
		gotoxy(80, 28);
		cout << "                            ";
		goto Mamh;
	}
}

void get_SV_DK(DS_SV_DANG_KY ds_sv_dk, DS_SINH_VIEN ds_sv, SV_DANG_KY*& p, NODE_SINH_VIEN*& p1, int vt)
{
	p = ds_sv_dk.pHead;
	for (int i = 0; i < vt; i++, p = p->pNext);
	for (p1 = ds_sv.pHead; strcmp(p1->data.MASV, p->MASV) != 0; p1 = p1->pNext);
}

void HighLight_SV_DK(SV_DANG_KY* p1, NODE_SINH_VIEN* p, int x, int y, int stt)
{
	for (int i = 0; i <= 86;i++)
	{
		BGHightLight();
		gotoxy(x + i, y);
		cout << ' ';
	}
	SetColor(color_black);

	gotoxy(x + 9, y);	cout << char(179) << "              " << char(179) << "                               " << char(179) << "              " << char(179);
	gotoxy(x + 2 + 1, y);		cout << stt;
	gotoxy(x + 9 + 3, y);	cout << p->data.MASV;
	gotoxy(x + 24 + 3, y);	cout << p->data.HO;
	gotoxy(x + 56 + 3, y);	cout << p->data.TEN;
	if (p1->DIEM != -1) {
		gotoxy(x + 71 + 3, y);	cout << p1->DIEM;
	}
	Normal();
}

void Normal_SV_DK(SV_DANG_KY* p1, NODE_SINH_VIEN* p, int x, int y, int stt)
{
	for (int i = 0; i <= 86;i++)
	{
		Normal();
		gotoxy(x + i, y);
		cout << ' ';
	}
	Normal();
	gotoxy(x + 9, y);	cout << char(179) << "              " << char(179) << "                               " << char(179) << "              " << char(179);
	gotoxy(x + 2 + 1, y);		cout << stt;
	gotoxy(x + 9 + 3, y);	cout << p->data.MASV;
	gotoxy(x + 24 + 3, y);	cout << p->data.HO;
	gotoxy(x + 56 + 3, y);	cout << p->data.TEN;
	if (p1->DIEM != -1) {
		gotoxy(x + 71 + 3, y);	cout << p1->DIEM;
	}
}

int tong_so_sv_dk(DS_SV_DANG_KY ds_sv_dk)
{
	int count = 0;
	for (SV_DANG_KY* i = ds_sv_dk.pHead; i != NULL; i = i->pNext, count++);
	return count;
}

void In_Diem(DS_LOP_TIN_CHI& ds_ltc, DS_SV_DANG_KY& ds_sv_dk, DS_SINH_VIEN ds_sv, bool mode)
{
	int stt = 1, x = 52, y = 8, trang = 1, luachon = 0;
	int tong_trang = so_trang(1.0 * tong_so_sv_dk(ds_sv_dk) / 20);
	NODE_SINH_VIEN* sv;
	SV_DANG_KY* sv_dk;
	gotoxy(50, 34);
	cout << "F1: Sua diem";
chuyen_trang:
	xoa_man_hinh();
	Normal();
	HideCursor(true);
	gotoxy(135, 32);
	cout << trang << '/' << tong_trang;
	rectagle(x - 5, y - 2, 95, 25);
	for (int i = 0; i <= 85;i++)
	{
		HideCursor(true);
		SetBGColor(color_darkwhite);
		gotoxy(x + i, y);
		cout << ' ';
	}
	SetColor(color_black);
	gotoxy(x + 2, y);	cout << "STT" << " ";
	gotoxy(x + 9, y);	cout << char(179) << "  MASV" << "  ";
	gotoxy(x + 24, y);	cout << char(179) << "  HO" << "                     ";
	gotoxy(x + 56, y);	cout << char(179) << "  TEN" << "    ";
	gotoxy(x + 71, y);	cout << char(179) << "  DIEM";
	Normal();
	gotoxy(x + 9, y + 1);	cout << char(179) << "              " << char(179) << "                               " << char(179) << "              " << char(179);

	get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - 1);
	int y1 = 1, count = 0;
	for (SV_DANG_KY* i = sv_dk; i != NULL && count < 20; i = i->pNext)
	{
		for (NODE_SINH_VIEN* j = ds_sv.pHead; j != NULL; j = j->pNext)
			if (strcmp(j->data.MASV, i->MASV) == 0)
			{
				count++;
				gotoxy(x + 9, y + (++y1));	cout << char(179) << "              " << char(179) << "                               " << char(179) << "              " << char(179);
				gotoxy(x + 2 + 1, y + y1);	cout << stt++;
				gotoxy(x + 9 + 3, y + y1);	cout << j->data.MASV;
				gotoxy(x + 24 + 3, y + y1);	cout << j->data.HO;
				gotoxy(x + 56 + 3, y + y1);	cout << j->data.TEN;
				if (i->DIEM != -1) {
					gotoxy(x + 71 + 3, y + y1);	cout << i->DIEM;
				}
				break;
			}
	}
	if (mode == true)
	{
		get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - count - 1);
		HighLight_SV_DK(sv_dk, sv, x, y + 2, stt - count);
	}
	char kitu;
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_Down && mode == true)
		{
			luachon++;
			if (luachon >= count) {
				luachon = count - 1;
			}
			else
			{
				get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - count - 1 + luachon - 1);
				Normal_SV_DK(sv_dk, sv, x, y + 2 + luachon - 1, stt - count - 1 + luachon);
				get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - count - 1 + luachon);
				HighLight_SV_DK(sv_dk, sv, x, y + 2 + luachon, stt - count - 1 + luachon + 1);
			}
		}
		else if (kitu == key_Up && mode == true)
		{
			luachon--;
			if (luachon < 0) {
				luachon = 0;
			}
			else
			{
				get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - count - 1 + luachon + 1);
				Normal_SV_DK(sv_dk, sv, x, y + 2 + luachon + 1, stt - count + luachon + 1);
				get_SV_DK(ds_sv_dk, ds_sv, sv_dk, sv, stt - count - 1 + luachon);
				HighLight_SV_DK(sv_dk, sv, x, y + 2 + luachon, stt - count + luachon);
			}
		}
		else if (kitu == key_Right)
		{
			trang += 1;
			if (trang > tong_trang)	trang = tong_trang;
			else
			{
				luachon = 0;
				Normal();
				goto chuyen_trang;
			}
		}
		else if (kitu == key_Left)
		{
			trang -= 1;
			if (trang < 1)	trang = 1;
			else
			{
				luachon = 0;
				stt -= (count + 20);
				Normal();
				goto chuyen_trang;
			}
		}
		else if (kitu == key_F1 && mode == true)
		{
			HideCursor(false);
			SetBGColor(6);

			gotoxy(x + 71 + 1, y + 2 + luachon);
			cout << "          ";
			int a = 0;
			if (sv_dk->DIEM > 0)
			{
				gotoxy(x + 71 + 3, y + 2 + luachon);
				cout << sv_dk->DIEM;
				if (sv_dk->DIEM == 10) a = 2;
				else a = 1;
			}
		reset:
			gotoxy(x + 71 + 3 + a, y + 2 + luachon);
			while (true)
			{
				kitu = GetKey();
				if (!dieukien(kitu) && so(kitu) && a < 2)
				{
					a++;
					if (sv_dk->DIEM < 0)
						sv_dk->DIEM = 0;
					sv_dk->DIEM = sv_dk->DIEM * 10 + int(kitu - 48);
					cout << kitu;
				}
				else if (kitu == key_bkspace && a > 0)
				{
					a = 0;
					sv_dk->DIEM = 0;
					gotoxy(x + 71 + 3, y + 2 + luachon);
					cout << "  ";
					gotoxy(x + 71 + 3, y + 2 + luachon);
				}
				else if (kitu == key_Enter)
				{
					if (sv_dk->DIEM > 10)
					{
						Normal();
						gotoxy(70, 33);
						cout << "Diem he so 10, ban vui long nhap lai !!!";
						Sleep(1500);
						gotoxy(70, 33);
						cout << "                                         ";
						SetBGColor(6);
						goto reset;
					}
					else
					{
						BGHightLight();
						HideCursor(true);
						gotoxy(x + 71 + 1, y + 2 + luachon);
						cout << "          ";
						if (a == 0) sv_dk->DIEM = -1;
						else
						{
							gotoxy(x + 71 + 3, y + 2 + luachon);
							cout << sv_dk->DIEM;
						}
						Ghi_file_lop_tin_chi(ds_ltc);
						Normal();
						break;
					}
				}
			}
		}
		else if (kitu == key_esc)
		{
			Normal();
			gotoxy(50, 34);
			cout << "             ";
			return;
		}
	}
}
