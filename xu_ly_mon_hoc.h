#pragma once
#include "ctdl.h"
#include "handleFile.h"
#include <ctime>
#include "xu_ly_sinh_vien.h"

using namespace std;
#define MAX 10000
#define item_mh 4
#define STACKSIZE 500

void them_sua_mon_hoc(TREE_MON_HOC*&, TREE_MON_HOC*, bool);
void in_ds_mon_hoc(TREE_MON_HOC*&, bool);
int dem_mon_hoc(TREE_MON_HOC*);
void ma_mon_hoc(TREE_MON_HOC*, char*);
TREE_MON_HOC* get_mon_hoc(TREE_MON_HOC*,TREE_MON_HOC*[], int&, int);
void Normal_mon_hoc(TREE_MON_HOC*, int, int, int);
void HighLight_mon_hoc(TREE_MON_HOC*, int, int, int);
void tao_khung_mon_hoc(TREE_MON_HOC*&);
void sap_xep_mon_hoc(TREE_MON_HOC*, MON_HOC* []);
void random_id(int[]);

void menu_monhoc()
{
	TREE_MON_HOC* T = NULL;
	random_id(ID_MONHOC);
	Doc_file_mon_hoc(T);
	tao_khung_mon_hoc(T);
}

void tao_khung_mon_hoc(TREE_MON_HOC*& T)
{
	system("cls");
	gotoxy(10, 2);
	SetBGColor(color_darkred);
	cout << "XU LY MON HOC";
	Normal();
	for (int i = 0; i <= 37;i++)
	{
		gotoxy(35, i);
		cout << char(179);
	}
	int x = 5, y = 8, d = 0, width = 24, heigh = 4;
	HideCursor(true);
	char menu[item][30] = {
		"In danh sach mon hoc",
		"   Them mon hoc",
		"  Xoa\\Sua mon hoc"
	};
	for (int i = 0; i < item; i++) {
		rectagle(x, y + d, width, heigh);
		gotoxy(x + 1, y + d + 2);
		d += 7;
		cout << menu[i];
	}
	HighLight();
	rectagle(x, y , width, heigh);
	gotoxy(x + 1, y + 2);
	cout << menu[0];

	d = 7;
	int luachon = 0;
	char kitu;
	gotoxy(x, y);
	while (true)
	{
		xoa_man_hinh();
		kitu = GetKey();
		if (kitu == key_esc) return;
		if (kitu == key_Down)
		{
			luachon++;
			if (luachon >= item)
			{
				luachon = 0;
				y -= d * (item - 1);

				Normal();
				rectagle(x, y + d * (item - 1), width, heigh);
				gotoxy(x + 1, y + d * (item - 1) + 2);
				cout << menu[item - 1];

				HighLight();
				rectagle(x, y, width, heigh);
				gotoxy(x + 1, y + 2);
				cout << menu[luachon];
			}
			else {
				y += d;

				Normal();
				rectagle(x, y - d, width, heigh);
				gotoxy(x + 1, y - d + 2);
				cout << menu[luachon - 1];

				HighLight();
				rectagle(x, y, width, heigh);
				gotoxy(x + 1, y + 2);
				cout << menu[luachon];
			}
		}
		else if (kitu == key_Up)
		{
			luachon--;
			if (luachon < 0)
			{
				luachon = item - 1;
				y += d * (item - 1);

				Normal();
				rectagle(x, y - d * (item - 1), width, heigh);
				gotoxy(x + 1, y - d * (item - 1) + 2);
				cout << menu[0];

				HighLight();
				rectagle(x, y, width, heigh);
				gotoxy(x + 1, y + 2);
				cout << menu[luachon];
			}
			else {
				y -= d;

				Normal();
				rectagle(x, y + d, width, heigh);
				gotoxy(x + 1, y + d + 2);
				cout << menu[luachon + 1];

				HighLight();
				rectagle(x, y, width, heigh);
				gotoxy(x + 1, y + 2);
				cout << menu[luachon];
			}
		}
		else if (kitu == key_Enter)
		{
			if (luachon == 0)
			{
				//in ds mon hoc
				in_ds_mon_hoc(T, false);
			}
			else if (luachon == 1)
			{
				//them mon hoc
				TREE_MON_HOC* p = new TREE_MON_HOC;
				them_sua_mon_hoc(T, p, false);
			}
			else if (luachon == 2)
			{
				//hieu chinh mon hoc

				in_ds_mon_hoc(T,true);
			}
		}
	}
}

void sap_xep_mon_hoc(TREE_MON_HOC* T, MON_HOC* ds_thu_tu_mon_hoc[])
{
	TREE_MON_HOC* p = T;
	TREE_MON_HOC* STACK[STACKSIZE];
	int sp = -1;
	int i = 0;
	while (p != NULL)
	{
		ds_thu_tu_mon_hoc[i] = new MON_HOC;
		strcpy(ds_thu_tu_mon_hoc[i]->MAMH, p->data.MAMH);
		strcpy(ds_thu_tu_mon_hoc[i]->TENMH, p->data.TENMH);
		ds_thu_tu_mon_hoc[i]->STCLT = p->data.STCLT;
		ds_thu_tu_mon_hoc[i++]->STCTH = p->data.STCTH;

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

	for (int j = 0; j < i-1;j++)
		for (int k = j + 1;k < i;k++)
			if (!so_sanh(ds_thu_tu_mon_hoc[j]->TENMH, ds_thu_tu_mon_hoc[k]->TENMH))
			{
				mon_hoc *temp = ds_thu_tu_mon_hoc[k];
				ds_thu_tu_mon_hoc[k] = ds_thu_tu_mon_hoc[j];
				ds_thu_tu_mon_hoc[j] = temp;
			}
}

void ma_mon_hoc(TREE_MON_HOC* T, char *a)
{
	int temp;
	do{
	for (int i = 6; i >= 3;i--)
	{
		temp = rand()% 9 + 1;
		a[i] = char(temp + 48);
	}	
	}while(check_mamh(a));
	a[0] = 'I';
	a[1] = 'N';
	a[2] = 'T';
	a[7] = '\0';
}

void them_sua_mon_hoc(TREE_MON_HOC*& T, TREE_MON_HOC* p, bool mode)
{
	HideCursor(false);
	int x = 70, y = 13, width = 30, heigh = 2;
	int luachon = 0;
	char kitu;
	char B[MAX_TENMH];
	int C, D;
reset:
	xoa_man_hinh();
	SetBGColor(color_darkyellow);
	SetColor(color_darkyellow);
	rectagle(x - 5, y - 3, 60, 15);
	char menu[item_mh][30] = {
		"Ma mon hoc",
		"Ten mon hoc",
		"So TCLT",
		"So TCTH"
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
	int b = 0, c = 0, d = 0;
	if (mode == true)
	{
		gotoxy(x + 22, y);		cout << p->data.MAMH;
		gotoxy(x + 22, y + 3);	cout << p->data.TENMH;
		gotoxy(x + 22, y + 6);	cout << p->data.STCLT;
		gotoxy(x + 22, y + 9);	cout << p->data.STCTH;
		b = strlen(p->data.TENMH);
		c = 1;
		d = 1;
		strcpy(B, p->data.TENMH);
		C = p->data.STCLT;
		D = p->data.STCTH;
	}
	else {
		gotoxy(x + 22, y);
		ma_mon_hoc(T, p->data.MAMH);
		cout << p->data.MAMH;
	}
	HideCursor(false);
	goto Tenmh;
Tenmh:
	gotoxy(x + 22 + b, y + 3);
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_esc) goto Out;
		else if (!dieukien(kitu) && b < MAX_TENMH)
		{

			if (chu_so(kitu)) {
				p->data.TENMH[b] = chu_in_hoa(kitu);
				cout << p->data.TENMH[b++];
			}
			else if (kitu == key_Space && p->data.TENMH[b - 1] != key_Space && b != 0) {
				p->data.TENMH[b++] = kitu;
				cout << kitu;
			}
		}
		else if (kitu == key_bkspace && b > 0)
		{
			p->data.TENMH[--b] = ' ';
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Stclt;
		else if (kitu == key_Up) goto Stcth;
		else if (kitu == key_Enter) goto Them;
	}
Stclt:
	gotoxy(x + 22 + c, y + 6);
	while (true)
	{
		kitu = GetKey();
		if (!dieukien(kitu) && so(kitu) && c < 1)
		{
			c++;
			p->data.STCLT = int(kitu - 48);
			cout << p->data.STCLT;
		}
		else if (kitu == key_bkspace && c > 0)
		{
			c--;
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Stcth;
		else if (kitu == key_Up) goto Tenmh;
		else if (kitu == key_esc) goto Out;
		else if (kitu == key_Enter) goto Them;
	}
Stcth:
	gotoxy(x + 22 + d, y + 9);
	while (true)
	{
		kitu = GetKey();
		if (!dieukien(kitu) && so(kitu) && d < 1)
		{
			d++;
			p->data.STCTH = int(kitu - 48);
			cout << p->data.STCTH;
		}
		else if (kitu == key_bkspace && d > 0)
		{
			d--;
			gotoxy(wherex() - 1, wherey());
			cout << ' ';
			gotoxy(wherex() - 1, wherey());
		}
		else if (kitu == key_Down)
			goto Tenmh;
		else if (kitu == key_Up) goto Stclt;
		else if (kitu == key_Enter) goto Them;
		else if (kitu == key_esc) goto Out;
	}

Them:
	if (b == 0 || c == 0 || d == 0) {
		gotoxy(70, 30);
		HideCursor(true);
		cout << "Khong thanh cong!!! Ban can dien du thong tin.";
		Sleep(1000);
		gotoxy(70, 30);
		cout << "                                                  ";
		HideCursor(false);
		if (b == 0) goto Tenmh;
		else if (c == 0) goto Stclt;
		else if (d == 0) goto Stcth;
	}
	else {
		if (b < MAX_TENMH)
			p->data.TENMH[b] = '\0';
		else
			p->data.TENMH[MAX_TENMH - 1] = '\0';

		if (mode == false) {
			p->data.ID = ID_MONHOC[dem_mon_hoc(T)];
			them_mon_hoc(T, p);
		}
		
		Ghi_file_mon_hoc(T);
		Normal();
		HideCursor(true);
		gotoxy(80, 30);
		if(mode == false)
			cout << "Them thanh cong !!!";
		else 
			cout<<"Sua thanh cong !!!";
		Sleep(1000);
		gotoxy(80, 30);
		cout << "                   ";
		goto reset;
	}
Out:
	if (mode == false)
	{
		string thong_bao = "Ban co that su muon thoat ?";
		int check = bang_thong_baoo(thong_bao, 70, 15, 34, 4, 7, 6);
		Normal();
		if (check == 1) goto reset;
		else return;
	}
	else
	{
		string thong_bao = "Neu ban thoat nhung thay doi se khong duoc luu !!!";
		int check = bang_thong_baoo(thong_bao, 60, 15, 58, 4, 15, 14);
		if (check == 0)
		{
			strcpy(p->data.TENMH, B);
			c = C;
			d = D;
			Normal();
			return;
		}
		else goto reset;	
	}
}

int dem_mon_hoc(TREE_MON_HOC* T)
{
	int count = 0;
	TREE_MON_HOC* p = T;
	TREE_MON_HOC* STACK[STACKSIZE];
	int sp = -1;

	while (p != NULL)
	{
		count++;

		if (p->pright != NULL)
			STACK[++sp] = p->pright;
		if (p->pleft != NULL)
			p = p->pleft;
		else
		{
			if (sp == -1)
				break;
			else
			{
				p = STACK[sp--];
			}
		}
	}
	if (T == NULL) return 0;
	return count;
}

TREE_MON_HOC* get_mon_hoc(TREE_MON_HOC* T, TREE_MON_HOC* STACK[], int& sp, int vt)
{
	int count = 0;
	TREE_MON_HOC* p = T;
	sp = -1;

	while (p != NULL && vt > 0)
	{
		vt--;
		if (p->pright != NULL)
			STACK[++sp] = p->pright;
		if (p->pleft != NULL)
			p = p->pleft;
		else
		{
			if (sp == -1)
				break;
			else
			{
				p = STACK[sp--];
			}
		}
	}
	if (T == NULL) return 0;
	return p;
}

void HighLight_mon_hoc(TREE_MON_HOC* p, int x, int y, int stt)
{
	for (int i = 0; i <= 85;i++)
	{
		BGHightLight();
		gotoxy(x + i, y);
		cout << ' ';
	}
	SetColor(color_black);
	gotoxy(x + 2, y);
	cout << "    " << char(179) << "              " << char(179) << "                                  " << char(179) << "               " << char(179);
	gotoxy(x + 2, y);			cout << stt;
	gotoxy(x + 2 + 5 + 2, y);	cout << p->data.MAMH;
	gotoxy(x + 12 + 10 + 2, y);	cout << p->data.TENMH;
	gotoxy(x + 22 + 30 + 9, y);	cout << "   " << p->data.STCLT;
	gotoxy(x + 52 + 15 + 9, y); cout << "   " << p->data.STCTH;
	Normal();
}

void Normal_mon_hoc(TREE_MON_HOC* p, int x, int y, int stt)
{
	for (int i = 0; i <= 85;i++)
	{
		Normal();
		gotoxy(x + i, y);
		cout << ' ';
	}
	Normal;
	gotoxy(x + 2, y);
	cout << "    " << char(179) << "              " << char(179) << "                                  " << char(179) << "               " << char(179);
	gotoxy(x + 2, y);			cout << stt;
	gotoxy(x + 2 + 5 + 2, y);	cout << p->data.MAMH;
	gotoxy(x + 12 + 10 + 2, y);	cout << p->data.TENMH;
	gotoxy(x + 22 + 30 + 9, y);	cout << "   " << p->data.STCLT;
	gotoxy(x + 52 + 15 + 9, y); cout << "   " << p->data.STCTH;

}

void in_ds_mon_hoc(TREE_MON_HOC*& T, bool mode)
{
	TREE_MON_HOC* STACK[STACKSIZE];
	int sp = -1;
	MON_HOC* ds_thu_tu_mon_hoc[STACKSIZE];
	sap_xep_mon_hoc(T, ds_thu_tu_mon_hoc);
	int stt = 1, x = 52, y = 8, trang = 1, luachon = 0, tong_trang;
	char kitu;
	TREE_MON_HOC* p = T;
	int tong_mon = dem_mon_hoc(T);
	if (mode == true)
	{
		gotoxy(50, 35);
		cout << "F1: SUA";
		gotoxy(50, 37);
		cout << "F2: XOA";
	}
	gotoxy(82, 4);
	SetBGColor(color_darkred);
	cout << "DANH SACH TAT CA MON HOC";
chuyen_trang:;
	xoa_man_hinh();
	Normal();
	gotoxy(135, 32);
	tong_trang = so_trang(1.0 * tong_mon / 20);
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
	gotoxy(x + 2, y);			cout << "Stt" << " " << char(179);
	gotoxy(x + 2 + 5 + 2, y);	cout << "Ma mon hoc" << "  " << char(179);
	gotoxy(x + 12 + 10 + 2, y);	cout << "Ten mon hoc" << "                     " << char(179);
	gotoxy(x + 22 + 30 + 9, y);	cout << "So TCLT" << "    " << char(179);
	gotoxy(x + 52 + 15 + 9, y); cout << "So TCTH";
	Normal();
	if (tong_mon == 0) {
		gotoxy(80, 29);
		cout << "DANH SACH TRONG !!!";
		Sleep(1000);
		return;
	}
	int y1 = 2,count = 0;
	gotoxy(x + 2, y + 1);
	cout << "    " << char(179) << "              " << char(179) << "                                  " << char(179) << "               " << char(179);
	if (mode == true)
	{
		while (p != NULL && count < 20)
		{
			count++;
			gotoxy(x + 2, y + y1);
			cout << "    " << char(179) << "              " << char(179) << "                                  " << char(179) << "               " << char(179);
			gotoxy(x + 2, y + y1);					cout << stt++;
			gotoxy(x + 2 + 5 + 2, y + y1);			cout << p->data.MAMH;
			gotoxy(x + 12 + 10 + 2, y + y1);		cout << p->data.TENMH;
			gotoxy(x + 22 + 30 + 9, y + y1);		cout << "   " << p->data.STCLT;
			gotoxy(x + 52 + 15 + 9, y + (y1++));	cout << "   " << p->data.STCTH;


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
		HighLight_mon_hoc(get_mon_hoc(T, STACK, sp, stt - count - 1 + luachon), x, y + 2 + luachon, stt - count + luachon);
	}
	else
	{
		for (int i = stt-1; i < tong_mon && count < 20; i++)
		{
			count++;
			gotoxy(x + 2, y + y1);
			cout << "    " << char(179) << "              " << char(179) << "                                  " << char(179) << "               " << char(179);
			gotoxy(x + 2, y + y1);					cout << stt++;
			gotoxy(x + 2 + 5 + 2, y + y1);			cout << ds_thu_tu_mon_hoc[i]->MAMH;
			gotoxy(x + 12 + 10 + 2, y + y1);		cout << ds_thu_tu_mon_hoc[i]->TENMH;
			gotoxy(x + 22 + 30 + 9, y + y1);		cout << ds_thu_tu_mon_hoc[i]->STCLT;
			gotoxy(x + 52 + 15 + 9, y + (y1++));	cout << "   " << ds_thu_tu_mon_hoc[i]->STCTH;
		}
	}
Huy_lop_failed:
	while (true)
	{
		kitu = GetKey();
		if (kitu == key_Right)
		{
			trang++;
			if (trang > tong_trang) trang = tong_trang;
			else 
			{
				if (mode == true) {
					p = get_mon_hoc(T, STACK, sp, stt - 1);
				}
				luachon = 0;
				goto chuyen_trang;
			}
		}
		else if (kitu == key_Left && trang > 1)
		{
			trang--;
			if (trang < 1) trang = 1;
			else
			{
				stt -= (count + 20);
				if (mode == true) {
					p = get_mon_hoc(T, STACK, sp, stt - 1);
				}
				luachon = 0;
				goto chuyen_trang;
			}
		}
		else if (kitu == key_Down && mode == true)
		{
			luachon++;
			if (luachon > count -1) luachon = count -1;
			else
			{
				Normal_mon_hoc(get_mon_hoc(T, STACK, sp, stt - count + luachon - 1 - 1), x, y + 2 + luachon - 1, stt - count + luachon - 1);
				HighLight_mon_hoc(get_mon_hoc(T, STACK, sp, stt - count + luachon - 1), x, y + 2 + luachon, stt - count + luachon);
			}
		}
		else if (kitu == key_Up && mode == true)
		{
			luachon--;
			if (luachon < 0) luachon = 0;
			else
			{
				Normal_mon_hoc(get_mon_hoc(T, STACK, sp, stt - count + luachon + 1 - 1), x, y + 2 + luachon + 1, stt - count + luachon + 1);
				HighLight_mon_hoc(get_mon_hoc(T, STACK, sp, stt - count + luachon - 1), x, y + 2 + luachon, stt - count + luachon);
			}
		}
		else if (kitu == key_F1 && mode == true)
		{
			TREE_MON_HOC* sua = get_mon_hoc(T, STACK, sp, stt - count - 1 + luachon);
			if (check_mh_dk(sua->data.MAMH))
			{
				gotoxy(75, 33);
				cout << "MON HOC DA DUOC DANG KI LOP TIN CHI, KHONG THE SUA";
				Sleep(1500);
				gotoxy(75, 33);
				cout << "                                                   ";
				goto Huy_lop_failed;
			}
			else
			{
				them_sua_mon_hoc(T,sua,true);
				stt -= count;
				p = get_mon_hoc(T, STACK, sp, stt - 1);
				goto chuyen_trang;
			}	
		}
		else if (kitu == key_F2 && mode == true)
		{
			TREE_MON_HOC* temp = get_mon_hoc(T, STACK, sp, stt - count + luachon - 1);
			if (check_mh_dk(temp->data.MAMH))
			{
				gotoxy(75, 33);
				cout << "MON HOC DA DUOC DANG KI LOP TIN CHI, KHONG THE XOA";
				Sleep(1500);
				gotoxy(75, 33);
				cout << "                                                   ";
				goto Huy_lop_failed;
			}
			else
			{
				string thong_bao = "Ban co that su muon xoa ?";
				int check = bang_thong_baoo(thong_bao, 70, 15, 34, 4, 7, 6);
				if (check == 0)
				{
					xoa_mon_hoc(T, temp);
					tong_mon--;
					if (luachon + stt - count > tong_mon) luachon--;
					if (luachon < 0)
					{
						luachon = 19;
						stt -= 20;
						trang--;
					}
					Ghi_file_mon_hoc(T);
				}
			}
			stt -= count;
			p = get_mon_hoc(T, STACK, sp, stt - 1);
			goto chuyen_trang;
		}
		else if (kitu == key_esc)
		{
			for (int i = 0; i < tong_mon;i++)
				delete ds_thu_tu_mon_hoc[i];
			gotoxy(82, 4);
			Normal();
			cout << "                        ";
			gotoxy(50, 35);
			cout << "        ";
			gotoxy(50, 37);
			cout << "        ";
			return;
		}
	}
}
