//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
for(int i=0;i<=300;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=RGB(255,255,255);
 }
}
PaintBox1->Canvas->Pen->Color=RGB(95,95,95);
PaintBox1->Canvas->Brush->Color=0;
PaintBox1->Canvas->Pen->Width = 2;
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(2+i*40,0,24+i*40,20);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(11+i*40,20,31+i*40,40);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(19+i*40,40,39+i*40,60);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(14+i*40,60,34+i*40,80);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(7+i*40,80,27+i*40,100);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(3+i*40,100,23+i*40,120);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(10+i*40,120,30+i*40,140);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(17+i*40,140,37+i*40,160);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(25+i*40,160,45+i*40,180);
}
for(int i=0;i<8;i++)
{
  PaintBox1->Canvas->Rectangle(15+i*40,180,35+i*40,200);
}

PaintBox1->Canvas->Pen->Color=RGB(95,95,95);
PaintBox1->Canvas->Pen->Width = 2;
PaintBox1->Canvas->MoveTo(0,0);
PaintBox1->Canvas->LineTo(300,0);
PaintBox1->Canvas->MoveTo(0,20);
PaintBox1->Canvas->LineTo(300,20);
PaintBox1->Canvas->MoveTo(0,40);
PaintBox1->Canvas->LineTo(300,40);
PaintBox1->Canvas->MoveTo(0,60);
PaintBox1->Canvas->LineTo(300,60);
PaintBox1->Canvas->MoveTo(0,80);
PaintBox1->Canvas->LineTo(300,80);
PaintBox1->Canvas->MoveTo(0,100);
PaintBox1->Canvas->LineTo(300,100);
PaintBox1->Canvas->MoveTo(0,120);
PaintBox1->Canvas->LineTo(300,120);
PaintBox1->Canvas->MoveTo(0,140);
PaintBox1->Canvas->LineTo(300,140);
PaintBox1->Canvas->MoveTo(0,160);
PaintBox1->Canvas->LineTo(300,160);
PaintBox1->Canvas->MoveTo(0,180);
PaintBox1->Canvas->LineTo(300,180);
PaintBox1->Canvas->MoveTo(0,200);
PaintBox1->Canvas->LineTo(300,200);

}
//---------------------------------------------------------------------------
