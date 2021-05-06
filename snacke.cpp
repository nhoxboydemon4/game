#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "XY.h"

#define MAX 100

int sd=4;
void khoi_tao(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void them(int a[], int x);
void xoa(int a[],int vt);
void su_ly(int toadox[], int toadoy[],int x, int y,int &xmoi,int &ymoi,int &diem);
void xoadot(int toadox[],int toadoy[]);
void hienthikhung(int diem);
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_trai();
void ve_tuong();
bool kt_ran_cham_duoi(int toadox[],int toadoy[]);
bool kt_ran(int toadox[],int toadoy[]);
bool kiem_tra_cham_tuong(int x0,int y0);
void tao_moi(int toadox[],int toadoy[],int &xmoi,int &ymoi);
bool kiem_tra_ran(int toadox[],int toadoy[],int xmoi,int ymoi);
bool ran_an_moi(int x0,int y0,int xmoi,int ymoi);
void menu();

int main(){
	int diem=1;
	bool gameover = false;
	int toadox[MAX],toadoy[MAX];
	int xmoi=0,ymoi=0;
	int x=20,y=13;
	srand(time(NULL));
	ve_tuong();
	khoi_tao(toadox,toadoy);
	ve_ran(toadox,toadoy);
	tao_moi(toadox,toadoy,xmoi,ymoi);
	int check=2;
	while(gameover == false){
	xoadot(toadox,toadoy);
	if(kbhit()){
		char kitu=getch();
		if(kitu==-32){
			kitu=getch();
			if(kitu==72){
				check=0;
			}
			if(kitu==75){
				check=1;
			}
			if(kitu==77){
				check=2;
			}
			if(kitu==80){
				check=3;
			}
		}
	}
	if(check==0){
	y--;
	}
	else if(check==1){
	x--;
	}
	else if(check==2){
	x++;
	}
	else if(check==3){
	y++;
	}
	su_ly(toadox,toadoy,x,y,xmoi,ymoi,diem);
	gameover = kt_ran(toadox,toadoy);
	gotoXY(2,2);
	printf("Diem: %d",diem);
	Sleep(200);
	}
	system("cls");
	gotoXY(50,15);
	printf("GAME OVER!!BAN GA VCL");
	getch();
	return 0;
}
void khoi_tao(int toadox[], int toadoy[]){
	int x=20,y=13;
	for(int i =0;i<sd;i++){
		toadox[i]=x;
		toadoy[i]=y; 	
		x--;
		
	}
}
void ve_ran(int toadox[], int toadoy[]){
	 for(int i=0;i<sd;i++)
	 {
	 	gotoXY(toadox[i],toadoy[i]);
	 	if(i==0)
	 	{
	 		printf("O");
		}
		else
		{
			printf("+");
		}
	}
}
void su_ly(int toadox[], int toadoy[],int x, int y,int &xmoi,int &ymoi,int &diem){
	them(toadox,x);
	them(toadoy,y);
	if(ran_an_moi(toadox[0],toadoy[0],xmoi,ymoi)==false){
		xoa(toadox,sd-1);
	    xoa(toadoy,sd-1);
	}
	else{
		tao_moi(toadox,toadoy,xmoi,ymoi);
		diem++;
	}
	ve_ran(toadox,toadoy);
}
void them(int a[], int x){
	for(int i = sd;i>0;i--){
		a[i]=a[i-1];
	}
	a[0]=x;
	sd++;
}
void xoa(int a[],int vt){
	for(int i=vt;i<sd;i++){
		a[i]=a[i+1];
	}
	sd--;
}
void xoadot(int toadox[],int toadoy[]){
	for(int i=0;i<sd;i++){
		gotoXY(toadox[i],toadoy[i]);
		printf(" ");
	}
}
void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		printf("_");
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x,y);
		printf("_");
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		printf("+");
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		printf("+");
		y++;
	}
}
void ve_tuong()
{
	char ten[12];
	SetColor(2);
	gotoXY(45,13);
	printf("WHAT YOUR NAME: ");
	gets(ten);
	system("cls");
	gotoXY(30,1);
	printf("NAME:%c",ten);
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	SetColor(7);
}
bool kiem_tra_cham_tuong(int x0,int y0)
{
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	//ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	//ran cham tuong phai
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	//ran cham tuong trai
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[],int toadoy[])
{
	for (int i = 1;i < sd;i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;//gameover
		}
	}
	return false;
}
bool kt_ran(int toadox[],int toadoy[])
{
	bool kt1 = kt_ran_cham_duoi(toadox, toadoy);//gameover = true
	bool kt2 = kiem_tra_cham_tuong(toadox[0], toadoy[0]);//gameover = false
	if (kt1 == true || kt2 == true)
	{
		return true;//gameover
	}
	return false;
}
void tao_moi(int toadox[],int toadoy[],int &xmoi,int &ymoi){
	do{
		xmoi=rand()%(99-10+1)+10;
	    ymoi=rand()%(24-4+1)+4;
	}
	while(kiem_tra_ran(toadox,toadoy,xmoi,ymoi)==true);
	gotoXY(xmoi,ymoi);
	printf("$");
	
}
bool kiem_tra_ran(int toadox[],int toadoy[],int xmoi,int ymoi){
	for (int i=0;i<sd;i++){
		if(toadox[i]==xmoi && toadoy[i]==ymoi)
		return true;
		else
	    return false;
	}
}
bool ran_an_moi(int x0,int y0,int xmoi,int ymoi){
	if(x0==xmoi&&y0==ymoi){
		return true;
	}
	else return false;
}
void hienthikhung(int diem)
	{
		char ht;
		gotoXY(60, 10);
		SetColor(2);
		printf("nhap ten: ");
		gotoXY(60, 18);
		printf ("DIEM: %d",diem);
		gotoXY(15, 1);
		gotoXY(60, 14);
		printf ("DIEU KHIEN BANG: CAC PHIM MUI TEN" );
		gotoXY(60, 18);
	}
